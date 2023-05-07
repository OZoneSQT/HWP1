/*
 * leds.h
 *
 * Created: 30/04/2023 21.41.08

#pragma once

#include <avr/io.h>
#include <stdint.h>


/************************************************************************/
/* @brief Initialization of LEDs, on PORTA                              */
/************************************************************************/
void leds_init();


/************************************************************************/
/* @brief Set state of individual led, on PORTA                         */
/************************************************************************/
void leds_set(uint8_t led_no, uint8_t state);


/************************************************************************/
/*  Display level on PORTA [0...8]                                      */
/************************************************************************/
void lightbar_level(uint8_t level);


/************************************************************************/
/* @brief Call method to set leds state accordantly                     */
/*        to switch PC0 and PC1		                                    */
/*																		*/
/* MAP: LED 1 = PC0	=> AND												*/
/*		LED 2 = PC1	=> OR												*/
/*		LED 3 = PC2	=> XOR												*/
/*		LED 4 = PC3	=> NAND												*/
/*		LED 5 = PC4	=> NOR												*/
/*		LED 6 = PC5	=> XNOR												*/
/*																		*/
/************************************************************************/
void logic_set_operators(uint8_t inputA, uint8_t inputB);


/*******************************************************************************/
void logic_set_operators(uint8_t inputA, uint8_t inputB)
{
	// Bitwise operations
	uint8_t and = (inputA & inputB);
	uint8_t or = (inputA | inputB);
	uint8_t xor = (inputA ^ inputB);
	uint8_t nand = ~(inputA & inputB);
	uint8_t nor = ~(inputA | inputB);
	uint8_t xnor = ~(inputA ^ inputB);

	// value matcher
	if(nand >= 1) nand = 1;
	if(nor >= 1) nor = 1;
	if(xnor >= 1) xnor = 1;

	// Output
	PORTA = (and << PINA0) | (or << PINA1) | (xor << PINA2) | (nand << PINA3) | (nor << PINA4) | (xnor << PINA5);
}

/*******************************************************************************/
