/*
 * leds.c
 *
 * Created: 19/03/2023 11.17.55
 * Author : Michel Sommer, 273966
 */

#include "leds.h"


/*******************************************************************************/
void leds_init()
{
	//DDRA = 0xff; //set PORTA as output for the leds
	DDRA = DDRA |= 0b00111111;

	// PORTA = 0xff; //turn of all leds
	PORTA = PORTA & 0b00111111;
}

/*******************************************************************************/
void leds_set(uint8_t led_no, uint8_t state)
{
	
	if (led_no < 1 || led_no > 6) {
		return;
	}

	// Calculate the pin number for the LED
	uint8_t pin = led_no - 1;


	// Set the state of the LED
	if (state == 0) {
		// Turn the LED on by setting the pin to LOW
		PORTA &= ~(1 << pin);
	}
	else {
		// Turn the LED off by setting the pin to HIGH
		PORTA |= (1 << pin);
	}
}

/*******************************************************************************/