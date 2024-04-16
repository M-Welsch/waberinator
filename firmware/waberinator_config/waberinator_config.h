#ifndef FIRMWARE_WABERINATOR_CONFIG_H
#define FIRMWARE_WABERINATOR_CONFIG_H

#include "stdbool.h"



int waberinator_config_store_to_flash(const waberinator_config_t *cfg);
int waberinator_config_load_from_flash(waberinator_config_t *cfg);

#endif //FIRMWARE_WABERINATOR_CONFIG_H
