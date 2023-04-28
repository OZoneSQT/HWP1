/*
 * @file temperature_reader.h
 * @brief Header file for thermometer application
 *
 * @Origin Date : 02/04/2023 11.20.08
 * @Author : Michel Sommer, 273966
 *
 * \defgroup thermometer application
 * @{
	 */

 #pragma once

 #include "settings.h"
 #include <stdint.h>
 #include "timer.h"
 #include "adc-hal.h"


 /************************************************************************/
 /* @brief Initialization temperature reader                             */
 /************************************************************************/
 void temperature_reader_init();

 /************************************************************************/
 /* @brief Read temperature                                              */
 /*																		 */
 /*	@param[out] temperature as float									 */
 /************************************************************************/
 float temperature_reader_read();
 
 /** @} */
 
 /*
 * @file temperature_reader.h
 * @brief Header file for thermometer application
 *
 * @Origin Date : 02/04/2023 11.20.08
 * @Author : Michel Sommer, 273966
 *
 * \defgroup thermometer application
 * @{
	 */

 #pragma once

 #include "settings.h"
 #include <stdint.h>
 #include "timer.h"
 #include "adc-hal.h"


 /************************************************************************/
 /* @brief Initialization temperature reader                             */
 /************************************************************************/
 void temperature_reader_init();

 /************************************************************************/
 /* @brief Read temperature                                              */
 /*																		 */
 /*	@param[out] temperature as float									 */
 /************************************************************************/
 float temperature_reader_read();
 
 /** @} */
 
 