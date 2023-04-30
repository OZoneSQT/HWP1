/*
 * @file interrupt.c
 *
 * @Origin Date : 28/04/2023 20.00.58
 * @Author : Michel Sommer, 273966
 */ 

#include "ioLib2560.h"


/************************************************************************/
void initPinChangeInterrupt(PinChangeInterrupt pin) 
{
	if (pin >= PCINT0 && pin <= PCINT7) 
	{
		PCICR |= (1 << PCIE0); // Enable PCINT0..7
		PCMSK0 |= (1 << pin);  // Enable the specific pin
	} 
	else if (pin >= PCINT8 && pin <= PCINT15) 
	{
		PCICR |= (1 << PCIE1); // Enable PCINT8..15
		PCMSK1 |= (1 << (pin - PCINT8)); // Enable the specific pin
	} 
	else if (pin >= PCINT16) 
	{
		PCICR |= (1 << PCIE2); // Enable PCINT16..23
		PCMSK2 |= (1 << (pin - PCINT16)); // Enable the specific pin
	}
}


/************************************************************************/
void initExternalInterrupt(ExternalInterrupt interrupt, uint8_t trigger) 
{
	uint8_t eicr_num = interrupt / 4; // Determine the EICRA or EICRB register to use
	uint8_t eicr_shift = (interrupt % 4) * 2; // Determine the bit shift in the register

	// Configure the trigger
	if (eicr_num == 0) 
	{
		EICRA &= ~(0x03 << eicr_shift);
		EICRA |= (trigger << eicr_shift);
	} 
	else 
	{
		EICRB &= ~(0x03 << eicr_shift);
		EICRB |= (trigger << eicr_shift);
	}

	// Enable the external interrupt
	EIMSK |= (1 << interrupt);
}


/************************************************************************/
