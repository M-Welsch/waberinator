#ifndef FIRMWARE_SMPS_H
#define FIRMWARE_SMPS_H

#include "stdbool.h"
#include "hal.h"

int smps_setOn(void);
int smps_setOff(void);

bool smps_getPwrGood(void);

#endif //FIRMWARE_SMPS_H
