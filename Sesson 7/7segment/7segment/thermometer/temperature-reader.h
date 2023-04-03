/*
 * temperature_reader.h
 *
 * Created: 02/04/2023 11.20.08
 * Author: Michel Sommer, 273966
 */

 #pragma once

 #include "../settings.h"
 #include <stdint.h>
 #include "../timer/timer.h"
 #include "../adc/adc-hal.h"


 /************************************************************************/
 /* @brief Initialization temperature reader                             */
 /************************************************************************/
 void temperature_reader_init();

 /************************************************************************/
 /* @brief Read temperature                                              */
 /*        returns temperature as float                                  */
 /************************************************************************/
 float temperature_reader_read();
 