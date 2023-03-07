/*
 * _8bitTimer.c
 *
 * Created: 07/03/2023 20.24.06
 *  Author: skrue
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

int extraTime = 0;

void init_Timer_B()
{
	DDRA = 0x01;
	
	// TCNT0A – Timer/Counter Register A
	
	
	// TCCR0A – Timer/Counter Control Register A
	// WGM01:0: Waveform Generation Mode
	TCCR0A = (1 << WGM01); //Set CTC Bit
	
	// OCR0A – Output Compare Register A
	OCR0A = 195;
	
	// TIMSK0 – Timer/Counter Interrupt Mask Register
	// OCIE0A: Timer/Counter0 Output Compare Match A Interrupt Enable
	TIMSK0 = (1 << OCIE0A);
	
	sei();
	
	// TCCR0A – Timer/Counter Control Register A
	// CS02:0: Clock Select
	TCCR0A = (1 << CS02) | (1 << CS00); //start at 1024 prescalar
}

ISR(TIMER0_COMPA_vect)
{
	extraTime++;
	
	if(extraTime > 100)
	{
		extraTime = 0;
		PORTA ^= (1 << PORTA0);
	}
}