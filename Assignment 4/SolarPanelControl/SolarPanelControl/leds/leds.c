/*
 * leds.c
 *
 * Created: 30/04/2023 21.41.21
 *  Author: skrue
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
void lightbar_level(uint8_t level)
{
	uint8_t out = 0b00000000;
	
	if(level == 1) out = 0b00000001;
	if(level == 2) out = 0b00000011;
	if(level == 3) out = 0b00000111;
	if(level == 4) out = 0b00001111;
	if(level == 5) out = 0b00011111;
	if(level == 6) out = 0b00111111;
	if(level == 7) out = 0b01111111;
	if(level == 8) out = 0b11111111;
	
	PORTA = PORTA & ~out;
}

/*******************************************************************************/
