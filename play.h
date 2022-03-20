#ifndef PLAY_H
#define PLAY_H

#include "interface.h"

void control(controlButton_t * controlButtons);
void normalMode(key_t * keys);
void holdMode(key_t * keys);
void play(key_t * keys, controlButton_t * controlButtons);
#endif