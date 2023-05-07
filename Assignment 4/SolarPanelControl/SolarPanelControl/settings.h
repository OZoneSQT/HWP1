/*
 * @file settings.h
 *
 * @Origin Date :30/04/2023 21.53.02
 * @Author : Michel Sommer, 273966
 */ 

#pragma once

#include "lib/ioLib2560.h"
#include "lib/timerLib2560.h"
#include "lib/comLib2560.h"


#define F_CPU 16000000	// CPU CLK
#define ADCPIN A_PIN15	// ADC pin, thermometer
#define DELAY_S 1000	// ADC measurement interval
#define DELAY_MS 10		// Display refresh time

// SPI
#define USE_SPI 1			/** Use 1 or 0 */
#define SCLK_PIN PORTB1	/** clk */
#define MOSI_PIN PORTB2	/** Master Out, Slave In */
#define MISO_PIN PORTB3	/** Master In, Slave Out Note: Dummy */
 
// SPI Slave Select
#define SS_SHIFT_REGISTER PORTB0 /** Shift register */

// Define the pins for each of the 7-segment displays
#define D1_PIN D_PIN40
#define D2_PIN D_PIN41
#define D3_PIN D_PIN42
#define D4_PIN D_PIN43

// Define buttons
#define BTN1 D_PIN16 /**< temp low threshold */
#define BTN2 D_PIN17 /**< temp high threshold */
#define BTN3 D_PIN18 /**< numeric display to current temperature */

// Define LEDs
#define LED1 D_PIN0
#define LED2 D_PIN1
#define LED3 D_PIN2
#define LED4 D_PIN3
#define LED6 D_PIN6 /**< valve */
#define LED7 D_PIN7 /**< pump */