#include "serial_interface_set.h"
#include "serial_interface/common.h"
#include "waber_thread.h"
#include "chprintf.h"
#include "core_defines.h"

int _light(BaseSequentialStream *chp, int argc, char *argv[]) {
    if (argc < 3) {
        argument_missing(chp);
        return -1;
    }
    const char *which_parameter_to_set = argv[0];
    const char *which_led = argv[1];
    const char *value = argv[2];

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
    else if (isEqual(which_parameter_to_set, "max_brightness") || isEqual(which_parameter_to_set, "mb")) {
        parameter = WABER_CFG_MAX_BRIGHTNESS;
    }
    else if (isEqual(which_parameter_to_set, "brightness")) {
        parameter = WABER_CFG_MOMENTARY_BRIGHTNESS;
    }
    else if (isEqual(which_parameter_to_set, "smoothness")) {
        parameter = WABER_CFG_SMOOTHNESS;
    }
    else if (isEqual(which_parameter_to_set, "active")) {
        parameter = WABER_CFG_ACTIVE;
    }
    else {
        chprintf(chp, "no such parameter as %s\n\r", which_parameter_to_set);
        return -1;
    }

    int led_to_set;
    customAtoI(which_led, &led_to_set);
    if ((led_to_set < 0) || (led_to_set > 6)) {
        chprintf(chp, "invalid led: %d\n\r", led_to_set);
        return -1;
    }

    float value_decoded = customAtoF(value);
    waberthread_set_cfg((uint8_t) led_to_set-1, parameter, value_decoded);
    return 0;
}

int _mode(BaseSequentialStream *chp, int argc, char *argv[]) {
    if (argc < 1) {
        argument_missing(chp);
        return -1;
    }
    if (isEqual(argv[0], "manual")) {
        waberthread_set_manual_mode(true);
        chprintf(chp, "setting manual mode\n\r");
    }
    else {
        waberthread_set_manual_mode(false);
        chprintf(chp, "setting automatic (\"wabering\") mode (you might have to send this command a second time)\n\r");
    }
    return 0;
}

int _poti_range(BaseSequentialStream *chp, int argc, char *argv[]) {
    UNUSED_PARAM(argc);
    UNUSED_PARAM(argv);
    chprintf(chp, "not implemented\n\r");
    return -1;
}

int _battery_monitor(BaseSequentialStream *chp, int argc, char *argv[]) {
    UNUSED_PARAM(argc);
    UNUSED_PARAM(argv);
    chprintf(chp, "not implemented\n\r");
    return -1;
}

int _smps(BaseSequentialStream *chp, int argc, char *argv[]) {
    if (argc < 1) {
        argument_missing(chp);
        return -1;
    }
    const char *on_or_off = argv[0];
    if (isEqual(on_or_off, "on")) {

    }
    return 0;
}

int _temperature(BaseSequentialStream *chp, int argc, char *argv[]) {
    UNUSED_PARAM(argc);
    UNUSED_PARAM(argv);
    chprintf(chp, "not implemented\n\r");
    return -1;
}

void set(BaseSequentialStream *chp, int argc, char *argv[]) {
    if (argc < 1) {
        argument_missing(chp);
        return;
    }
    int retval = 0;
    const char *what_to_set = argv[0];

    if (isEqual(what_to_set, "light") || isEqual(what_to_set, "l")) {
        retval = _light(chp, argc-1, argv+1);
    }
    else if (isEqual(what_to_set, "mode")) {
        retval = _mode(chp, argc-1, argv+1);
    }
    else if (isEqual(what_to_set, "poti_range")) {
        retval = _poti_range(chp, argc-1, argv+1);
    }
    else if (isEqual(what_to_set, "battery_monitor")) {
        retval = _battery_monitor(chp, argc-1, argv+1);
    }
    else if (isEqual(what_to_set, "smps")) {
        retval = _smps(chp, argc-1, argv+1);
    }
    else if (isEqual(what_to_set, "temperature")) {
        retval = _temperature(chp, argc-1, argv+1);
    }
    else {
        retval = -1;
        chprintf(chp, "no such setter as %s\n\r", what_to_set);
    }

    chprintf(chp, "setting %s ", what_to_set);
    if (retval == 0) {
        chprintf(chp, "successful\n\r");
    }
    else {
        chprintf(chp, "failed\n\r");
    }

}
