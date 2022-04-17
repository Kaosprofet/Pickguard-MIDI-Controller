#include "uart.h"
#include "macros.h"

#define F_CPU 16000000
#define BAUD 9600

#define BAUD_PRESCALE ((F_CPU / (BAUD * 16UL)) - 1)

void initUart(void) {
    UBRR0H = (unsigned char)(BAUD_PRESCALE >> 8);
	UBRR0L = (unsigned char)BAUD_PRESCALE;

    UCSR0B |= (1 << TXEN0);  // UART enabled with only TX
    UCSR0C = (1 << USBS0) | (3 << UCSZ00);    // 2 stop bits, 8 bit data recieve // (1 << URSEL0) kanskje un�dvendig?
}

void transmitByte(unsigned char byte) {
    waitUntilBitIsSet(UCSR0A, UDRE0);
    UDR0 = byte;
}