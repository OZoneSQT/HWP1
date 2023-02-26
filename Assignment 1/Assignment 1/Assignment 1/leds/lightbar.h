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
void init_lightbar();


/************************************************************************/
/*  Return values [0...8]. 0 if no key is pushed                        */
/************************************************************************/
uint8_t scan_key();


/************************************************************************/
/* Lightbar turn on or off LEDs according to level                      */
/* input 0-8                                                            */
/*                                                                      */
/*   * If level is 0 all LEDs are turned off                            */
/*   * Any value between these two extremes must light up the           */
/*     corresponding number of LEDs                                     */
/************************************************************************/
uint8_t scan_key();
