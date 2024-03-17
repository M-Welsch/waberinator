#include "ch.h"
#include "hal.h"
#include "chprintf.h"
#include "led_string.h"
#include "waber_thread.h"
#include "wab_mutex.h"

waber_led_cfg_t waber_led_cfg[6];
static bool manual_mode = false;

void led_setBrightness(uint16_t dutycycle) {
    chprintf((BaseSequentialStream*) &SD2, "Waber: %ld\n\r", dutycycle);
}

static THD_WORKING_AREA(waberThread, 1024);
static THD_FUNCTION(waberThread1, arg) {
    (void)arg;
    chRegSetThreadName("waberthread1");
    systime_t time = chVTGetSystemTimeX();
    float brightness[6] = {0};
    uint32_t tick = 0;
    waber_led_cfg[0].phase = 0;
    waber_led_cfg[0].depth = 1;
    waber_led_cfg[0].frequency = 1;
    waber_led_cfg[0].max_brightness = 1;
    waber_led_cfg[0].momentary_brightness = 0.5f;
    waber_led_cfg[0].smoothness = 4;

    waber_led_cfg[1].phase = 0;
    waber_led_cfg[1].depth = 1;
    waber_led_cfg[1].frequency = 0.2f;
    waber_led_cfg[1].max_brightness = 1;
    waber_led_cfg[1].momentary_brightness = 0.6f;
    waber_led_cfg[1].smoothness = 2;

    waber_led_cfg[2].phase = 2;
    waber_led_cfg[2].depth = 1;
    waber_led_cfg[2].frequency = 0.2f;
    waber_led_cfg[2].max_brightness = 1;
    waber_led_cfg[2].momentary_brightness = 0.7f;
    waber_led_cfg[2].smoothness = 2;

    waber_led_cfg[3].phase = 0;
    waber_led_cfg[3].depth = 0.1f;
    waber_led_cfg[3].frequency = 0.2f;
    waber_led_cfg[3].max_brightness = 1;
    waber_led_cfg[3].momentary_brightness = 0.8f;
    waber_led_cfg[3].smoothness = 2;

    waber_led_cfg[4].phase = 0;
    waber_led_cfg[4].depth = 1;
    waber_led_cfg[4].frequency = 1;
    waber_led_cfg[4].max_brightness = 1;
    waber_led_cfg[4].momentary_brightness = 0.9f;
    waber_led_cfg[4].smoothness = 2;

    waber_led_cfg[5].phase = 0;
    waber_led_cfg[5].depth = 1;
    waber_led_cfg[5].frequency = 0.5f;
    waber_led_cfg[5].max_brightness = 0.5f;
    waber_led_cfg[5].momentary_brightness = 1;
    waber_led_cfg[5].smoothness = 2;

    systime_t time_start = 0;
    systime_t time_needed = 0;
    systime_t time_available = TIME_MS2I(WABER_TICK_MS);
    systime_t time_max = 0;
    float brightness_max[6] = {0};  // just to use the dc
    bool read_manual_mode = false;

    while (true) {
        chMtxLock(&manual_mode_cfg);
        read_manual_mode = manual_mode;
        chMtxUnlock(&manual_mode_cfg);
        if (!read_manual_mode) {
            chMtxLock(&led_cfg);
            led_string_setBrightness(1, brightness[0]);
            led_string_setBrightness(2, brightness[1]);
            led_string_setBrightness(3, brightness[2]);
            led_string_setBrightness(4, brightness[3]);
            led_string_setBrightness(5, brightness[4]);
            led_string_setBrightness(6, brightness[5]);
            chMtxUnlock(&led_cfg);

            time_start = chVTGetSystemTimeX();
            time += TIME_MS2I(WABER_TICK_MS);
            chMtxLock(&led_cfg);
            brightness[0] = waber(tick, &waber_led_cfg[0]);
            brightness[1] = waber(tick, &waber_led_cfg[1]);
            brightness[2] = waber(tick, &waber_led_cfg[2]);
            brightness[3] = waber(tick, &waber_led_cfg[3]);
            brightness[4] = waber(tick, &waber_led_cfg[4]);
            brightness[5] = waber(tick, &waber_led_cfg[5]);
            chMtxUnlock(&led_cfg);
            tick++;
            time_needed = chVTGetSystemTimeX() - time_start;
            if (time_needed > time_max) {
                time_max = time_needed;
            }
            for (uint8_t c = 0; c < 6; c++) {
                if (brightness[c] > brightness_max[c]) {
                    brightness_max[c] = brightness[c];
                }
            }
            if (tick % 50 == 0) {
                //chprintf((BaseSequentialStream*) &SD2, "Maximum Time needed: %d of %d: [%f, %f, %f, %f, %f, %f]\n\r", time_max, time_available, brightness[0], brightness[1], brightness[2], brightness[3], brightness[4], brightness[5]);
            }
            chThdSleepUntil(time);
        }
        else {
            // manual mode
            chMtxLock(&led_cfg);
            led_string_setBrightness(1, waber_led_cfg[0].momentary_brightness);
            led_string_setBrightness(2, waber_led_cfg[1].momentary_brightness);
            led_string_setBrightness(3, waber_led_cfg[2].momentary_brightness);
            led_string_setBrightness(4, waber_led_cfg[3].momentary_brightness);
            led_string_setBrightness(5, waber_led_cfg[4].momentary_brightness);
            led_string_setBrightness(6, waber_led_cfg[5].momentary_brightness);
            chMtxUnlock(&led_cfg);
            chThdSleepMilliseconds(100);
        }
    }
}

void waberthread_init(void) {
    chThdCreateStatic(waberThread, sizeof(waberThread), HIGHPRIO, waberThread1, NULL);
}

int waberthread_set_manual_mode(const bool set_manual_mode) {
    chMtxLock(&manual_mode_cfg);
    manual_mode = set_manual_mode;
    chMtxUnlock(&manual_mode_cfg);
    return 0;
}

int waberthread_set_cfg(uint8_t led_channel, wabercfg_parameter_e parameter, float value) {
    chMtxLock(&led_cfg);
    switch (parameter) {
        case WABER_CFG_PHASE:
            waber_led_cfg[led_channel].phase = value;
            break;
        case WABER_CFG_DEPTH:
            if ((value > 1.0f) || (value < 0.0f)) {
                return -1;
            }
            waber_led_cfg[led_channel].depth = value;
            break;
        case WABER_CFG_FREQUENCY:
            waber_led_cfg[led_channel].frequency = value;
            break;
        case WABER_CFG_MAX_BRIGHTNESS:
            if ((value > 1.0f) || (value < 0.0f)) {
                return -1;
            }
            waber_led_cfg[led_channel].max_brightness = value;
            break;
        case WABER_CFG_MOMENTARY_BRIGHTNESS:
            if ((value > 1.0f) || (value < 0.0f)) {
                return -1;
            }
            waber_led_cfg[led_channel].momentary_brightness = value;
            break;
        case WABER_CFG_SMOOTHNESS:
            waber_led_cfg[led_channel].smoothness = value;
            break;
        default:
            return -1;
    }
    chMtxUnlock(&led_cfg);
    return 0;
}

int waberthread_get_cfg(uint8_t led_channel, wabercfg_parameter_e parameter, float *value) {
    if (value == NULL) {
        return -1;
    }
    chMtxLock(&led_cfg);
    switch (parameter) {
        case WABER_CFG_PHASE:
            *value = waber_led_cfg[led_channel].phase;
            break;
        case WABER_CFG_DEPTH:
            *value = waber_led_cfg[led_channel].depth;
            break;
        case WABER_CFG_FREQUENCY:
            *value = waber_led_cfg[led_channel].frequency;
            break;
        case WABER_CFG_MAX_BRIGHTNESS:
            *value = waber_led_cfg[led_channel].max_brightness;
            break;
        case WABER_CFG_SMOOTHNESS:
            *value = waber_led_cfg[led_channel].smoothness;
            break;
        default:
            return -1;
    }
    chMtxUnlock(&led_cfg);
    return 0;
}

int waberthread_get_complete_cfg(uint8_t led_channel, waber_led_cfg_t *cfg) {
    chMtxLock(&led_cfg);
    cfg->phase = waber_led_cfg[led_channel].phase;
    cfg->depth = waber_led_cfg[led_channel].depth;
    cfg->frequency = waber_led_cfg[led_channel].frequency;
    cfg->max_brightness = waber_led_cfg[led_channel].max_brightness;
    cfg->smoothness = waber_led_cfg[led_channel].smoothness;
    chMtxUnlock(&led_cfg);
    return 0;
}
