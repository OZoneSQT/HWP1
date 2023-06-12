/*
 * @file ioLib2560.h
 * @brief Header for io library
 *
 * @Origin Date : 28/04/2023 20.02.01
 * @Author : Michel Sommer, 273966
 *
 * \defgroup io library
 * @{
	 */

#pragma once

#ifndef F_CPU
#define F_CPU 16000000 // clk
#endif /* F_CPU */

#include "def.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <stdio.h>
#include <util/delay.h>

#ifndef REF_VOLTAGE
#define REF_VOLTAGE 5.0
#endif /* REF_VOLTAGE */

#ifndef DEBOUNCE_DELAY
#define DEBOUNCE_DELAY 50 // 50 ms debounce delay
#endif /* DEBOUNCE_DELAY */


// Function pointer type for interrupt callbacks
typedef void (*PinInterruptCallback)(void);
typedef void (*ExtInterruptCallback)(void);

// Trigger configuration values
typedef enum edge {
	ISC_LOW_LEVEL, ISC_ANY_CHANGE, ISC_FALLING, ISC_RISING
} Edge;


/************************************************************************/
/* @brief Initialization Digital IO	Output pin							*/
/*																		*/
/* @param[in] Pin pin													*/
/************************************************************************/
void initOutputPin(uint8_t pin);

/************************************************************************/
/* @brief Initialization Digital IO Input pin							*/
/*																		*/
/* @param[in] Pin pin													*/
/************************************************************************/
void initInputPin(uint8_t pin);

/************************************************************************/
/* @brief Read status of Digital IO	pin				                    */
/*																		*/
/* @param[in] Pin pin													*/
/* @param[out] returns 1, if pin is high								*/
/************************************************************************/
uint8_t readInputPinStatus(uint8_t pin);

/************************************************************************/
/* @brief Read status of Digital IO	pin, debounce protected.			*/
/*		  Debounce time is defined										*/
/*																		*/
/* @param[in] Pin pin													*/
/* @param[out] returns 1, if pin is high								*/
/************************************************************************/
uint8_t readInputPinStatusDebounce(uint8_t pin);

/************************************************************************/
/* @brief Set Digital IO pin high										*/
/*																		*/
/* @param[in] Pin pin													*/
/************************************************************************/
void setOutputPinHigh(uint8_t pin);

/************************************************************************/
/* @brief Set Digital IO pin low										*/
/*																		*/
/* @param[in] Pin pin													*/
/************************************************************************/
void setOutputPinLow(uint8_t pin);

/************************************************************************/
/* @brief Toggle Digital IO pin high/low								*/
/*																		*/
/* @param[in] Pin pin													*/
/************************************************************************/
void toggleOutputPin(uint8_t pin);


/************************************************************************/

/************************************************************************/
/* @brief Initialization analog 8 bit input pin		                    */
/*																		*/
/* @param[in] AdcPin pin												*/
/************************************************************************/
void init8BitAnalogInputPin(uint8_t pin);

/************************************************************************/
/* @brief Initialization analog 10 bit input pin		                */
/*																		*/
/* @param[in] AdcPin pin												*/
/************************************************************************/
void init10BitAnalogInputPin(uint8_t pin);

/************************************************************************/
/* @brief Read value of analog pin					                    */
/*																		*/
/* @param[in] AdcPin pin												*/
/************************************************************************/
uint16_t readAnalogPinUint(uint8_t pin);

/************************************************************************/
/* @brief Read value of analog pin					                    */
/*																		*/
/* @param[in] AdcPin pin												*/
/************************************************************************/
int16_t readAnalogPinSint(uint8_t pin);

/************************************************************************/
/* @brief Read value of analog pin					                    */
/*																		*/
/* @param[in] AdcPin pin												*/
/************************************************************************/
float readAnalogPinFloat(uint8_t pin);


/************************************************************************/
/*
	// Pin Change, ISR How to:
	
	// Pin Change Interrupt Request 0 ISR
	ISR(PCINT0_vect) { // Interrupt code for PCINT0..7 pins }

	// Pin Change Interrupt Request 1 ISR
	ISR(PCINT1_vect) { // Interrupt code for PCINT8..15 pins }

	// Pin Change Interrupt Request 2 ISR
	ISR(PCINT2_vect) { // Interrupt code for PCINT16..23 pins }
 */

/************************************************************************/
/* @brief Initialization of pin change interrupt pin	                */
/*																		*/
/* @param[in] PinChangeInterrupt pin									*/
/************************************************************************/
void initPinChangeInterrupt(uint8_t pin);
  
/************************************************************************/
/* @brief Initialization of pin change interrupt pin	                */
/*																		*/
/* @param[in] PinChangeInterrupt pin									*/
/* @param[in] *PinInterruptCallback pointer, can be NULL 				*/
/************************************************************************/
void initPinChangeInterruptCallback(uint8_t pin, PinInterruptCallback callback);


/************************************************************************/
/*
	// Ext ISR, How to:
	
	// External Interrupt Request 0 ISR
	ISR(INT0_vect) { // Interrupt code for INT0 }

	// External Interrupt Request 1 ISR
	ISR(INT1_vect) { // Interrupt code for INT1 }

	// External Interrupt Request 2 ISR
	ISR(INT2_vect) { // Interrupt code for INT2 }
	
	***
	
	// External Interrupt Request 5 ISR
	ISR(INT7_vect) { // Interrupt code for INT5 }

 */

/************************************************************************/
/* @brief Initialization External Interrupt Pin		                    */
/*																		*/
/* @param[in] ExternalInterrupt interrupt pin							*/
/* @param[in] Edge trigger, trigger edge								*/
/************************************************************************/
void initExternalInterrupt(uint8_t pin, Edge trigger);

/************************************************************************/
/* @brief Initialization External Interrupt Pin		                    */
/*																		*/
/* @param[in] ExternalInterrupt interrupt pin							*/
/* @param[in] Edge trigger, trigger edge								*/
/* @param[in] *ExtInterruptCallback pointer, can be NULL				*/
/************************************************************************/
void initExternalInterruptCallback(uint8_t pin, Edge trigger, ExtInterruptCallback callback);


/************************************************************************/
/*
	// Analog Comparator Interrupt, How to:
	
	ISR(ANALOG_COMP_vect) { // Interrupt activated code }

	// The interrupt will trigger when the voltage at AdcPin is higher 
	// than the internal voltage reference.
 */

/************************************************************************/
/* @brief Initialization Analog Comparator Interrupt, Trigger on high   */
/*																		*/
/* @param[in] AdcPin pin												*/
/************************************************************************/
void initAnalogComparatorHigherInterrupt(uint8_t pin);


/************************************************************************/
/* @brief Initialization Analog Comparator Interrupt, Trigger on low    */
/*																		*/
/* @param[in] AdcPin pin												*/
/************************************************************************/
void initAnalogComparatorLowerInterrupt(uint8_t pin);


/************************************************************************/

/************************************************************************/
/* @brief Initialization pins for a 4x4 matrix keyboard				    */
/*																		*/
/* @param[in] row1, register address for pin, for row 1					*/
/* @param[in] row1, register address for pin, for row 2					*/
/* @param[in] row1, register address for pin, for row 3					*/
/* @param[in] row1, register address for pin, for row 4					*/
/* @param[in] col1, register address for pin, for column 1				*/
/* @param[in] col2, register address for pin, for column 2				*/
/* @param[in] col3, register address for pin, for column 3				*/
/* @param[in] col4, register address for pin, for column 4				*/
/************************************************************************/
void matrix_init(uint8_t row1, uint8_t row2, uint8_t row3, uint8_t row4, uint8_t col1, uint8_t col2, uint8_t col3, uint8_t col4);

/************************************************************************/
/* @brief Returns char value representing pressed button				*/
/*																		*/
/* @param[out] returns char, if button is pressed.						*/
/*             returns \0 if no button is pressed.						*/
/************************************************************************/
char matrix_read();


/************************************************************************/

/************************************************************************/
/* @brief Enable global interrupts									    */
/************************************************************************/
void ioLib2560_enable_interrupts();


/************************************************************************/

/** @} */