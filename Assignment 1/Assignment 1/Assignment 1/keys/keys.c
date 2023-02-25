/*
 * keys.c
 *
 * Created: 19/02/2023 10.37.05
 * Author: Michel Sommer, 273966
 */ 

#include "keys.h"

void init_keys()
{
	DDRC = DDRC & 0b00111111;	//set pins 0 to 5 as input
	PORTC = PORTC |= 0b00111111;		//activates pull up resistors of PORTC
}

uint8_t get_key(uint8_t key_no)
{
	--key_no;
	// uint8_t x = PINC & (1 << key_no);
	
	//return x;
	
			if (PINC & (1 << key_no)) 
		{
			return 1;
		} 
		else 
		{
			return 0;
		}
		
	/*
	if(key_no <= 1 && key_no >= 6)
	{		
		--key_no;
		uint8_t x = PINC & (1 << key_no);
		return x;
/*		
		if (x == 1) 
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
		return 2;
	}
*/
}

/*
		if (PINC & (1 << key_no)) 
		{
			return 1;
		} 
		else 
		{
			return 0;
		}
*/