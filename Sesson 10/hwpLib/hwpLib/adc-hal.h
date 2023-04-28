/*
 * @file adc_hal.h
 * @brief Header file for ADC hal
 *
 * @Origin Date : 31/03/2023 09.31.46
 * @Author : Michel Sommer, 273966
 *
 * \defgroup adc library
 * @{
	 */

 #pragma once
 
 #include "settings.h"
 #include <stdint.h>
 #include <avr/io.h>


  /** Enumeration to limit input options, and maps to pin */
  typedef enum AdcPin
  {
	 ADC_0 = PF0, 
	 ADC_1 = PF1, 
	 ADC_2 = PF2, 
	 ADC_3 = PF3,
	 ADC_4 = PF4, 
	 ADC_5 = PF5, 
	 ADC_6 = PF6, 
	 ADC_7 = PF7,
	 ADC_8 = PK0, 
	 ADC_9 = PK1, 
	 ADC_10 = PK2, 
	 ADC_11 = PK3,
	 ADC_12 = PK4, 
	 ADC_13 = PK5, 
	 ADC_14 = PK6, 
	 ADC_15 = PK7
  } adcPin_t;


 /************************************************************************/
 /* @brief Initialization of 8-bit adc on pin                            */
 /*																		 */
 /* @param[in] adcPin_t pin												 */
 /************************************************************************/
 void adc_init_8bit(adcPin_t pin);


 /************************************************************************/
 /* @brief Initialization of 10-bit adc on pin                           */
 /*																		 */
 /* @param[in] adcPin_t pin												 */
 /************************************************************************/
 void adc_init_10bit(adcPin_t pin);


 /************************************************************************/
 /* @brief Read adc value from pin                                       */
 /*        Note voltage reff. = 5VDC                                     */
 /*																		 */
 /* @param[in] adcPin_t pin												 */
 /*																		 */
 /* @param[out] uint16_t returns measured value on pin					 */
 /************************************************************************/
 uint16_t adc_read(adcPin_t pin);
 
 /** @} */