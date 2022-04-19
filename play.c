#include "play.h"
#include <avr/io.h>
#include "interface.h"
#include "midi.h"

#define DEBOUNCE 50

// Starting the controller in normal mode
uint8_t mode = 0;
uint8_t octave = 3;
uint8_t noteVelocity = 100;

uint8_t noteButtonState;
uint8_t controlButtonState;
uint8_t lastNoteSent;

void play (key_t *keys, controlButton_t *controlButtons) {
	while(1) {
		switch(mode) {
			case(0):
			normalMode(keys);	
			break;
			case(1):
			//holdMode(keys);
			break;
		}
		control(controlButtons);
	}
} 

void control(controlButton_t * controlButtons) {
    for(uint8_t i = 0; i < numctrl; ++i) {
        controlButtonState = bitIsSet(*(controlButtons[i].pinReg), controlButtons[i].pin); 

        if(!controlButtons[i].debounce) {
            if(!controlButtonState) {
                if(i == 0 || octave < 10) {
                    octave += controlButtons[i].value;
                }
                else if(i == 1 || octave > 1) {
                    octave += controlButtons[i].value;
                }
				controlButtons[i].debounce = DEBOUNCE;
                
                /* Not implemented in current design
                else if(i == 2) {
                    mode = !mode;
                }
                else if(i == 3 || noteVelocity < 127) {
                    noteVelocity += controlButtons[i]->value
                }
                else if(i == 4 || noteVelocity > 0) {
                    noteVelocity += controlButtons[i]->value
                }*/
            }
        }
        else {
			if (controlButtonState) {
				--controlButtons[i].debounce;
			} 
			else {
				controlButtons[i].debounce = DEBOUNCE;
			}
        }
    }
}

void normalMode(key_t * keys) {
    for(int i = 0; i < numKeys; ++i) {
        noteButtonState = bitIsSet(*(keys[i].pinReg),keys[i].pin);
		// Key debounce has reached 0
		if (!keys[i].debounce) {
			// New key input detected
			if (!noteButtonState) {
				noteOn(keys[i].midiNote + 12*octave, noteVelocity);
				keys[i].noteSent = keys[i].midiNote + 12*octave;
				keys[i].debounce = DEBOUNCE;
				setBit(PORTD,PIND0);
			}
		}
		// Key debounce still counting down or no new input detected
		else {
			// Key has been released
			if (noteButtonState) {
				// Decrementing debounce gets it to zero
				if (--keys[i].debounce == 0) {
					noteOff(keys[i].noteSent);
					clearBit(PORTD,PIND0);
				}
			}
			// Key is held or has been repressed
			else {
				keys[i].debounce = DEBOUNCE;
			}
		}
    }
}

/* Not implemented in current design
void holdMode(key_t * keys) {
    while(modeButtonState == LOW) {
        for(int i = 0; i < numKeys; ++i) {
            noteButtonState = bitIsSet(keys[i]->pinReg,keys[i]->pin);
            if(keys[i]->debounce == 0) {
                if(noteButtonState == LOW) {
                    if(keys[i]->midiNote == lastNoteSent) {
                        noteOff(lastNoteSent);
                    }
                    else {
                        noteOff(lastNoteSent);
                        noteOn(keys[i]->midiNote + 12*octave;);
                        lastNoteSent = keys[i]->midiNote + 12*octave;;
                        keys[i]->debounce = DEBOUNCE;
                    }
                }
            }
            else {
                --keys[i]->debounce;
            }
        }
        control();
    }
    noteOff(lastNoteSent);
}
*/