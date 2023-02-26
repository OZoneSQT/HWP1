/*
 * keys.h
 *
 * Created: 19/02/2023 10.37.17
 * Author: Michel Sommer, 273966
 */ 

#pragma once

#include <avr/io.h>

/************************************************************************/
/* Initialization of keys, setting PORTC for PC0-PC5 as input 			*/
/************************************************************************/
void init_keys();


/************************************************************************/
/* Initialization of isr keys, setting PORTD for PD2-PD3 as input 		*/
/************************************************************************/
void init_isrKeys();


/************************************************************************/
/* key_no [1..6], return true if key pressed							*/
/* Allowed keys: PC0-PC5, PD2-PD3                                       */
/************************************************************************/
uint8_t get_key(uint8_t key_no); 