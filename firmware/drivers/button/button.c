#include "hal.h"
#include "ch.h"
#include "button.h"
#include "chevents.h"
#include "core_defines.h"

static void pb_cb(void *arg) {
    UNUSED_PARAM(arg);
    //statemachine_sendEventFromIsr(EVENT_BUTTON_PRESSED);
}


void button_init(void) {
    palEnableLineEvent(LINE_BUTTON, PAL_EVENT_MODE_FALLING_EDGE);
    palSetLineCallback(LINE_BUTTON, pb_cb, NULL);

}