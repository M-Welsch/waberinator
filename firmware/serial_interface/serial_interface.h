#ifndef FIRMWARE_SERIAL_INTERFACE_H
#define FIRMWARE_SERIAL_INTERFACE_H

#define BCU_COMM_MB_BUFFER_SIZE 256
#define BCU_COMM_INPUT_BUFFER_SIZE 256

#include "ch.h"

extern mailbox_t _comm_mb;
extern msg_t _comm_mb_buffer[BCU_COMM_MB_BUFFER_SIZE];

void communicationThreads_init(void);
msg_t putIntoOutputMailbox(char* msg);

#endif //FIRMWARE_SERIAL_INTERFACE_H
