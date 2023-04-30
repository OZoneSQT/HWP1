/*
 * @file data.h
 *
 * @Origin Date : 28/04/2023 19.58.58
 * @Author : Michel Sommer, 273966
 */ 

#pragma once

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <stdbool.h>

# ifndef REF_VOLTAGE
#define REF_VOLTAGE 5.0
# endif /* REF_VOLTAGE */


// Trigger configuration values
typedef enum edge {
	ISC_LOW_LEVEL, ISC_ANY_CHANGE, ISC_FALLING, ISC_RISING
} Edge;


typedef enum pinChangeInterrupt {
	C_PIN0 = PCINT0, C_PIN1 = PCINT1, C_PIN2 = PCINT2, C_PIN3 = PCINT3, C_PIN4 = PCINT4, C_PIN5 = PCINT5,
	C_PIN6 = PCINT6, C_PIN7 =  PCINT7, C_PIN8 = PCINT8, C_PIN9 = PCINT9, C_PIN10 = PCINT10, C_PIN11 = PCINT11,
	C_PIN12 = PCINT12, C_PIN13 = PCINT13, C_PIN14 = PCINT14, C_PIN15 = PCINT15, C_PIN16 = PCINT16, C_PIN17 = PCINT17,
	C_PIN18 = PCINT18, C_PIN19 = PCINT19, C_PIN20 = PCINT20, C_PIN21 = PCINT21, C_PIN22 = PCINT22, C_PIN23 = PCINT23 
} PinChangeInterrupt;


typedef enum externalInterrupt {
	I_PIN0 = INT0, I_PIN1 = INT1, I_PIN2 = INT2, I_PIN3 = INT3, 
	I_PIN4 = INT4, I_PIN5 = INT5, I_PIN6 = INT6, I_PIN7 = INT7
} ExternalInterrupt;


// Digital Pin enumeration
typedef enum pin {
	D_PIN0 = PA0, D_PIN1 = PA1, D_PIN2 = PA2, D_PIN3 = PA3, D_PIN4 = PA4, D_PIN5 = PA5, D_PIN6 = PA6, D_PIN7 = PA7,
	D_PIN8 = PB0, D_PIN9 = PB1, D_PIN10 = PB2, D_PIN11 = PB3, D_PIN12 = PB4, D_PIN13 = PB5, D_PIN14 = PB6, D_PIN15 = PB7,
	D_PIN24 = PD0, D_PIN25 = PD1, D_PIN26 = PD2, D_PIN27 = PD3, D_PIN28 = PD4, D_PIN29 = PD5, D_PIN30 = PD6, D_PIN31 = PD7,
	D_PIN32 = PE0, D_PIN33 = PE1, D_PIN34 = PE2, D_PIN35 = PE3, D_PIN36 = PE4, D_PIN37 = PE5, D_PIN38 = PE6, D_PIN39 = PE7,
	D_PIN40 = PF0, D_PIN41 = PF1, D_PIN42 = PF2, D_PIN43 = PF3, D_PIN44 = PF4, D_PIN45 = PF5, D_PIN46 = PF6, D_PIN47 = PF7,
	D_PIN48 = PG0, D_PIN49 = PG1, D_PIN50 = PG2, D_PIN51 = PG3, D_PIN52 = PG4, D_PIN53 = PG5, 
	D_PIN54 = PH0, D_PIN55 = PH1, D_PIN56 = PH2, D_PIN57 = PH3, D_PIN58 = PH4, D_PIN59 = PH5, D_PIN60 = PH6, D_PIN61 = PH7
} Pin;


  /** Enumeration to limit input options, and maps to pin */
  typedef enum adcpin {
	  A_PIN0 = PF0, A_PIN1 = PF1, A_PIN2 = PF2, A_PIN3 = PF3, A_PIN4 = PF4, A_PIN5 = PF5, 
	  A_PIN6 = PF6, A_PIN7 = PF7, A_PIN8 = PK0, A_PIN9 = PK1, A_PIN10 = PK2, 
	  A_PIN11 = PK3, A_PIN12 = PK4, A_PIN13 = PK5, A_PIN14 = PK6, A_PIN15 = PK7
} AdcPin;

