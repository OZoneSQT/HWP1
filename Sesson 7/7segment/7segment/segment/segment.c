/*
 * segment.c
 *
 * Created: 24/03/2023 10.54.42
 * Author: Michel Sommer, 273966
 */ 

#include "segment.h"

uint16_t dig1 = LE, dig2 = LE, dig3 = LE, dig4 = LE;

static uint8_t digit = 1;
static uint16_t firstvalue; // variable to know if the high digit is 0 or no and to display it or no

/************************************************************************/
uint8_t type_check()
{

}


/************************************************************************/
//Function to divide the number in 4 different digit
static uint16_t get_segment(uint16_t value)
{
	dig1=value/1000;
	dig2=(value%1000)/100;
	dig3=(value%100)/10;
	dig4=value%10;
	
	if(digit==4) return dig4;
	if(digit==3) return dig3;
	if(digit==2) return dig2;
	if(digit==1) return dig1;
	
	return 0;	
}

/************************************************************************/
void display_printint_4s(uint16_t value)
{
	
}

/************************************************************************/
void segment_init(uint16_t refresh_ms)
{
	timer_init_8bit(DELAY_MS);
	
	// RCK-->PB0 and when the 8 segments are good, SCK-->PB1 for each segment and SI-->PB2 for the value
	DDRB |= _BV(RCK) | _BV(SCK) | _BV(SI);
	
	// D1-->PF0, D2-->PF1, D3-->PF2, D4-->PF3,
	DDRF |= _BV(D1) | _BV(D2) | _BV(D3) | _BV(D4);
	
	PORTB &= ~(_BV(RCK) | _BV(SCK) | _BV(SI));
	PORTF |= _BV(D1) | _BV(D2) | _BV(D3) | _BV(D4);
	
}

/************************************************************************/
void segment_print_uint(uint16_t value)
{
	assert(scanf("%d", &value) != 0); // aborts call, if datatype check fails
	
	dig1 = 0;
	dig2 = 0;
	dig3 = 0;
	dig4 = 0;
	
}

/************************************************************************/
void segment_print_int(int16_t value)
{
	assert(scanf("%d", &value) != 0); // aborts call, if datatype check fails
	
	if(0 > value) {
		dig4 = LN;
	}
	
	dig1 = 0;
	dig2 = 0;
	dig3 = 0;
	dig4 = 0;	
}

/************************************************************************/
void segment_print_float(float value, uint8_t decimals)
{
	assert(scanf("%f", &value) != 0); // aborts call, if datatype check fails
	
	dig1 = 0;
	dig2 = 0;
	dig3 = 0;
	dig4 = 0;	
	
	if(0 > value) {
		dig4 = LN;
		if(decimals == 1)
		{
			
		} 
		else if(decimals >= 2)
		{
			
		}
		else 
		{
			
		}
	}
	if(decimals == 1)
	{
		
	}
	else if(decimals >= 2)
	{
		
	}
	else
	{
		
	}
		
}

/************************************************************************/
void segment_print_letter(letters_t letter, uint8_t position)
{
	
	
	
}

/************************************************************************/
