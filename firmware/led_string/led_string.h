//
// Created by max on 14.03.24.
//

#ifndef FIRMWARE_LED_STRING_H
#define FIRMWARE_LED_STRING_H

#include <stdint.h>

#define NUM_CHANNELS 6

void led_string_init(void);
int led_string_setBrightness(uint8_t channel, float brightness);

#endif //FIRMWARE_LED_STRING_H
