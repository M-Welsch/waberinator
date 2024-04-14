#ifndef FIRMWARE_WABERINATOR_CONFIG_H
#define FIRMWARE_WABERINATOR_CONFIG_H

#include "stdbool.h"

typedef struct {
    float phase;
    float depth;
    float frequency;
    float max_brightness;
    float momentary_brightness;
    float smoothness;
    bool active;
} waber_led_cfg_t;

typedef struct {
    float global_min_brightness;
    float global_max_brightness;
    float global_min_frequency;
    float global_max_frequency;
    float global_min_depth;
    float global_max_depth;
    waber_led_cfg_t led1_cfg;
    waber_led_cfg_t led2_cfg;
    waber_led_cfg_t led3_cfg;
    waber_led_cfg_t led4_cfg;
    waber_led_cfg_t led5_cfg;
    waber_led_cfg_t led6_cfg;
} waberinator_config_t;

int waberinator_config_store_to_flash(const waberinator_config_t *cfg);
int waberinator_config_load_from_flash(waberinator_config_t *cfg);

#endif //FIRMWARE_WABERINATOR_CONFIG_H
