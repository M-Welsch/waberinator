#include "hal.h"

#include "modem.h"

int modem_on(void) {
    palSetLine(MODEM_IO0_RESET);
    palSetLine(MODEM_EN);
    if (palReadLine(MODEM_EN) && palReadLine(MODEM_IO0_RESET)) {
        return 0;
    }
    else {
        return -1;
    }
}

int modem_off(void) {
    palClearLine(MODEM_IO0_RESET);
    palClearLine(MODEM_EN);
    if (!palReadLine(MODEM_EN) && !palReadLine(MODEM_IO0_RESET)) {
        return 0;
    }
    else {
        return -1;
    }
}
