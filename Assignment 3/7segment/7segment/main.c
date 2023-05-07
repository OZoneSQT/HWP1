/*
 * @title : 7-segment application
 * @file main.c
 * @brief Main application
 *
 * @Origin Date : 24/03/2023 10.39.27
 * @Author : Michel Sommer, 273966
 *
 * \defgroup host application
 * @{
	 */

 #include "settings.h"
 #include <stdint.h>
 #include "thermometer/thermometer.h"


 /*******************************************************************************/
 /** Main method: Initialize and Starts the application */
 int main(void)
 {
	 /* KISS - Keep It Simpel S****d */
 
	 thermometer_init(); /** Initialize thermometer */
	 thermometer_run(); /** Run thermometer */
 
	 return 0;
 }

 /*******************************************************************************/

/** @} */