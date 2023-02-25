/*
 * IOtest.c
 *
 * Created: 24/02/2023 09.23.08
 * Author : skrue
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	
	while(1)
	{
		//eksample();
		buttonLed();
		//counter();
    }
	return 0;
}

void buttonLed()
{
	DDRC = DDRC & 0x00;		// Input
	PORTC |= 0xFF;			// PUD
	DDRD = DDRD & 0x00;		// Input
	PORTD |= 0xFF;			// PUD
	DDRA = DDRA | 0xFF;		// Output

			
	while (1)
	{
		if((PINC & 0b11111110) != 0)
		{
			 PORTA = 0x01;
		}
		if((PINC & 0b11111101) != 0)
		{
			 PORTA = 0x02;
		}
		if((PINC & 0b11111011) != 0)
		{
			 PORTA = 0x03;
		}
		if((PINC & 0b11110111) != 0)
		{
			 PORTA = 0x04;
		}
		if((PINC & 0b11101111) != 0)
		{
			 PORTA = 0x05;
		}
		if((PINC & 0b11011111) != 0)
		{
			 PORTA = 0x06;
		}
		if((PIND & 0b11111101) != 0)
		{
			 PORTA = 0x07;
		}
		if((PIND & 0b11111011) != 0)
		{
			 PORTA = 0x08;
		}
		else
		{
			PORTA = 0xFF;
		}
	}
}

void counter()
{
	DDRA = 0xFF;
	PORTA = 0xFF;
	
	while (1)
	{
		PORTA++;
		_delay_ms(1000);
	}
}

void eksample(){
	DDRC = DDRC & 0b11111101;	
	PORTC |= 0b00000010; 		
	DDRA = DDRA | 0b10000000;			
	
	while(1)
	{
		if((PINC & 0b00000010) != 0)		
			PORTA = PORTA | 0b10000000;	
		else
			PORTA = PORTA & 0b01111111;	
    }
}

