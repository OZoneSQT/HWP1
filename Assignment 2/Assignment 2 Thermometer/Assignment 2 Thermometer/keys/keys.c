/*
 * keys.c
 *
 * Created: 19/02/2023 10.37.05
 * Author: Michel Sommer, 273966
 */ 

#include "keys.h"


/*******************************************************************************/
void keys_init()
{
	DDRC = DDRC & 0b00111111;		//set pins 0 to 5 as input
	PORTC = PORTC |= 0b00111111;	//activates pull up resistors of PORTC
}

/*******************************************************************************/
void keys_isr_init()
{
	DDRD = DDRD & 0b00001100;		//set pins 2 to 3 as input
	PORTD = PORTD |= 0b00001100;	//activates pull up resistors of PORTD	
}

/*******************************************************************************/
uint8_t keys_get_state(uint8_t key_no)
{
	// if(key_no > 8 || key_no >= 0) return;
	
	--key_no;
	
	if (key_no <= 6)
	{
		return key(key_no);
	}
	else
	{
		return isrkey(key_no);
	}
}

/*******************************************************************************/
uint8_t key(uint8_t key_no)
{
	if (PINC & (1 << key_no))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*******************************************************************************/
uint8_t isrkey(uint8_t key_no)
{
	if (PIND & (1 << key_no))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*******************************************************************************/
void keys_isr_init_pd2()
{
    // Configure PD2 as an input
    DDRD &= ~(1 << PD2);

    // Enable pull-up resistor on PD2
    PORTD |= (1 << PD2);

    // Configure the interrupt sense control to trigger on the rising edge for INT2 (PD2)
    // ISC21 = 1, ISC20 = 1 for INT2 (PD2)
    EICRA |= (1 << ISC21) | (1 << ISC20);

    // Enable the external interrupt for INT2
    EIMSK |= (1 << INT2);

    // Enable global interrupts
    sei();
}

/*******************************************************************************/
void keys_isr_init_pd3()
{
    // Configure PD3 as an input
    DDRD &= ~(1 << PD3);

    // Enable pull-up resistor on PD3
    PORTD |= (1 << PD3);

    // Configure the interrupt sense control to trigger on the rising edge for INT3 (PD3)
    // ISC31 = 1, ISC30 = 1 for INT3 (PD3)
    EICRA |= (1 << ISC31) | (1 << ISC30);

    // Enable the external interrupt for INT3
    EIMSK |= (1 << INT3);

    // Enable global interrupts
    sei();
}

/*******************************************************************************/