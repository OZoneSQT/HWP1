/*
 * _16bitTimer.c
 *
 * Created: 07/03/2023 20.24.27
 *  Author: skrue
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>

void init_Timer_B()
{
	DDRA = 0x01;
	
	TCCR1B = (1 << WGM12);
	OCR1A = 19531;
	TIMSK1 = (1 << OCIE1A);
	
	sei();
	
	TCCR1B |= (1 << CS12) | (1 << CS10);
	
	while(1)
	{
		//TODO:: Please write your application code
	}
}

ISR(TIMER1_COMPA_vect)
{
	PORTA ^= (1 << PORTA0);
}