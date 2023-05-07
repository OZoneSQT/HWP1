/*
 * TestBuild.c
 *
 * Created: 10/02/2023 10.13.33
 * Author : skruen
 */ 

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRB |= (1 << PB7);		// Sets pin as output
	//PORTB &= ~(1 << PB7);	// Sets pin low
    
    while (1) 
    {
		
		PORTB |= (1 << PB7);	// Sets pin high
		_delay_ms(1000);
		
		// PORTB &= ~(1 << PB7);	// Sets pin low
		PORTB &= (0 << PB7);	// Sets pin low
		_delay_ms(500);
		
    }
}

