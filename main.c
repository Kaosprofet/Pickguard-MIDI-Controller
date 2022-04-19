/* Pickguard MIDI-controller

Published under the GNU General Public License v3.0

Created by Kaosprofet
*/

#include <avr/io.h>
#include "play.h"
#include "interface.h"
#include "macros.h"
#include "uart.h"

#define LEDPIN PIND0

// Initialise all keys with ports, pinnumbering and MIDI-note

key_t keys[] = {
	{ PIND7, &PORTD, &PIND, 11, 0, 0 },     // B
	{ PINB0, &PORTB, &PINB, 12, 0, 0 },     // C
	{ PIND6, &PORTD, &PIND, 13, 0, 0 },     // C#
	{ PINB1, &PORTB, &PINB, 14, 0, 0 },     // D
	{ PIND5, &PORTD, &PIND, 15, 0, 0 },     // D#
	{ PINB2, &PORTB, &PINB, 16, 0, 0 },     // E
	{ PINC0, &PORTC, &PINC, 17, 0, 0 },     // F
	{ PIND2, &PORTD, &PIND, 18, 0, 0 },     // F#
	{ PINC1, &PORTC, &PINC, 19, 0, 0 },     // G
	{ PINC5, &PORTC, &PINC, 20, 0, 0 },     // G#
	{ PINC2, &PORTC, &PINC, 21, 0, 0 },     // A
	{ PINC4, &PORTC, &PINC, 22, 0, 0 },     // A#
	{ PINC3, &PORTC, &PINC, 23, 0, 0 }     // B
};

controlButton_t controlButtons[] = {
	{ PIND3, &PORTD, &PIND,  1, 0 },  // Octave up
	{ PIND4, &PORTD, &PIND, -1, 0 },  // Octave down
	// Not implemented in current design
	//{ 3, 0,  0, 0 },  // Mode switch
	//{ 4, 0,  0, 0 },  // Velocity up
	//{ 5, 0,  0, 0 }  // Velocity down
};

void init(void);

int main(void) {
    init();
	play(keys, controlButtons);
}

void init(void) {
	
	setBit(DDRD, LEDPIN);
	
    // Setting pullup for buttons
    for(uint8_t i = 0; i < numKeys; ++i) {
        setBit(*(keys[i].portReg), keys[i].pin);
    }
    for(uint8_t i = 0; i < numctrl; ++i) {
        setBit(*(controlButtons[i].portReg), controlButtons[i].pin);
    }

    initUart();
	midiSend(0xB0, 5, 0);
}