/*
 * segment.c
 *
 * Created: 24/03/2023 10.54.42
 * Author: Michel Sommer, 273966
 */ 

#include "segment.h"

uint16_t segment1 = LE;
uint16_t segment2 = LE;
uint16_t segment3 = LE;
uint16_t segment4 = LE;

// least significant digit	
uint16_t decimal1 = LB;
uint16_t decimal2 = LB;
uint16_t digit1 = LB;
uint16_t digit2 = LB;
uint16_t digit3 = LB;
uint16_t digit4 = LB;
// highest significant digit

/************************************************************************/
//Function to divide the number in 4 different digit
static uint16_t set_segment_values(float value)
{
	decimal1 = (uint16_t)((value-(uint16_t)value)*10)%10;
	decimal2 = (uint16_t)(((value-(uint16_t)value)*10)-decimal1)%10;
	
	digit1 = (uint16_t)value%10;
	digit2 = ((uint16_t)value%100)/10;
	digit3 = ((uint16_t)value%1000)/100;
	digit4 = (uint16_t)value/1000;	
}

/************************************************************************/
static letters_t map_output_value(uint16_t value)
{
	// divide and conger 
	if(value < 5 ) 
	{
		if(value == 0) value = L0;
		if(value == 1) value = L1;
		if(value == 2) value = L2;
		if(value == 3) value = L3;
		if(value == 4) value = L4;
	}	
	else if (value >= 5)
	{
		if(value == 5) value = L5;
		if(value == 6) value = L6;
		if(value == 7) value = L7;
		if(value == 8) value = L8;
		if(value == 9) value = L9;
	}
	else
	{
		// return blank
		value == LB;	
	}

	return value;
}

/************************************************************************/
static void print_uint(float value)
{
	segment1 = digit1;
	segment2 = digit2;
	segment3 = digit3;
	segment4 = digit4;	
}

/************************************************************************/
static void print_sint(float value)
{
	if (value < 0)
	{
		segment1 = digit1;
		segment2 = digit2;
		segment3 = digit3;
		segment4 = LN;
	}
	else
	{
		segment1 = digit1;
		segment2 = digit2;
		segment3 = digit3;
		segment4 = digit4;
	}

}

/************************************************************************/
static void print_float(float value, uint8_t decimals)
{
	if (value < 0)
	{
		if(value <= -10)
		{
			segment1 = digit1 || LD;
			segment2 = digit2;
			segment3 = digit3;
			segment4 = LN;
		}
		if(decimals == 1){
			segment1 = decimal1;
			segment2 = digit1 || LD;
			segment3 = digit2;
			segment4 = LN;
		}
		else if(decimals <= 2)
		{
			segment1 = decimal2;
			segment2 = decimal1;
			segment3 = digit1 || LD;
			segment4 = LN;
		}
		else
		{
			segment1 = digit1;
			segment2 = digit2;
			segment3 = digit3;
			segment4 = LN;
		}
	}
	else if (value > 99) {
		if(decimals <= 1)
		{
			segment1 = decimal1;
			segment2 = digit1 || LD;
			segment3 = digit2;
			segment4 = digit3;
		}
		else
		{
			segment1 = decimal2;
			segment2 = decimal1;
			segment3 = digit1 || LD;
			segment4 = digit2;
		}
	}
	else
	{
		segment1 = digit1;
		segment2 = digit2;
		segment3 = digit3;
		segment4 = digit4;
	}

}

/************************************************************************/
void segment_print(float value, print_t format, uint8_t decimals)
{
	set_segment_values(value);
	
	if(value < 9999) 
	{
		if(format == UINT16_T)
		{
			print_uint(value);
		}
		else if (format == INT16_T)
		{
			print_sint(value);
		}
		else if (format == FLOAT)
		{
			print_float(value, decimals);
		}
		else
		{
			digit1 = LE;
			digit2 = LE;
			digit3 = LE;
			digit4 = LE;
		}
	}
	else
	{
		digit1 = LE;
		digit2 = LE;
		digit3 = LE;
		digit4 = LE;
	}
	
	segment_hal_print(segment1, segment2, segment3, segment4);
	
}

/************************************************************************/
void segment_print_letter(letters_t segment1, letters_t segment2, letters_t segment3, letters_t segment4)
{
	segment_hal_print(segment1, segment2, segment3, segment4);
}

/************************************************************************/
void segment_init(uint16_t refresh_ms)
{
	segment_hal_init(refresh_ms);
}

/************************************************************************/
