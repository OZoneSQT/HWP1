/*
 * segment.h
 *
 * Created: 24/03/2023 10.54.15
 * Author: Michel Sommer, 273966
 */ 

#pragma once

#include "letters.h"


/************************************************************************/
/* @brief Initialization of 7-segment display                           */
/************************************************************************/
void segment_init(uint16_t refresh_ms);


/************************************************************************/
/* @brief Print unsigned int value to 7 segment display                 */
/************************************************************************/
void segment_print_uint(uint16_t value);


/************************************************************************/
/* @brief Print signed int value to 7 segment display                   */
/************************************************************************/
void segment_print_int(int16_t value);


/************************************************************************/
/* @brief Print float value to 7 segment display                        */
/************************************************************************/
void segment_print_float(float value, uint8_t decimals);


/************************************************************************/
/* @brief Prints value to 7 segment display                             */
/************************************************************************/
void segment_print_letter(letters_t letter, uint8_t position);