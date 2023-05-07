/*
 * key.c
 *
 * Created: 21/03/2023 20.39.52
 * Author: Michel Sommer, 273966
 */

 #include "key.h"


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

}

/*******************************************************************************/
