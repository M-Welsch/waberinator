#include "waberinator_config.h"

waber_led_cfg_t waber_led_cfg[6];

waberinator_config_t waberinator_config;

int _default_config(void) {
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

    waberinator_config.led1_cfg = waber_led_cfg[0];
    waberinator_config.led2_cfg = waber_led_cfg[1];
    waberinator_config.led3_cfg = waber_led_cfg[2];
    waberinator_config.led4_cfg = waber_led_cfg[3];
    waberinator_config.led5_cfg = waber_led_cfg[4];
    waberinator_config.led6_cfg = waber_led_cfg[5];

    waberinator_config.global_min_brightness = 0.0f;
    waberinator_config.global_max_brightness = 1.0f;
    waberinator_config.global_min_frequency = 0.0f;
    waberinator_config.global_max_frequency = 1.0f;
    waberinator_config.global_min_depth = 0.0f;
    waberinator_config.global_max_depth = 1.0f;
    waberinator_config.manual_mode = false;

    return 0;
}

int waberinator_config_load_from_flash(waberinator_config_t *cfg) {
    _default_config();
    cfg->global_min_brightness = waberinator_config.global_min_brightness;
    cfg->global_max_brightness = waberinator_config.global_max_brightness;
    cfg->global_min_frequency = waberinator_config.global_min_frequency;
    cfg->global_max_frequency = waberinator_config.global_max_frequency;
    cfg->global_min_depth = waberinator_config.global_min_depth;
    cfg->global_max_depth = waberinator_config.global_max_depth;
    cfg->manual_mode = waberinator_config.manual_mode;
    cfg->led1_cfg = waberinator_config.led1_cfg;
    cfg->led2_cfg = waberinator_config.led2_cfg;
    cfg->led3_cfg = waberinator_config.led3_cfg;
    cfg->led4_cfg = waberinator_config.led4_cfg;
    cfg->led5_cfg = waberinator_config.led5_cfg;
    cfg->led6_cfg = waberinator_config.led6_cfg;
    cfg = &waberinator_config;
    return 0;
}

int waberinator_config_get_led()