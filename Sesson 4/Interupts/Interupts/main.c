/*
 * Interupts.c
 *
 * Created: 03/03/2023 10.05.00
 * Author : skrue
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void init_interupt(){
	// Set PD2 (INT2) to input
	DDRD &= ~_BV(DDD2);
	PORTD |= _BV(PD2);

/*	
	// 00 - Set INT2 to interrupt on LOW level of pin
	EICRA &= ~_BV(ISC20);
	EICRA &= ~_BV(ISC21);
*/

/*	
	// 01 - Set INT2 to interrupt on level change (failing edge and rising edge)
	EICRA |= _BV(ISC20);
	EICRA &= ~_BV(ISC21);
*/

/*
	// 10 - Set INT2 to interrupt on change to low level (failing edge)
	EICRA &= ~_BV(ISC20);
	EICRA |= ~_BV(ISC21);
*/
	
	// 11 - Set INT2 to interrupt on change to high level (rising edge)
	EICRA &= ~_BV(ISC20);
	EICRA &= ~_BV(ISC21);
	

	// Enable INT2 in the External interrupt register
	EIMSK |= _BV(INT2);
}

void init_counter()
{
	DDRA = 0xFF;
	PORTA = 0xFF;
}

// Reset Counter
ISR(INT2_vect) 
{
	init_counter();
}

void counter()
{
	
	while (1)
	{
		PORTA++;
		_delay_ms(1000);
	}
}

int main(void)
{
	init_interupt();
	init_counter();
	
	sei();	// Init external interrupts (Sets I-flag))
	
    while (1) 
    {
		counter();
    }
}



