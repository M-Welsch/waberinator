#include "ch.h"

#include "battery_monitor.h"
#include "adc.h"
#include "smps.h"

static THD_WORKING_AREA(waBatteryMonitorThread, 128);
static THD_FUNCTION(BatteryMonitorThread, arg) {
    (void)arg;
    chRegSetThreadName("battery_monitor");
    adc_readings_t adc_readings;
    uint8_t undervoltage_counter = 0;
    while (true) {
        adc_readPoti(&adc_readings);
        if (adc_readings.vbat < 0.64f) { // shuts off at around 11V
            undervoltage_counter++;
            if (undervoltage_counter == 5) {
                smps_setOff();
            }
        }
        else {
            undervoltage_counter = 0;
        }
        chThdSleepMilliseconds(100);
    }
}

void battery_monitor_init(void) {
    chThdCreateStatic(waBatteryMonitorThread, sizeof(waBatteryMonitorThread), NORMALPRIO, BatteryMonitorThread, NULL);
}
