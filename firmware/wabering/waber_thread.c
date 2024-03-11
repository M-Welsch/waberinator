#include "ch.h"
#include "wabering.h"
#include "hal.h"
#include "chprintf.h"

void led_setBrightness(uint16_t dutycycle) {
    chprintf((BaseSequentialStream*) &SD2, "Waber: %ld\n\r", dutycycle);
}

static THD_WORKING_AREA(waberThread, 1024);
static THD_FUNCTION(waberThread1, arg) {
    (void)arg;
    chRegSetThreadName("waberthread1");
    systime_t time = chVTGetSystemTimeX();
    uint16_t duty_cycle = 0;
    uint32_t tick = 0;
    wabercfg_t cfg;
    cfg.phase = 0;
    cfg.depth = 1;
    cfg.frequency = 0.2;
    cfg.brightness = 1;
    cfg.smoothness = 2;

    while (true) {
        time += TIME_MS2I(100); //WABER_TICK_MS);
        led_setBrightness(duty_cycle);
        duty_cycle = waber(tick, &cfg);
        tick++;
        chThdSleepUntil(time);
    }
}

void waberthread_init(void) {
    chThdCreateStatic(waberThread, sizeof(waberThread), NORMALPRIO, waberThread1, NULL);
}
