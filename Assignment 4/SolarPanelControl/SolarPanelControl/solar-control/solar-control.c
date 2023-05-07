/*
 * @file solar_control.c
 *
 * @Origin Date : 30/04/2023 21.45.44
 * @Author : Michel Sommer, 273966
 */ 

#include "solar-control.h"
#include "../thermometer/thermometer.h"
#include "../lib/ioLib2560.h"


uint8_t timeout = 0;
display_t state = DISPLAY_CURRENT;

/************************************************************************/
// Pressing switch 1 change the numeric display to tlow
// LED 1 turns on (2 and 3 off)
// When the numeric display show tlow, the user can enter a
// new value on the matrix keyboard and save it by pressing ‘#’ or
// cancel by pressing ‘*’
static void btn_temp_low()
{
	state = DISPLAY_LOW;
	setOutputPinHigh(LED1);
	setOutputPinLow(LED2);
	setOutputPinLow(LED3);
	thermometer_display_low();
}

/************************************************************************/
// Pressing switch 2 change the numeric display to thigh.
// LED 2 turns on (1 and 3 off)
// When the numeric display show thigh the user can enter a
// new value on the matrix keyboard and save it by pressing ‘#’ or
// cancel by pressing ‘*’
static void btn_temp_high()
{
	state = DISPLAY_HIGH;
	setOutputPinHigh(LED2);
	setOutputPinLow(LED1);
	setOutputPinLow(LED3);
	thermometer_display_high();
}

/************************************************************************/
// Pressing switch 3 change the numeric display to current
// temperature. LED 3 turns on (1 and 2 off)
static void btn_temp_current()
{
	state = DISPLAY_CURRENT;
	setOutputPinHigh(LED3);
	setOutputPinLow(LED1);
	setOutputPinLow(LED2);
	thermometer_display_current();
}

/************************************************************************/
// LED 6 must be on if the valve is open and off if the valve is closed
// Optional:
// Servo driver, using PWM. Study how to configure Fast PWM in the
// MCU datasheet. Notice that the shield pin-connectors for servos
// are connected to MCU Timer 5 (see shield diagram).
// The servo must turn clockwise when the thigh trigger point is
// reached and counterclockwise when the t_low setpoint is reached.
static void valve_open()
{
	setOutputPinHigh(LED6);
	pwm_pulselength(OC5A, 2);
}

static void valve_closed()
{
	setOutputPinLow(LED6);
	pwm_pulselength(OC5A, 1);
}

/************************************************************************/
// LED 7must be on when the pump is running and off when it	
// is not (you do not connect a real pump)
static void pump_open()
{
	setOutputPinHigh(LED7);
}

static void pump_closed()
{
	setOutputPinLow(LED7);
}

/************************************************************************/
// Optional:
// Use a Timer to return to current temperature in the numeric
// display 5 sec. after t_low, or thigh have been shown/changed.
void return_to_deff()
{
	if(timeout == 0) thermometer_display_current();
}

/************************************************************************/
void solar_control_init()
{
	/*
		J15 Mapping, for VIA Shield:
		
		// TODO make a more innovative key mapping, use pin number for name in ioLib2560
		
		J15 pin		Function	Port pin	Enum
		1			TO			PD7			D_PIN31
		3			OC0B		PG5			D_PIN53
		5			OC1B		PB6			D_PIN14
		7			OC2B		PH6			D_PIN60
		9			OC3B		PE4			D_PIN36
		11			ICP4		PL0			D_PIN70
		13			OC4B		PH4			D_PIN58
		15			T5			PL2			D_PIN72
		
		J15 pin		Function	Port pin	Enum
		2			OC0A		PB7			D_PIN15
		4			OC1A		PB5			D_PIN13
		6			OC2A		PB4			D_PIN12
		8			OC3A		PE3			D_PIN35
		10			OC3C		PE5			D_PIN37
		12			OC4A		PH3			D_PIN57
		14			OC4C		PH5			D_PIN59
		16			ICP5		PL1			D_PIN71
*/
	
	thermometer_init();
	//matrix_init(D_PIN31, D_PIN53, D_PIN14, D_PIN60, D_PIN36, D_PIN70, D_PIN58, D_PIN72);	// 1-15
	matrix_init(D_PIN15, D_PIN13, D_PIN12, D_PIN35, D_PIN37, D_PIN57, D_PIN59, D_PIN71);	// 2-16
	init16BitTimer(TIMER2,0,1);
	
	// init input
	initInputPin(BTN1); /**< temp low threshold */
	initInputPin(BTN2); /**< temp high threshold */
	initInputPin(BTN3); /**< numeric display to current temperature */
	
	// init output
	initOutputPin(LED1);
	initOutputPin(LED2);
	initOutputPin(LED3);
	initOutputPin(LED6); /**< valve */
	initOutputPin(LED7); /**< pump */
}

/************************************************************************/
// Main routine
void solar_control_run()
{
	timerLib2560_enable_interrupts();
	
	while (1)
	{
		
		//matrix keyboard handling:
		char input = matrix_read();

		if(input != '\0')
		{
			timeout = 5;

			while(timeout != 0)
			{
				char new[3] = {};

				for(uint8_t i = 0; i < 3; i++)
				{
					if(input == '*')
					{
						btn_temp_current();
						timeout = 0;
					}

					if(input != 'A' || input != 'B' || input != 'C' || input != 'D')
					{
						new[i] = input;
						thermometer_value_to_display(new);
					}

					timeout = 5;

					if(input == '#')
					{
						if(state == DISPLAY_HIGH) 
						{
							thermometer_set_high_threshold(new);	
						}
						else if(state == DISPLAY_LOW)
						{
							thermometer_set_low_threshold(new);
						}
						
						timeout = 0;
					}
				}

				if(matrix_read() == '#')
				{
					if(state == DISPLAY_HIGH)
					{
						thermometer_set_high_threshold(new);
					}
					else if(state == DISPLAY_LOW)
					{
						thermometer_set_low_threshold(new);
					}
					
					return;
				}
			}
		}
		
		//Button handling
		if(readInputPinStatus(BTN1))
		{
			btn_temp_low();
		}
		else if(readInputPinStatus(BTN2))
		{
			btn_temp_high();
		}
		else if(readInputPinStatus(BTN3))
		{
			btn_temp_low();
		}
		
		if(heater_status() == LOW)
		{
			valve_open();
			pump_closed();
		}
		else if(heater_status() == OK)
		{
			valve_closed();
			pump_closed();
		}
		else if(heater_status() == HIGH)
		{
			valve_closed();
			pump_open();
		}
		
	}
}

/************************************************************************/
ISR(TIMER2_COMPA_vect) 
{ 
	if(timeout >= 0) timeout--; 
}

/************************************************************************/
