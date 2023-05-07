/*
 * @file TimerLib2560.h
 * @brief Header for timer library 
 *
 * @Origin Date : 28/04/2023 18.18.06
 * @Author : Michel Sommer, 273966
 *
 * \defgroup timer library
 * @{
	 */

#pragma once


#ifndef F_CPU
#define F_CPU 16000000	// CLK
#endif /* F_CPU */

#include <avr/io.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>


// 16-bit timer options using enumeration
typedef enum {
	TIMER1,
	TIMER2,
	TIMER3,
	TIMER4,
	TIMER5
} Timer16Bit;


// PWM_PIN options using enumeration
typedef enum {
	OC3B,
	OC3C,
	OC4B,
	OC4C,
	OC2B,
	OC1A,
	OC1B,
	OC2A,
	OC4A,
	OC5A,
	OC5B,
	OC5C,
	OC1C,
	OC3A,
	OC4D
} PWM_PIN;


/************************************************************************/
/* @brief Initialization 8 bit Timer0, with time in ms                  */
/*																		*/
/* @param[in] uint16_t time in ms										*/
/************************************************************************/
void init8BitTimer(uint8_t time_ms);


/************************************************************************/
/* @brief Initialization 16 bit timers                                  */
/*																		*/
/* @param[in] Timer16Bit 16-bit timer id								*/
/* @param[in] uint16_t time in milliseconds 							*/
/* @param[in] uint8_t add seconds to time 								*/
/* @param[in] uint8_t add minutes to time 								*/
/* @param[in] uint8_t add hours to time 								*/
/************************************************************************/
void init16BitTimer(Timer16Bit timer, ...);


/************************************************************************/
/* @brief Initialization 32 bit with time in ms							*/
/*	Initializes the 16 bit timers										*/
/*	The maximum	of the 32-bit timer	is approximately 137.4 hours		*/
/*																		*/
/* @param[in] Timer16Bit 16-bit timer id 1/2							*/
/* @param[in] Timer16Bit 16-bit timer id 2/2							*/
/* @param[in] uint16_t time in milliseconds 							*/
/* @param[in] uint8_t add seconds to time 								*/
/* @param[in] uint8_t add minutes to time 								*/
/* @param[in] uint8_t add hours to time 								*/
/************************************************************************/
void init32BitTimer(Timer16Bit timer1, Timer16Bit timer2, ...);

/************************************************************************/

/************************************************************************/
/* @brief Initialization Watchdog Interrupt								*/
/*								                                        */
/* @note[in] ISR(WDT_vect) { // code goes here }                        */
/*			 wdt_reset();    // Reset the WDT                           */
/************************************************************************/
void initWDTInterrupt(uint32_t ms);


/************************************************************************/

/************************************************************************/
/* @brief Initialization and run pwm on pin                             */
/*		  Set pin and percentage.                                       */
/*										                                */
/* @param[in] PWM_PIN pin id				                            */
/* @param[in] uint8_t percentage of period	                            */
/************************************************************************/
void pwm_pulse(PWM_PIN pin, uint8_t percentage);


/************************************************************************/
/* @brief Initialization and run pwm on pin                             */
/*		  Set pin and pulse length.                                     */
/*										                                */
/* @param[in] PWM_PIN pin id				                            */
/* @param[in] uint16_t pulse_length_ms length of pulse in ms	        */
/************************************************************************/
void pwm_percentage(PWM_PIN pin, uint16_t pulse_length_ms);


/************************************************************************/
/* @brief Initialization and run pwm on pin                             */
/*										                                */
/* @param[in] PWM_PIN pin id				                            */
/* @param[in] uint8_t percentage of period	                            */
/* @param[in] uint16_t pulse_length_ms length of pulse in ms	        */
/************************************************************************/
void pwm_percentage_pulselength(PWM_PIN pin, uint8_t percentage, uint16_t pulse_length_ms);


/************************************************************************/
/* @brief Stop pwm on pin                                               */
/*										                                */
/* @param[in] PWM_PIN pin id				                            */
/************************************************************************/
void pwm_stop(PWM_PIN pin);


/************************************************************************/

/************************************************************************/
/* @brief Enable global interrupts									    */
/************************************************************************/
void timerLib2560_enable_interrupts();


/************************************************************************/

/** @} */