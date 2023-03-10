/*
 * Stopwatch.c
 *
 * Created: 10/03/2023 08.37.28
 * Author : skrue
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include "isrKeys.h"

#define F_CPU 16000000

uint8_t delay_ms = 6000;	// 1 sec;
uint8_t running = 0;

void setup()
{
	init_isr_keys();
	init_stopwatch(delay_ms);
}

int main(void)
{
	setup();
	sei();	//init interrupt
	
    while (1) 
    {
    }
}

ISR(INT2_vect)
{
	start_stopwatch();
	running = 1;
}

ISR(INT3_vect)
{
	if(running == 1)
	{
		pause_stopwatch();
		running = 0;
	}
	else
	{
		reset_stopwatch();
		running = 1;
	}
}
