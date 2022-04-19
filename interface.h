/* Pickguard MIDI-controller

Variables and typedefs for ardware interaction

Published under the GNU General Public License v3.0

Created by Kaosprofet in 2022
*/

#ifndef INTERFACE_H
#define INTERFACE_H

#include <avr/io.h>

#define numKeys 13
#define numctrl 2

// Defining and initialising key pedals
typedef struct key_t {
	uint8_t pin;
	volatile uint8_t * portReg;
	volatile uint8_t * pinReg;
	uint8_t midiNote;
	uint8_t debounce;
	uint8_t noteSent;
} key_t;

// Defining and initialising control button
typedef struct controlButton_t {
	uint8_t pin;
	volatile uint8_t * portReg;
	volatile uint8_t * pinReg;
	uint8_t value;
	uint8_t debounce;
} controlButton_t;

#endif