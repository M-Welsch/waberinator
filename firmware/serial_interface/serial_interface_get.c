#include "serial_interface_get.h"
#include "serial_interface/common.h"
#include "core_defines.h"
#include "chprintf.h"

int _get_light(BaseSequentialStream *chp, int argc, char *argv[]) {
    UNUSED_PARAM(argc);
    UNUSED_PARAM(argv);
    chprintf(chp, "not implemented\n\r");
    return -1;
}

int _get_mode(BaseSequentialStream *chp, int argc, char *argv[]) {
    UNUSED_PARAM(argc);
    UNUSED_PARAM(argv);
    chprintf(chp, "not implemented\n\r");
    return -1;
}

int _get_poti_range(BaseSequentialStream *chp, int argc, char *argv[]) {
    UNUSED_PARAM(argc);
    UNUSED_PARAM(argv);
    chprintf(chp, "not implemented\n\r");
    return -1;
}

int _get_battery_monitor(BaseSequentialStream *chp, int argc, char *argv[]) {
    UNUSED_PARAM(argc);
    UNUSED_PARAM(argv);
    chprintf(chp, "not implemented\n\r");
    return -1;
}

int _get_smps(BaseSequentialStream *chp, int argc, char *argv[]) {
    UNUSED_PARAM(argc);
    UNUSED_PARAM(argv);
    chprintf(chp, "not implemented\n\r");
    return -1;
}

int _get_temperature(BaseSequentialStream *chp, int argc, char *argv[]) {
    UNUSED_PARAM(argc);
    UNUSED_PARAM(argv);
    chprintf(chp, "not implemented\n\r");
    return -1;
}

int _get_modem(BaseSequentialStream *chp, int argc, char *argv[]) {
    UNUSED_PARAM(argc);
    UNUSED_PARAM(argv);
    chprintf(chp, "not implemented\n\r");
    return -1;
}

void get(BaseSequentialStream *chp, int argc, char *argv[]) {
    if (argc < 1) {
        argument_missing(chp);
        return;
    }
    int retval = 0;
    const char *what_to_set = argv[0];

    if (isEqual(what_to_set, "light") || isEqual(what_to_set, "l")) {
        retval = _get_light(chp, argc-1, argv+1);
    }
    else if (isEqual(what_to_set, "mode")) {
        retval = _get_mode(chp, argc-1, argv+1);
    }
    else if (isEqual(what_to_set, "poti_range")) {
        retval = _get_poti_range(chp, argc-1, argv+1);
    }
    else if (isEqual(what_to_set, "battery_monitor")) {
        retval = _get_battery_monitor(chp, argc-1, argv+1);
    }
    else if (isEqual(what_to_set, "smps")) {
        retval = _get_smps(chp, argc-1, argv+1);
    }
    else if (isEqual(what_to_set, "temperature")) {
        retval = _get_temperature(chp, argc-1, argv+1);
    }
    else if (isEqual(what_to_set, "modem")) {
        retval = _get_modem(chp, argc-1, argv+1);
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