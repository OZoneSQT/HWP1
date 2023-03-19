/*
 * thermometer.h
 *
 * Created: 19/03/2023 11.04.03
 * Author: Michel Sommer, 273966
 */

#pragma once

#include <stdint.h>


/************************************************************************/
/* @brief Initialization of thermometer, setting timer                  */
/************************************************************************/
void thermometer_init(uint16_t ms);


/************************************************************************/
/* @brief run thermometer                                               */
/************************************************************************/
void thermometer_run();