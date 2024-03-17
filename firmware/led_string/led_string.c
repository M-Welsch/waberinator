#include "led_string.h"
#include "hal.h"

static PWMConfig pwm1_cfg = {
        100000,                                    /* 10kHz PWM clock frequency.   */
        1000,                                    /* Initial PWM period 1S.       */
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

static PWMConfig pwm3_cfg = {
        100000,                                    /* 10kHz PWM clock frequency.   */
        1000,                                    /* Initial PWM period 1S.       */
        NULL,
        {
                {PWM_OUTPUT_ACTIVE_HIGH, NULL},
                {PWM_OUTPUT_ACTIVE_HIGH, NULL},
                {PWM_OUTPUT_ACTIVE_HIGH, NULL},
                {PWM_OUTPUT_ACTIVE_HIGH, NULL}
        },
        0,
        0,
        0
};

static PWMConfig pwm15_cfg = {
        100000,                                    /* 10kHz PWM clock frequency.   */
        1000,                                    /* Initial PWM period 1S.       */
        NULL,
        {
                {PWM_OUTPUT_ACTIVE_HIGH, NULL},
                {PWM_OUTPUT_ACTIVE_HIGH, NULL},
        },
        0,
        0,
        0
};


void led_string_init(void) {
    pwmStart(&PWMD1, &pwm1_cfg);
    pwmStart(&PWMD3, &pwm3_cfg);
    pwmStart(&PWMD15, &pwm15_cfg);
}

int led_string_setBrightness(uint8_t channel, float brightness) {
    if (brightness > 1.0f || brightness < 0.0f) {
        return -1;
    }
    uint16_t dutycycle = (uint16_t) (brightness * (float) UINT16_MAX);
    switch (channel) {
        case 1:
            pwmEnableChannel(&PWMD3, 0, PWM_PERCENTAGE_TO_WIDTH(&PWMD3, dutycycle));
            break;
        case 2:
            pwmEnableChannel(&PWMD3, 1, PWM_PERCENTAGE_TO_WIDTH(&PWMD3, dutycycle));
            break;
        case 3:
            pwmEnableChannel(&PWMD3, 2, PWM_PERCENTAGE_TO_WIDTH(&PWMD3, dutycycle));
            break;
        case 4:
            pwmEnableChannel(&PWMD3, 3, PWM_PERCENTAGE_TO_WIDTH(&PWMD3, dutycycle));
            break;
        case 5:
            pwmEnableChannel(&PWMD15, 0, PWM_PERCENTAGE_TO_WIDTH(&PWMD15, dutycycle));
            break;
        case 6:
            pwmEnableChannel(&PWMD15, 1, PWM_PERCENTAGE_TO_WIDTH(&PWMD15, dutycycle));
            break;

        default:
            return -1;  // invalid channel
    }
    return 0;
}
