#ifndef FIRMWARE_ADC_H
#define FIRMWARE_ADC_H

#include "stdint.h"

uint16_t adc_readPoti(uint8_t channel);
uint16_t adc_readBattery(void);

#endif //FIRMWARE_ADC_H
