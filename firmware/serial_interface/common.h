#ifndef FIRMWARE_COMMON_H
#define FIRMWARE_COMMON_H

#include "stdbool.h"
#include "hal.h"
#include "shell.h"


int customAtoI(const char *str, int *result);
float customAtoF(const char *str);

bool isEqual(const char *buffer, const char *string);
void argument_missing(BaseSequentialStream *chp);

#endif //FIRMWARE_COMMON_H
