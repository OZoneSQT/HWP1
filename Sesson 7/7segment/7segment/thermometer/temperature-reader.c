/*
 * temperature_reader.c
 *
 * Created: 02/04/2023 11.19.40
 * Author: Michel Sommer, 273966
 */

#include "temperature-reader.h"


/************************************************************************/
static float convert_convertToCelcius(uint16_t adcValue)
{
	//ADC on 2^10 bits so a resolution of 1024. Vref = 5V and use the formula : (Vin-500)/10 with Vin=ADC*5/1024
	float degree = ((((float)adcValue*50/1024)*100)-500)/10;
	
	// Equation, derived from regression on values from data sheet
	return (0.1*degree-50);
}

/************************************************************************/
static float convert_convertToFahrenheit(uint16_t adcValue)
{
	return ((convert_convertToCelcius(adcValue)*(9/5))+32);
}

/************************************************************************/
static float convert_convertToKelvin(uint16_t adcValue)
{
	return (convert_convertToCelcius(adcValue)+273.15);
}

/************************************************************************/
void temperature_reader_init() 
{
	timer_init_8bit(DELAY_MS);			// update display
	adc_init_10bit(ADCPIN);				// Set 10 bit adc
	//sei();							// Enable global interrupts
}

/************************************************************************/
float temperature_reader_read_float()
{
	return convert_convertToCelcius(adc_read(ADCPIN));
}

/************************************************************************/
