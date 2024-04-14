#ifndef FIRMWARE_WABERING_H
#define FIRMWARE_WABERING_H

#include "stdint.h"
#include "stdbool.h"
#include "waberinator_config.h"

#define WABER_TICK_MS 20
#define WABER_TICKS_PER_S (1000/WABER_TICK_MS)

#ifdef TEST
float _compressor(float input, float smoothness);
float _sine(float tick, float frequency, float phase);
float _compressed_sine(float tick_f, float frequency, float phase, float smoothness);
float _waber(float tick_f, wabercfg_t* cfg);
#endif

float waber(uint32_t tick, waber_led_cfg_t* cfg);

#endif //FIRMWARE_WABERING_H
