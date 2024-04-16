#ifndef FIRMWARE_ADC_H
#define FIRMWARE_ADC_H

#include "stdint.h"

#define ADC_CHANNEL_BRIGHTNESS  0
#define ADC_CHANNEL_FREQUENCY   3
#define ADC_CHANNEL_DEPTH       1
#define ADC_CHANNEL_BATTERY     2

typedef struct {
    float brightness;
    float frequency;
    float depth;
    float vbat;
} adc_readings_t;

int adc_init(void);
int adc_readPoti(adc_readings_t* readings);
float adc_readBattery(void);

#endif //FIRMWARE_ADC_H
