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
 
 uint16_t low = 0;
 uint16_t high = 30;
 float last = 15;
 temp_t threshold = OK;


/*******************************************************************************/
ISR(TIMER1_COMPA_vect)
{
	last = readAnalogPinUint(A_PIN15);
}

/*******************************************************************************/
temp_t heater_status()
{
	if( last > low && last < high ) return OK;
	if( last < low ) return LOW;
	if( last < high ) return HIGH;
}

/*******************************************************************************/
void thermometer_display_current()
{
	threshold = DISPLAY_CURRENT;
	segment_print(last, FLOAT, 1);
}

/*******************************************************************************/
void thermometer_display_high()
{
	segment_print(high, UINT16_T, 0);
}

/*******************************************************************************/
void thermometer_display_low()
{
	segment_print(low, UINT16_T, 0);
}

/*******************************************************************************/
uint16_t map_to_value(char value)
{
	if(value == '1') { return 1; }
	else if(value == '2') { return 2; }
	else if(value == '3') { return 3; }
	else if(value == '4') { return 4; }
	else if(value == '5') { return 5; }
	else if(value == '6') { return 6; }
	else if(value == '7') { return 7; }
	else if(value == '8') { return 8; }
	else if(value == '9') { return 9; }
	else if(value == '0') { return 0; }
	else { return NULL; }
}
/*******************************************************************************/
uint16_t thermometer_set_threshold(char newValue[])
{
	uint16_t value = 0;
	if(newValue[0] != NULL) value = map_to_value(newValue[0]);
	if(newValue[1] != NULL) value = value + ( map_to_value(newValue[1]) * 10 );
	if(newValue[2] != NULL) value = value + ( map_to_value(newValue[2]) * 100 );
	if(newValue[3] != NULL) value = value + ( map_to_value(newValue[3]) * 1000 );
	
	return value;
}

/*******************************************************************************/
void thermometer_set_high_threshold(char newValue[])
{
	high = thermometer_set_threshold(newValue);
}

/*******************************************************************************/
void thermometer_set_low_threshold(char newValue[])
{
	low = thermometer_set_threshold(newValue);
}

/*******************************************************************************/
letters_t map_letter(char value)
{
	if(value == '1') return L1;
	if(value == '2') return L2;
	if(value == '3') return L3;
	if(value == '4') return L4;
	if(value == '5') return L5;
	if(value == '6') return L6;
	if(value == '7') return L7;
	if(value == '8') return L8;
	if(value == '9') return L9;
	if(value == '0') return L0;
	if(value == 'A') return LA;
	if(value == 'B') return LB;
	if(value == 'C') return LC;
	if(value == 'D') return LD;

	return LB;	
}

/*******************************************************************************/
void thermometer_value_to_display(char value[])
{
	segment_print_letter(map_letter(value[3]), map_letter(value[2]), map_letter(value[1]), map_letter(value[0]));
}

/*******************************************************************************/
/** Initialization of thermometer */
void thermometer_init()
{
	init16BitTimer(TIMER1, 0, DELAY_S);
	init10BitAnalogInputPin(A_PIN15);
	segment_init(DELAY_MS);
}

 /*******************************************************************************/

/** @} */