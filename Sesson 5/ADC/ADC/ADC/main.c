/*
 * ADC.c
 *
 * Created: 10/03/2023 11.36.59
 * Author : skrue
 */ 

/**
	Example code that demonstrates how to make a 10-bit ADC measurement on the ATmega2560, triggered 
	by an interrupt on pin PD2, and display the result as an 8-bit value on PORTA:
	
	
	Explanation:

	1.	The volatile variable adc_value is declared to store the ADC measurement. It needs to be 
		volatile since it is modified inside an interrupt service routine.

	2.	The interrupt service routine ISR(INT0_vect) is triggered by the interrupt on PD2. 
		Inside the ISR, the ADCSRA register is set to start an ADC conversion.

	3.	The function adc_init() sets the voltage reference to an external capacitor on AREF, 
		enables the ADC, sets the prescaler to 16, and enables the interrupt on conversion complete.

	4.	The function port_init() sets PORTA pins as output.

	5.	In main(), port_init() and adc_init() are called, global interrupts are enabled with sei(), 
		PD2 is set as input and enabled with a pull-up resistor, and external interrupt INT0 is set 
		to trigger on falling edge of PD2.

	6.	Inside the infinite while loop in main(), the 10-bit ADC value is shifted to an 8-bit value 
		with uint8_t adc_result = (uint8_t)(adc_value >> 2), and then output to PORTA with 
		PORTA = adc_result. The shift is needed since PORTA is an 8-bit register and can only hold 
		values between 0 and 255.
 
 */
#define F_CPU 16000000

#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint16_t adc_value; // Volatile variable to store ADC measurement

ISR(INT0_vect) {
  ADCSRA |= (1 << ADSC); // Start ADC conversion
}

void adc_init() {
  ADMUX = (1 << REFS0); // Set external capacitor on AREF pin as voltage reference
  ADCSRA = (1 << ADEN) | (1 << ADIE) | (1 << ADPS2); // Enable ADC, interrupt on conversion complete, prescaler of 16
}

void port_init() {
  DDRA = 0xFF; // Set PORTA pins as output
}

int main() {
  port_init();
  adc_init();
  sei(); // Enable global interrupts
  DDRD &= ~(1 << PD2); // Set PD2 as input
  PORTD |= (1 << PD2); // Enable pull-up resistor on PD2
  EICRA |= (1 << ISC01); // Set interrupt on falling edge of PD2
  EIMSK |= (1 << INT0); // Enable external interrupt INT0 (PD2)
  
  while (1) {
    uint8_t adc_result = (uint8_t)(adc_value >> 2); // Shift 10-bit ADC value to 8-bit value
    PORTA = adc_result; // Output ADC value to PORTA
  }
}