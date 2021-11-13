#ifnded MIDI_H
#define MIDI_H

#include <avr/io.h>

void noteOn(uint8_t note);
void noteOff(uint8_t note);
void midiSend(uint8_t byte1, uint8_t byte2, uint8_t byte3);

#endif