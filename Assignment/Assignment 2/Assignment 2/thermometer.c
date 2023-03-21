/*
 * thermometer.c
 *
 * Created: 21/03/2023 20.59.53
 * Author: Michel Sommer, 273966
 */

 #include "thermometer.h"

 static uint8_t _init = 0;
 static uint8_t _halt = 0;

 static int16_t _reading_min = 0;
 static int16_t _reading_last = 0;
 static int16_t _reading_max = 0;


 /*******************************************************************************/
 // Timer1 - 16 bit timer
 // Interrupt Time each second to update the temperature
 ISR(TIMER1_COMPA_vect)
 {
	uint16_t t = thermometer_convertToCelcius(adc_read(ADCPIN));
	if(_init == 0)
	{
		 _init++;
		 _reading_max=t;
		 _reading_last=t;
		 _reading_min=t;
	}
	else
	{
		_reading_last = t;
		if( t < _reading_min ) _reading_min = t;
		if( t > _reading_max ) _reading_max = t;
	}
 
	if( _halt != 0) _halt--;
 }

 /*******************************************************************************/
int16_t thermometer_convertToCelcius(uint16_t adcValue)
 {
	 //ADC on 2^10 bits so a resolution of 1024. Vref = 5V and use the formula : (Vin-500)/10 with Vin=ADC*5/1024
	 float degree = ( ( ( (float)adcValue * 50 / 1024 ) * 100 ) -500 ) / 10;
	 return (int16_t)( 0.1 * degree - 50 );
 }

 /*******************************************************************************/
 static void temperature_bar()
 {
	 // Map display temp on led bar: 18C = 1 led, ... ,25C = 8led
	 uint8_t level = 0;
	 if( _reading_last == 18 ) level = 1;
	 if( _reading_last == 19 ) level = 2;
	 if( _reading_last == 20 ) level = 3;
	 if( _reading_last == 21 ) level = 4;
	 if( _reading_last == 22 ) level = 5;
	 if( _reading_last == 23 ) level = 6;
	 if( _reading_last == 24 ) level = 7;
	 if( _reading_last == 25 ) level = 8;
 
	 lightbar_level(level);
 }

 /*******************************************************************************/
 // select output. min / max is displayed for 2 sec, using timer 1
 static uint16_t thermometer_display()
 {
	temperature_bar();
 
	if( _halt < 3 )
	{
		_halt--;
		return _reading_max;
	}
	else if( _halt == 3 )
	{
		_halt = 0;
		return _reading_last;
	}
	else if( _halt < 0 )
	{
		_halt--;
		return _reading_min;
	}
	else
	{
		return _reading_last;
	}
 }

 /*******************************************************************************/
 // Timer2 - 8 bit timer
 // Interrupt Time each 10 millisecond to display the digit
 ISR(TIMER2_COMPA_vect)
 {
	uint16_t result = (uint16_t)thermometer_display();
	display_printint_4s(result);
 }

 /*******************************************************************************/
 // Interrupt Service Routine for INT2 (PD2) - show min
 ISR(INT2_vect) 
 {
	_halt = 2;
 }

 /*******************************************************************************/
 // Interrupt Service Routine for INT3 (PD3) - show max
 ISR(INT3_vect) 
 {
	_halt = 5;
 }

 /*******************************************************************************/
 void thermometer_init(uint16_t ms)
 {
	keys_isr_init_pd2();				// show min
	keys_isr_init_pd3();				// show max
	timer_init_16bit(TIMER_1, DELAY_S);	// read temp
	timer_init_8bit(DELAY_MS);			// update display
	adc_init_10bit(ADCPIN);				// adc pin
	display_init();						// 7-segment displays
	lightbar_init();					// light bar
 
	sei();								// Enable global interrupts
 }

 /*******************************************************************************/
 void thermometer_run()
 {
	while(1){}
 }

 /*******************************************************************************/
