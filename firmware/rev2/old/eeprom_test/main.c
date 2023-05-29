/* writes stuff into eeprom */

#include <avr/io.h>
#include <avr/eeprom.h>

void main(void) {
	for(uint8_t i = 0; i < 256; i++) {
		eeprom_update_word(i,i);
	}
	for(uint8_t i = 0; i < 256; i++) {
		eeprom_update_word(i+256,i);
	}
	exit(0);
}