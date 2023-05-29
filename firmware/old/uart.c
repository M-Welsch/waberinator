#ifndef UART_H
#define UART_H

#include <avr/io.h>

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

#define BAUDRATE 38400UL //Definition als unsigned long, sonst gibt es Fehler in der Berechnung
#define F_CPU 1000000

void uart_init (void)
{
    uint16_t ubrr = (uint16_t) ((uint32_t) F_CPU/(16*BAUDRATE) - 1);
 
    UBRRH = (uint8_t) (ubrr>>8);
    UBRRL = (uint8_t) (ubrr);
 
    // UART Receiver und Transmitter anschalten 
    // Data mode 8N1, asynchron 
    UCSRB = (1 << RXEN) | (1 << TXEN);
    UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);

    // Flush Receive-Buffer (entfernen evtl. vorhandener ungültiger Werte) 
    do
    {
        UDR;
    }
    while (UCSRA & (1 << RXC));
}
		
