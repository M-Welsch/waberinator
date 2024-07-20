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
#endif

#define ABSOLUTE_MINIMUM_FREQUENCY 0.5f
#define THRESHOLD_FREQUENCY_CHANGE 0.05f

/** defines the parameters for a single LED string */
typedef struct {
    float phase;                  /**< phase in rad (where 2*pi is a full period) */
    float depth;                  /**< modulation depth of the wabering. 0-1, where 0 is no modulation and 1 is modulation over the complete brightness*/
    float frequency;              /**< frequency in Hz */
    float max_brightness;         /**< maximum brightness from 0..1 */
    float momentary_brightness;   /**< brightness if manual mode is set */
    float smoothness;             /**< boah ... hard to explain. Look at the geogebra file */
    bool active;                  /**< true if the LED does things, otherwise false */
} waber_led_cfg_t;

typedef struct {
    float global_min_brightness;
    float global_max_brightness;
    float global_min_frequency;
    float global_max_frequency;
    float global_min_depth;
    float global_max_depth;
    bool synchronous;               /**< all LEDs waber exactly the same (no phase delay) */
    bool manual_mode;
    waber_led_cfg_t led_cfg[6];
} waberinator_config_t;

float waber(uint32_t tick, waber_led_cfg_t *cfg, float frequency_factor, float depth_factor);

#endif //FIRMWARE_WABERING_H
