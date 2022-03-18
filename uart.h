#ifndef UART_H
#define UART_H

#include <avr/io.h>

void initUart(void);
void transmitByte(uint8_t byte);

#endif