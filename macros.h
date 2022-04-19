/* Pickguard MIDI-controller

Macros to simplify code

Published under the GNU General Public License v3.0

Created by Kaosprofet in 2022
*/

#ifndef MACROS_H
#define MACROS_H

#define setBit(reg, bit) (reg |= (1<<bit))
#define clearBit(reg, bit) (reg &= ~(1<<bit))
#define toggleBit(reg, bit) (reg ^= (1<<bit)) 

#define bitIsSet(reg, bit) (reg & (1<<bit))

#define waitUntilBitIsSet(reg, bit) while(!bitIsSet(reg,bit))
#define waitUntilBitIsClear(reg, bit) while(bitIsSet(reg,bit))

#endif