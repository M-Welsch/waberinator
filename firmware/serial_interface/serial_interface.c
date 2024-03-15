#include "ch.h"
#include "hal.h"

#include "shell.h"
#include <string.h>

#include "chprintf.h"

#include "serial_interface.h"
#include "waber_thread.h"
#include "core_defines.h"

uint8_t customAtoI(const char *str, int *result) {
    long longValue = 0;

    while (*str) {
        if (*str < '0' || *str > '9') {
            // Non-digit character found
            return 0;
        }

        longValue = longValue * 10 + (*str - '0');

        // Check for overflow
        if (longValue > UINT16_MAX || longValue < 0) {
            // Overflow occurred
            return 0;
        }

        str++;
    }

    *result = (int) longValue;
    return 1;
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

static inline bool isEqual(const char *buffer, const char *string) {
    return strcmp((char *) buffer, string) == 0;
}

static void _argument_missing(BaseSequentialStream *chp) {
    chprintf(chp, "Error: argument missing\n");
}

void _probe(BaseSequentialStream *chp, int argc, char *argv[]) {
    UNUSED_PARAM(chp);
    UNUSED_PARAM(argc);
    UNUSED_PARAM(argv);
    chprintf(chp, "Echo\n");
}

void _set(BaseSequentialStream *chp, int argc, char *argv[]) {
    if (argc < 3) {
        _argument_missing(chp);
        return;
    }
    char *which_led = argv[0];
    char *which_parameter_to_set = argv[1];
    char *value = argv[2];

    wabercfg_parameter_e parameter;
    if (isEqual(which_parameter_to_set, "phase")) {
        parameter = WABER_CFG_PHASE;
    }
    else if (isEqual(which_parameter_to_set, "depth")) {
        parameter = WABER_CFG_DEPTH;
    }
    else if (isEqual(which_parameter_to_set, "frequency")) {
        parameter = WABER_CFG_FREQUENCY;
    }
    else if (isEqual(which_parameter_to_set, "brightness")) {
        parameter = WABER_CFG_BRIGHTNESS;
    }
    else if (isEqual(which_parameter_to_set, "smoothness")) {
        parameter = WABER_CFG_SMOOTHNESS;
    }
    else {
        chprintf(chp, "no such parameter as %s\n\r", which_parameter_to_set);
        return;
    }

    int led_to_set;
    customAtoI(which_led, &led_to_set);
    if ((led_to_set < 0) || (led_to_set > 6)) {
        chprintf(chp, "invalid led: %d\n\r", led_to_set);
        return;
    }

    float value_decoded = customAtoF(value);
    waberthread_set_cfg((uint8_t) led_to_set-1, parameter, value_decoded);
}

static const ShellCommand commands[] = {
        {"probe", _probe},
        {"set", _set},
        {NULL, NULL}
};

static ShellConfig shell_cfg1 = {
        (BaseSequentialStream *)&SD2,
        commands
};

#define SHELL_WA_SIZE   THD_WORKING_AREA_SIZE(1024)
static void _communicationInputMainloop(void) {
    thread_t *shelltp = chThdCreateFromHeap(NULL, SHELL_WA_SIZE, "shell", NORMALPRIO+1, shellThread, (void *)&shell_cfg1);
    chThdWait(shelltp);
}

static THD_WORKING_AREA(communicationInputThread, 128);
static THD_FUNCTION(communicationInput, arg) {
    UNUSED_PARAM(arg);
    chRegSetThreadName("Serial Communication Input Thread");
    while (true) {
        _communicationInputMainloop();
    }
}

void communicationThreads_init(void) {
    shellInit();
    sdStart(&SD2, NULL);

    thread_t *shelltp = chThdCreateFromHeap(NULL, SHELL_WA_SIZE, "shell", NORMALPRIO + 1, shellThread, (void *)&shell_cfg1);
    //chThdWait(shelltp);               /* Waiting termination.             */

    //_initializeMailbox();
    //chThdCreateStatic(communicationOutputThread, sizeof(communicationOutputThread), NORMALPRIO, communicationOutput, NULL);
    //chThdCreateStatic(communicationInputThread, sizeof(communicationInputThread), NORMALPRIO + 1, communicationInput, NULL);
}