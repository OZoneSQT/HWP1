/*
 * \file types.h
 *
 * \date : 28/04/2023 19.00.08
 * \author : Michel Sommer, 273966
 */ 

#pragma once

#ifndef F_CPU
#define F_CPU 16000000	// CLK
#endif /* F_CPU */

#include <avr/io.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>

// 16-bit timer options using enumeration
typedef enum {
	TIMER1, 
	TIMER2, 
	TIMER3, 
	TIMER4, 
	TIMER5
} Timer16Bit;


// PWM_PIN options using enumeration
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

