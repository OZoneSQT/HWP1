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
#include "../keys/keys.h"
#include "../lib/timerLib2560.h"
#include "../led/segment.h"
#include "temperature-reader.h"


/***********************************************************************/
/* Sensor spec:														   */
/* Output voltage of the sensor is 10mV/°C and typically 750mV@25°C	   */
/* aka: 740 mV = 24 C, 730 mV = 23C e.g.							   */
/***********************************************************************/


/************************************************************************/
/* @brief Initialization of thermometer, setting timer                  */
/************************************************************************/
void thermometer_init();


/************************************************************************/
/* @brief run thermometer                                               */
/************************************************************************/
void thermometer_run();

/** @} */