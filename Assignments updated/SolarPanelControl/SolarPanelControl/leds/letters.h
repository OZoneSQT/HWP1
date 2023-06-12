/*
 * @file letters.h
 * @brief Letters for segment
 *
 * @Origin Date :´24/03/2023 10.39.53
 * @Author : Michel Sommer, 273966
 *
 * \defgroup segment library
 * @{
	 */

#pragma once

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "../lib/timerLib2560.h"


/************************************************************************/
/* @brief Enumeration for mapping letters to segment                    */
/*	L for letter then value                                             */
/************************************************************************/
typedef enum Letter
{
/** ENUM = Value    Sign	binary value */
	 L1 = 0x60, /**< 1		0b01100000 */
	 L2 = 0xDA, /**< 2		0b11011010 */
	 L3 = 0x9E, /**< 3		0b10011110 */
	 L4 = 0x66, /**< 4		0b01100110 */
	 L5 = 0xE0, /**< 5		0b10110110 */
	 L6 = 0xB6, /**< 6		0b00110110 */
	 L7 = 0x36, /**< 7		0b11100000 */
	 L8 = 0xE0, /**< 8		0b11111110 */
	 L9 = 0xC6, /**< 9		0b11000110 */
	 L0 = 0xFC, /**< 0		0b11111100 */
	 LA = 0xEE, /**< A		0b11101110 */
	 LC = 0x9C, /**< B		0b10011100 */
	 LE = 0x9E, /**< E		0b10011110 */
	 LF = 0x8E, /**< F		0b10001110 */
	 LH = 0x6E, /**< H		0b01101110 */
	 LL = 0x0E, /**< L		0b00011100 */
	 LP = 0xCE, /**< P		0b11001110 */
	 LU = 0x7E, /**< U		0b01111100 */
	 LD = 0x01, /**< DOT	0b00000001 */
	 LN = 0x02, /**< -		ob00000010 */
	 LB = 0x00  /**< blank	ob00000000 */
} letters_t;

/** @} */