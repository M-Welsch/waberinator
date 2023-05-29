#define FOSC 8000000UL
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
//#include <stdlib.h>

int main(void) {

	DDRD |= (1<<PD5) | (1<<PD6) | (1<<PD7);					//PD7 ist ein Ausgang
	DDRB |= (1<<PB0);
	PORTD = 0x00;
	_delay_ms(1000);
	PORTD |= (1<<PD5) | (1<<PD6) | (1<<PD7);					//und ist High
	PORTB |= (1<<PB0);

	while(1) {
		_delay_ms(1000);
		PORTD ^= (1<<PD5);
	}
}