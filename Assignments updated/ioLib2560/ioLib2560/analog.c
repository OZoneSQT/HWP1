/*
 * @file analog.c
 *
 * @Origin Date : 28/04/2023 19.59.13
 * @Author : Michel Sommer, 273966
 */ 

#include "ioLib2560.h"

uint16_t adc_values[16] = {0};


/************************************************************************/
void initAnalogInputPin(uint8_t pin, uint8_t bits) 
{
	ADMUX |= (1 << REFS0); // Set reference voltage to AVCC
	ADCSRA |= (1 << ADEN) | (1 << ADIE) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Enable ADC and ADC interrupt, set prescaler to 128
	if (bits == 8) 
	{
		ADMUX |= (1 << ADLAR); // Left adjust result for 8-bit value
	} 
	else 
	{
		ADMUX &= ~(1 << ADLAR); // Right adjust result for 10-bit value
	}
	ADMUX = (ADMUX & 0xF0) | (pin & 0x0F); // Select ADC channel
	ADCSRA |= (1 << ADSC); // Start ADC conversion
}

/************************************************************************/
void init8BitAnalogInputPin(uint8_t pin) 
{
	initAnalogInputPin(pin, 8);
}

/************************************************************************/
void init10BitAnalogInputPin(uint8_t pin) 
{
	initAnalogInputPin(pin, 10);
}

/************************************************************************/
uint16_t readAnalogPin(uint8_t pin) 
{
	ADMUX = (ADMUX & 0xF0) | (pin & 0x0F); // Set the ADC channel
	ADCSRA |= (1 << ADSC); // Start ADC conversion

	while (ADCSRA & (1 << ADSC)); // Wait for conversion to complete

	if (ADMUX & (1 << ADLAR)) 
	{
		return ADCH; // Return 8-bit value
	} 
	else 
	{
		return ADC; // Return 10-bit value
	}
}

/************************************************************************/
uint16_t readAnalogPinUint(uint8_t pin) 
{
	return adc_values[pin];
}

/************************************************************************/
int16_t readAnalogPinSint(uint8_t pin) 
{
	return (int16_t)adc_values[pin];
}

/************************************************************************/
float readAnalogPinFloat(uint8_t pin) 
{
	return (adc_values[pin] * REF_VOLTAGE) / ((ADMUX & (1 << ADLAR)) ? 256.0 : 1024.0);
}

/************************************************************************/
// Interrupt Service Routine (ISR) for ADC conversion complete
ISR(ADC_vect) 
{
	uint8_t pin = ADMUX & 0x0F;
	if (ADMUX & (1 << ADLAR)) 
	{
		adc_values[pin] = ADCH;
		} 
		else 
		{
		adc_values[pin] = ADC;
	}
	ADCSRA |= (1 << ADSC); // Start next ADC conversion
}

/************************************************************************/
void initAnalogComparatorHigherInterrupt(uint8_t pin) 
{
	ACSR |= (1 << ACBG); // Use internal voltage reference as threshold
	ADMUX = (ADMUX & 0xF0) | (pin & 0x0F); // Select ADC channel for AIN1

	ACSR &= ~(1 << ACIE); // Disable interrupt while configuring
	ACSR &= ~(1 << ACIC); // Disable input capture

	ACSR &= ~(1 << ACIS1) & ~(1 << ACIS0); // Set interrupt trigger to rising edge
	ACSR |= (1 << ACIE); // Enable interrupt
}

/************************************************************************/
void initAnalogComparatorLowerInterrupt(uint8_t pin) 
{
	ACSR |= (1 << ACBG); // Use internal voltage reference as threshold
	ADMUX = (ADMUX & 0xF0) | (pin & 0x0F); // Select ADC channel for AIN1

	ACSR &= ~(1 << ACIE); // Disable interrupt while configuring
	ACSR &= ~(1 << ACIC); // Disable input capture

	ACSR &= ~(1 << ACIS1); // Set interrupt trigger to falling edge
	ACSR |= (1 << ACIS0);

	ACSR |= (1 << ACIE); // Enable interrupt
}

/************************************************************************/
