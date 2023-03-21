/*
 * timer.h
 *
 * Created: 21/03/2023 20.57.03
 * Author: Michel Sommer, 273966
 */

#pragma once

#include "../settings.h"
#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>


// Enumeration to limit input options
typedef enum 
{
	TIMER_1 = 1, TIMER_3 = 3
} timer_t; 

/*
 *  Interrupt service routines:
 *	ISR(TIMER1_COMPA_vect) { } Timer1 - 16 bit timer
 *	ISR(TIMER2_COMPA_vect) { } Timer2 - 8 bit timer
 *	ISR(TIMER3_COMPA_vect) { } Timer3 - 16 bit timer
 *
 *	Note:	that Timer2 is an 8-bit timer and can only count up to
 *			255, so the maximum time you can set is about 16ms with
 *			a prescaler of 1024. If you need longer times, you
 *			will need to use a 16-bit timer like Timer1 or Timer3.
 */


/************************************************************************/
/* @brief Initialization 16 bit timers                                  */
/*        Options: Timer1, or Timer3, with time in ms                   */
/************************************************************************/
void timer_init_16bit(uint8_t time_ms,timer_t timer_number);


/************************************************************************/
/* @brief Initialization 8 bit Timer2, with time in ms                  */
/************************************************************************/
void timer_init_8bit(uint8_t time_ms);
