/*
 * isrKeys.c
 *
 * Created: 10/03/2023 09.09.16
 *  Author: skrue
 */ 
#include "isrKeys.h"

void init_isr_keys()
{
	// Set PD2 and PD3 as input with pull-ups on pin 2 and 3
	DDRD &= ~(_BV(PD2) | _BV(PD3));
	PORTD |= _BV(PD2) | _BV(PD3);

	// Set Interrupt on falling edge
	EICRA |= _BV(ISC31) | _BV(ISC21);
	EIMSK |= _BV(INT3) | _BV(INT2);
}