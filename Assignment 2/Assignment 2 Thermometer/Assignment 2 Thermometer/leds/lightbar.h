/*
 * lightbar.h
 *
 * Created: 26/02/2023 10.43.55
 * Author : Michel Sommer, 273966
 */ 

#pragma once

#include "../keys/keys.h"
#include <stdint.h>
#include <stdio.h>


/************************************************************************/
/* Initialization of leds, setting PORTA for PC0-PC7 as output 			*/
/************************************************************************/
void lightbar_init();


/************************************************************************/
/* Initialization of leds, setting PORTA for PC0-PC7 as output 			*/
/* and initialization of isr keys 		                            	*/
/************************************************************************/
void lightbar_isr_keys_init();


/************************************************************************/
/* Light bar turn on or off LEDs according to level                     */
/* input 0-8                                                            */
/*                                                                      */
/*   * If level is 0 all LEDs are turned off                            */
/*   * Any value between these two extremes must light up the           */
/*     corresponding number of LEDs                                     */
/************************************************************************/
void lightbar_scan_key();


/************************************************************************/
/*  Display level on PORTA [0...8]                                      */
/************************************************************************/
void lightbar_level(uint8_t level);
