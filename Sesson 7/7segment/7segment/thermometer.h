/*
 * thermometer.h
 *
 * Created: 31/03/2023 09.35.34
 * Author: Michel Sommer, 273966
 */

#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include "key/key-hal.h"
#include "timer/timer.h"
#include "led/segment-hal.h"
#include "adc/adc-hal.h"


/*
 * Sensor spec:
 *
 * The output voltage of the sensor is 10mV/°C, and typically 750mV@25°C
 * aka: 740 mV = 24 C, 730 mV = 23C e.g.
 */


/************************************************************************/
/* @brief Initialization of thermometer, setting timer                  */
/************************************************************************/
void thermometer_init();


/************************************************************************/
/* @brief run thermometer                                               */
/************************************************************************/
void thermometer_run();
