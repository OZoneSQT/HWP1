/*
 * analog.c
 *
 * Created: 28/04/2023 19.59.13
 *  Author: skrue
 */ 

#include "ioLib2560.h"


void init8BitAnalogInput(AdcPin pin);
void init10BitAnalogInput(AdcPin pin);
uint16_t readAnalogPin(AdcPin pin);
void initAnalogComparatorHigherInterrupt(AdcPin pin);
void initAnalogComparatorLowerInterrupt(AdcPin pin);

/*
	int main() {
		// Example usage
		init10BitAnalogInput(ADC0);
		uint16_t value = readAnalogPin(ADC0);

		while (1) {
		}
		return 0;
	}
*/

void init8BitAnalogInput(AdcPin pin) {
	ADMUX |= (1 << ADLAR); // Left adjust ADC result for 8-bit resolution
	init10BitAnalogInput(pin);
}

void init10BitAnalogInput(AdcPin pin) {
	ADMUX &= ~(1 << ADLAR); // Right adjust ADC result for 10-bit resolution
	ADMUX = (ADMUX & 0xF0) | (pin & 0x0F); // Set the ADC channel
	ADMUX |= (1 << REFS0); // Set the reference voltage (AVcc with external capacitor at AREF pin)
	ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Enable ADC and set prescaler to 128
}

uint16_t readAnalogPin(AdcPin pin) {
	ADMUX = (ADMUX & 0xF0) | (pin & 0x0F); // Set the ADC channel
	ADCSRA |= (1 << ADSC); // Start ADC conversion

	while (ADCSRA & (1 << ADSC)); // Wait for conversion to complete

	if (ADMUX & (1 << ADLAR)) {
		return ADCH; // Return 8-bit value
		} else {
		return ADC; // Return 10-bit value
	}
}

void initAnalogComparatorHigherInterrupt(AdcPin pin) {
	initAnalogComparatorInterrupt(pin, false);
}

void initAnalogComparatorLowerInterrupt(AdcPin pin) {
	initAnalogComparatorInterrupt(pin, true);
}

void initAnalogComparatorInterrupt(AdcPin pin, bool lower) {
	// Configure the comparator
	ACSR &= ~(1 << ACIC); // Disable input capture

	if (lower) {
		ACSR &= ~(1 << ACIS1) & ~(1 << ACIS0); // Trigger on falling output edge
		} else {
		ACSR |= (1 << ACIS1) | (1 << ACIS0); // Trigger on rising output edge
	}

	ACSR |= (1 << ACIE); // Enable comparator interrupt

	// Connect the selected ADC pin to AIN1 (PD7)
	// Only ADC0 to ADC7 can be connected to AIN1
	if (pin >= ADC0 && pin <= ADC7) {
		DIDR1 |= (1 << (pin - ADC0)); // Disable digital input buffer for the selected ADC pin
		ADMUX = (ADMUX & 0xE0) | (pin & 0x07); // Set the ADC channel
		ADCSRB |= (1 << MUX5); // Set MUX5 to connect the selected ADC pin to AIN1
		} else {
		// The selected ADC pin cannot be connected to AIN1
		// Consider using an external multiplexer or modifying the code to support other pins
	}
}