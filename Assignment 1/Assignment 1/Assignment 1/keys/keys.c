/*
 * keys.c
 *
 * Created: 19/02/2023 10.37.05
 * Author: Michel Sommer, 273966
 */ 

#include "keys.h"

void init_keys()
{
	DDRC = DDRC & 0b11000000;	//set pins 0 to 5 as input
	PORTC |= 0b00111111;		//activates pull up resistors of PORTC
	
	//PINC = 0x3f;	
	
	DDRA = DDRA | 0b10000000;
}

uint8_t get_key(uint8_t key_no)
{
	if(key_no <= 1 && key_no >= 6)
	{
		uint8_t status = PINC & _BV(--key_no);	//Make key_no match bit and get pin status
		
		if (status == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 255;
	}
}