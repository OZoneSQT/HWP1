/*
 * segment.h
 *
 * Created: 21/03/2023 20.41.02
 * Author: Michel Sommer, 273966
 */

 #pragma once

 #include <stdint.h>
 #include <avr/io.h>
 #include <avr/interrupt.h>


 #define RCK PORTB0
 #define SCK PORTB1
 #define SI PORTB2
 #define D1 PORTF0
 #define D2 PORTF1
 #define D3 PORTF2
 #define D4 PORTF3


 /************************************************************************/
 /* @brief Initialization of y-segment display                           */
 /************************************************************************/
 void display_init();


 /************************************************************************/
 /* @brief Prints value to 7 segment display                             */
 /************************************************************************/
 void display_printint_4s(uint16_t value);
 