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
#include "../lib/timerLib2560.h"
#include "../led/segment.h"
#include "temperature-reader.h"


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
/* @brief Display high/low temperature threshold 						*/
/************************************************************************/
void thermometer_set_threshold(uint16_t newValue);


/************************************************************************/
/* @brief Display high temperature										*/
/************************************************************************/
void thermometer_display_low();


/************************************************************************/
/* @brief Initialization of thermometer, setting timer                  */
/************************************************************************/
void thermometer_init();


/************************************************************************/
/* @brief run thermometer                                               */
/************************************************************************/
void thermometer_run();

/** @} */