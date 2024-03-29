/*
 * lightbar.c
 *
 * Created: 26/02/2023 10.43.23
 * Author: Michel Sommer, 273966
 */

#include "lightbar.h"


void init_lightbar()
{
		//set PORTA as output for the leds
		DDRA = DDRA |= 0b11111111;

		//turn of all leds
		PORTA = PORTA & 0b11111111;
		
		init_keys();
		init_isrKeys():
}


uint8_t scan_key();
{
	uint8_t level = 0;
	
	for (uint8_t i = 1; i <= 8; i++ )
	{
		if(get_key(i) != 0) level++;
	}
		
	return level;
}


void lightbar(uint8_t level)
{
	uint8_t out = 0b00000000;
	
	if(level = 1) = 0b00000001; 
	if(level = 2) = 0b00000011;
	if(level = 3) = 0b00000111;
	if(level = 4) = 0b00001111;
	if(level = 5) = 0b00011111;
	if(level = 6) = 0b00111111;
	if(level = 7) = 0b01111111;
	if(level = 8) = 0b11111111;
	
	PORTA = PORTA & ~out;
}
