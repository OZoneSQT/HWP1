/*
 * logic.c
 *
 * Created: 19/02/2023 11.23.27
 * Author: Michel Sommer, 273966
 */ 

#include "logic.h"


/*******************************************************************************/
void logic_indicator_leds()
{
	leds_init();
	keys_isr_init();
}

/*******************************************************************************/
void logic_set_operators(uint8_t inputA, uint8_t inputB)
{
	// Bitwise operations
	uint8_t and = (inputA & inputB);
	uint8_t or = (inputA | inputB);
	uint8_t xor = (inputA ^ inputB);
	uint8_t nand = ~(inputA & inputB);
	uint8_t nor = ~(inputA | inputB);
	uint8_t xnor = ~(inputA ^ inputB);

	// value matcher
	if(nand >= 1) nand = 1;
	if(nor >= 1) nor = 1;
	if(xnor >= 1) xnor = 1;

	// Output
	PORTA = (and << PINA0) | (or << PINA1) | (xor << PINA2) | (nand << PINA3) | (nor << PINA4) | (xnor << PINA5);
}

/*******************************************************************************/
