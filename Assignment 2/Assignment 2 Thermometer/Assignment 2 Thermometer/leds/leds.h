/*
 * leds.h
 *
 * Created: 19/03/2023 11.17.25
 * Author : Michel Sommer, 273966
 */

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
