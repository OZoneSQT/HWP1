/*
 * matrix.c
 *
 * Created: 21/04/2023 22.03.57
 *  Author: skrue
 */ 

#include "matrix.h"
#include <stdint.h>

volatile uint8_t keys[3][3];

/*
2-16
	OC0A = 
	OC1A = 
	OC2A = 
	OC3A = 
	OC3C = 
	OC4A = 
	OC4C = 
	ICP5 = 

*/


void loop() { char Matrix[4][4] = 
{ 
	{'1', '2', '3', 'C'},
	{'4', '5', '6', 'D'},
	{'7', '8', '9', 'E'},
	{'A', '0', 'B', 'F'} 
};
	