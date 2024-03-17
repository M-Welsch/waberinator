#ifndef FIRMWARE_LED_STRING_H
#define FIRMWARE_LED_STRING_H

#include <stdint.h>

void led_string_init(void);
int led_string_setBrightness(uint8_t channel, float brightness);
int led_string_on(uint8_t channel);
int led_string_off(uint8_t channel);

#endif //FIRMWARE_LED_STRING_H
