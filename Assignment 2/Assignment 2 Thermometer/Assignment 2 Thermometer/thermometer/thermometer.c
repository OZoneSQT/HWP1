/*
 * thermometer.c
 *
 * Created: 19/03/2023 11.03.38
 * Author: Michel Sommer, 273966
 */

#include "thermometer.h"

float sample;
float degree;
int16_t temp;


/*******************************************************************************/
static int16_t thermometer_convertToCelcius(uint16_t adcValue)
{
	//ADC on 2^10 bits so a resolution of 1024. Vref=5V and use the formula : (Vin-500)/10 with Vin=ADC*5/1024
	degree = ( ( ( (float)ADC * 50 / 1024 ) * 100 ) -500 ) / 10;
	//force to INT
	int16_t temp = (int16_t)degree;
	return(temp);
}

/*******************************************************************************/
void thermometer_init(uint16_t ms)
{
	
	
}

/*******************************************************************************/
void thermometer_run()
{
	
	
}

/*******************************************************************************/