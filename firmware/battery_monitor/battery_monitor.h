//
// Created by max on 08.07.24.
//

#ifndef FIRMWARE_BATTERY_MONITOR_H
#define FIRMWARE_BATTERY_MONITOR_H

#define BATT_EMPTY_VOLTAGE 10.0f
#define BATT_FULL_VOLTAGE 13.8f

float digits2vbat(float adc_reading);
void battery_monitor_init(void);

#endif //FIRMWARE_BATTERY_MONITOR_H
