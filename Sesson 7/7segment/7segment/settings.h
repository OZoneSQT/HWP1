/*
 * settings.h
 *
 * Created: 31/03/2023 09.28.53
 * Author: Michel Sommer, 273966
 */

 #pragma once
 
 #define F_CPU 16000000	// CLK
 
 #define ADCPIN ADC_15		// ADC pin, thermometer
 #define DELAY_S 1000		// ADC measurement interval
 #define DELAY_MS 10		// Display refresh time
 #define DECIMAL 1  		// Number of decimals in display
 #define TYPE FLOAT			// Set displayed type to float: UINT16_T, INT16_T, FLOAT
 
 // Define the pins for RCK, SCK, and SI for the shift register
 #define RCK_PIN PORTB0
 #define SCK_PIN PORTB1
 #define SI_PIN PORTB2

 // Define the pins for each of the 7-segment displays
 #define D1_PIN PORTF0
 #define D2_PIN PORTF1
 #define D3_PIN PORTF2
 #define D4_PIN PORTF3