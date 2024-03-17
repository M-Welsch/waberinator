#include "stdint.h"
#include <string.h>

#include "common.h"

#include "chprintf.h"

int customAtoI(const char *str, int *result) {
    long longValue = 0;

    while (*str) {
        if (*str < '0' || *str > '9') {
            // Non-digit character found
            return -1;
        }

        longValue = longValue * 10 + (*str - '0');

        // Check for overflow
        if (longValue > UINT16_MAX || longValue < 0) {
            // Overflow occurred
            return -1;
        }

        str++;
    }

    *result = (int) longValue;
    return 0;
}

/**
 * @note source: https://www.techieclues.com/blogs/converting-string-to-float-in-c
 * @param str
 * @return
 */
float customAtoF(const char *str) {
    float result = 0.0;
    float decimalFactor = 0.1;
    int sign = 1;
    int i = 0;

    if (str[i] == '-') {
        sign = -1;
        i++;
    }

    while (str[i] != '\0') {
        if (str[i] == '.') {
            i++;
            while (str[i] != '\0') {
                result += (str[i] - '0') * decimalFactor;
                decimalFactor *= 0.1;
                i++;
            }
        } else {
            result = result * 10 + (str[i] - '0');
            i++;
        }
    }

    return sign * result;
}

bool isEqual(const char *buffer, const char *string) {
    return strcmp((char *) buffer, string) == 0;
}

void argument_missing(BaseSequentialStream *chp) {
    chprintf(chp, "Error: argument missing\n");
}