#ifndef FIRMWARE_WABERING_H
#define FIRMWARE_WABERING_H

#include "stdint.h"
#include "stdbool.h"

#define WABER_TICK_MS 20
#define WABER_TICKS_PER_S (1000/WABER_TICK_MS)

#ifdef TEST
float _compressor(float input, float smoothness);
float _sine(float tick, float frequency, float phase);
float _compressed_sine(float tick_f, float frequency, float phase, float smoothness);
float _waber(float tick_f, wabercfg_t* cfg);
#endif

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
    bool manual_mode;
    waber_led_cfg_t led_cfg[6];
} waberinator_config_t;

float waber(uint32_t tick, waber_led_cfg_t* cfg);

#endif //FIRMWARE_WABERING_H
