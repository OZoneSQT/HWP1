/*
 * timerExample.c
 *
 * Example on how to use Timer1 on an Atmega2560 microcontroller to create a delay 
 * of a specified duration using timer and interrupts. The delay duration is specified 
 * in milliseconds as a uint8_t value:
 *
 * Created: 10/03/2023 09.48.00
 *  Author: skrue
 */ 

/*
 * From sample interrupt code published by Noah Stahl on his blog, at:
 * http://arduinomega.blogspot.com/p/arduino-code.html
 * 
 */


/***
	Here's how the code works:

	The init_timer function sets up Timer1 to run in normal mode with a prescaler 
	of 256, and sets the timer compare value based on the desired delay duration.
	
	The start_delay function initializes the timer with the specified delay duration, 
	and starts it by setting the prescaler bits in TCCR1B.

	When the timer reaches the specified compare value, it triggers the Timer1 compare match 
	interrupt (TIMER1_COMPA_vect), which disables the timer and sets the delay_completed flag.
	
	In the main loop, the code repeatedly starts a delay of 1 second, waits for it to complete 
	using the delay_completed flag, and toggles the LED on PORTB0.

	Note that the exact values of the prescaler and compare value used in this example may need 
	to be adjusted for your specific use case, depending on the clock speed of your microcontroller 
	and the desired delay duration. You should consult the datasheet of your AVR microcontroller 
	to determine the correct prescaler and compare values for your specific application.
	
	Description:    The pre-scaler and the timer count divide the timer-counter
	clock frequency to give a timer overflow interrupt rate:


	Interrupt rate =  16 * 10^6 / (prescaler * (255 - TCNT2))

	TCCR1AB        Prescaler    Freq [KHz], Period [usec] after prescale
	0x0            (TC stopped)     0         0
	0x1                1        16000.        0.0625
	0x2                8         2000.        0.500
	0x3               32          500.        2.000
	0x4               64          250.        4.000
	0x5              128          125.        8.000
	0x6              256           62.5      16.000
	0x7             1024           15.625    64.000
	
	
	To calculate the prescaler value in an Atmega2560 timer, you first need to determine the clock frequency and the desired timer frequency.

	The clock frequency can be set in the Control Register (CLKPR) or through the fuses, and it is typically 16 MHz on an Atmega2560. The desired timer frequency will depend on the application and the desired delay.

	Once you have determined the clock frequency and the desired timer frequency, you can use the following formula to calculate the prescaler value:

	Prescaler Value = ceil(log2(Clock Frequency / (Timer Frequency * Timer Resolution))) - 1

	where Timer Resolution is the duration of each timer tick, which depends on the selected prescaler value.

	For example, if the clock frequency is 16 MHz and you want a timer frequency of 1 kHz (1 ms per tick), and you select a prescaler value of 1024, then the prescaler value would be:

	Prescaler Value = ceil(log2(16 MHz / (1 kHz * 1 ms))) - 1
	Prescaler Value = ceil(log2(16000)) - 1
	Prescaler Value = 13

	Therefore, you would set the prescaler value to 1024 in the timer control register.
*/

#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint8_t timer_count = 0;
volatile uint8_t delay_completed = 0;

void init_timer(void) {
	TCCR1A = 0x00;   // Timer1 normal mode
	TCCR1B = 0x0C;   // Timer1 prescaler set to 256
	OCR1A = 156 * (uint16_t)timer_count; // Timer1 compare value for specified delay duration
	TIMSK1 |= (1 << OCIE1A); // Enable Timer1 compare match interrupt
}

void start_delay(uint8_t delay_ms) {
	// Set the timer count and delay completion flag
	timer_count = delay_ms;
	delay_completed = 0;
	// Initialize the timer and start it
	init_timer();
	TCCR1B |= (1 << CS10) | (1 << CS12); // Start Timer1 with prescaler set to 256
}

ISR(TIMER1_COMPA_vect) {
	// Disable Timer1
	TCCR1B &= ~((1 << CS10) | (1 << CS11) | (1 << CS12));
	// Set the delay completion flag
	delay_completed = 1;
}

int main(void) {
	// Set PORTB0 as output for LED
	DDRB |= (1 << PB0);
	// Enable global interrupts
	sei();
	while (1) {
		// Start a delay of 1000ms (1s)
		start_delay(1000);
		// Wait for the delay to complete
		while (!delay_completed);
		// Toggle the LED on PORTB0
		PORTB ^= (1 << PB0);
	}
}