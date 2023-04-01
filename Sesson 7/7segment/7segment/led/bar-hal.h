/*
 * bar_hal.h
 *
 * Created: 31/03/2023 09.39.09
 * Author: Michel Sommer, 273966
 */

 #pragma once

 #include "../key/key.h"
 #include <stdint.h>
 #include <stdio.h>


 /************************************************************************/
 /* Initialization of leds, setting PORTA for PC0-PC7 as output 	       	*/
 /************************************************************************/
 void lightbar_init();


 /************************************************************************/
 /*  Display level on PORTA [0...8]                                      */
 /************************************************************************/
 void lightbar_level(uint8_t level);
