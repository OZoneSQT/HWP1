/*
 * segment_display.c
 *
 * Created: 19/03/2023 11.01.13
 * Author: Michel Sommer, 273966
 */

#include "segment-display.h"

#define RCK PORTB0
#define SCK PORTB1
#define SI PORTB2
#define D1 PORTF0
#define D2 PORTF1
#define D3 PORTF2
#define D4 PORTF3

static int digit = 1;
static int firstvalue; // variable to know if the high digit is 0 or no and to display it or no

/*******************************************************************************/
void display_init()
{
	// RCK-->PB0 and when the 8 segments are good, SCK-->PB1 for each segment and SI-->PB2 for the value
	DDRB |= _BV(RCK) | _BV(SCK) | _BV(SI);
	
	// D1-->PF0, D2-->PF1, D3-->PF2, D4-->PF3,
	DDRF |= _BV(D1) | _BV(D2) | _BV(D3) | _BV(D4);
	
	PORTB &= ~(_BV(RCK) | _BV(SCK) | _BV(SI));
	PORTF |= _BV(D1) | _BV(D2) | _BV(D3) | _BV(D4);
}

/*******************************************************************************/
//Function to divide the number in 4 different digit
static uint16_t printint_1u(uint16_t value)
{
	uint16_t dig1, dig2, dig3, dig4;
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

/*******************************************************************************/
void display_printint_4s(uint16_t value)
{
	//Array to display
	int display[8];
	
	//Array for each number
	int numbers [11][8] = {
		{1,1,0,0,0,0,0,0},
		{1,1,1,1,1,0,0,1},
		{1,0,1,0,0,1,0,0},
		{1,0,1,1,0,0,0,0},
		{1,0,0,1,1,0,0,1},
		{1,0,0,1,0,0,1,0},
		{1,0,0,0,0,0,1,0},
		{1,1,1,1,1,0,0,0},
		{1,0,0,0,0,0,0,0},
		{1,0,0,1,0,0,0,0},
		{1,0,0,0,0,1,1,0}
	};
	
	//if there is more than 4 digit, print EEEE on the 7 segments, so row 11 of the array
	if (value>9999)
	{
		for (int i=0; i<8;i++)
		{
			display[i] = numbers[10][i];
		}
		PORTF &= ~(_BV(D1) | _BV(D2) | _BV(D3) | _BV(D4));
	}
	//else, print the number
	else
	{
		//save the number to display on the 4 digit
		uint16_t todisplay = printint_1u(value);

		//turn off all the digit
		PORTF |= _BV(D1) | _BV(D2) | _BV(D3) | _BV(D4);
		
		//create a table to know which segment to turn on
		for (int i=0; i<8;i++)
		{
			display[i] = numbers[todisplay][i];
		}
		
		// 4 if to not display the first digit if it's a 0, and for the second digit, if the first is 0 and the second too, don't display it, and same thing for digit 3
		if (digit==1)
		{
			if (todisplay==0)
			{
				digit++;
				firstvalue=1;
			}
			else
			{
				PORTF &= ~_BV(D1);
				digit++;
				firstvalue=0;
			}
		}
		else if (digit==2)
		{
			if (todisplay==0&&firstvalue==1)
			{
				digit++;
			}
			else
			{
				PORTF &= ~_BV(D2);
				digit++;
			}
		}
		else if (digit==3)
		{
			if (todisplay == 0&&firstvalue==1)
			{
				digit++;
			}
			else
			{
				PORTF &= ~_BV(D3);
				digit++;
			}
		}
		else if (digit == 4)
		{
			PORTF &= ~_BV(D4);
			digit=1;
			firstvalue=0;
		}
	}
	
	//turn off to be at 0
	PORTB &= ~_BV(RCK);

	//for loop to change the value on the register
	for(int i=0; i<8; i++)
	{
		if(display[i]==0)
		{
			PORTB &= ~_BV(SI);
		}
		else
		{
			PORTB |= _BV(SI);
		}
		//turn on and turn off each time to have the rising edge
		PORTB |= _BV(SCK);
		PORTB &= ~_BV(SCK);
	}
	PORTB |= _BV(RCK);	
}

/*******************************************************************************/
