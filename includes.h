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
  { PD1, PORTD, PIND, 11, 0, 0 },     // B
  { PB0, PORTB, PINB, 12, 0, 0 },     // C
  { PD6, PORTD, PIND, 13, 0, 0 },     // C#
  { PB1, PORTB, PINB, 14, 0, 0 },     // D
  { PD5, PORTD, PIND, 15, 0, 0 },     // D#
  { PB2, PORTB, PINB, 16, 0, 0 },     // E
  { PC0, PORTC, PINC, 17, 0, 0 },     // F
  { PD2, PORTD, PIND, 18, 0, 0 },     // F#
  { PC1, PORTC, PINC, 19, 0, 0 },     // G
  { PC5, PORTC, PINC, 20, 0, 0 },     // G#
  { PC2, PORTC, PINC, 21, 0, 0 },     // A
  { PC4, PORTC, PINC, 22, 0, 0 },     // A#
  { PC3, PORTC, PINC, 23, 0, 0 },     // B
  {  0, 0,  0, 0, 0 }      // end of list marker
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
  { PD3, PORTD, PIND,  1, 0 },  // Octave up
  { PD4, PORTD, PIND, -1, 0 },  // Octave down
  // Not implemented in current design
  //{ 3, 0,  0, 0 },  // Mode switch
  //{ 4, 0,  0, 0 },  // Velocity up
  //{ 5, 0,  0, 0 },  // Velocity down
  { 0, 0,  0, 0 }   // end of list marker
};

#endif