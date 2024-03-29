/*
 * thermometer.h
 *
 * Created: 19/03/2023 11.04.03
 * Author: Michel Sommer, 273966
 */

#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include "../keys/keys.h"
#include "../timer/timer.h"
#include "../leds/lightbar.h"
#include "../leds/segment-display.h"
#include "../adc/adc.h"


/*
 * Sensor spec:
 *
 * The output voltage of the sensor is 10mV/�C, and typically 750mV@25�C
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
