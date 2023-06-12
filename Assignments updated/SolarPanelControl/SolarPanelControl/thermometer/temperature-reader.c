/*
 * @file temperature_reader.c
 * @brief Methods to read and convert temperature 
 *
 * @Origin Date : 02/04/2023 11.19.40
 * @Author : Michel Sommer, 273966
 *
 * \defgroup thermometer application
 * @{
	 */

#include "temperature-reader.h"


/************************************************************************/
/** Function to convert adc value to centius */
static float convert_convertToCelcius(uint16_t adcValue)
{
	/** ADC on 2^10 bits so a resolution of 1024. Vref = 5V and use the formula : (Vin-500)/10 with Vin=ADC*5/1024 */
	float degree = ((((float)adcValue*50/1024)*100)-500)/10;
	
	/** Equation, derived from regression on values from data sheet */
	return (0.1*degree-50);
}

/************************************************************************/
/** Function to convert adc value to fahrenheit */
static float convert_convertToFahrenheit(uint16_t adcValue)
{
	return ((convert_convertToCelcius(adcValue)*(9/5))+32);
}

/************************************************************************/
/** Function to convert adc value to kelvin */
static float convert_convertToKelvin(uint16_t adcValue)
{
	return (convert_convertToCelcius(adcValue)+273.15);
}

/************************************************************************/
/** Initialization of temperature reader */
void temperature_reader_init() 
{
	init8BitTimer(DELAY_MS);	/** update display */
	init10BitAnalogInputPin(ADCPIN);		/** Set 10 bit adc */
}

/************************************************************************/
/** Function to read float values  */
float temperature_reader_read_float()
{
	return convert_convertToCelcius(readAnalogPinUint(ADCPIN));
}

/************************************************************************/

/** @} */