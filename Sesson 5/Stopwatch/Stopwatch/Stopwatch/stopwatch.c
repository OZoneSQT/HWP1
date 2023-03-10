/*
 * stopwatch.c
 *
 * Created: 10/03/2023 08.39.00
 *  Author: skrue
 */ 

#include "stopwatch.h"

uint8_t run = 0;
uint8_t counter = 0x00;

void init_stopwatch(uint8_t ms)
{
	DDRA |= 0xff;
	PORTA |= 0xff;
	init_delay_timer(ms);
	stopwatch();
}

void stopwatch()
{
	while(run == 1)
	{
		counter++;
		delay();
	}
}

void start_stopwatch()
{
	run = 1;
}

void reset_stopwatch()
{
	counter = 0x00;
}

void pause_stopwatch()
{
	run = 0;
}