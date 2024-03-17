#include "smps.h"

int smps_setOn(void) {
    palSetLine(LINE_LM73606_EN);
    return -1;
}

int smps_setOff(void) {
    palClearLine(LINE_LM73606_EN);
    return -1;
}

bool smps_getPwrGood(void) {
    return palReadLine(LINE_LM73606_PG);
}
