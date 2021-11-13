/*
Pickguard MIDI-controller by Kaosprofet 
*/

#include "includes.h"

void init(void);
void control(void);
void normalMode(void);
void holdMode(void);

void main(void) {
    init();
    while(1) {
        switch(mode) {
            case(0):
                normalMode();
                break;
            case(1):
                holdMode();
                break;
        }
        control();
    }
}

void init(void) {
    initUart();
}

void control(void) {
    for(uint8_t i=0; controlButtons[i].pin !=0; ++i) {
        controlButtonState = bitIsSet(controlButtons[i].reg, controlButtons[i].pin); 

        if(controlButtons[i].debounce == 0) {
            if(controlButtonState == 0) {
                if(i == 0 || octave < 10) {
                    octaveChange(controlButtons[i].value);
                }
                else if(i == 1 || octave > 0) {
                    octaveChange(controlButtons[i].value);
                }
                else if(i == 2 || noteVelocity < 127) {
                    velocityChange(controlButtons[i].value);
                }
                else if(i == 3 || noteVelocity > 0) {
                    velocityChange(controlButtons[i].value);
                }
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
        notePedalState = bitIsSet(keys[i].reg,keys[i].pin);
        
        if(keys[i].debounce == 0) {
            if(notePedalState == 0) {
                noteOn(keys[i].midiNote + 12*octave);
                keys[i].noteSent = keys[i].midiNote + 12*octave;
                keys[i].debounce = DEBOUNCE;
            }
        }
        else {
            if(notePedalState == 1) {
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

void holdMode(void) {
    while(modeButtonState == LOW) {
        for(int i = 0; keys[i].pin != 0; ++i) {
            notePedalState = bitIsSet(keys[i].regkeys[i].pin);
            if(keys[i].debounce == 0) {
                if(notePedalState == LOW) {
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