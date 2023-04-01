/*
 * 7segment.c
 *
 * Created: 24/03/2023 10.39.27
 * Author: Michel Sommer, 273966
 */

 #include "settings.h"
 #include <stdint.h>
 #include "thermometer.h"


 /*******************************************************************************/
 int main(void)
 {
 /* KISS - Keep It Simpel S****d */
 
 // Initialize thermometer 
 thermometer_init();
 
 // Run thermometer
 thermometer_run();
 
 return 0;
 }

 /*******************************************************************************/
