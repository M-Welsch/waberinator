#ifndef FIRMWARE_LED_STATUS_H
#define FIRMWARE_LED_STATUS_H

#include "stdint.h"

void led_status_init(void);
int led_status_color_numeric(uint16_t red, uint16_t green, uint16_t blue);

typedef enum {
    STATUS_LED_COLOR_RED,
    STATUS_LED_COLOR_GREEN,
    STATUS_LED_COLOR_BLUE,
} status_led_color_t;

int led_status_color(status_led_color_t color, uint16_t brightness_percent);

#endif //FIRMWARE_LED_STATUS_H
