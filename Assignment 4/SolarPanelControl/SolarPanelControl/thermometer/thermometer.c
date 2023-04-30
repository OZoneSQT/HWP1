/*
 * @file thermometer.c
 * @brief Thermometer application
 *
 * @Origin Date : 31/03/2023 09.35.21
 * @Author : Michel Sommer, 273966
 *
 * \defgroup thermometer application
 * @{
	 */

 #include "thermometer.h"

 static uint8_t _init = 0;
 static uint8_t _halt = 0;

 static float _reading_min = 0;
 static float _reading_last = 0;
 static float _reading_max = 0;


/*******************************************************************************/
/** Timer1 16-bit timer. Interrupt Time each second to update the temperature */
ISR(TIMER1_COMPA_vect)
{
	_reading_last = temperature_reader_read_float();
	
	if( _init == 0 )
	{
		_init++;
		_reading_max = _reading_last;
		_reading_min = _reading_last;
	}
	else
	{
		if( _reading_last < _reading_min ) _reading_min = _reading_last;
		if( _reading_last > _reading_max ) _reading_max = _reading_last;
	}
 
	if( _halt != 0) _halt--;	/** alternative view countdown */
}

/*******************************************************************************/
/** select output. min / max is displayed for 2 sec, using timer 1 */
 static float thermometer_display()
 {
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
 /** Timer2 8-bit timer. Interrupt Time each 10 millisecond to display the digit */
 ISR(TIMER2_COMPA_vect)
 {
	segment_print( thermometer_display(), TYPE, DECIMAL );
 }

 /*******************************************************************************/
 /** Interrupt Service Routine for INT2 (PD2) - show min */
 ISR(INT2_vect)
 {
	_halt = 2;
 }

 /*******************************************************************************/
 /** Interrupt Service Routine for INT3 (PD3) - show max */
 ISR(INT3_vect)
 {
	_halt = 5;
 }

 /*******************************************************************************/
 /** Initialization of thermometer */
 void thermometer_init()
 {
	 keys_isr_init_pd2();				    /** show min */
	 keys_isr_init_pd3();				    /** show max */
	 
	 timer_init_16bit(TIMER_1, DELAY_S);	/** read temp */
	 segment_init(DELAY_MS);				/** 7-segment displays */
	 
	 sei();								    /** Enable global interrupts */
 }

 /*******************************************************************************/
 /** Run thermometer */
 void thermometer_run()
 {
	while(1){}
 }

 /*******************************************************************************/

/** @} */