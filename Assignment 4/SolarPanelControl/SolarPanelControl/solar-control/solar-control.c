/*
 * solar_control.c
 *
 * Created: 30/04/2023 21.45.44
 *  Author: skrue
 */ 
#define btn1 PC0; /**< temp low threshold */
#define btn2 PC1; /**< temp high threshold */
#define btn3 PC2; /**< numeric display to current temperature */
#define led1 PA0;
#define led2 PA1;
#define led3 PA2;
#define led4 PA3;
#define led6 PA6; /**< valve */
#define led7 PA7; /**< pump */

typedef enum {
	LOW,
	OK,
	HIGH
	} temp_t;

uint8_t timeout = 0;

/************************************************************************/
// Pressing switch 1 change the numeric display to tlow
// LED 1 turns on (2 and 3 off)
// When the numeric display show tlow, the user can enter a
// new value on the matrix keyboard and save it by pressing ‘#’ or
// cancel by pressing ‘*’
static void btn_temp_low()
{
	SetOutputPinHigh(led1);
	SetOutputPinLow(led2);
	SetOutputPinLow(led3);
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
	SetOutputPinHigh(led2);
	SetOutputPinLow(led1);
	SetOutputPinLow(led3);
}

/************************************************************************/
// Pressing switch 3 change the numeric display to current
// temperature. LED 3 turns on (1 and 2 off)
static void btn_temp_high()
{
	SetOutputPinHigh(led3);
	SetOutputPinLow(led1);
	SetOutputPinLow(led2);
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
	SetOutputPinHigh(led6);
	pwm_percentage(, 2);
}

static void valve_closed()
{
	SetOutputPinLow(led6);
	pwm_percentage(PWM_PIN pin, 1);
}

/************************************************************************/
// LED 7must be on when the pump is running and off when it	
// is not (you do not connect a real pump)
static void pump_open()
{
	SetOutputPinHigh(led7);
}

static void pump_closed()
{
	SetOutputPinLow(led7);
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
	thermometer_init();
	matrix_init();
	init16BitTimer(TIMER2,0,1);
	
	// init input
	initInputPin(btn1); /**< temp low threshold */
	initInputPin(btn2); /**< temp high threshold */
	initInputPin(btn3); /**< numeric display to current temperature */
	
	// init output
	initOutputPin(led1);
	initOutputPin(led2);
	initOutputPin(led3);
	initOutputPin(led6); /**< valve */
	initOutputPin(led7); /**< pump */
}

/************************************************************************/
void solar_control_run()
{
	timerLib2560_enable_interrupts();
	thermometer_run();
	
	while (1)
	{
		if(readInputPinStatus(btn1))
		{
			btn_temp_low();
		}
		else if(readInputPinStatus(btn2))
		{
			btn_temp_high();
		}
		else if(readInputPinStatus(btn3))
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
