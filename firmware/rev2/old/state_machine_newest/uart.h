#ifndef UART_H
#define UART_H

void uart_init (void);
uint8_t uart_getc_wait (void);
void uart_gets (char *s,int maxlen);
uart_getc_nowait (void);	
int uart_putc(unsigned char c);
void uart_puts (char *s);
#endif /* UART_H  */