#include "ch.h"
#include "hal.h"

#include "shell.h"
#include <string.h>

#include "chprintf.h"

#include "serial_interface.h"
#include "waber_thread.h"
#include "core_defines.h"
#include "serial_interface/common.h"
#include "serial_interface_set.h"
#include "adc.h"
#include "wab_mutex.h"


void _probe(BaseSequentialStream *chp, int argc, char *argv[]) {
    UNUSED_PARAM(chp);
    UNUSED_PARAM(argc);
    UNUSED_PARAM(argv);
    chprintf(chp, "Echo\n");
}

void get(BaseSequentialStream *chp, int argc, char *argv[]) {
    if (argc < 1) {
        argument_missing(chp);
        return;
    }
    int retval = 0;
    const char *what_to_get = argv[0];
    if (isEqual(what_to_get, "adc")) {
        adc_readings_t readings;
        chMtxLock(&mtx_adc);
        adc_readPoti(&readings);
        chMtxUnlock(&mtx_adc);
        chprintf(chp, "br=%f, f=%f, d=%f, vbat=%f\n", readings.brightness, readings.frequency, readings.depth, readings.vbat);
    }
    else {
        retval = -1;
        chprintf(chp, "no such getter as %s\n\r", what_to_get);
    }
}

static const ShellCommand commands[] = {
        {"probe", _probe},
        {"set",   set},
        {"s", set},
        {"get",   get},
        {"g", get},
        {NULL, NULL}
};

static ShellConfig shell_cfg_debug = {
        (BaseSequentialStream *)&SD2,
        commands
};

static ShellConfig shell_cfg_modem = {
        (BaseSequentialStream *)&SD1,
        commands
};

#define SHELL_WA_SIZE   THD_WORKING_AREA_SIZE(1024)


void communicationThreads_init(void) {
    shellInit();
    sdStart(&SD2, NULL);
    sdStart(&SD1, NULL);
    thread_t *shelltp_debug = chThdCreateFromHeap(NULL, SHELL_WA_SIZE, "shell_debug", NORMALPRIO + 1, shellThread, (void *)&shell_cfg_debug);
    thread_t *shelltp_modem = chThdCreateFromHeap(NULL, SHELL_WA_SIZE, "shell_modem", NORMALPRIO + 1, shellThread, (void *)&shell_cfg_modem);
    //chThdWait(shelltp);               /* Waiting termination.             */
}