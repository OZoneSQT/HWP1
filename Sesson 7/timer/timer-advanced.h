/*
 * timer_advanced.h
 *
 * Created: 15/04/2023 14.30.57
 *  Author: skrue
 */ 


#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

typedef enum {
	TIMER_1 = 1, TIMER_3 = 3
} timer_t;

void timer_init_8bit(uint8_t time_ms);
void timer_init_16bit(uint8_t time_ms, timer_t timer_number);
void timer_init_32bit(uint32_t time_ms);

#endif // TIMER_H
