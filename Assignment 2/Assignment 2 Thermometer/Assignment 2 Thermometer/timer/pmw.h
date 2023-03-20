/*
 * pmw.h
 *
 * Created: 19/03/2023 14.31.28
 * Author: Michel Sommer, 273966
 */

#pragma once

#include "../settings.h"
#include <stdint.h>
#include <avr/io.h>

// Define the PWM_PIN enumeration type
typedef enum {
	OC3B, OC3C, OC4B, OC4C, OC2B, OC1A, OC1B, OC2A, OC4A, OC5A, OC5B, OC5C, OC1C, OC3A, OC4D
} PWM_PIN;


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