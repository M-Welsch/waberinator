#ifndef WABERINATOR_CORE_DEFINES_H
#define WABERINATOR_CORE_DEFINES_H

#define DIMENSION(x) (uint8_t)(sizeof(x)/sizeof(x[0]))
#define UNUSED_PARAM(x) (void)(x)

#define EVENT_BUTTON_PRESSED                  EVENT_MASK(0)

#endif //WABERINATOR_CORE_DEFINES_H
