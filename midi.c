#include "includes.h"

void noteOn(uint8_t note) {
    midiSend(0x90, note, noteVelocity);
}

void noteOff(uint8_t note) {
    midiSend(0x80, note, noteVelocity);
}

void midiSend(uint8_t byte1, uint8_t byte2, uint8_t byte3) {
    transmitByte(byte1);
    transmitByte(byte2);
    transmitByte(byte3);
}