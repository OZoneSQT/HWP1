/*
 * @file solar_control.h
 * @brief Header file for Solar Control application
 *
 * @Origin Date :30/04/2023 21.45.35
 * @Author : Michel Sommer, 273966
 *
 * \defgroup solar control application
 * @{
	 */

#pragma once

#include "lib/ioLib2560.h"
#include "lib/timerLib2560.h"
#include "lib/comLib2560.h"
#include "thermometer/thermometer.h"

/************************************************************************/
/* Requirements:														*/
/*	- The current temperature must be displayed on the numeric display. */
/*  - Pressing switch 1 change the numeric display to tlow.				*/
/*    LED 1 turns on (2 and 3 off).										*/
/*  - Pressing switch 2 change the numeric display to thigh.			*/
/*    LED 2 turns on (1 and 3 off).										*/
/*  - When the numeric display show tlow, or thigh the user can			*/
/*	  enter a new value on the matrix keyboard and save it by			*/
/*	  pressing ‘#’ or cancel by pressing ‘*’.							*/
/*  - Pressing switch 3 change the numeric display to current			*/
/*	  temperature. LED 3 turns on (1 and 2 off).						*/
/*  - LED 6 must be on if the valve is open and off if					*/
/*	  the valve is closed.												*/
/*  - LED 7must be on when the pump is running and off when it			*/
/*	  is not (you do not connect a real pump).							*/
/************************************************************************/
/* Optional:															*/
/*	- Servo driver, using PWM. Study how to configure Fast PWM in the   */
/*	  MCU datasheet. Notice that the shield pin-connectors for servos	*/
/*	  are connected to MCU Timer 5 (see shield diagram).				*/
/*	  The servo must turn clockwise when the thigh trigger point is		*/
/*	  reached and counterclockwise when the t_low setpoint is reached.	*/
/*	- Use a Timer to return to current temperature in the numeric		*/
/*	  display 5 sec. after t_low, or thigh have been shown/changed.		*/
/************************************************************************/
/* Documentation:														*/
/*	- Inline comments.													*/
/*	- UML class and activity diagrams									*/
/************************************************************************/
/* What to hand-in:														*/
/*	- All source files and diagrams.									*/
/************************************************************************/


/************************************************************************/
/* @brief Initialization of Solar Control								*/
/************************************************************************/
void solar_control_init();


/************************************************************************/
/* @brief run Solar Control application                                 */
/************************************************************************/
void solar_control_run();

/** @} */