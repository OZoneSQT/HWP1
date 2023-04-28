/*
 * \file TimerLib2560.h
 * \brief Header for timer library 
 *
 * \Origin Date :28/04/2023 18.18.06
 * \Author : Michel Sommer, 273966
 *
 * \defgroup timer library
 * @{
	 */

#pragma once

#include "types.h"
#include <avr/io.h>
#include <stdint.h>
#include <stdarg.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>
#include <stdint.h>

void init8BitTimer0(uint32_t ms);
void init16BitTimer(Timer16Bit timer, ...);
void init32BitTimer(Timer32Bit timer, ...);

/************************************************************************/

/*
   // WDT ISR
   ISR(WDT_vect) {
	  // Your interrupt code goes here
   }
 */
void initWDTInterrupt(uint32_t ms)


/************************************************************************/

/************************************************************************/
/* @brief Initialization and run pwm on pin                             */
/*		  Set pin and percentage.                                       */
/************************************************************************/
void pwm_pulse(PWM_PIN pin, uint8_t percentage);


/************************************************************************/
/* @brief Initialization and run pwm on pin                             */
/*		  Set pin and pulse length.                                     */
/************************************************************************/
void pwm_percentage(PWM_PIN pin, uint16_t pulse_length_ms);


/************************************************************************/
/* @brief Initialization and run pwm on pin                             */
/*		  Set pin, percentage, and pulse length.                        */
/************************************************************************/
void pwm_percentage_pulselength(PWM_PIN pin, uint8_t percentage, uint16_t pulse_length_ms);


/************************************************************************/
/* @brief Stop pwm on pin                                               */
/************************************************************************/
void pwm_stop(PWM_PIN pin);






/** @} */