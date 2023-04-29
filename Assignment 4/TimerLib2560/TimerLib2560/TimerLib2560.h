/*
 * \file TimerLib2560.h
 * \brief Header for timer library 
 *
 * \date : 28/04/2023 18.18.06
 * \author : Michel Sommer, 273966
 *
 * \defgroup timer library
 * @{
	 */

#pragma once

#include "types.h"


/************************************************************************/
/* \brief Initialization 8 bit Timer0, with time in ms                  */
/*																		*/
/* \param uint16_t time in ms											*/
/************************************************************************/
void init8BitTimer(uint8_t time_ms);


/************************************************************************/
/* \brief Initialization 16 bit timers                                  */
/*																		*/
/* \param Timer16Bit 16-bit timer id									*/
/* \param uint16_t time in milliseconds 								*/
/* \param uint8_t add seconds to time 									*/
/* \param uint8_t add minutes to time 									*/
/* \param uint8_t add hours to time 									*/
/************************************************************************/
void init16BitTimer(Timer16Bit timer, ...);


/************************************************************************/
/* \brief Initialization 32 bit with time in ms							*/
/*	Initializes the 16 bit timers										*/
/*	The maximum	of the 32-bit timer	is approximately 137.4 hours		*/
/*																		*/
/* \param Timer16Bit 16-bit timer id 1/2								*/
/* \param Timer16Bit 16-bit timer id 2/2								*/
/* \param uint16_t time in milliseconds 								*/
/* \param uint8_t add seconds to time 									*/
/* \param uint8_t add minutes to time 									*/
/* \param uint8_t add hours to time 									*/
/************************************************************************/
void init32BitTimer(Timer16Bit timer1, Timer16Bit timer2, ...);

/************************************************************************/

/************************************************************************/
/* \brief Initialization Watchdog Interrupt								*/
/*								                                        */
/* \note  ISR(WDT_vect) { // code goes here }                           */
/*		  wdt_reset();    // Reset the WDT                              */
/************************************************************************/
void initWDTInterrupt(uint32_t ms);


/************************************************************************/

/************************************************************************/
/* \brief Initialization and run pwm on pin                             */
/*		  Set pin and percentage.                                       */
/*										                                */
/* \param PWM_PIN pin id				                                */
/* \param uint8_t percentage of period	                                */
/************************************************************************/
void pwm_pulse(PWM_PIN pin, uint8_t percentage);


/************************************************************************/
/* \brief Initialization and run pwm on pin                             */
/*		  Set pin and pulse length.                                     */
/*										                                */
/* \param PWM_PIN pin id				                                */
/* \param uint16_t pulse_length_ms length of pulse in ms	            */
/************************************************************************/
void pwm_percentage(PWM_PIN pin, uint16_t pulse_length_ms);


/************************************************************************/
/* \brief Initialization and run pwm on pin                             */
/*										                                */
/* \param PWM_PIN pin id				                                */
/* \param uint8_t percentage of period	                                */
/* \param uint16_t pulse_length_ms length of pulse in ms	            */
/************************************************************************/
void pwm_percentage_pulselength(PWM_PIN pin, uint8_t percentage, uint16_t pulse_length_ms);


/************************************************************************/
/* \brief Stop pwm on pin                                               */
/*										                                */
/* \param PWM_PIN pin id				                                */
/************************************************************************/
void pwm_stop(PWM_PIN pin);


/** @} */