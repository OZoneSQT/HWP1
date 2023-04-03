/*
 * segment_hal.c
 *
 * Created: 03/04/2023 20.56.17
 * Author: Michel Sommer, 273966
 */

#include "segment-hal.h"


// Array to hold the output values for each of the 7-segment displays.
uint16_t segments[4] = {0, 0, 0, 0};
	
	
/************************************************************************/
/* 
 * Function to update the segments array with the desired values.
 * This function could take in the four values for each 7-segment display
 * and store them in the corresponding element of the segments array.
 */
static void updateSegments(uint16_t segment1, uint16_t segment2, uint16_t segment3, uint16_t segment4)
{
	segments[0] = segment1;
	segments[1] = segment2;
	segments[2] = segment3;
	segments[3] = segment4;
}
 
/************************************************************************/
/*
 * Function to shift out the data from the segments array using the M74HC595 shift register.
 * The function takes the segments array as a parameter
 */
static void shiftOutSegments(uint16_t segments[4])
{
	// Set RCK pin low
	PORTB &= ~(1 << RCK_PIN);

	// Loop through each segment in reverse order
	for (int i = 3; i >= 0; i--)
	{
		uint16_t segment = segments[i];

		// Shift out the two least significant bits of the segment value
		for (int j = 0; j < 2; j++)
		{
			// Shift out the next bit (starting with the least significant)
			if (segment & 0x01)
			{
				PORTB |= (1 << SI_PIN);
			}
			else
			{
				PORTB &= ~(1 << SI_PIN);
			}
			PORTB |= (1 << SCK_PIN);
			PORTB &= ~(1 << SCK_PIN);

			// Shift the segment value one bit to the right
			segment >>= 1;
		}

		// Shift out a high bit to turn off the blank LED
		PORTB &= ~(1 << SI_PIN);
		PORTB |= (1 << SCK_PIN);
		PORTB &= ~(1 << SCK_PIN);
	}

	// Set RCK pin high to latch the data into the shift register
	PORTB |= (1 << RCK_PIN);
}

/************************************************************************/
void segment_hal_off()
{
	// Turn off all displays
	PORTF |= (1 << D1_PIN);
	PORTF |= (1 << D2_PIN);
	PORTF |= (1 << D3_PIN);
	PORTF |= (1 << D4_PIN);
}

/************************************************************************/
void segment_hal_print(letters_t segment1, letters_t segment2, letters_t segment3, letters_t segment4)
{
	segment_hal_off();

	// Turn on the displays
	PORTF &= ~(1 << D1_PIN); // Display 1
	PORTF &= ~(1 << D2_PIN); // Display 2
	PORTF &= ~(1 << D3_PIN); // Display 3
	PORTF &= ~(1 << D4_PIN); // Display 4

	// Update the segments array with the desired values
	updateSegments(segment1, segment2, segment3, segment4);

	// Shift out the data from the segments array to the shift register
	shiftOutSegments(segments);	
}

/************************************************************************/
void segment_hal_init(uint16_t refresh_ms)
{
	// Initialize 8-bit timer
	timer_init_8bit(refresh_ms);
	
	// Initialize SPI ports
	DDRB |= (1 << RCK_PIN) | (1 << SCK_PIN) | (1 << SI_PIN);
	
	// Initialize multiplexing ports
	DDRF |= (1 << D1_PIN) | (1 << D2_PIN) | (1 << D3_PIN) | (1 << D4_PIN);
	
	// Enable global interrupts
	//sei();
}

/************************************************************************/
