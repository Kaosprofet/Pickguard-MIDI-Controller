/* Pickguard MIDI-controller

Main program, might be moved to main.c if size allows

Published under the GNU General Public License v3.0

Created by Kaosprofet in 2022
*/

#ifndef PLAY_H
#define PLAY_H

#include "interface.h"

void control(controlButton_t * controlButtons);
void normalMode(key_t * keys);
void holdMode(key_t * keys);
void play(key_t * keys, controlButton_t * controlButtons);
#endif