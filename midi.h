/* Pickguard MIDI-controller

Published under the GNU General Public License v3.0

Created by Kaosprofet
*/
#ifndef MIDI_H
#define MIDI_H

#include <avr/io.h>

void noteOn(uint8_t note, uint8_t noteVelocity);
void noteOff(uint8_t note);
void midiSend(uint8_t byte1, uint8_t byte2, uint8_t byte3);

#endif