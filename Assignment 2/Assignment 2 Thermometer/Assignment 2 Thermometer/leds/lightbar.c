/*
 * lightbar.c
 *
 * Created: 26/02/2023 10.43.23
 * Author: Michel Sommer, 273966
 */

#include "lightbar.h"


/*******************************************************************************/
void lightbar_init()
{
		//set PORTA as output for the leds
		DDRA = DDRA |= 0b11111111;

		//turn of all leds
		PORTA = PORTA & 0b11111111;
}

/*******************************************************************************/
void lightbar_isr_keys_init()
{
	//set PORTA as output for the leds
	DDRA = DDRA |= 0b11111111;

	//turn of all leds
	PORTA = PORTA & 0b11111111;
	
	keys_init();
	keys_isr_init();
}

/*******************************************************************************/
void lightbar_scan_key()
{
	uint8_t level = 0;
	
	for (uint8_t i = 1; i <= 8; i++ )
	{
		if(keys_get_state(i) != 0) level++;
	}
		
	return level;
}

/*******************************************************************************/
void lightbar_level(uint8_t level)
{
	uint8_t out = 0b00000000;
	
	if(level == 1) out = 0b00000001; 
	if(level == 2) out = 0b00000011;
	if(level == 3) out = 0b00000111;
	if(level == 4) out = 0b00001111;
	if(level == 5) out = 0b00011111;
	if(level == 6) out = 0b00111111;
	if(level == 7) out = 0b01111111;
	if(level == 8) out = 0b11111111;
	
	PORTA = PORTA & ~out;
}

/*******************************************************************************/
