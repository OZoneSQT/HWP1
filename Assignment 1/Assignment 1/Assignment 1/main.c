/*
 * Assignment 1.c
 *
 * Created: 17/02/2023 10.21.40
 * Author : Michel Sommer, 273966
 */ 

#include <stdint.h>
#include <avr/io.h>
#include "keys/keys.h"
#include "logic/logic.h"	// To show a different implementation method of leds 
#include "leds/led_driver.h"

int main(void)
{
	init_keys();
	init_leds();
	
	uint8_t keyS1 = 1;	//S1 = PA0
	uint8_t keyS2 = 2;	//S2 = PA1
	
    while (1) 
    {
		set_led(keyS1, get_key(keyS1));
		set_led(keyS2, get_key(keyS2));
    }
	
	return 0;
}
/*
void logic()
{
	init_keys();
	logic_indicator_leds();
	
	uint8_t keyS1 = 1;	//S1 = PA0
	uint8_t keyS2 = 2;	//S2 = PA1
	
    while (1) 
    {
		uint8_t inputA = get_key(keyS1);
		uint8_t inputB = get_key(keyS2);
		set_logical_operators(inputA, inputB);
    }
}*/