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
    float tick_f = (float) tick;
    float current_frequency = cfg->frequency*frequency_factor;
    static float last_frequency = 0.01f;
    static float phi_adjustment = 0.0f;
    if (fabsf(last_frequency - current_frequency) > THRESHOLD_FREQUENCY_CHANGE) {
        phi_adjustment = 2 * M_PI * tick_f/WABER_TICKS_PER_S * (last_frequency - current_frequency);
        if (phi_adjustment > 2 * M_PI) {
            phi_adjustment -= 2 * M_PI;
        }
    }
    last_frequency = current_frequency;
    float phase = cfg->phase + phi_adjustment;
    float depth = cfg->depth * depth_factor;
    float brightness = cfg->max_brightness;
    float smoothness = cfg->smoothness;

    float compressed_sine = _compressed_sine(tick_f, current_frequency, phase, smoothness);
    float waber = brightness * (1 + depth * (compressed_sine - 1));
    return waber;
}