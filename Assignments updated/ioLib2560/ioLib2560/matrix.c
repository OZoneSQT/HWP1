/*
 * @file matrix.c
 *
 * @Origin Date :07/05/2023 10.30.42
 * @Author : Michel Sommer, 273966
 */

#include "ioLib2560.h"

#define NUM_ROWS 4
#define NUM_COLS 4

// Matrix pin configuration
uint16_t row_pins[NUM_ROWS];
uint16_t col_pins[NUM_COLS];

// Keymap for the matrix keyboard
char keymap[NUM_ROWS][NUM_COLS] = {
	{'1', '2', '3', 'A'},
	{'4', '5', '6', 'B'},
	{'7', '8', '9', 'C'},
	{'*', '0', '#', 'D'}
};

/************************************************************************/
void matrix_init(uint8_t row1, uint8_t row2, uint8_t row3, uint8_t row4, uint8_t col1, uint8_t col2, uint8_t col3, uint8_t col4) 
{
	row_pins[0] = row1;
	row_pins[1] = row2;
	row_pins[2] = row3;
	row_pins[3] = row4;
	col_pins[0] = col1;
	col_pins[1] = col2;
	col_pins[2] = col3;
	col_pins[3] = col4;

	// Configure row pins as output and set them high
	for (uint8_t i = 0; i < NUM_ROWS; i++) 
	{
		initOutputPin(row_pins[i]);
		setOutputPinHigh(row_pins[i]);
	}

	// Configure column pins as input and enable pull-up resistors
	for (uint8_t i = 0; i < NUM_COLS; i++) 
	{
		initInputPin(col_pins[i]);
	}
}

/************************************************************************/
// Scanning, using row scan method
char matrix_read() 
{
	char key = '\0';

	// Scan rows
	for (uint8_t row = 0; row < NUM_ROWS; row++) 
	{
		setOutputPinLow(row_pins[row]);

		// Check columns for a pressed key
		for (uint8_t col = 0; col < NUM_COLS; col++) 
		{
			if (readInputPinStatusDebounce(col_pins[col])) 
			{ // Key is pressed
				key = keymap[row][col];
				while (readInputPinStatus(col_pins[col])); // Wait for the key to be released
			}
		}

		setOutputPinHigh(row_pins[row]);
	}

	return key;
}

/************************************************************************/
