#include "wabering.h"
#include "math.h"

float _compressor(float input, float smoothness) {
    float numerator = exp(input * smoothness) - 1;
    float denominator = exp(smoothness) - 1;
    return numerator / denominator;
}

float _sine(float tick, float frequency, float phase) {
    float in_sine = phase + 2 * M_PI * frequency * tick / 60;
    return 0.5 * sinf(in_sine) + 0.5;
}

float _compressed_sine(float tick_f, float frequency, float phase, float smoothness) {
    float sine = _sine(tick_f, frequency, phase);
    return _compressor(sine, smoothness);
}

float _waber(float tick_f, wabercfg_t* cfg) {
    float phase = cfg->phase;
    float depth = cfg->depth;
    float frequency = cfg->frequency;
    float brightness = cfg->brightness;
    float smoothness = cfg->smoothness;


    float compressed_sine = _compressed_sine(tick_f, frequency, phase, smoothness);
    float waber = brightness * (1 + depth * (compressed_sine - 1));
    return waber;
}

uint16_t waber(uint32_t tick, wabercfg_t* cfg) {
    float tick_f = (float) tick;
    float waber = _waber(tick_f, cfg);

    return (uint16_t) (waber * INT16_MAX);
}