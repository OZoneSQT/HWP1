/*
 * @file settings.h
 * @brief Config header
 *
 * @Origin Date : 31/03/2023 09.28.53
 * @Author : Michel Sommer, 273966
 *
 * \defgroup host application
 * @{
	 */

 #pragma once
 
 #define F_CPU 16000000	// CLK
 
 #define ADCPIN ADC_15		// ADC pin, thermometer
 #define DELAY_S 1000		// ADC measurement interval
 #define DELAY_MS 10		// Display refresh time
 #define DECIMAL 1  		// Number of decimals in display
 #define TYPE FLOAT			// Set displayed type to float: UINT16_T, INT16_T, FLOAT

 // SPI
 #define USE_SPI 1			/** Use 1 or 0 */
 #define SCLK_PIN PORTB1	/** clk */
 #define MOSI_PIN PORTB2	/** Master Out, Slave In */
 #define MISO_PIN PORTB3	/** Master In, Slave Out Note: Dummy */
 
 // SPI Slave Select
 #define SS_SHIFT_REGISTER PORTB0 /** Shift register */

 // Define the pins for each of the 7-segment displays
 #define D1_PIN PORTF0
 #define D2_PIN PORTF1
 #define D3_PIN PORTF2
 #define D4_PIN PORTF3
 
 /** @} */