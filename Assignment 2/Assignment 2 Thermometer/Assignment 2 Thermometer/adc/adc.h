/*
 * adc.h
 *
 * Created: 19/03/2023 12.58.42
 * Author: Michel Sommer, 273966
 */

 #pragma once
 
 #include <stdint.h>
 #include <avr/io.h>

// Enumeration to limit input options
typedef enum adcPin adcPin_t;
enum adcPin
{
	ADC0, ADC1, ADC2, ADC3, 
	ADC4, ADC5, ADC6, ADC7, 
	ADC8, ADC9, ADC10, ADC11, 
	ADC12, ADC13, ADC14, ADC15
};


 /************************************************************************/
 /* @brief Initialization of 8-bit adc on port                           */
 /************************************************************************/
 void adc_init_8bit(adcPin_t pin);


 /************************************************************************/
 /* @brief Initialization of 10-bit adc on port                          */
 /************************************************************************/
 void adc_init_10bit(adcPin_t pin);


 /************************************************************************/
 /* @brief Read adc value from port                                      */
 /*        Note voltage reff. = 5VDC                                     */
 /************************************************************************/
 uint16_t adc_read(adcPin_t pin);
 