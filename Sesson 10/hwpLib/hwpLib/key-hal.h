/*
 * @file key_hal.h
 * @brief Header file, for ISR buttons
 *
 * @Origin Date :31/03/2023 09.32.30
 * @Author : Michel Sommer, 273966
 *
 * \defgroup isr key library
 * @{
	 */

#pragma once

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>


/*
 *  Interrupt service routines:
 *	ISR(INT2_vect) { } // INT2 (PD2)
 *	ISR(INT3_vect) { } // INT3 (PD3)
 */


/************************************************************************/
/* @brief Initialization of isr keys									*/
/*	setting PORTD for PD2 as ext. interrupt								*/
/************************************************************************/
void keys_isr_init_pd2();


/************************************************************************/
/* Initialization of isr keys											*/
/*	setting PORTD for PD3 as ext. interrupt								*/
/************************************************************************/
void keys_isr_init_pd3();

/** @} */