#include "ch.h"
#include "hal.h"

#include "shell.h"
#include "chprintf.h"

#include "serial_interface.h"
#include "core_defines.h"

/** @brief mailbox for messages to a connected Terminal like a PC */
mailbox_t _comm_mb;
msg_t _comm_mb_buffer[BCU_COMM_MB_BUFFER_SIZE];

void _initializeMailbox(void) {
    chMBObjectInit(&_comm_mb, _comm_mb_buffer, BCU_COMM_MB_BUFFER_SIZE);
}

msg_t putIntoOutputMailbox(char* msg) {
    return chMBPostTimeout(&_comm_mb, (msg_t) msg, TIME_MS2I(200));
}

static void _communicationOutputMainloop(BaseSequentialStream *stream) {
    msg_t msg = 0;
    chMBFetchTimeout(&_comm_mb, &msg, TIME_INFINITE);
    const char *s_msg = (const char *)msg;
    chprintf(stream, "%s\n", s_msg);
}

static THD_WORKING_AREA(communicationOutputThread, 128);
static THD_FUNCTION(communicationOutput, arg) {
    UNUSED_PARAM(arg);
    chRegSetThreadName("Serial Communication Output Thread");
    BaseSequentialStream *stream = (BaseSequentialStream *) &SD2;
    while (true) {
        _communicationOutputMainloop(stream);
    }
}

static void cmd_get(BaseSequentialStream *chp, int argc, char *argv[]) {
    UNUSED_PARAM(chp);
    UNUSED_PARAM(argc);
    UNUSED_PARAM(argv);
}

static const ShellCommand commands[] = {
        {"get", cmd_get},
        {NULL, NULL}
};

static ShellConfig shell_cfg1 = {
        (BaseSequentialStream *)&SD2,
        commands
};

#define SHELL_WA_SIZE   THD_WORKING_AREA_SIZE(2048)
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


    //_initializeMailbox();
    //chThdCreateStatic(communicationOutputThread, sizeof(communicationOutputThread), NORMALPRIO, communicationOutput, NULL);
    //chThdCreateStatic(communicationInputThread, sizeof(communicationInputThread), NORMALPRIO + 1, communicationInput, NULL);
}