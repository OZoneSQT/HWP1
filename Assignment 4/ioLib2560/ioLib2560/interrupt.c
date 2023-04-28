/*
 * interrupt.c
 *
 * Created: 28/04/2023 20.00.58
 *  Author: skrue
 */ 

#include "ioLib2560.h"

void initExternalInterrupt(ExternalInterrupt interrupt, uint8_t trigger);
void initPinChangeInterrupt(PinChangeInterrupt pin);


/*
	int main() {
		// Example usage
		initPinChangeInterrupt(PCINT2);
		initExternalInterrupt(INT1, ISC_FALLING); // Trigger on falling edge

		sei(); // Enable global interrupts

		while (1) {
		}
		return 0;
	}
*/

void initPinChangeInterrupt(PinChangeInterrupt pin) {
	if (pin >= PCINT0 && pin <= PCINT7) {
		PCICR |= (1 << PCIE0); // Enable PCINT0..7
		PCMSK0 |= (1 << pin);  // Enable the specific pin
		} else if (pin >= PCINT8 && pin <= PCINT15) {
		PCICR |= (1 << PCIE1); // Enable PCINT8..15
		PCMSK1 |= (1 << (pin - PCINT8)); // Enable the specific pin
		} else if (pin >= PCINT16) {
		PCICR |= (1 << PCIE2); // Enable PCINT16..23
		PCMSK2 |= (1 << (pin - PCINT16)); // Enable the specific pin
	}
}

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



void initExternalInterrupt(ExternalInterrupt interrupt, uint8_t trigger) {
	uint8_t eicr_num = interrupt / 4; // Determine the EICRA or EICRB register to use
	uint8_t eicr_shift = (interrupt % 4) * 2; // Determine the bit shift in the register

	// Configure the trigger
	if (eicr_num == 0) {
		EICRA &= ~(0x03 << eicr_shift);
		EICRA |= (trigger << eicr_shift);
		} else {
		EICRB &= ~(0x03 << eicr_shift);
		EICRB |= (trigger << eicr_shift);
	}

	// Enable the external interrupt
	EIMSK |= (1 << interrupt);
}

// External Interrupt Request 0 ISR
ISR(INT0_vect) {
	// Your interrupt code for INT0 goes here
}

// External Interrupt Request 1 ISR
ISR(INT1_vect) {
	// Your interrupt code for INT1 goes here
}

// ... Add other interrupt request ISRs for INT2 to INT7