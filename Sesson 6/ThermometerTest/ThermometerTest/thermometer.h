/*
 * thermometer.h
 *
 * Created: 17/03/2023 09.11.05
 *  Author: skrue
 */ 
#pragma once
#include <stdint.h>
#include "led.h"
#include "adc.h"

/************************************************************************/
/* @brief initialization method                                         */
/************************************************************************/
void therm_create(int min, int max);

/************************************************************************/
/* @brief update function                                               */
/************************************************************************/
void therm_run();
