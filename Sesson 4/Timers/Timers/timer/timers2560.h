/*
 * timers2560.h
 *
 * Created: 03/03/2023 19.19.23
 *  Author: skrue
 */ 

#pragma once

void init_timers_328();
void init_timers_2560();

timer_t calc_Freq( uint16_t targetFrq, CPU_CLK clkFreq, PRESCALER prescaler, RESOLUTION timerRes );
timer_t calc_Time( uint16_t targetTime, CPU_CLK clkFreq, PRESCALER prescaler, RESOLUTION timerRes );