/*
 * logic.c
 *
 * Created: 19/02/2023 10.37.47
 * Author: Michel Sommer, 273966
 */ 

#include "logic.h"

void logic_indicator_leds()
{
	DDRA = 0xc0;	//set pins 0 to 5 as output
	PORTA = 0x3f;	// turn off leds
}

void set_logical_operators(uint8_t inputA, uint8_t inputB)
{
	//AND
	if(inputA & inputB) setPortState(PORTA, PA0);
	
	//OR
	if((inputA | inputB) && !(inputA & inputB) ) setPortState(PORTA, PA1);
	
	//XOR
	if(inputA ^ inputB) setPortState(PORTA, PA2);
	
	//NAND
	if(!(inputA & inputB)) setPortState(PORTA, PA3);
	
	//NOR
	if(!(inputA | inputB)) setPortState(PORTA, PA4);
	
	//XNOR
	if(!(inputA ^ inputB)) setPortState(PORTA, PA5);
}