/*
 * leds.c
 *
 * Created: 30/04/2023 21.41.21
 *  Author: skrue
 */ 


#include <avr/io.h>

void inits_leds() {
	DDRA = 0xFF;
	PORTA = 0xFF;
}

void set_led(uint8_t led_no, uint8_t state) {
	if (state == 1) {
		PORTA &= ~(1 << led_no-1);
	}
	else if (state == 0) {
		PORTA |= 1 << led_no-1;
	}
}