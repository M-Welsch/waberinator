#include "led_string.h"
#include "hal.h"


static PWMConfig pwm3_cfg = {
        24000000,                                    /* 10kHz PWM clock frequency.   */
        65535,                                    /* Initial PWM period 1S.       */
        NULL,
        {
                {PWM_OUTPUT_ACTIVE_HIGH, NULL},
                {PWM_OUTPUT_ACTIVE_LOW, NULL},
                {PWM_OUTPUT_ACTIVE_HIGH, NULL},
                {PWM_OUTPUT_ACTIVE_LOW, NULL}
        },
        0,
        0,
        0
};

static PWMConfig pwm15_cfg = {
        24000000,                                    /* 10kHz PWM clock frequency.   */
        65535,                                    /* Initial PWM period 1S.       */
        NULL,
        {
                {PWM_OUTPUT_ACTIVE_HIGH, NULL},
                {PWM_OUTPUT_ACTIVE_LOW, NULL},
        },
        0,
        0,
        0
};


void led_string_init(void) {
    pwmStart(&PWMD3, &pwm3_cfg);
    pwmStart(&PWMD15, &pwm15_cfg);
}

int led_string_setBrightness(uint8_t channel, float brightness) {
    if (brightness > 1.0f || brightness < 0.0f) {
        return -1;
    }
    uint16_t dutycycle = (uint16_t) (brightness * (float) 10000U);
    switch (channel) {
        case 1:
            pwmEnableChannel(&PWMD3, 0, PWM_PERCENTAGE_TO_WIDTH(&PWMD3, dutycycle));
            break;
        case 2:
            pwmEnableChannel(&PWMD3, 1, PWM_PERCENTAGE_TO_WIDTH(&PWMD3, 10000U-dutycycle));
            break;
        case 3:
            pwmEnableChannel(&PWMD3, 2, PWM_PERCENTAGE_TO_WIDTH(&PWMD3, dutycycle));
            break;
        case 4:
            pwmEnableChannel(&PWMD3, 3, PWM_PERCENTAGE_TO_WIDTH(&PWMD3, 10000U-dutycycle));
            break;
        case 5:
            pwmEnableChannel(&PWMD15, 0, PWM_PERCENTAGE_TO_WIDTH(&PWMD15, dutycycle));
            break;
        case 6:
            pwmEnableChannel(&PWMD15, 1, PWM_PERCENTAGE_TO_WIDTH(&PWMD15, 10000U-dutycycle));
            break;

        default:
            return -1;  // invalid channel
    }
    return 0;
}

int led_string_on(uint8_t channel) {
    switch (channel) {
        case 1:
            palSetLine(LINE_LEDSTRING1_DRV_EN);
            break;
        case 2:
            palSetLine(LINE_LEDSTRING2_DRV_EN);
            break;
        case 3:
            palSetLine(LINE_LEDSTRING3_DRV_EN);
            break;
        case 4:
            palSetLine(LINE_LEDSTRING4_DRV_EN);
            break;
        case 5:
            palSetLine(LINE_LEDSTRING5_DRV_EN);
            break;
        case 6:
            palSetLine(LINE_LEDSTRING6_DRV_EN);
            break;
        default:
            return -1;
    }
    return 0;
}

int led_string_off(uint8_t channel) {
    switch (channel) {
        case 1:
            palClearLine(LINE_LEDSTRING1_DRV_EN);
            break;
        case 2:
            palClearLine(LINE_LEDSTRING2_DRV_EN);
            break;
        case 3:
            palClearLine(LINE_LEDSTRING3_DRV_EN);
            break;
        case 4:
            palClearLine(LINE_LEDSTRING4_DRV_EN);
            break;
        case 5:
            palClearLine(LINE_LEDSTRING5_DRV_EN);
            break;
        case 6:
            palClearLine(LINE_LEDSTRING6_DRV_EN);
            break;
        default:
            return -1;
    }
    return 0;
}