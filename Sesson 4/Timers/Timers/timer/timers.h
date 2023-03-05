/*
 * timers.h
 *
 * Created: 03/03/2023 19.19.56
 *  Author: skrue
 */ 

#pragma once

#include <math.h>
#include <stdio.h>

enum CPU_CLK { CPU_8M, CPU_16M };
enum RESOLUTION { RES_8_BIT, RES_16_BIT };
enum PRESCALER { CLK_8, CLK_64, CLK_256, CLK_1024 };
	
typedef struct timer_t = (struct timer_t*)malloc(sizeof(struct timer_t));

typedef struct timer_t {
		uint16_t targetFrq;
		uint16_t realTime;
		uint16_t freq;
		uint16_t totalTicks;
		uint16_t overflows;
		uint16_t remainder;
	};
	
void init_timers_328();
void init_timers_2560();

void delTimer(struct timer_t *timer_t);

timer_t calc_Freq( uint16_t targetFrq, CPU_CLK clkFreq, PRESCALER prescaler, RESOLUTION timerRes );
timer_t calc_Time( uint16_t targetTime, CPU_CLK clkFreq, PRESCALER prescaler, RESOLUTION timerRes );
	
