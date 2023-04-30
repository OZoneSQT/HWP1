/*
 * @file segment.h
 * @brief Segment header file
 *
 * @Origin Date : 24/03/2023 10.54.15
 * @Author : Michel Sommer, 273966
 *
 * \defgroup segment library
 * @{
	 */

#pragma once

#include "letters.h"
#include "segment-hal.h"


/** Enumeration to set output */
typedef enum
{
	INT16_T,	/**< int16_t as printed data type */
	UINT16_T,	/**< uint16_t as printed data type */
	FLOAT		/**< float as printed data type */
} print_t;


/************************************************************************/
/* @brief Initialization of 7-segment display                           */
/*																		 */
/* @param[in] uint16_t refresh_ms										*/
/************************************************************************/
void segment_init(uint16_t refresh_ms);


/************************************************************************/
/* @brief Print float value to 7 segment display                        */
/*																		*/
/* @param[in] float value												*/
/* @param[in] print_t print format										*/
/* @param[in] uint8_t number of decimals								*/
/************************************************************************/
void segment_print(float value, print_t format, uint8_t decimals);


/************************************************************************/
/* @brief Prints value to 7 segment display                             */
/*																		*/
/* @param[in] letters_t value to segment1								*/
/* @param[in] letters_t value to segment2								*/
/* @param[in] letters_t value to segment3								*/
/* @param[in] letters_t value to segment4								*/
/************************************************************************/
void segment_print_letter(letters_t segment1, letters_t segment2, letters_t segment3, letters_t segment4);

/** @} */