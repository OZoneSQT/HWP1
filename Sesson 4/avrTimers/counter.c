/*
 * counter.c
 *
 * Created: 07/03/2023 21.24.28
 *  Author: skrue
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint8_t counter = 0;

void init_counter()
{
	// Set Port A as output and turn off LEDs
	DDRA = 0xFF;
	PORTA = 0xFF;

	// Set PD2 and PD3 as input with pull-ups on pin 2 and 3
	DDRD &= ~(_BV(PD2) | _BV(PD3));
	PORTD |= _BV(PD2) | _BV(PD3);

	// Set Interrupt on falling edge
	EICRA |= _BV(ISC31) | _BV(ISC21);
	EIMSK |= _BV(INT3) | _BV(INT2);

	// Clear counter
	counter = 0;
}

ISR(INT2_vect)
{
	PORTA = ~(++counter);

}

ISR(INT3_vect)
{
	PORTA = ~(--counter);
}