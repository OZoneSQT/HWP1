/*
 * main_32bit.c
 *
 * Created: 15/04/2023 15.23.06
 *  Author: skrue
 */ 

#define F_CPU = 16000000

#include <avr/io.h>
#include <util/delay.h>
#include "../timer-advanced.h"

volatile uint8_t timer1_overflow = 0;

void timer32_callback(void) 
{
	// Toggle an LED connected to PINB0
	PORTB ^= (1 << PORTB0);
}

ISR(TIMER1_OVF_vect) 
{
	if (timer1_overflow) 
	{
		timer32_callback();
	}
	timer1_overflow = !timer1_overflow;
}

ISR(TIMER3_OVF_vect) 
{
	// Handle Timer3 overflow for 32-bit timer
}

int main(void) 
{
	// Configure PINB0 as output
	DDRB |= (1 << DDB0);

	// Initialize Timer1 and Timer3 as a 32-bit timer with a 10000ms (10 seconds) period
	timer_init_32bit(10000);

	while (1) 
	{
		// Main loop
	}

	return 0;
}