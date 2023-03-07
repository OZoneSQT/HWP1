/*
 * pwm.c
 *
 * Created: 07/03/2023 20.24.45
 *  Author: skrue
 */ 

#define F_CPU	20000000

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

double _dutyCycle = 0;

void init_pwm(uint8_t dutyCycle)
{
	_dutyCycle = dutyCycle;
	DDRD = (1 << PORTD6);
	
	TCCR0A = (1 << COM0A1) | (1 << WGM00) | (1 << WGM01);
	TIMSK0 = (1 << TOIE0);
	
	OCR0A = (_dutyCycle/100.0)*255.0;
	
	sei();
	
	TCCR0B = (1 << CS00) | (1 << CS02);
	
	while(1)
	{
		//TODO:: Please write your application code
		_delay_ms(100);
		
		_dutyCycle += 10;
		
		if(_dutyCycle > 100)
		{
			_dutyCycle = 0;
		}
	}
}

ISR(TIMER0_OVF_vect)
{
	OCR0A = (_dutyCycle/100.0)*255;
}