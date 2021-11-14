#include "includes.h"

#define DEBOUNCE 50

uint8_t mode = 0;
uint8_t octave = 2;
uint8_t velocity = 100;

uint8_t noteButtonState;
uint8_t controlButtonState;
uint8_t lastNoteSent;

void control(void) {
    for(uint8_t i = 0; controlButtons[i].pin != 0; ++i) {
        controlButtonState = bitIsSet(controlButtons[i].reg, controlButtons[i].pin); 

        if(controlButtons[i].debounce == 0) {
            if(controlButtonState == 0) {
                if(i == 0 || octave < 10) {
                    octave += controlButtons[i].value;
                }
                else if(i == 1 || octave > 1) {
                    octave += controlButtons[i].value;
                }
                /* Not implemented in current design
                else if(i == 2) {
                    mode = !mode;
                }
                else if(i == 3 || noteVelocity < 127) {
                    noteVelocity += controlButtons[i].value
                }
                else if(i == 4 || noteVelocity > 0) {
                    noteVelocity += controlButtons[i].value
                }*/
                controlButtons[i].debounce = DEBOUNCE;
            }
        }
        else {
            --controlButtons[i].debounce;
        }
    }
}

void normalMode(void) {
    for(int i = 0; keys[i].pin != 0; ++i) {
        noteButtonState = bitIsSet(keys[i].reg,keys[i].pin);
        
        if(keys[i].debounce == 0) {
            if(noteButtonState == 0) {
                noteOn(keys[i].midiNote + 12*octave);
                keys[i].noteSent = keys[i].midiNote + 12*octave;
                keys[i].debounce = DEBOUNCE;
            }
        }
        else {
            if(noteButtonState == 1) {
                if(--keys[i].debounce == 0) {
                    noteOff(keys[i].noteSent);
                }  
            }
            else {
                keys[i].debounce = DEBOUNCE;
            }                                                 
        }
    }
}
/* Not implemented in current design
void holdMode(void) {
    while(modeButtonState == LOW) {
        for(int i = 0; keys[i].pin != 0; ++i) {
            noteButtonState = bitIsSet(keys[i].regkeys[i].pin);
            if(keys[i].debounce == 0) {
                if(noteButtonState == LOW) {
                    if(keys[i].midiNote == lastNoteSent) {
                        noteOff(lastNoteSent);
                    }
                    else {
                        noteOff(lastNoteSent);
                        noteOn(keys[i].midiNote + 12*octave;);
                        lastNoteSent = keys[i].midiNote + 12*octave;;
                        keys[i].debounce = DEBOUNCE;
                    }
                }
            }
            else {
                --keys[i].debounce;
            }
        }
        modeButtonState = bitIsSet(, modeButtonPin); //add correct reg
    }
    noteOff(lastNoteSent);
}
*/