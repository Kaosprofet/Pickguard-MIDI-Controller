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