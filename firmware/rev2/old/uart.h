#ifndef UART_H
#define UART_H

#include <avr/io.h>
#include "uart.c"

extern void uart_init (void);

static inline int
uart_putc (const uint8_t c)
{
    // Warten, bis UDR bereit ist für einen neuen Wert 
    while (!(UCSRA & (1 << UDRE)))
        ;

    // UDR Schreiben startet die Übertragung 
    UDR = c;

    return 1;
}

static inline uint8_t
uart_getc_wait (void)
{
    // Warten, bis etwas empfangen wird 
    while (!(UCSRA & (1 << RXC)))
        ;

    // Das empfangene Zeichen zurückliefern 
    return UDR;
}

static inline int
uart_getc_nowait (void)
{
    // Liefer das empfangene Zeichen, falls etwas empfangen wurde; -1 sonst 
    return (UCSRA & (1 << RXC)) ? (int) UDR : -1;
}

#endif /* UART_H  */
