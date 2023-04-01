/*
 * timer.c
 *
 * Created: 31/03/2023 09.25.15
 * Author: Michel Sommer, 273966
 */

 #include "timer.h"


 /*******************************************************************************/
 static uint16_t get_prescaler(int16_t time_ms)
 {
 // Calculate the timer prescaler based on the input time
 uint16_t prescaler = 1;
 
 if (time_ms <= 1)
 {
 // no prescaler needed for 1ms or less
 prescaler = 1;
 }
 else if (time_ms <= 8)
 {
 // 8 prescaler for 2-8ms
 prescaler = 8;
 }
 else if (time_ms <= 64)
 {
 // 64 prescaler for 9-64ms
 prescaler = 64;
 }
 else if (time_ms <= 256)
 {
 // 256 prescaler for 65-256ms
 prescaler = 256;
 }
 else
 {
 // 1024 prescaler for 257ms or more
 prescaler = 1024;
 }
 
 return prescaler;
 }

 /*******************************************************************************/
 void timer_init_16bit(uint8_t time_ms,timer_t timer_number)
 {
 // Determine the timer registers to use based on the timer number
 volatile uint16_t* tccra_reg;
 volatile uint16_t* tccrb_reg;
 volatile uint16_t* ocr_reg;
 volatile uint16_t* timsk_reg;
 
 switch(timer_number)
 {
 case 1:
 tccra_reg = &TCCR1A;
 tccrb_reg = &TCCR1B;
 ocr_reg = &OCR1A;
 timsk_reg = &TIMSK1;
 break;
 
 case 3:
 tccra_reg = &TCCR3A;
 tccrb_reg = &TCCR3B;
 ocr_reg = &OCR3A;
 timsk_reg = &TIMSK3;
 break;
 
 default:
 return; // invalid timer number
 }
 
 uint16_t prescaler = get_prescaler(time_ms);
 
 // Calculate the timer compare value based on the input time and prescaler
 uint16_t compare_value = (uint16_t)((F_CPU / prescaler) * time_ms / 1000);
 
 // Set the timer to CTC mode and set the prescaler and compare value
 *tccra_reg = 0;
 *tccrb_reg = (1 << WGM12) | (prescaler & 0x07);
 *ocr_reg = compare_value;
 
 // Enable the timer interrupt
 *timsk_reg = (1 << OCIE1A);
 }

 /*******************************************************************************/
 void timer_init_8bit(uint8_t time_ms)
 {
 uint16_t prescaler = get_prescaler(time_ms);
 
 // Calculate the timer compare value based on the input time and prescaler
 uint8_t compare_value = (uint8_t)((F_CPU / prescaler) * time_ms / 1000);
 
 // Set the timer to CTC mode and set the prescaler and compare value
 TCCR2A = (1 << WGM21);
 TCCR2B = prescaler & 0x07;
 OCR2A = compare_value;
 
 // Enable the timer interrupt
 TIMSK2 = (1 << OCIE2A);
 }

 /*******************************************************************************/
