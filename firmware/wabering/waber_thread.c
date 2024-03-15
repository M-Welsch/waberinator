#include "ch.h"
#include "wabering.h"
#include "hal.h"
#include "chprintf.h"
#include "led_string.h"

void led_setBrightness(uint16_t dutycycle) {
    chprintf((BaseSequentialStream*) &SD2, "Waber: %ld\n\r", dutycycle);
}

static THD_WORKING_AREA(waberThread, 1024);
static THD_FUNCTION(waberThread1, arg) {
    (void)arg;
    chRegSetThreadName("waberthread1");
    systime_t time = chVTGetSystemTimeX();
    float brightness[6] = {0};
    uint32_t tick = 0;
    wabercfg_t cfg[6];
    cfg[0].phase = 0;
    cfg[0].depth = 1;
    cfg[0].frequency = 1;
    cfg[0].brightness = 1;
    cfg[0].smoothness = 4;

    cfg[1].phase = 0;
    cfg[1].depth = 1;
    cfg[1].frequency = 0.2;
    cfg[1].brightness = 1;
    cfg[1].smoothness = 2;

    cfg[2].phase = 2;
    cfg[2].depth = 1;
    cfg[2].frequency = 0.2;
    cfg[2].brightness = 1;
    cfg[2].smoothness = 2;

    cfg[3].phase = 0;
    cfg[3].depth = 0.1;
    cfg[3].frequency = 0.2;
    cfg[3].brightness = 1;
    cfg[3].smoothness = 2;

    cfg[4].phase = 0;
    cfg[4].depth = 1;
    cfg[4].frequency = 1;
    cfg[4].brightness = 1;
    cfg[4].smoothness = 2;

    cfg[5].phase = 0;
    cfg[5].depth = 1;
    cfg[5].frequency = 0.5;
    cfg[5].brightness = 0.5;
    cfg[5].smoothness = 2;

    systime_t time_start = 0;
    systime_t time_needed = 0;
    systime_t time_available = TIME_MS2I(WABER_TICK_MS);
    systime_t time_max = 0;
    float brightness_max[6] = {0};  // just to use the dc
    while (true) {
        led_string_setBrightness(1, brightness[0]);
        led_string_setBrightness(2, brightness[1]);
        led_string_setBrightness(3, brightness[2]);
        led_string_setBrightness(4, brightness[3]);
        time_start = chVTGetSystemTimeX();
        time += TIME_MS2I(WABER_TICK_MS);
        //led_setBrightness(brightness);
        brightness[0] = waber(tick, &cfg[0]);
        brightness[1] = waber(tick, &cfg[1]);
        brightness[2] = waber(tick, &cfg[2]);
        brightness[3] = waber(tick, &cfg[3]);
        brightness[4] = waber(tick, &cfg[4]);
        brightness[5] = waber(tick, &cfg[5]);
        tick++;
        time_needed = chVTGetSystemTimeX() - time_start;
        if (time_needed > time_max) {
            time_max = time_needed;
        }
        for (uint8_t c = 0; c < 6; c++) {
            if (brightness[c] > brightness_max[c]) {
                brightness_max[c] = brightness[c];
            }
        }
        if (tick % 50 == 0) {
            chprintf((BaseSequentialStream*) &SD2, "Maximum Time needed: %d of %d: [%f, %f, %f, %f, %f, %f]\n\r", time_max, time_available, brightness[0], brightness[1], brightness[2], brightness[3], brightness[4], brightness[5]);
        }
        chThdSleepUntil(time);
    }
}

void waberthread_init(void) {
    chThdCreateStatic(waberThread, sizeof(waberThread), HIGHPRIO, waberThread1, NULL);
}
