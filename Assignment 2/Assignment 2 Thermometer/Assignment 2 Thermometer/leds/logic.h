/*
 * logic.h
 *
 * Created: 19/02/2023 10.37.29
 * Author: Michel Sommer, 273966
 */ 

#pragma once

#include <avr/io.h>
#include <stdbool.h>
#include "leds.h"
#include "../keys/keys.h"


/************************************************************************/
/* @brief Macros for setting state of port                              */
/*        Example: setPortState(PORTB, PB0);                            */
/************************************************************************/
#define getPortState(port, bit) (port) & ( 1 << bit )
#define setPortState(port, bit) (port) |= ( 1 << bit )
#define clearPortState(port, bit) (port) &= ~( 1 << bit )
#define flipPortState(port, bit) (port) ^= ( 1 << bit )	


/************************************************************************/
/* @brief Initialization of keys, setting PORTC for PA0-PA5 as input 	*/
/************************************************************************/
void logic_indicator_leds();


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