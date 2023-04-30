/*
 * @file segment_hal.h
 * @brief Header file for Segment hal
 *
 * @Origin Date : 03/04/2023 20.56.41
 * @Author : Michel Sommer, 273966
 *
 * \defgroup segment library
 * @{
	 */

 #pragma once

 #include <stdint.h>
 #include <avr/io.h>
 #include "../settings.h"
 #include "../lib/comLib2560.h"
 #include "letters.h"


 /************************************************************************/
 /* @brief Initialization of 7-segment display hal                       */
 /*																		 */
 /* @param[in] uint16_t display refresh speed in ms						 */
 /************************************************************************/
 void segment_hal_init(uint16_t refresh_ms);


 /************************************************************************/
 /* @brief turn off 7 segment display                                    */
 /************************************************************************/
 void segment_hal_off();


 /************************************************************************/
 /* @brief Prints value to 7 segment display                             */
 /*																		 */
 /* @param[in] letters_t value to segment1								 */
 /* @param[in] letters_t value to segment2								 */
 /* @param[in] letters_t value to segment3								 */
 /* @param[in] letters_t value to segment4								 */
 /************************************************************************/
 void segment_hal_print(letters_t segment1, letters_t segment2, letters_t segment3, letters_t segment4);

/** @} */