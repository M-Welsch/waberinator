#define TEST 1

#include "wabering.h"
#include <stdio.h>

int main(void) {
    wabercfg_t cfg;
    cfg.phase = 0;
    cfg.depth = 0.5;
    cfg.frequency = 2;
    cfg.brightness = 1;
    cfg.smoothness = 2;

    printf("Testing Compressorfunc:\n");
    for (uint32_t c = 0; c < 100; c++) {
        float inp = (float) c / 100;
        printf("%f, %f\n", inp, _compressor(inp, cfg.smoothness));
    }

    printf("Testing Sinefunc:\n");
    for (uint32_t c = 0; c < 100; c++) {
        printf("%ld, %f\n", c, _sine(c, cfg.frequency, cfg.phase));
    }

    printf("Testing Compressed Sine:\n");
    for (uint32_t c = 0; c < 100; c++) {
        float inp = (float) c / 100;
        printf("%ld, %f\n", c, _compressed_sine(c, cfg.frequency, cfg.phase, cfg.smoothness));
    }

    printf("Testing Waberfunc Float:\n");
    for (uint32_t c = 0; c < 100; c++) {
        float tick_f = (float) c;
        printf("%ld, %f\n", c, _waber(tick_f, &cfg));
    }

    printf("Testing Waberfunc Int:\n");
    for (uint32_t c = 0; c < 100; c++) {
        float tick_f = (float) c;
        printf("%ld, %d\n", c, waber(tick_f, &cfg));
    }
}






