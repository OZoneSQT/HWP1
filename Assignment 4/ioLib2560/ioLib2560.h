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

#include "types.h"


/************************************************************************/
/* @brief Initialization Digital IO	Output pin							*/
/*																		*/
/* @param[in] Pin pin													*/
/************************************************************************/
void initOutputPin(Pin pin);

/************************************************************************/
/* @brief Initialization Digital IO Input pin							*/
/*																		*/
/* @param[in] Pin pin													*/
/************************************************************************/
void initInputPin(Pin pin);

/************************************************************************/
/* @brief Read status of Digital IO	pin				                    */
/*																		*/
/* @param[in] Pin pin													*/
/* @param[out] returns 1, if pin is high								*/
/************************************************************************/
bool readInputPinStatus(Pin pin);

/************************************************************************/
/* @brief Set Digital IO pin high										*/
/*																		*/
/* @param[in] Pin pin													*/
/************************************************************************/
void SetOutputPinHigh(Pin pin);

/************************************************************************/
/* @brief Set Digital IO pin low										*/
/*																		*/
/* @param[in] Pin pin													*/
/************************************************************************/
void SetOutputPinLow(Pin pin);

/************************************************************************/
/* @brief Toggle Digital IO pin high/low								*/
/*																		*/
/* @param[in] Pin pin													*/
/************************************************************************/
void ToggleOutputPin(Pin pin);


/************************************************************************/

/************************************************************************/
/* @brief Initialization analog 8 bit input pin		                    */
/*																		*/
/* @param[in] AdcPin pin												*/
/************************************************************************/
void init8BitAnalogInputPin(AdcPin pin);

/************************************************************************/
/* @brief Initialization analog 10 bit input pin		                */
/*																		*/
/* @param[in] AdcPin pin												*/
/************************************************************************/
void init10BitAnalogInputPin(AdcPin pin);

/************************************************************************/
/* @brief Read value of analog pin					                    */
/*																		*/
/* @param[in] AdcPin pin												*/
/************************************************************************/
uint16_t readAnalogPinUint(AdcPin pin);

/************************************************************************/
/* @brief Read value of analog pin					                    */
/*																		*/
/* @param[in] AdcPin pin												*/
/************************************************************************/
int16_t readAnalogPinSint(AdcPin pin);

/************************************************************************/
/* @brief Read value of analog pin					                    */
/*																		*/
/* @param[in] AdcPin pin												*/
/************************************************************************/
float readAnalogPinFloat(AdcPin pin);


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
void initPinChangeInterrupt(PinChangeInterrupt pin);


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
	
	// External Interrupt Request 7 ISR
	ISR(INT7_vect) { // Interrupt code for INT7 }

 */

/************************************************************************/
/* @brief Initialization External Interrupt Pin		                    */
/*																		*/
/* @param[in] ExternalInterrupt interrupt pin							*/
/* @param[in] Edge trigger, trigger edge								*/
/************************************************************************/
void initExternalInterrupt(ExternalInterrupt pin, Edge trigger);


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
void initAnalogComparatorHigherInterrupt(AdcPin pin);


/************************************************************************/
/* @brief Initialization Analog Comparator Interrupt, Trigger on low    */
/*																		*/
/* @param[in] AdcPin pin												*/
/************************************************************************/
void initAnalogComparatorLowerInterrupt(AdcPin pin);


/************************************************************************/

/************************************************************************/
/* @brief Enable global interrupts									    */
/************************************************************************/
void ioLib2560_enable_interrupts();


/************************************************************************/

/** @} */