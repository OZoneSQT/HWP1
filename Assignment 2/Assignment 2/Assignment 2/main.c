/*
 * Assignment 2.c
 *
 * Created: 21/03/2023 20.38.06
 * Author: Michel Sommer, 273966
 */

 #include "settings.h"
 #include <stdint.h>
 #include "thermometer.h"


 /*******************************************************************************/
 int main(void)
 {
	 /* KISS - Keep It Simpel S****d */
 
	 // Set timer in ms
	 thermometer_init(DELAY_S);
 
	 // Run thermometer
	 thermometer_run();
 
	 return 0;
 }

 /*******************************************************************************/
