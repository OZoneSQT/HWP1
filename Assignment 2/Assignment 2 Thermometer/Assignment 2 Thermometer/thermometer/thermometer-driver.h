/*
 * thermometer_driver.h
 *
 * Created: 19/03/2023 12.17.53
 * Author: Michel Sommer, 273966
 */

 #pragma once

 #include <stdint.h>



/************************************************************************/
/* @brief Initialization of thermometer driver                          */
/************************************************************************/
void thermometer_driver_init();
 
 
/************************************************************************/
/* @brief Get reading from thermometer, returning struct                */
/************************************************************************/
reading_t thermometer_read();
