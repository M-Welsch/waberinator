#ifndef FIRMWARE_WABER_THREAD_H
#define FIRMWARE_WABER_THREAD_H

#include "wabering.h"

typedef enum {
    WABER_CFG_PHASE,
    WABER_CFG_DEPTH,
    WABER_CFG_FREQUENCY,
    WABER_CFG_MAX_BRIGHTNESS,
    WABER_CFG_MOMENTARY_BRIGHTNESS,
    WABER_CFG_SMOOTHNESS
} wabercfg_parameter_e;

void waberthread_init(void);

int waberthread_set_cfg(uint8_t led_channel, wabercfg_parameter_e parameter, float value);
int waberthread_set_manual_mode(const bool set_manual_mode);
int waberthread_get_cfg(uint8_t led_channel, wabercfg_parameter_e parameter, float *value);
int waberthread_get_complete_cfg(uint8_t led_channel, waber_led_cfg_t *cfg);

#endif //FIRMWARE_WABER_THREAD_H
