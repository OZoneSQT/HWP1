/*
 * timers.c
 *
 * Created: 03/03/2023 19.20.10
 *  Author: skrue
 */ 

#include "timers.h"

void init_timers_328(){}
void init_timers_2560(){}

void delTimer(struct timer_t *timer_t) 
{
	if (timer_t != NULL) {
		free(timer_t->targetFrq);
		free(timer_t->realTime);
		free(timer_t->freq);
		free(timer_t->totalTicks);
		free(timer_t->overflows);
		free(timer_t->remainder);
		free(timer_t);
	}
}

timer_t calc_Freq( uint16_t targetFrq, CPU_CLK clkFreq, PRESCALER prescaler, RESOLUTION timerRes )
{
	uint32_t clk = 0;
	uint16_t scaler = 8;
	uint16_t res = 16;
	
	if (clkFreq == CPU_8M) { clk = 8000000;}
	if (clkFreq == CPU_16M) { clk = 16000000;}
	
	if (timerRes == RES_8_BIT) { res = 8;}
	if (timerRes == RES_16_BIT) { res = 16;}
	
	if (prescaler == CLK_8) { scaler = 8;}
	if (prescaler == CLK_64) { scaler = 64;}
	if (prescaler == CLK_256) { scaler = 256;}
	if (prescaler == CLK_1024) { scaler = 1024;}
	
	timer_t.realTime = 1 / targetFrq;
	timer_t.targetFrq = targetFrq:
	timer_t.freq = (uint16_t) clk / scaler;
	timer_t.totalTicks = timer_t.realTime * timer_t.freq;
	timer_t.overflows = floor(timer_t.totalTicks / pow(2, res));
	timer_t.remainder = timer_t.totalTicks - (timer_t.overflows * pow(2, res));
	
	return timer_t;
}

timer_t calc_Time( uint16_t targetTime, CPU_CLK clkFreq, PRESCALER prescaler, RESOLUTION timerRes )
{
	uint32_t clk = 0;
	uint16_t scaler = 8;
	uint16_t res = 16;
	
	if (clkFreq == CPU_8M) { clk = 8000000;}
	if (clkFreq == CPU_16M) { clk = 16000000;}
	
	if (timerRes == RES_8_BIT) { res = 8;}
	if (timerRes == RES_16_BIT) { res = 16;}
		
	if (prescaler == CLK_8) { scaler = 8;}
	if (prescaler == CLK_64) { scaler = 64;}
	if (prescaler == CLK_256) { scaler = 256;}
	if (prescaler == CLK_1024) { scaler = 1024;}
	
	timer_t.realTime = targetTime;
	timer_t.targetFrq = 1 / targetTime;
	timer_t.freq = (uint16_t) clk / scaler;
	timer_t.totalTicks = timer_t.realTime * timer_t.freq;
	timer_t.overflows = floor(timer_t.totalTicks / pow(2, res));
	timer_t.remainder = timer_t.totalTicks - (timer_t.overflows * pow(2, res));
	
	return timer_t;
}


/************************************************************************/
/* TCNTn ( Timer / Counter register )                                   */
/* TOVn  ( Timer Overflow flag )										*/
/* TCCRn ( Timer Counter control register )								*/
/* OCRn  ( output compare register )									*/
/* OCFn  ( output compare match flag )									*/
/************************************************************************/