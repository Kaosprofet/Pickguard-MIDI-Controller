#ifndef INCLUDES_H
#define INCLUDES_H

#include <avr/io.h>
#include "macros.h"
#include "midi.h"
#include "uart.h"
#include "play.h"

#define F_CPU 16000000
#define BAUD 9600

uint8_t mode = 0;
uint8_t octave = 2;
uint8_t noteVelocity = 100;

// Defining and initialising key pedals
typedef struct key_t {
    uint8_t pin;
    uint8_t portReg;
    uint8_t pinReg;
    uint8_t midiNote;
    uint8_t debounce;
    uint8_t noteSent;
} key_t;

// pins needs to be fixed for the board, ad 
key_t keys[] = {                                
  { PIND1, PORTD, PIND, 11, 0, 0 },     // B
  { PINB0, PORTB, PINB, 12, 0, 0 },     // C
  { PIND6, PORTD, PIND, 13, 0, 0 },     // C#
  { PINB1, PORTB, PINB, 14, 0, 0 },     // D
  { PIND5, PORTD, PIND, 15, 0, 0 },     // D#
  { PINB2, PORTB, PINB, 16, 0, 0 },     // E
  { PINC0, PORTC, PINC, 17, 0, 0 },     // F
  { PIND2, PORTD, PIND, 18, 0, 0 },     // F#
  { PINC1, PORTC, PINC, 19, 0, 0 },     // G
  { PINC5, PORTC, PINC, 20, 0, 0 },     // G#
  { PINC2, PORTC, PINC, 21, 0, 0 },     // A
  { PINC4, PORTC, PINC, 22, 0, 0 },     // A#
  { PINC3, PORTC, PINC, 23, 0, 0 },     // B
  {  0, 0,  0, 0, 0 }					// end of list marker
};

// Defining and initialising control button 
typedef struct controlButton_t {
  uint8_t pin;
  uint8_t portReg;
  uint8_t pinReg;
  uint8_t value;
  uint8_t debounce;
} controlButton_t;

controlButton_t controlButtons[] = {
  { PIND3, PORTD, PIND,  1, 0 },  // Octave up
  { PIND4, PORTD, PIND, -1, 0 },  // Octave down
  // Not implemented in current design
  //{ 3, 0,  0, 0 },  // Mode switch
  //{ 4, 0,  0, 0 },  // Velocity up
  //{ 5, 0,  0, 0 },  // Velocity down
  { 0, 0,  0, 0 }   // end of list marker
};

#endif