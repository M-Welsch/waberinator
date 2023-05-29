/* TODOs
* Major
* - logging
* - Test this while loop in update_adc
*
* Minor
* - overtemperature detection via OS pin => Overtemp has to be written to LM75 correctly
* - shutdown LM75 after each measure
* - disable BROWN-OUT DETECTOR
* 
* Possible Performance tweaks:
* - set ADC prescaler to 32. Fadc is then 250kHz (more noisy, but convesion completes faster) (1<<ADPS2)|(1<<ADPS0)
*/
#include <avr/io.h>
#include <util/delay.h>
#include <math.h>
#include <stdlib.h>
#include <avr/eeprom.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

#include "i2c_master.h"
#include "uart.h"

#define LEDS PB1
#define LED_STRING_1 PB2
#define ADC_FREQUENCY 0
#define ADC_DEPTH 1
#define ADC_VBAT 2
#define LT8642_EN PB0
#define OVERTEMERATURE_LED PB2
#define LM75B_OS_PIN PD2
#define BUTTON PD3
#define VBAT_CHECK_LED_GREEN1 PD4
#define VBAT_CHECK_LED_GREEN2 PD5
#define VBAT_CHECK_LED_YELLOW PD6
#define VBAT_CHECK_LED_RED PD7

#define LM75B_SMPS 0x90
#define LM75B_LDO 0x92
#define LM75B_SMPS_WRITE 0x90
#define LM75B_SMPS_READ 0x91

#define UNDERVOLTAGE_THRESHOLD 594 //with 100k and 33k => Vbat,min = 11.8V
#define OVERTEMPERATURE_THRESHOLD 21760 //about 85°C
#define ADC_THRESHOLD 4
#define UNDERVOLTAGE_COUNT 3 //measures with undervoltage necessary to cause shutdown

/* globals */
uint8_t old_adc_value = 0;
uint8_t eeprom_pointer = 0;
uint8_t adc_channel = 0;
uint16_t waberung_frequency = 0;
uint16_t waberung_depth = 0;
uint16_t vbat = 0;
uint16_t temperature = 0;
uint16_t temperature_ldo = 0;

/* flags */
volatile uint8_t logger[3];
volatile uint8_t overtemperature_flag = 0;
volatile uint8_t undervoltage_flag = 0;
volatile uint8_t adc_conversion_complete_flag = 0;
uint8_t logging_active = 0;
uint8_t button_pushed_flag = 0;

/* complex datatypes */
enum reasons {overtemperature, undervoltage};
struct eeprom_data_template {
	enum reasons id;
	uint8_t byte0;
	uint8_t byte1;
	uint8_t byte2;
};
enum states {INITIAL, WABERING, SHUTDOWN};
enum states state = INITIAL;
char buffer[32];

/* functions */

int16_t getTemperature(uint8_t sensor_address)  {
	int16_t raw_temperature = 0;
	int8_t temp_negative = 0;
	
	/* set pointer to temp-register*/
	i2c_start(sensor_address);
	i2c_write(0x00);

	/* read 16bit value from temp-register and free the bus*/
	i2c_start(sensor_address|0x01);
	raw_temperature = ((uint8_t) i2c_read_ack())<<8;
	raw_temperature |= i2c_read_nack();
	i2c_stop();

	return raw_temperature >> 5; 
}

void shutdown_LM75(void) {
	/* set pointer to config-register*/
	i2c_start(LM75B_SMPS_WRITE);
	i2c_write(0x01);

	/* set shutdown bit */
	i2c_write(0x01); //fixme: don't change queue with: 0x19 
	i2c_stop();
}

void wake_LM75(void) {
	/* set pointer to config-register*/
	i2c_start(LM75B_SMPS_WRITE);
	i2c_write(0x01);

	/* set shutdown bit */
	i2c_write(0x00); 
	i2c_stop();	
}

void external_interrupt_init() {
	/* generate Interrupt if INT0 = PD2 or INT1 = PD3 is pulled to zero */
	MCUCR |= (1<<ISC01) | (1<<ISC11); //fixme: commenting out this line makes the program stuck ... dont know why
	GICR |= (1<<INT0) | (1<<INT1);
}
void timer2_init() {
	/* put timer into Clear Timer on Compare Match (CTC) mode. It clears the timer when its value reaches OCR2 */
	TCCR2 |= (1<<WGM21);
	TCCR2 &= ~(1<<WGM20);
	OCR2 = 255; //with prescaler of 1024 it has a cycle of 0.032768s

	/* set prescaler to 1024 */
	TCCR2 |= (1<<CS00) | (1<<CS01) | (1<<CS02);
 
	/* enable interrupt on compare match */
	TIMSK |= (1<<TOIE2);

}

void MaxTemperatureInterrupt_init(uint16_t temperature_raw) {
	uint8_t msb_temperature = 0;
	uint8_t lsb_temperature = 0;
	uint16_t readback_temperature = 0;
	msb_temperature = (uint8_t) ((temperature_raw&0xff00)>>8);
	lsb_temperature = (uint8_t) (temperature_raw&0x00ff);

	/* set pointer to conf-register */
	i2c_start(LM75B_SMPS_WRITE);
	i2c_write(0x01);


	/* set bit3 and 4 HIGH to set queue to 6 */
	i2c_start(LM75B_SMPS_WRITE);
	i2c_write(0x18);
	i2c_stop();

	/* set pointer to overtemp-register (0x03)*/
	i2c_start(LM75B_SMPS_WRITE);
	i2c_write(0x03);

	i2c_write(msb_temperature);
	i2c_write(lsb_temperature);
	// sprintf(buffer,"Value = %i\nMSB = %i\nLSB = %i\n",temperature_hundreths_degrees_celsius,msb_temperature,lsb_temperature);
	// uart_puts(buffer);
	i2c_start(LM75B_SMPS_READ);
	readback_temperature = ((uint8_t) i2c_read_ack())<<8;
	readback_temperature |= i2c_read_nack();
	// sprintf(buffer,"Value = %i\n",readback_temperature);
	// uart_puts(buffer);
	i2c_stop();
}

void adc_init() {
	uint8_t use_old_setting = 0;
	ADMUX = (1<<REFS0);               // Set Reference to AVCC and input to ADC0
	if(use_old_setting) {
		ADCSRA = (1<<ADFR)|(1<<ADEN)      // Enable ADC, set prescaler to 16
		|(1<<ADPS2)|(1<<ADIE);    		// Fadc=Fcpu/prescaler=1000000/16=62.5kHz
                                      // Fadc should be between 50kHz and 200kHz
                                      // Enable ADC conversion complete interrupt
	}
	else {
		ADCSRA = (1<<ADEN)|(1<<ADIE)|(1<<ADPS1)|(1<<ADPS2); //enable ADC, set prescaler to 64 (8MHz/64=125kHz), enable conversion compete interrupt, use single conversion mode
	}


    //sei();                            // Set the I-bit in SREG

    //ADCSRA |= (1<<ADSC);              // Start the first conversion
}

void switch_adc(uint8_t channel) {
	ADMUX = (channel & 0x03)|(1<<REFS0);
}

void update_adc_values() {

	//Fixme: crossing of ADC Channels ... 
	switch_adc(adc_channel);
	adc_conversion_complete_flag = 0;
	ADCSRA |= (1<<ADSC); //start conversion
	while(adc_conversion_complete_flag==0) {} //wait until conversion is complete (alternatively check for the ADSC. If it is 0 then the conversion is complete)
	switch(adc_channel) {
		case ADC_FREQUENCY:
			vbat = ADC;
			break;
		case ADC_DEPTH:
			waberung_frequency= ADC;
			break;
		case ADC_VBAT:
			waberung_depth = (uint8_t) (ADC/4);
			if(waberung_depth > 252) waberung_depth = 252;
			break;
		default:
			break;
	}
	adc_channel++;
	if(adc_channel>2) adc_channel = 0;
}

void pwm_init() {
    TCCR1A = (1<<WGM10)|(1<<COM1A1)   // Set up the two Control registers of Timer1.
            |(1<<COM1B1);             // Wave Form Generation is Fast PWM 8 Bit,
    TCCR1B = (1<<WGM12)|(1<<CS12);     // OC1A and OC1B are cleared on compare match
									  // and set at BOTTOM. Clock Prescaler is 256.

    OCR1A = 0;                       // 63: Dutycycle of OC1A = 25%
    OCR1B = 0;                      // 127:Dutycycle of OC1B = 50%
}

/* initializes i2c, uart, eeprom, interrupt */
void initialize() {
	uart_init();
	uart_puts("Start\n");
	i2c_init();
	getTemperature(LM75B_SMPS); //Datasheet says to ignore first reading.
	uart_puts("Here I am\n");
	adc_init();
	external_interrupt_init();
	MaxTemperatureInterrupt_init(OVERTEMPERATURE_THRESHOLD);
	timer2_init();
	pwm_init();
	sei();
	DDRB |= ((1<<LEDS) | (1<<LED_STRING_1) | (1<<LT8642_EN) | (1<<OVERTEMERATURE_LED));
	DDRD |= ((1<<VBAT_CHECK_LED_GREEN1)|(1<<VBAT_CHECK_LED_GREEN2)|(1<<VBAT_CHECK_LED_YELLOW)|(1<<VBAT_CHECK_LED_RED));
	PORTD &= ~((1<<VBAT_CHECK_LED_GREEN1)|(1<<VBAT_CHECK_LED_GREEN2)|(1<<VBAT_CHECK_LED_YELLOW)|(1<<VBAT_CHECK_LED_RED));
	PORTD |= (1<<BUTTON) | (1<<LM75B_OS_PIN); //enable pullup
	PORTB &= ~(1<<OVERTEMERATURE_LED);
	eeprom_pointer = (eeprom_read_word(511))*3;
	if(eeprom_pointer > 511) {
		eeprom_pointer = 0;
		eeprom_update_word(511,eeprom_pointer);
	}
}

void shutdown() {
	uart_puts("Shutdown!!\n");
	state = SHUTDOWN;
	TCCR1A &= ~(1<<COM1A1); //disable PWM
	OCR1A = 0;
	OCR1B = 0;
	DDRB &= ~(1<<LEDS);
	PORTB &= ~(1<<LT8642_EN);
	set_sleep_mode (SLEEP_MODE_PWR_DOWN); //external interrupt can wake the MCU.
	//fixme: adc is still active
	sleep_mode();
}

void log_event(enum reasons reason) {
	struct eeprom_data_template log;
	log.id = reason;
	log.byte0 = logger[0];
	log.byte1 = logger[1];
	log.byte2 = logger[2];

	eeprom_update_word(eeprom_pointer, log.id);
	eeprom_update_word(eeprom_pointer+1, log.byte0);
	eeprom_update_word(eeprom_pointer+2, log.byte1);
	eeprom_update_word(eeprom_pointer+3, log.byte2);
	eeprom_update_word(511,eeprom_pointer+1);
}

void set_control_leds() {
	if(vbat > 692) {
		PORTD |= ((1<<VBAT_CHECK_LED_GREEN1)|(1<<VBAT_CHECK_LED_GREEN2)|(1<<VBAT_CHECK_LED_YELLOW)|(1<<VBAT_CHECK_LED_RED));
	}
	else if(vbat > 660) {
		PORTD |= ((1<<VBAT_CHECK_LED_GREEN2)|(1<<VBAT_CHECK_LED_YELLOW)|(1<<VBAT_CHECK_LED_RED));
		PORTD &= ~(1<<VBAT_CHECK_LED_GREEN1);
	}
	else if(vbat > 624) {
		PORTD |= ((1<<VBAT_CHECK_LED_YELLOW)|(1<<VBAT_CHECK_LED_RED));
		PORTD &= ~((1<<VBAT_CHECK_LED_GREEN1)|(1<<VBAT_CHECK_LED_GREEN2));
	}
	else {
		PORTD |= (1<<VBAT_CHECK_LED_RED);
		PORTD &= ~((1<<VBAT_CHECK_LED_GREEN1)|(1<<VBAT_CHECK_LED_GREEN2)|(1<<VBAT_CHECK_LED_YELLOW));		
	}
	if(overtemperature_flag) {
		PORTB |= (1<<OVERTEMERATURE_LED);
	} else {
		PORTB &= ~(1<<OVERTEMERATURE_LED);
	}
}

uint8_t counter = 0;
uint8_t counter_direction = 0; /*0 = upward, 1 = downward */
uint8_t dreiecksfunktion() {
	uint8_t return_value = 0;
	uint8_t noise = 0;

	if(counter <= (255 - waberung_depth)) counter_direction = 0;
	if(counter == 252) counter_direction = 1;

	if(counter_direction == 0) {
		/* counting upward */
		return_value = counter;
		counter++;
	}
	else {
		/* counting downward */
		return_value = counter;
		counter--;
	}
	noise = rand() & 0x03; /* results in a value between 0 and 3 */

	return_value += noise;

	return return_value;
}

int main(void){
	

	initialize();

	uint16_t mainloop_counter = 0;
	uint8_t mainloop_counter2 = 0;
	uint8_t overtemperature_counter = 0;
	uint8_t undervoltage_counter = 0;
	float time_to_wait = 1;
	uint8_t time_to_wait_ms = 1;

	/* check with which state to start */
	switch_adc(ADC_VBAT); // don't know why switching to VBAT works here but not in update_adc ...
	for(uint8_t i = 0; i < 8; i++) {
		while(adc_conversion_complete_flag == 0) {}
			if(ADC < UNDERVOLTAGE_THRESHOLD) {
			undervoltage_counter++;
			adc_conversion_complete_flag = 0;
		}
	}
	if(undervoltage_counter > 6) {
		undervoltage_flag = 1;
		//if(logging_active) {
			sprintf(buffer,"Undervoltage. Vbat = %i\n", ADC);
			uart_puts(buffer);
		//}
		shutdown();
	}

	uint8_t pinToCheck = 0;
	pinToCheck = PIND & (1<<BUTTON);
	uart_puts(buffer);
	//if(pinToCheck == 0x00) {
		logging_active = 1;
		uart_puts("Logging Active\n");
		PORTD |= ((1<<VBAT_CHECK_LED_GREEN1)|(1<<VBAT_CHECK_LED_GREEN2)|(1<<VBAT_CHECK_LED_YELLOW)|(1<<VBAT_CHECK_LED_RED));
		_delay_ms(300);
		PORTD &= ~((1<<VBAT_CHECK_LED_GREEN1)|(1<<VBAT_CHECK_LED_GREEN2)|(1<<VBAT_CHECK_LED_YELLOW)|(1<<VBAT_CHECK_LED_RED));
	//}

	PORTB |= (1<<LT8642_EN);
	uint8_t Waber;
	while(1){
		if(mainloop_counter%10000 == 0) {

			/* read temperature, check whether it is ok and shutdown if not */
			temperature = getTemperature(LM75B_SMPS);
			temperature_ldo = getTemperature(LM75B_LDO);
			/* output values if device is in logging mode
			* Format: timestamp, temperature, vbat, frequency, depth
			*/
			if(logging_active) {
				sprintf(buffer,"0,%i,%i,%i,%i,%i\n",temperature,temperature_ldo,vbat,waberung_frequency,waberung_depth);
				uart_puts(buffer);	
			}
			if(temperature > OVERTEMPERATURE_THRESHOLD) {
				if(overtemperature_counter > 6) {
					log_event(overtemperature);
					shutdown();
					break;
				}
				overtemperature_counter ++;
			}
			mainloop_counter=0;

			if(vbat < UNDERVOLTAGE_THRESHOLD) {
				sprintf(buffer,"Undervoltage detected, VBAT = %i\n",vbat);
				uart_puts(buffer);
				if(undervoltage_counter > UNDERVOLTAGE_COUNT) { 
					log_event(undervoltage);
					shutdown();
					break;
				}
				undervoltage_counter++;
			}
			else {
				if(undervoltage_counter!=0) {
					undervoltage_counter--;				
				}
			}
		}

		/* update ADC values */
		update_adc_values();
		//sprintf(buffer,"DC=%i, ADC-Values: w_freq = %i, w_dep = %i, vbat = %i\n", OCR1A, waberung_frequency, waberung_depth, vbat);
		//sprintf(buffer,"dir: %i\n", counter_direction);
		//uart_puts(buffer);
		//sprintf(buffer,"TimeToWait = %i\n",(uint16_t) time_to_wait);
		//uart_puts(buffer);
		if(mainloop_counter2 == time_to_wait_ms) {
			/* update dutycycle */
			
			Waber = dreiecksfunktion();
			OCR1A = Waber;
			OCR1B = Waber;
			//time_to_wait = 1+(99*(((float) waberung_frequency)/1023)); 
			//time_to_wait_ms = (uint8_t) time_to_wait;
			time_to_wait_ms = 1 + waberung_frequency/15; //fixme: find usable value ranges
			//sprintf(buffer, "Time to wait: %i\n",time_to_wait_ms);
			mainloop_counter2 = 0;
		}

		/* Control LEDS */
		if((button_pushed_flag==1)&&((mainloop_counter%100)==0)) { //change the x in mainloop_counter%x to smth. lower in order to make it respond fateer. On the downside it slows down everything else
			//sprintf(buffer,"Button pushed. Vbat = %i, PIND = %i\n",vbat,PIND);
			//uart_puts(buffer);
			if((PIND&(1<<BUTTON))==(0xff&(1<<BUTTON))) {
				/* enter this branch if Button is released */
				PORTD &= ~((1<<VBAT_CHECK_LED_GREEN1)|(1<<VBAT_CHECK_LED_GREEN2)|(1<<VBAT_CHECK_LED_YELLOW)|(1<<VBAT_CHECK_LED_RED));
				PORTB &= ~(1<<OVERTEMERATURE_LED);
				button_pushed_flag = 0;
				GICR |= (1<<INT1);
				if(state==SHUTDOWN) {
					//shutdown();
				}
			} else {
				set_control_leds();
			} 
		}
		_delay_us(25);
		mainloop_counter++;
		mainloop_counter2++;
	}
	
	return 0;
}

ISR(INT0_vect) {
	overtemperature_flag = 1;
	if(logging_active) {
		uart_puts("LT8642 PGOOD Fail!\n");
	}
}

/* Button Pushed */
ISR(INT1_vect) {
	if(logging_active) {
		uart_puts("Button pushed\n");
	}
	GICR &= ~(1<<INT1);
	button_pushed_flag = 1;
}

ISR(ADC_vect) {
	/* only set the flag, if ADC-Value has changed significantly */ ///TODO place this in update_adc. Setting the flag only if value changes significantly puts the initial undervoltage check into infinity loop.
	if(((ADC > old_adc_value) && ((ADC - old_adc_value) > ADC_THRESHOLD)) || ((ADC < old_adc_value) && ((old_adc_value - ADC) > ADC_THRESHOLD))) {
		old_adc_value = ADC;
	}
	adc_conversion_complete_flag = 1;
}

ISR(TIMER2_OVF_vect) {
	if(logger[0] != 255) {
		logger[0]++;
	}
	else {
		logger[0] = 0;
		if(logger[1] != 255) {
			logger[1]++;
		}
		else {
			logger[1] = 0;
			logger[2]++;
		}
	}
}
