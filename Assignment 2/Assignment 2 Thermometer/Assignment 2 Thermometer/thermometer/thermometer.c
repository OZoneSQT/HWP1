/*
 * thermometer.c
 *
 * Created: 19/03/2023 11.03.38
 * Author: Michel Sommer, 273966
 */

#include "thermometer.h"

static adcPin _adc = ADC15;
static uint8_t _init = 0;
static uint8_t _halt = 0;

reading_t* reading;
float sample;
float degree;
int16_t temp;


/*******************************************************************************/

static int16_t thermometer_convertToCelcius(uint16_t adcValue)
{
	// TODO fix
	
	//ADC on 2^10 bits so a resolution of 1024. Vref=5V and use the formula : (Vin-500)/10 with Vin=ADC*5/1024
	degree = ( ( ( (float)ADC * 50 / 1024 ) * 100 ) -500 ) / 10;
	//force to INT
	int16_t temp = (int16_t)degree;
	return(temp);
}

/*******************************************************************************/
// Timer1 - 16 bit timer
// Interrupt Time each second to update the temperature
ISR(TIMER1_COMPA_vect)
{
	uint16_t t = adc_read(_adc);
	
	if(_init == 0)
	{
		_init++;
		reading.max = t;
		reading.last = t;
		reading.min = t;
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
	//TODO Calc to display temp on led bar 18C = 1 led, 25C = 8led
	
	
	uint8_t level;
	lightbar_level(level);
}

/*******************************************************************************/
// Timer2 - 8 bit timer
// Interrupt Time each 10 millisecond to display the digit
ISR(TIMER2_COMPA_vect)
{
	float resule = thermometer_display();
	printint_4s();
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
	timer_init_16bit(TIMER_1, 1000);	// read temp
	timer_init_8bit(10);				// update display
	adc_init_8bit(_adc);				// adc pin 15
	lightbar_init();					// light bar
}

/*******************************************************************************/
void thermometer_run()
{
	while(1){}
}

/*******************************************************************************/
