#include "hal.h"

#include "modem.h"

int modem_on(void) {
    palSetLine(LINE_MODEM_EN);
    palSetLine(LINE_MODEM_IO0_RESET);
    chThdSleepMilliseconds(2);
    if (palReadLine(LINE_MODEM_EN) && palReadLine(LINE_MODEM_IO0_RESET)) {
        return 0;
    }
    else {
        return -1;
    }
}

int modem_off(void) {
    palClearLine(LINE_MODEM_EN);
    palClearLine(LINE_MODEM_IO0_RESET);
    chThdSleepMilliseconds(2);
    if (!palReadLine(LINE_MODEM_EN) && !palReadLine(LINE_MODEM_IO0_RESET)) {
        return 0;
    }
    else {
        return -1;
    }
}
