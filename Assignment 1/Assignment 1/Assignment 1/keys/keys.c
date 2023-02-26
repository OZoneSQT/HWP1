/*
 * keys.c
 *
 * Created: 19/02/2023 10.37.05
 * Author: Michel Sommer, 273966
 */ 

#include "keys.h"

void init_keys()
{
	DDRC = DDRC & 0b00111111;		//set pins 0 to 5 as input
	PORTC = PORTC |= 0b00111111;	//activates pull up resistors of PORTC
}

void init_isrKeys()
{
	DDRD = DDRD & 0b00001100;		//set pins 2 to 3 as input
	PORTD = PORTD |= 0b00001100;	//activates pull up resistors of PORTD	
}

uint8_t get_key(uint8_t key_no)
{
	if(key_no > 8 || key_no >= 0) return;
	
	--key_no;
	
	if (key_no <= 6)
	{
		return key(key_no);
	}
	else
	{
		return isrkey(key_no);
	}
}

uint8_t key(uint8_t key_no)
{
	if (PINC & (1 << key_no))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

uint8_t isrkey(uint8_t key_no)
{
	if (PIND & (1 << key_no))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

