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
 
 #define RCK PORTB0
 #define SCK PORTB1
 #define SI PORTB2
 
 #define D1 PORTF0
 #define D2 PORTF1
 #define D3 PORTF2
 #define D4 PORTF3