/* lässt LED wabern
 * flashen mit: sudo avrdude -c usbasp -p atmega8 -B 100 -U flash:w:main.hex -B 1
 * TODO:
 * - add another poti for modulation amplitude and offset
 * - port everything to attiny45
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define FOSC 8000000UL
#define F_CPU 8000000UL
#define BAUD 9600
#define ubrr 51

#define ADC_THRESHOLD 4

/* Globals */
char string_buffer[32];

void uart_init() {
	UBRRH = (unsigned char)(ubrr>>8);
	UBRRL = (unsigned char)ubrr;
	
	UCSRB = (1 << RXEN) | (1 << TXEN);
    UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
}
int uart_putc(unsigned char c) {
    while (!(UCSRA & (1<<UDRE)))  /* warten bis Senden moeglich */
    {
    }                             
 
    UDR = c;                      /* sende Zeichen */
    return 0;
}
void uart_puts (char *s) {
    while (*s)
    {   /* so lange *s != '\0' also ungleich dem "String-Endezeichen(Terminator)" */
        uart_putc(*s);
        s++;
    }
}

void init_pwm() {
	DDRB = 0x0E;                      // Set Port PB1, PB2 and PB3 as Output
    
    TCCR1A = (1<<WGM10)|(1<<COM1A1)   // Set up the two Control registers of Timer1.
            |(1<<COM1B1);             // Wave Form Generation is Fast PWM 8 Bit,
    TCCR1B = (1<<WGM12)|(1<<CS12);     // OC1A and OC1B are cleared on compare match
									  // and set at BOTTOM. Clock Prescaler is 256.
								
	TCCR2 = (1<<WGM20)|(1<<WGM21)|(1<<COM21)|(1<<CS21)|(1<<CS22);   // Set up the two Control registers of Timer1.
																	// Wave Form Generation is Fast PWM 8 Bit,
																	// OC1A and OC1B are cleared on compare match
																	// and set at BOTTOM. Clock Prescaler is 256.
									
									

    OCR1A = 0;                       // 63: Dutycycle of OC1A = 25%
    OCR1B = 0;                      // 127:Dutycycle of OC1B = 50%
    OCR2 = 0;
    /*
     * OCR1A/B and OCR2 store the duty cycle in 8bit accuracy in this mode! (Fast PWM 8 Bit)
     */
	
}

uint8_t counter = 0;
uint8_t counter_direction = 0; /*0 = upward, 1 = downward */
uint8_t dreiecksfunktion(uint8_t offset) {
	uint8_t return_value = 0;
	uint8_t noise = 0;

	if(counter == 252) counter_direction = 1;
	if(counter == offset) counter_direction = 0;

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
uint16_t old_adc_value = 0;
uint8_t adc_interrupt_flag = 0;
void init_adc() {
	ADMUX = (1<<REFS0);               // Set Reference to AVCC and input to ADC0
    ADCSRA = (1<<ADFR)|(1<<ADEN)      // Enable ADC, set prescaler to 16
            |(1<<ADPS2)|(1<<ADIE);    // Fadc=Fcpu/prescaler=1000000/16=62.5kHz
                                      // Fadc should be between 50kHz and 200kHz
                                      // Enable ADC conversion complete interrupt

    sei();                            // Set the I-bit in SREG

    ADCSRA |= (1<<ADSC);              // Start the first conversion
}

// void switch_adc(uint8_t channel) {
// 	ADMUX = (channel & 0x07)|(1<<REFS0);
// }

int main(void)
{
	uart_init();
	init_pwm();
	init_adc();

	uint8_t dutycycle_a = 0;
	uint8_t dutycycle_b = 0;
	double time_to_wait = 1e3;
    while(1) {
    	if(adc_interrupt_flag) {
    		sprintf(string_buffer,"%i\n",ADC);
    		uart_puts(string_buffer);
    		adc_interrupt_flag = 0;
    		time_to_wait = 1e3 + (1e4*ADC)/1023;
    	}
    	dutycycle_a = dreiecksfunktion(127);
    	OCR1A = dutycycle_a;
    	OCR1B = dutycycle_b;
    	_delay_us(time_to_wait);
    }
    return 0;
}

ISR(ADC_vect) {
	/* only set the flag, if ADC-Value has changed significantly */

	if(((ADC > old_adc_value) && ((ADC - old_adc_value) > ADC_THRESHOLD)) || ((ADC < old_adc_value) && ((old_adc_value - ADC) > ADC_THRESHOLD))) {
		old_adc_value = ADC;
		adc_interrupt_flag = 1;
	}
}