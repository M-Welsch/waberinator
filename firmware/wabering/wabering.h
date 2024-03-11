#ifndef FIRMWARE_WABERING_H
#define FIRMWARE_WABERING_H

#include "stdint.h"

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

uint16_t waber(uint32_t tick, wabercfg_t* cfg);

#endif //FIRMWARE_WABERING_H
