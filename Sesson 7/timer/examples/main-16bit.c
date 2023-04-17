/*
 * main_16bit.c
 *
 * Created: 15/04/2023 15.22.51
 *  Author: skrue
 */ 

#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>
#include "../timer-advanced.h"


void timer3_callback(void) 
{
	// Toggle an LED connected to PINB1
	PORTB ^= (1 << PORTB0);
}

ISR(TIMER3_OVF_vect) 
{
	timer3_callback();
}

int main(void) 
{
	// Configure PINB0 as output
	DDRB |= (1 << DDB0);

	// Initialize Timer3 as a 16-bit timer with a 1000ms period
	timer_init_16bit(1000, TIMER_3);

	while (1) 
	{
		// Main loop
	}

	return 0;
}