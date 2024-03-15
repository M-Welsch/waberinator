#ifndef FIRMWARE_WABERING_H
#define FIRMWARE_WABERING_H

#include "stdint.h"

#define WABER_TICK_MS 20
#define WABER_TICKS_PER_S (1000/WABER_TICK_MS)

typedef struct {
    float phase;
    float depth;
    float frequency;
    float brightness;
    float smoothness;
} wabercfg_t;

#ifdef TEST
float _compressor(float input, float smoothness);
float _sine(float tick, float frequency, float phase);
float _compressed_sine(float tick_f, float frequency, float phase, float smoothness);
float _waber(float tick_f, wabercfg_t* cfg);
#endif

float waber(uint32_t tick, wabercfg_t* cfg);

#endif //FIRMWARE_WABERING_H
