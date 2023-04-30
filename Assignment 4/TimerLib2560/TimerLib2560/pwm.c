/*
 * @file pwm.c
 *
 * @Origin Date : 28/04/2023 19.04.39
 * @Author : Michel Sommer, 273966
 */ 

#include "timerLib2560.h"


/*******************************************************************************/
// Function to initialize PWM using a 16-bit timer
static void init_pwm(PWM_PIN pin, uint8_t percentage, uint16_t pulse_length_ms)
{
	uint16_t top_value = (F_CPU / 1000) * pulse_length_ms / 8; // Calculate TOP value for the 16-bit timer, assuming a prescaler of 8
	uint16_t compare_value = (top_value * percentage) / 100; // Calculate the compare value for the specified duty cycle percentage

	// Configure the 16-bit timer and PWM pin
	switch (pin)
	{
		case OC1A:
		case OC1B:
		case OC1C:
		// Configure Timer/Counter1 for Fast PWM mode and set the prescaler to 8
		TCCR1A = (1 << WGM11) | (1 << WGM10);
		TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS11);

		// Set TOP value for Timer/Counter1
		ICR1 = top_value;

		// Set the compare value for the specified duty cycle percentage
		if (pin == OC1A)
		{
			OCR1A = compare_value;
			TCCR1A |= (1 << COM1A1); // Enable PWM on OC1A
		}
		else if (pin == OC1B)
		{
			OCR1B = compare_value;
			TCCR1A |= (1 << COM1B1); // Enable PWM on OC1B
		}
		else
		{ // OC1C
			OCR1C = compare_value;
			TCCR1A |= (1 << COM1C1); // Enable PWM on OC1C
		}

		// Configure the corresponding pin as output
		DDRB |= (1 << (pin - OC1A + DDB5));
		break;

		case OC3A:
		case OC3B:
		case OC3C:
		// Configure Timer/Counter3 for Fast PWM mode and set the prescaler to 8
		TCCR3A = (1 << WGM31) | (1 << WGM30);
		TCCR3B = (1 << WGM33) | (1 << WGM32) | (1 << CS31);

		// Set TOP value for Timer/Counter3
		ICR3 = top_value;

		// Set the compare value for the specified duty cycle percentage
		if (pin == OC3A)
		{
			OCR3A = compare_value;
			TCCR3A |= (1 << COM3A1); // Enable PWM on OC3A
		}
		else if (pin == OC3B)
		{
			OCR3B = compare_value;
			TCCR3A |= (1 << COM3B1); // Enable PWM on OC3B
		}
		else
		{ // OC3C
			OCR3C = compare_value;
			TCCR3A |= (1 << COM3C1); // Enable PWM on OC3C
		}

		// Configure the corresponding pin as output
		if (pin == OC3A)
		{
			DDRE |= (1 << DDE3);
		}
		else if (pin == OC3B)
		{
			DDRE |= (1 << DDE4);
		}
		else
		{ // OC3C
			DDRE |= (1 << DDE5);
		}
		break;

		case OC4A:
		case OC4B:
		case OC4C:
		// Configure Timer/Counter4 for Fast PWM mode and set the prescaler to 8
		TCCR4A = (1 << WGM41) | (1 << WGM40);
		TCCR4B = (1 << WGM43) | (1 << WGM42) | (1 << CS41);

		// Set TOP value for Timer/Counter4
		ICR4 = top_value;

		// Set the compare value for the specified duty cycle percentage
		if (pin == OC4A)
		{
			OCR4A = compare_value;
			TCCR4A |= (1 << COM4A1); // Enable PWM on OC4A
		}
		else if (pin == OC4B)
		{
			OCR4B = compare_value;
			TCCR4A |= (1 << COM4B1); // Enable PWM on OC4B
		}
		else
		{ // OC4C
			OCR4C = compare_value;
			TCCR4A |= (1 << COM4C1); // Enable PWM on OC4C
		}

		// Configure the corresponding pin as output
		if (pin == OC4A)
		{
			DDRH |= (1 << DDH3);
		}
		else if (pin == OC4B)
		{
			DDRH |= (1 << DDH4);
		}
		else
		{ // OC4C
			DDRH |= (1 << DDH5);
		}
		break;

		case OC5A:
		case OC5B:
		case OC5C:
		// Configure Timer/Counter5 for Fast PWM mode and set the prescaler to 8
		TCCR5A = (1 << WGM51) | (1 << WGM50);
		TCCR5B = (1 << WGM53) | (1 << WGM52) | (1 << CS51);

		// Set TOP value for Timer/Counter5
		ICR5 = top_value;

		// Set the compare value for the specified duty cycle percentage
		if (pin == OC5A)
		{
			OCR5A = compare_value;
			TCCR5A |= (1 << COM5A1); // Enable PWM on OC5A
		}
		else if (pin == OC5B)
		{
			OCR5B = compare_value;
			TCCR5A |= (1 << COM5B1); // Enable PWM on OC5B
		}
		else
		{ // OC5C
			OCR5C = compare_value;
			TCCR5A |= (1 << COM5C1); // Enable PWM on OC5C
		}

		// Configure the corresponding pin as output
		if (pin == OC5A)
		{
			DDRL |= (1 << DDL3);
		}
		else if (pin == OC5B)
		{
			DDRL |= (1 << DDL4);
		}
		else
		{ // OC5C
			DDRL |= (1 << DDL5);
		}
		break;

		default:
		
		// Unsupported PWM pin - do nothing
		break;
	}
}

/*******************************************************************************/
void pwm_pulse(PWM_PIN pin, uint8_t percentage) 
{
	init_pwm(pin, percentage, 20);
}

/*******************************************************************************/
void pwm_percentage(PWM_PIN pin, uint16_t pulse_length_ms)
{
	init_pwm(pin, 100, pulse_length_ms);
}

/*******************************************************************************/
void pwm_percentage_pulselength(PWM_PIN pin, uint8_t percentage, uint16_t pulse_length_ms)
{
	init_pwm(pin, percentage, pulse_length_ms);
}

/*******************************************************************************/
void pwm_stop(PWM_PIN pin) 
{
	// Disable PWM and set the output pin to LOW
	switch (pin)
	{
		case OC1A:
		TCCR1A &= ~(1 << COM1A1);
		PORTB &= ~(1 << (pin - OC1A + DDB5));
		break;
		case OC1B:
		TCCR1A &= ~(1 << COM1B1);
		PORTB &= ~(1 << (pin - OC1A + DDB5));
		break;
		case OC1C:
		TCCR1A &= ~(1 << COM1C1);
		PORTB &= ~(1 << (pin - OC1A + DDB5));
		break;
		case OC3A:
		TCCR3A &= ~(1 << COM3A1);
		PORTE &= ~(1 << DDE3);
		break;
		case OC3B:
		TCCR3A &= ~(1 << COM3B1);
		PORTE &= ~(1 << DDE4);
		break;
		case OC3C:
		TCCR3A &= ~(1 << COM3C1);
		PORTE &= ~(1 << DDE5);
		break;
		case OC4A:
		TCCR4A &= ~(1 << COM4A1);
		PORTH &= ~(1 << DDH3);
		break;
		case OC4B:
		TCCR4A &= ~(1 << COM4B1);
		PORTH &= ~(1 << DDH4);
		break;
		case OC4C:
		TCCR4A &= ~(1 << COM4C1);
		PORTH &= ~(1 << DDH5);
		break;
		case OC5A:
		TCCR5A &= ~(1 << COM5A1);
		PORTL &= ~(1 << DDL3);
		break;
		case OC5B:
		TCCR5A &= ~(1 << COM5B1);
		PORTL &= ~(1 << DDL4);
		break;
		case OC5C:
		TCCR5A &= ~(1 << COM5C1);
		PORTL &= ~(1 << DDL5);
		break;
		default:
		// Unsupported PWM pin - do nothing
		break;
	}
}

/*******************************************************************************/
