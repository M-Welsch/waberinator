#include "hal.h"

#include "led_status.h"


static PWMConfig pwm1_cfg = {
        6000000,                                    /* 10kHz PWM clock frequency.   */
        65535,                                    /* Initial PWM period 1S.       */
        NULL,
        {
                {PWM_OUTPUT_ACTIVE_HIGH, NULL},
                {PWM_OUTPUT_ACTIVE_HIGH, NULL},
                {PWM_OUTPUT_ACTIVE_HIGH, NULL},
                {PWM_OUTPUT_DISABLED, NULL}
        },
        0,
        0,
        0
};

void led_status_init(void) {
    pwmStart(&PWMD1, &pwm1_cfg);
}

int led_status_color_numeric(uint16_t red, uint16_t green, uint16_t blue) {
    if (red > 10000) {
        red = 10000;
    }
    if (green > 10000) {
        green = 10000;
    }
    if (blue > 10000) {
        blue = 10000;
    }
    pwmEnableChannel(&PWMD1, 0, PWM_PERCENTAGE_TO_WIDTH(&PWMD1, blue));
    pwmEnableChannel(&PWMD1, 1, PWM_PERCENTAGE_TO_WIDTH(&PWMD1, green));
    pwmEnableChannel(&PWMD1, 2, PWM_PERCENTAGE_TO_WIDTH(&PWMD1, red));
    return 0;
}

/**
 * @param color pick one
 * @param brightness_percent values = [0 .. 10000] like in the pwm drivers
 * @return
 */
int led_status_color(const status_led_color_t color, uint16_t brightness_percent) {
    switch (color) {
        case STATUS_LED_COLOR_RED:
            led_status_color_numeric(brightness_percent, 0, 0);
            break;
        case STATUS_LED_COLOR_GREEN:
            led_status_color_numeric(0, brightness_percent, 0);
            break;
        case STATUS_LED_COLOR_BLUE:
            led_status_color_numeric(0, 0, brightness_percent);
            break;
        default:
            return -1;
    }
    return 0;
}