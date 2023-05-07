/*
 * @file thermometer.h
 * @brief Hesder file for Thermometer application
 *
 * @Origin Date : 31/03/2023 09.35.34
 * @Author : Michel Sommer, 273966
 *
 * \defgroup thermometer application
 * @{
	 */

#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include "../leds/segment.h"
#include "temperature-reader.h"

typedef enum {
	LOW,
	OK,
	HIGH
} temp_t;

typedef enum {
	DISPLAY_LOW,
	DISPLAY_CURRENT,
	DISPLAY_HIGH
} display_t;

/***********************************************************************/
/* Sensor spec:														   */
/* Output voltage of the sensor is 10mV/°C and typically 750mV@25°C	   */
/* aka: 740 mV = 24 C, 730 mV = 23C e.g.							   */
/***********************************************************************/


/************************************************************************/
/* @brief return threshold state for temperature						*/
/************************************************************************/
temp_t heater_status();


/************************************************************************/
/* @brief Display high temperature										*/
/************************************************************************/
void thermometer_display_current();


/************************************************************************/
/* @brief Display high temperature										*/
/************************************************************************/
void thermometer_display_high();


/************************************************************************/
/* @brief Display high temperature threshold 							*/
/************************************************************************/
void thermometer_set_high_threshold(char newValue[]);


/************************************************************************/
/* @brief Display low temperature threshold 							*/
/************************************************************************/
void thermometer_low_threshold(char newValue[]);


/************************************************************************/
/* @brief value to display 												*/
/************************************************************************/
void thermometer_value_to_display(char value[]);


/************************************************************************/
/* @brief Display high temperature										*/
/************************************************************************/
void thermometer_display_low();


/************************************************************************/
/* @brief Initialization of thermometer, setting timer                  */
/************************************************************************/
void thermometer_init();

/** @} */