/*
 * logic.c
 *
 * Created: 19/02/2023 10.37.47
 * Author: Michel Sommer, 273966
 */ 

#include "logic.h"

void logic_indicator_leds()
{
	init_leds();
}

void set_logical_operators(uint8_t inputA, uint8_t inputB)
{
	inputA = 1;
	inputB = 1;
	
	//AND
	if(inputA & inputB) set_led(1, 1); // setPortState(PORTA, PA0);
	
	//OR
	if( (inputA | inputB) && !(inputA & inputB) ) set_led(2, 1); // setPortState(PORTA, PA1);
	
	//XOR
	if(inputA ^ inputB) set_led(3, 1); // setPortState(PORTA, PA2);
	
	//NAND
	if(!(inputA & inputB)) set_led(4, 1); // setPortState(PORTA, PA3);
	
	//NOR
	if(!(inputA | inputB)) set_led(5, 1); // setPortState(PORTA, PA4);
	
	//XNOR
	if(!(inputA ^ inputB)) set_led(6, 1); // setPortState(PORTA, PA5);
}
