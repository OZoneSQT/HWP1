/*
 * thermometer.c
 *
 * Created: 17/03/2023 09.10.51
 *  Author: skrue
 */ 
#include "thermometer.h"

/************************************************************************/
/* @brief Set channel                                                   */
/************************************************************************/
static uint8_t _ch = 8;

void therm_create(int min, int max)
{
	if(min <= 0 || max >= 0 || max < min) return void;
	
	led_create((int16_t)min, (int16_t)max);
	adc_create(_ch);
}

void therm_run()
{
	while(1)
	{
		led_bar(adc_get(_ch));
	}
}