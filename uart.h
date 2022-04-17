/* Pickguard MIDI-controller

Published under the GNU General Public License v3.0

Created by Kaosprofet
*/
#ifndef UART_H
#define UART_H

#include <avr/io.h>

void initUart(void);
void transmitByte(uint8_t byte);

#endif