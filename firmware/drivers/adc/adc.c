#include "adc.h"
#include "hal.h"

#define ADC_GRP1_NUM_CHANNELS   4
#define ADC_GRP1_BUF_DEPTH      8
#define ADC_BUFFER_SIZE         (ADC_GRP1_BUF_DEPTH * ADC_GRP1_NUM_CHANNELS)
#define ADC_FULLSCALE            4095

static adcsample_t adc_sample_buffer[ADC_BUFFER_SIZE];


/*
 * ADC conversion group.
 * Mode:        Linear buffer, 8 samples of 1 channel, SW triggered.
 * Channels:    IN10.
 */
static const ADCConversionGroup adcgrpcfg1 = {
        TRUE,
        ADC_GRP1_NUM_CHANNELS,
        NULL,
        NULL,
        ADC_CFGR1_CONT | ADC_CFGR1_RES_12BIT,             /* CFGR1 */
        ADC_TR(0, 0),                                     /* TR */
        ADC_SMPR_SMP_1P5,                                 /* SMPR */
        ADC_CHSELR_CHSEL0 | ADC_CHSELR_CHSEL1 | ADC_CHSELR_CHSEL12 | ADC_CHSELR_CHSEL13 /* CHSELR */
};

int adc_init(void) {
    adcStart(&ADCD1, NULL);
    adcStartConversion(&ADCD1, &adcgrpcfg1, adc_sample_buffer, ADC_GRP1_BUF_DEPTH);
    return 0;
}

/**
 * @param channel
 * @return between 0 .. 1
 */
int adc_readPoti(adc_readings_t *readings) {
    uint16_t brightness = 0;
    uint16_t frequency = 0;
    uint16_t depth = 0;
    uint16_t vbat = 0;
    for (uint8_t c = 0; c < ADC_GRP1_BUF_DEPTH; c++) {
        /* reversing direction */
        brightness += ADC_FULLSCALE - adc_sample_buffer[c * ADC_GRP1_NUM_CHANNELS + ADC_CHANNEL_BRIGHTNESS];
    }
    for (uint8_t c = 0; c < ADC_GRP1_BUF_DEPTH; c++) {
        frequency += adc_sample_buffer[c * ADC_GRP1_NUM_CHANNELS + ADC_CHANNEL_FREQUENCY];
    }
    for (uint8_t c = 0; c < ADC_GRP1_BUF_DEPTH; c++) {
        depth += ADC_FULLSCALE -  adc_sample_buffer[c * ADC_GRP1_NUM_CHANNELS + ADC_CHANNEL_DEPTH];
    }
    for (uint8_t c = 0; c < ADC_GRP1_BUF_DEPTH; c++) {
        vbat += adc_sample_buffer[c * ADC_GRP1_NUM_CHANNELS + ADC_CHANNEL_BATTERY];
    }
    readings->brightness = ((float) brightness) / ((float) (ADC_FULLSCALE*ADC_GRP1_BUF_DEPTH));
    readings->frequency = ((float) frequency) / ((float) (ADC_FULLSCALE*ADC_GRP1_BUF_DEPTH));
    readings->depth = ((float) depth) / ((float) (ADC_FULLSCALE*ADC_GRP1_BUF_DEPTH));
    readings->vbat = ((float) vbat) / ((float) (ADC_FULLSCALE*ADC_GRP1_BUF_DEPTH));
    return 0;
}

/**
 * @return between 0 .. 1
 */
float adc_readBattery(void) {
    return 0.5f;
}
