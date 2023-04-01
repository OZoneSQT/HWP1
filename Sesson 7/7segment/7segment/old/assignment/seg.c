/*
 * seg.c
 *
 * Created: 31/03/2023 09.51.35
 *  Author: skrue
 */ 

#include "seg.h"

// Default number values
uint8_t digit_one = 0b11111111;
uint8_t digit_two = 0b11111111;
uint8_t digit_three = 0b11111111;
uint8_t digit_four = 0b11111111;

// Current number being shown on display
uint8_t current_number = 0;

// Simplify number selection array
uint8_t numbers_array[] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};

uint8_t use_spi = 0;

void init_display(uint8_t use_spi_mode)
{
	// RCK = PB0 - slave select (chip enable)
	// SCK = PB1 - Clock pin
	// SI  = PB2 - Master out slave in

	// Setup pins that give data to the shift register
	DDRB |= _BV(DDB0) | _BV(DDB1) | _BV(DDB2);

	// Disable the slave select to not interfere with other
	// SPI processes
	PORTB |= _BV(PB0);
	PORTB &= ~(_BV(PB1) | _BV(PB2));

	// Setup pins that control which segment is currently powered on
	DDRF |= _BV(DDF0) | _BV(DDF1) | _BV(DDF2) | _BV(DDF3);
	PORTF |= _BV(PF0) | _BV(PF1) | _BV(PF2) | _BV(PF3);

	// Setup interrupt to run at 100Hz
	OCR4A = 1249; // 100Hz
	// NEED THE LOWER BIT WRITE HERE
	TCCR4B |= _BV(WGM42);            // Mode CTC
	TCCR4B |= _BV(CS41) | _BV(CS40); // Prescaler 64
	TCCR4A |= _BV(COM4A0);           // Output compare match
	TIMSK4 |= _BV(OCIE4A);           // Turn on the interrupt

	use_spi = use_spi_mode;

	if(use_spi){
		// Set clock polarity and clock phase to:
		// base clock value is zero, sample on leading clock
		// Read on rising edge, change on falling edge
		SPCR &= ~ (_BV(CPOL) | _BV(CPHA));

		// Set from which bit the data is transfered form.
		// This is when SPI has the whole byte of data loaded into the register already
		// set bit means least significant bit.
		SPCR |= _BV(DORD);

		// Set this device as master
		SPCR |= _BV(MSTR);


		// These bits control the clock of SPI:
		// This combination leads to a frequency of:
		// 16Mhz/ 128 - not very fast
		SPCR |= _BV(SPR1) | _BV(SPR0);
		SPSR &= ~_BV(SPI2X); // This doubles the SPI speed in master. Set to off

		// Enable the SPI
		SPCR |= _BV(SPE);
	}
}

// Set segment numbers manually with macros
void set_segments(uint8_t numbers_new[4])
{
	digit_one = numbers_new[0];
	digit_two = numbers_new[1];
	digit_three = numbers_new[2];
	digit_four = numbers_new[3];
}

// Pass number and let it be parsed automaticaly
void set_number_4u(uint16_t number)
{
	if (number < 9999)
	{
		// Separate the number into digits
		digit_one = numbers_array[number / 1000];
		digit_two = numbers_array[(number % 1000) / 100];
		digit_three = numbers_array[(number % 100) / 10];
		digit_four = numbers_array[(number % 10) / 1];
	}
	else
	{
		digit_one = NINE;
		digit_two = NINE;
		digit_three = NINE;
		digit_four = NINE;
	}
}

// Transfer current number data to shift register
void print_segments()
{
	// Lets the number be chosen using index
	const uint8_t digits[] = {digit_one, digit_two, digit_three, digit_four};

	if(use_spi){
		// Select the salve
		PORTB &= ~(_BV(PB0));
		SPDR = digits[current_number];
		while(!(SPSR & (1<<SPIF)));

		// Deselct the salve
		PORTB |= _BV(PB0);

		}else{
		// Loop and upload one bit at a time to shift register
		for (uint8_t i = 0; i < 8; i++)
		{
			// Get the bit in index i
			uint8_t bitStatus = (digits[current_number] >> (i)) & 1;

			if (bitStatus)
			{
				PORTB |= _BV(PB2);
			}
			else
			{
				PORTB &= ~(_BV(PB2));
			}

			// Put the bit in the shift register buffer
			PORTB |= _BV(PB1);
			PORTB &= ~(_BV(PB1));
		}
		PORTB |= _BV(PB0);
		PORTB &= ~(_BV(PB0));

	}
	// Move data from the shift register's buffer to the active register

	
	// Turn on the transistor for this segment to show
	PORTF &= ~(_BV(current_number));
}

// Handle refresh of display
ISR(TIMER4_COMPA_vect)
{
	// Handle which segment to turn off
	PORTF |= _BV((current_number + 3) % 4);

	// Show one number. Based on current number value
	print_segments();

	// Go to the next segment in next interrupt
	current_number++;
	current_number = current_number % 4;
}