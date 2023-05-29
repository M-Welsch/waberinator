#ifndef UART_H
#define UART_H

#include <avr/io.h>
#include "uart.h"

#define FOSC 8000000UL
#define F_CPU 8000000UL
#define BAUD 9600
#define ubrr 51

extern void uart_init (void);

uint8_t uart_getc_wait (void)
{
    // Warten, bis etwas empfangen wird 
    while (!(UCSRA & (1 << RXC)))
        ;

    // Das empfangene Zeichen zurückliefern 
    return UDR;
}

void uart_gets (char *s,int maxlen)
{
    int i=0;
    while(i<=maxlen)
    {
        i++;
        *s=uart_getc_nowait();
        if (*s=='\n') {
        *s='\0';
        break;}
        s++; 
    }
    if (i>maxlen) {*s='\0';}
    
}

int uart_getc_nowait (void)
{
    // Liefer das empfangene Zeichen, falls etwas empfangen wurde; -1 sonst 
    return (UCSRA & (1 << RXC)) ? (int) UDR : -1;
}

#endif /* UART_H  */

		
void uart_init() {
    UBRRH = (unsigned char)(ubrr>>8);
    UBRRL = (unsigned char)ubrr;
    
    UCSRB = (1 << RXEN) | (1 << TXEN);
    UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
}

int uart_putc(unsigned char c) {
    while (!(UCSRA & (1<<UDRE)))  /* warten bis Senden moeglich */
    {
    }                             
 
    UDR = c;                      /* sende Zeichen */
    return 0;
}
void uart_puts (char *s) {
    while (*s)
    {   /* so lange *s != '\0' also ungleich dem "String-Endezeichen(Terminator)" */
        uart_putc(*s);
        s++;
    }
}