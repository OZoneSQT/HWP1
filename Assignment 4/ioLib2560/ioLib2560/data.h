/*
 * data.h
 *
 * Created: 28/04/2023 19.58.58
 *  Author: skrue
 */ 

#pragma once

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <stdbool.h>

// Trigger configuration values
#define ISC_LOW_LEVEL 0
#define ISC_ANY_CHANGE 1
#define ISC_FALLING 2
#define ISC_RISING 3

typedef enum {
	PCINT0, PCINT1, PCINT2, PCINT3, PCINT4, PCINT5,
	PCINT6, PCINT7, PCINT8, PCINT9, PCINT10, PCINT11,
	PCINT12, PCINT13, PCINT14, PCINT15, PCINT16
} PinChangeInterrupt;


typedef struct {
	volatile uint8_t* ddr;
	volatile uint8_t* port;
	volatile uint8_t* pin;
	uint8_t bit;
} Pin;


typedef enum {
	INT0, INT1, INT2, INT3, INT4, INT5, INT6, INT7
} ExternalInterrupt;


typedef enum {
	ADC0, ADC1, ADC2, ADC3, ADC4, ADC5, ADC6, ADC7,
	ADC8, ADC9, ADC10, ADC11, ADC12, ADC13, ADC14, ADC15
} AdcPin;

