/*
 * segment_display.h
 *
 * Created: 19/03/2023 11.01.23
 * Author: Michel Sommer, 273966
 */

#pragma once

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>


/************************************************************************/
/* @brief Initialization of y-segment display                           */
/************************************************************************/
void display_init();


/************************************************************************/
/* @brief Prints value to 7 segment display                             */
/************************************************************************/
void display_printint_4s(uint16_t value);
