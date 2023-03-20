/*
 * thermometer.c
 *
 * Created: 19/03/2023 11.03.38
 * Author: Michel Sommer, 273966
 */

#include "thermometer.h"

static uint8_t _init = 0;
static uint8_t _halt = 0;
reading_t* reading;


/*******************************************************************************/

static int16_t thermometer_convertToCelcius(uint16_t adcValue)
{
	//ADC on 2^10 bits so a resolution of 1024. Vref = 5V and use the formula : (Vin-500)/10 with Vin=ADC*5/1024
	float degree = ( ( ( (float)adcValue * 50 / 1024 ) * 100 ) -500 ) / 10;
	return (int16_t)( 0.1 * degree - 50 );
}

/*******************************************************************************/
// Timer1 - 16 bit timer
// Interrupt Time each second to update the temperature
ISR(TIMER1_COMPA_vect)
{
	uint16_t t = adc_read(ADCPIN);
	
	
	// TODO update / read value from struct, or save as variables 
	
	
	if(_init == 0)
	{
		_init++;
		reading.max=t;
		reading.last=t;
		reading.min=t;
	}
	else
	{
		reading.last = t;
		if( t < reading.min ) reading.min = t;
		if( t > reading.max ) reading.max = t;
	}
	
	if( _halt != 0) _halt--;
}

/*******************************************************************************/
// select output. min / max is displayed for 2 sec, using timer 1
static uint16_t thermometer_display()
{
	if( _halt < 3 )
	{
		_halt--;
		return reading.max;
	}
	else if( _halt == 3 )
	{
		_halt = 0;
		return reading.last;
	}
	else if( _halt < 0 )
	{
		_halt--;
		return reading.min;
	}
	else
	{
		return reading.last;
	}
} 

/*******************************************************************************/
void temperature_bar(uint16_t adcValue)
{
	// Map display temp on led bar: 18C = 1 led, ... ,25C = 8led
	uint8_t level = 0;
	if( adcValue == 18 ) level = 1;
	if( adcValue == 19 ) level = 2;
	if( adcValue == 20 ) level = 3;
	if( adcValue == 21 ) level = 4;
	if( adcValue == 22 ) level = 5;
	if( adcValue == 23 ) level = 6;
	if( adcValue == 24 ) level = 7;
	if( adcValue == 25 ) level = 8;
	
	lightbar_level(level);
}

/*******************************************************************************/
// Timer2 - 8 bit timer
// Interrupt Time each 10 millisecond to display the digit
ISR(TIMER2_COMPA_vect)
{
	uint16_t result = (uint16_t)thermometer_display();
	printint_4s(result);
}

/*******************************************************************************/
// Interrupt Service Routine for INT2 (PD2) - show min
ISR(INT2_vect) {
	_halt = 2;
}

/*******************************************************************************/
// Interrupt Service Routine for INT3 (PD3) - show max
ISR(INT3_vect) {
	_halt = 5;
}

/*******************************************************************************/
void thermometer_init(uint16_t ms)
{
	// Dynamically allocate memory using malloc()
	reading = (reading_t*)malloc(sizeof(reading_t));
	
	keys_isr_init_pd2();				// show min
	keys_isr_init_pd3();				// show max
	timer_init_16bit(TIMER_1, DELAY_S);	// read temp
	timer_init_8bit(DELAY_MS);			// update display
	adc_init_10bit(ADCPIN);				// adc pin
	lightbar_init();					// light bar
}

/*******************************************************************************/
void thermometer_run()
{
	while(1){}
}

/*******************************************************************************/
