#include "ch.h"

#include "battery_monitor.h"
#include "core_defines.h"
#include "adc.h"
#include "smps.h"
#include "led_status.h"
#include "button.h"
#include "wab_mutex.h"

#define DIGITS_TO_VBAT_M 17.494366022355468f
#define DIGITS_TO_VBAT_T -0.2808784254411832f

float digits2vbat(float adc_reading) {
    return DIGITS_TO_VBAT_M * adc_reading + DIGITS_TO_VBAT_T;
}

int flash_status_led_according_to_battery_voltage(float vbat) {
    if (vbat > BATT_FULL_VOLTAGE) {
        led_status_color(STATUS_LED_COLOR_GREEN, 10000);
    }
    else if (vbat < BATT_EMPTY_VOLTAGE) {
        led_status_color(STATUS_LED_COLOR_RED, 10000);
    }
    else {
        float soc = (vbat - BATT_EMPTY_VOLTAGE) / (BATT_FULL_VOLTAGE - BATT_EMPTY_VOLTAGE);
        uint16_t red = (uint16_t) (10000.0f * (1-soc));
        uint16_t green = (uint16_t) (10000.0f * soc);
        led_status_color_numeric(red, green, 0);
    }
    return 0;
}

int uvlo(float vbat) {
    static uint8_t undervoltage_counter = 0;
    if (vbat < 11.2) {
        undervoltage_counter++;
        if (undervoltage_counter == 5) {
            smps_setOff();
            while (true) {
                led_status_color(STATUS_LED_COLOR_RED, 500);
                chThdSleepMilliseconds(1000);
                led_status_color_numeric(0,0,0);
                chThdSleepMilliseconds(1000);
            }
        }
    }
    else {
        undervoltage_counter = 0;
    }
    return 0;
}

static THD_WORKING_AREA(waBatteryMonitorThread, 128);
static THD_FUNCTION(BatteryMonitorThread, arg) {
    (void)arg;
    chRegSetThreadName("battery_monitor");
    adc_readings_t adc_readings;
    while (true) {
        eventmask_t evt = chEvtWaitAllTimeout(ALL_EVENTS, TIME_MS2I(100));
        UNUSED_PARAM(evt);  // later ... maybe

        chMtxLock(&mtx_adc);
        adc_readPoti(&adc_readings);
        chMtxUnlock(&mtx_adc);
        float vbat = digits2vbat(adc_readings.vbat);
        uvlo(vbat);
        if (button_pressed()) {
            flash_status_led_according_to_battery_voltage(vbat);
        }
        else {
            led_status_color_numeric(0,0,0);
        }
    }
}

void battery_monitor_init(void) {
    chThdCreateStatic(waBatteryMonitorThread, sizeof(waBatteryMonitorThread), NORMALPRIO, BatteryMonitorThread, NULL);
}
