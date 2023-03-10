/*
 * counter.c
 *
 * Created: 10/03/2023 08.38.43
 *  Author: skrue
 */ 

#include "counter.h"

uint8_t run = 0;
uint8_t counter = 0x00;

void init_counter(uint8_t ms)
{
	DDRA |= 0xff;
	PORTA |= 0xff;
	init_delay_timer(ms);
}

void counter()
{
	while(run == 1)
	{
		counter++;
		delay();
	}
}

void start_counter()
{
	run = 1;
}

void reset_counter()
{
	counter = 0x00;
}

void pause_counter()
{
	run = 0;
}
