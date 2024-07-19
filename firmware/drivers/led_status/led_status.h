#ifndef FIRMWARE_LED_STATUS_H
#define FIRMWARE_LED_STATUS_H

#include "stdint.h"

void led_status_init(void);
int led_status_color_numeric(uint8_t red, uint8_t green, uint8_t blue);

typedef enum {
    STATUS_LED_COLOR_RED,
} status_led_color_t;

int led_status_color(status_led_color_t color);

#endif //FIRMWARE_LED_STATUS_H
