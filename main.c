/*
Pickguard MIDI-controller by Kaosprofet 
*/

#include "includes.h"

void init(void);

int main(void) {
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
    // Setting pullup for buttons
    for(int i = 0; keys[i].pin != 0; ++i) {
        setBit(keys[i].portReg, keys[i].pin);
    }
    for(uint8_t i = 0; controlButtons[i].pin != 0; ++i) {
        setBit(controlButtons[i].portReg, controlButtons[i].pin);
    }

    initUart();
}