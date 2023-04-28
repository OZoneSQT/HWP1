/*
 * ioLib2560.h
 *
 * Created: 28/04/2023 20.02.01
 *  Author: skrue
 */ 

#pragma once

#include "data.h"

// Digital
void initOutputPin(Pin pin);
bool readPinStatus(Pin pin);

// Analog
void init8BitAnalogInput(AdcPin pin);
void init10BitAnalogInput(AdcPin pin);
uint16_t readAnalogPin(AdcPin pin);


/*
	// Pin Change Interrupt Request 0 ISR
	ISR(PCINT0_vect) {
		// Your interrupt code for PCINT0..7 pins goes here
	}

	// Pin Change Interrupt Request 1 ISR
	ISR(PCINT1_vect) {
		// Your interrupt code for PCINT8..15 pins goes here
	}

	// Pin Change Interrupt Request 2 ISR
	ISR(PCINT2_vect) {
		// Your interrupt code for PCINT16..23 pins goes here
	}
 */

// Int ISR
void initPinChangeInterrupt(PinChangeInterrupt pin);

/*
	// External Interrupt Request 0 ISR
	ISR(INT0_vect) {
		// Your interrupt code for INT0 goes here
	}

	// External Interrupt Request 1 ISR
	ISR(INT1_vect) {
		// Your interrupt code for INT1 goes here
	}

	// ... Add other interrupt request ISRs for INT2 to INT7
 */
// Ext ISR
void initExternalInterrupt(ExternalInterrupt interrupt, uint8_t trigger);
void initAnalogComparatorHigherInterrupt(AdcPin pin);
void initAnalogComparatorLowerInterrupt(AdcPin pin);

