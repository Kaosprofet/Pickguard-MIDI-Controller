#ifnded INCLUDES_H
#define INCLUDES_H

#include <avr/io.h>
#include "macros.h"
#include "midi.h"

#define DEBOUNCE 50
#define modeButtonPin 11 // Fix pin for actual board

uint8_t mode = 0;
uint8_t octave = 2;
uint8_t velocity = 100;

uint8_t notePedalState;
uint8_t controlPedalState;
uint8_t lastNoteSent;

// Defining and initialising key pedals
typedef struct key_t {
    uint8_t pin;
    uint8_t midiNote;
    uint8_t debounce;
    uint8_t noteSent;
} key_t;

// pins needs to be fixed for the board
key_t keys[] = {                                
  { 22, 11, 0, 0 },     // B
  { 24, 12, 0, 0 },     // C
  { 26, 13, 0, 0 },     // C#
  { 28, 14, 0, 0 },     // D
  { 30, 15, 0, 0 },     // D#
  { 32, 16, 0, 0 },     // E
  { 34, 17, 0, 0 },     // F
  { 36, 18, 0, 0 },     // F#
  { 38, 19, 0, 0 },     // G
  { 40, 20, 0, 0 },     // G#
  { 42, 21, 0, 0 },     // A
  { 44, 22, 0, 0 },     // A#
  { 46, 23, 0, 0 },     // B
  {  0,  0, 0, 0 }      // end of list marker
};

// Defining and initialising control button 
typedef struct controlButton_t {
  uint8_t pin;
  uint8_t value;
  uint8_t debounce;
} controlButton_t;

controlButton_t controlButtons[] = {
  { 1,  1, 0 },   // Octave up
  { 2, -1, 0 },   // Octave down
  { 3,  1, 0 },   // Velocity up
  { 4, -1, 0 },   // Velocity down
  { 0,  0, 0 }    // end of list marker
};



#endif