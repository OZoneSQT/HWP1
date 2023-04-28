/*
 * @file timer.h
 * @brief Header for internal timer functions
 *
 * @Origin Date : 31/03/2023 09.25.00
 * @Author : Michel Sommer, 273966
 *
 * \defgroup timer library
 * @{
	 */

 #pragma once

 #include "settings.h"
 #include <stdint.h>
 #include <avr/io.h>
 #include <avr/interrupt.h>


 /** Enumeration to limit input options */
 typedef enum 
 {
	TIMER_1 = 1, /**< 16-bit TIMER1 */
	TIMER_3 = 3  /**< 16-bit TIMER3 */
 } timer_t; 

/************************************************************************/
/*  @brief Interrupt service routines examples:							*/
/*		ISR(TIMER1_COMPA_vect) { TOV1 |= 1 } Timer1 - 16-bit timer		*/
/*		ISR(TIMER2_COMPA_vect) { TOV2 |= 1 } Timer2 - 8-bit timer		*/
/*		ISR(TIMER3_COMPA_vect) { TOV3 |= 1 } Timer3 - 16-bit timer		*/
/*		ISR(TIMER3_COMPA_vect) { TOV3 |= 1 } Timer3 - 32-bit timer		*/
/*																		*/
/*	Note:	that Timer2 is an 8-bit timer and can only count up to		*/
/*			255, so the maximum time you can set is about 16ms with		*/
/*			a prescaler of 1024. If you need longer times, you			*/
/*			will need to use a 16-bit timer like Timer1 or Timer3.		*/
/************************************************************************/


/************************************************************************/
/* @brief Initialization 32 bit with time in ms							*/
/*	Initializes the 16 bit timers: Timer1 and Timer3					*/
/*	The maximum	of the 32-bit timer	is approximately 137.4 hours		*/
/*																		*/
/* @param[in] uint32_t time in ms										*/
/************************************************************************/
void timer_init_32bit(uint32_t time_ms);


/************************************************************************/
/* @brief Initialization 16 bit timers                                  */
/*        Options: Timer1, or Timer3, with time in ms                   */
/*																		*/
/* @param[in] uint16_t time in ms										*/
/* @param[in] timer_t 16-bit timer id									*/
/************************************************************************/
void timer_init_16bit(uint8_t time_ms,timer_t timer_number);


/************************************************************************/
/* @brief Initialization 8 bit Timer2, with time in ms                  */
/*																		*/
/* @param[in] uint16_t time in ms										*/
/************************************************************************/
void timer_init_8bit(uint8_t time_ms);

/** @} */

/*
 * @file timer.h
 * @brief Header for internal timer functions
 *
 * @Origin Date : 31/03/2023 09.25.00
 * @Author : Michel Sommer, 273966
 *
 * \defgroup timer library
 * @{
	 */

 #pragma once

 #include "settings.h"
 #include <stdint.h>
 #include <avr/io.h>
 #include <avr/interrupt.h>


 /** Enumeration to limit input options */
 typedef enum 
 {
	TIMER_1 = 1, /**< 16-bit TIMER1 */
	TIMER_3 = 3  /**< 16-bit TIMER3 */
 } timer_t; 

/************************************************************************/
/*  @brief Interrupt service routines examples:							*/
/*		ISR(TIMER1_COMPA_vect) { TOV1 |= 1 } Timer1 - 16-bit timer		*/
/*		ISR(TIMER2_COMPA_vect) { TOV2 |= 1 } Timer2 - 8-bit timer		*/
/*		ISR(TIMER3_COMPA_vect) { TOV3 |= 1 } Timer3 - 16-bit timer		*/
/*		ISR(TIMER3_COMPA_vect) { TOV3 |= 1 } Timer3 - 32-bit timer		*/
/*																		*/
/*	Note:	that Timer2 is an 8-bit timer and can only count up to		*/
/*			255, so the maximum time you can set is about 16ms with		*/
/*			a prescaler of 1024. If you need longer times, you			*/
/*			will need to use a 16-bit timer like Timer1 or Timer3.		*/
/************************************************************************/


/************************************************************************/
/* @brief Initialization 32 bit with time in ms							*/
/*	Initializes the 16 bit timers: Timer1 and Timer3					*/
/*	The maximum	of the 32-bit timer	is approximately 137.4 hours		*/
/*																		*/
/* @param[in] uint32_t time in ms										*/
/************************************************************************/
void timer_init_32bit(uint32_t time_ms);


/************************************************************************/
/* @brief Initialization 16 bit timers                                  */
/*        Options: Timer1, or Timer3, with time in ms                   */
/*																		*/
/* @param[in] uint16_t time in ms										*/
/* @param[in] timer_t 16-bit timer id									*/
/************************************************************************/
void timer_init_16bit(uint8_t time_ms,timer_t timer_number);


/************************************************************************/
/* @brief Initialization 8 bit Timer2, with time in ms                  */
/*																		*/
/* @param[in] uint16_t time in ms										*/
/************************************************************************/
void timer_init_8bit(uint8_t time_ms);

/** @} */

