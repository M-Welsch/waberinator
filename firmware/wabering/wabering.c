#include "wabering.h"
#include "math.h"

float _compressor(float input, float smoothness) {
    float numerator = exp(input * smoothness) - 1;
    float denominator = exp(smoothness) - 1;
    return numerator / denominator;
}

float _sine(float tick, float frequency, float phase) {
    float in_sine = phase + 2.0f * M_PI * frequency * tick / WABER_TICKS_PER_S;
    return 0.5f * sinf(in_sine) + 0.5f;
}

float _compressed_sine(float tick_f, float frequency, float phase, float smoothness) {
    float sine = _sine(tick_f, frequency, phase);
    return _compressor(sine, smoothness);
}

float waber(uint32_t tick, waber_led_cfg_t *cfg, float frequency_factor, float depth_factor) {
    float phase = cfg->phase;
    float depth = cfg->depth * depth_factor;
    float frequency = cfg->frequency * frequency_factor;
    float brightness = cfg->max_brightness;
    float smoothness = cfg->smoothness;
    float tick_f = (float) tick;


    float compressed_sine = _compressed_sine(tick_f, frequency, phase, smoothness);
    float waber = brightness * (1 + depth * (compressed_sine - 1));
    return waber;
}