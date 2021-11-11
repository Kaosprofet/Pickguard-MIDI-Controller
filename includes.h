#ifnded INCLUDES_H
#define INCLUDES_H

#include "makros.h"
#include "midi.h"

#define DEBOUNCE 50

typedef struct key_t {
    uint8_t pin;
    uint8_t midiNote;
    uint8_t debounce;
    uint8_t noteSent;
} key_t


// needs to be fixed for the board
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

#endif