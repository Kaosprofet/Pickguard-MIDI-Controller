#ifnded MIDI_H
#define MIDI_H

#include "uart.h"

void midiSend(uint8_t byte1, uint8_t byte2, uint8_t byte3);
void noteOn(uint8_t note);
void noteOff(uint8_t note);

#endif