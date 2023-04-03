/*
 * segment_hal.h
 *
 * Created: 03/04/2023 20.56.41
 * Author: Michel Sommer, 273966
 */

 #pragma once

 #include <stdint.h>
 #include <avr/io.h>
 #include "../settings.h"
 #include "letters.h"


 /************************************************************************/
 /* @brief Initialization of 7-segment display hal                       */
 /************************************************************************/
 void segment_hal_init(uint16_t refresh_ms);


 /************************************************************************/
 /* @brief turn off 7 segment display                                    */
 /************************************************************************/
 void segment_hal_off();


 /************************************************************************/
 /* @brief Prints value to 7 segment display                             */
 /************************************************************************/
 void segment_hal_print(letters_t segment1, letters_t segment2, letters_t segment3, letters_t segment4);
