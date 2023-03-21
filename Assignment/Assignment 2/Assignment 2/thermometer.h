/*
 * thermometer.h
 *
 * Created: 21/03/2023 21.00.05
 * Author: Michel Sommer, 273966
 */

#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include "key/key.h"
#include "timer/timer.h"
#include "led/bar.h"
#include "led/segment.h"
#include "adc/adc.h"


/*
 * Sensor spec:
 *
 * The output voltage of the sensor is 10mV/°C, and typically 750mV@25°C
 * aka: 740 mV = 24 C, 730 mV = 23C e.g.
 */


/************************************************************************/
/* @brief Initialization of thermometer, setting timer                  */
/************************************************************************/
void thermometer_init(uint16_t ms);


/************************************************************************/
/* @brief run thermometer                                               */
/************************************************************************/
void thermometer_run();
