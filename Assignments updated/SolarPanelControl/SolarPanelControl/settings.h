/*
 * @file settings.h
 *
 * @Origin Date :30/04/2023 21.53.02
 * @Author : Michel Sommer, 273966
 */ 

#pragma once

#include "lib/def.h"
#include "lib/ioLib2560.h"
#include "lib/timerLib2560.h"
#include "lib/comLib2560.h"


#define F_CPU 16000000	// CPU CLK
#define ADCPIN A15		// ADC pin, thermometer
#define DELAY_S 1000	// ADC measurement interval
#define DELAY_MS 10		// Display refresh time

// SPI
#define USE_SPI 1		/** Use 1 or 0 */
#define SCLK_PIN D52	/** clk */
#define MOSI_PIN D51	/** Master Out, Slave In */
#define MISO_PIN D50	/** Master In, Slave Out Note: Dummy */
 
// SPI Slave Select
#define SS_SHIFT_REGISTER PORTB0 /** Shift register */

// Define the pins for each of the 7-segment displays
#define D1_PIN A8
#define D2_PIN A9
#define D3_PIN A10
#define D4_PIN A11

// Define buttons
#define BTN1 D37 /**< temp low threshold */
#define BTN2 D36 /**< temp high threshold */
#define BTN3 D35 /**< numeric display to current temperature */

// Define LEDs
#define LED1 D22
#define LED2 D23
#define LED3 D24
#define LED4 D25
#define LED6 D28 /**< valve */
#define LED7 D29 /**< pump */