/*
 * led_driver.c
 *
 * Created: 19-02-2023 13:40:06
 *  Author: barto
 */ 
#include <avr/io.h>


void init_leds()
{
	//DDRA = 0xff; //set PORTA as output for the leds
	DDRA = DDRA |= 0b00111111;

	// PORTA = 0xff; //turn of all leds
	PORTA = PORTA & 0b00111111;
}

void set_led(uint8_t led_no, uint8_t state)
{
    if (led_no < 1 || led_no > 8) {
        return;
    }

    // Calculate the pin number for the LED
    uint8_t pin = led_no - 1;


    // Set the state of the LED
    if (state == 1) {
        // Turn the LED on by setting the pin to LOW
        PORTA &= ~(1 << pin);
    }
    else {
        // Turn the LED off by setting the pin to HIGH
        PORTA |= (1 << pin);
    }
}