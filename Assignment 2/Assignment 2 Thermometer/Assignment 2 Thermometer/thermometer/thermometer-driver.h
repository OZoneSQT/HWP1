/*
 * thermometer_driver.h
 *
 * Created: 19/03/2023 12.17.53
 * Author: Michel Sommer, 273966
 */

 #pragma once

 #include <stdint.h>


/************************************************************************/
/* @brief Struct containing readings                                    */
/************************************************************************/
typedef struct Reading {
	union {
		int16_t min = 0;
		int16_t reading = 0;
		int16_t max = 0;
	};
} reading_t;


/************************************************************************/
/* @brief Initialization of thermometer driver                          */
/************************************************************************/
void thermometer_driver_init();
 
 
/************************************************************************/
/* @brief Get reading from thermometer, returning struct                */
/************************************************************************/
reading_t thermometer_read();
