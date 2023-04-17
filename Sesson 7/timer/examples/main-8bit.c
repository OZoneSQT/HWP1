/*
 * main_8bit.c
 *
 * Created: 15/04/2023 15.22.41
 *  Author: skrue
 */ 

#define F_CPU = 16000000

#include <avr/io.h>
#include <util/delay.h>
"../timer-advanced.h"

void timer1_callback(void) 
{
	// Toggle an LED connected to PINB0
	PORTB ^= (1 << PORTB0);
}

ISR(TIMER1_OVF_vect) 
{
	timer1_callback();
}

int main(void) 
{
	// Configure PINB0 as output
	DDRB |= (1 << DDB0);

	// Initialize Timer1 as an 8-bit timer with a 500ms period
	timer_init_8bit(500);

	while (1) 
	{
		// Main loop
	}

	return 0;
}