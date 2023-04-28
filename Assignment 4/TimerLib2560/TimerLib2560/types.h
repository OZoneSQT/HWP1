/*
 * types.h
 *
 * Created: 28/04/2023 19.00.08
 *  Author: skrue
 */ 

#pragma once

#ifndef F_CPU
#define F_CPU 16000000	// CLK
#endif /* F_CPU */

typedef enum {
	TIMER1,
	TIMER2,
	TIMER3,
	TIMER4,
	TIMER5
} Timer16Bit;

typedef struct {
	Timer16Bit timer1;
	Timer16Bit timer2;
} Timer32Bit;


// Define the PWM_PIN enumeration type
typedef enum {
	OC3B, 
	OC3C, 
	OC4B, 
	OC4C, 
	OC2B, 
	OC1A, 
	OC1B, 
	OC2A, 
	OC4A, 
	OC5A, 
	OC5B, 
	OC5C, 
	OC1C, 
	OC3A, 
	OC4D
} PWM_PIN;

