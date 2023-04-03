/*
 * segment.h
 *
 * Created: 24/03/2023 10.54.15
 * Author: Michel Sommer, 273966
 */ 

#pragma once

#include "letters.h"
#include "segment-hal.h"


// Enumeration to set output
typedef enum
{
	INT16_T, UINT16_T, FLOAT
} print_t;


/************************************************************************/
/* @brief Initialization of 7-segment display                           */
/************************************************************************/
void segment_init(uint16_t refresh_ms);


/************************************************************************/
/* @brief Print float value to 7 segment display                        */
/************************************************************************/
void segment_print(float value, print_t format, uint8_t decimals);


/************************************************************************/
/* @brief Prints value to 7 segment display                             */
/************************************************************************/
void segment_print_letter(letters_t segment1, letters_t segment2, letters_t segment3, letters_t segment4);
