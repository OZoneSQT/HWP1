/*
 * @file timer.c
 *
 * @Origin Date : 28/04/2023 18.39.45
 * @Author : Michel Sommer, 273966
 */ 

#include "timerLib2560.h"

/************************************************************************/
// Array to store interrupt callbacks
static Timer8BitInterruptCallback timer8BitInterruptCallback = NULL;
static TimerInterruptCallback timerInterruptCallbacks[5] = {NULL};
	
/************************************************************************/
// Initialization of functions
uint16_t calculatePrescaler(uint32_t time_ms);

/************************************************************************/
void init8BitTimer(uint8_t time_ms) {
	init8BitTimerCallback(time_ms, NULL);
}


/************************************************************************/
void init8BitTimerCallback(uint8_t time_ms, Timer8BitInterruptCallback callback) 
{
	uint16_t prescaler = calculatePrescaler(time_ms);
	uint8_t prescalerBits = 0;
	uint32_t tickCount;

	if (prescaler == 1) 
	{
		prescalerBits = (1 << CS00);
		tickCount = F_CPU / 1000;
	} 
	else if (prescaler == 8) 
	{
		prescalerBits = (1 << CS01);
		tickCount = F_CPU / 8000;
	} 
	else if (prescaler == 64) 
	{
		prescalerBits = (1 << CS00) | (1 << CS01);
		tickCount = F_CPU / 64000;
	} 
	else if (prescaler == 256) 
	{
		prescalerBits = (1 << CS02);
		tickCount = F_CPU / 256000;
	} 
	else 
	{ // 1024
		prescalerBits = (1 << CS02) | (1 << CS00);
		tickCount = F_CPU / 1024000;
	}

	if (callback != NULL) timer8BitInterruptCallback = callback;
	
	TCCR0A |= (1 << WGM01);  // Set CTC mode
	TCCR0B |= prescalerBits; // Set prescaler
	OCR0A = (uint8_t)((time_ms * tickCount) - 1); // Set the compare value
	TIMSK0 |= (1 << OCIE0A); // Enable compare interrupt
}


/************************************************************************/
void init16BitTimer(Timer16Bit timer, ...)
{
	uint32_t milliseconds = 0;
	uint8_t seconds = 0;
	uint8_t minutes = 0; 
	uint8_t hours = 0; 
	
	va_list args;
	va_start(args, timer);
		milliseconds = va_arg(args, MS_t);
		seconds = va_arg(args, SS_t);
		minutes = va_arg(args, MM_t);
		hours = va_arg(args, HH_t);
		
		milliseconds = ((uint32_t)hours * 3600000) + ((uint32_t)minutes * 60000) + ((uint32_t)seconds * 1000) + milliseconds;

	va_end(args);
	
	init16BitTimerCallback(timer, NULL, (MS_t)milliseconds);
}


/************************************************************************/
void init16BitTimerCallback(Timer16Bit timer, TimerInterruptCallback callback, ...) 
{
	uint32_t milliseconds = 0;
	uint8_t seconds = 0;
	uint8_t minutes = 0;
	uint8_t hours = 0;
	
	va_list args;
	va_start(args, timer);
		milliseconds = va_arg(args, MS_t);
		seconds = va_arg(args, SS_t);
		minutes = va_arg(args, MM_t);
		hours = va_arg(args, HH_t);
		
		milliseconds = ((uint32_t)hours * 3600000) + ((uint32_t)minutes * 60000) + ((uint32_t)seconds * 1000) + milliseconds;

	va_end(args);

	uint16_t prescaler = calculatePrescaler(milliseconds);
	uint16_t prescalerBits = 0;
	uint32_t tickCount;

	if (prescaler == 1) 
	{
		prescalerBits = (1 << CS10);
		tickCount = F_CPU / 1000;
	} 
	else if (prescaler == 8) 
	{
		prescalerBits = (1 << CS11);
		tickCount = F_CPU / 8000;
	} 
	else if (prescaler == 64) 
	{
		prescalerBits = (1 << CS10) | (1 << CS11);
		tickCount = F_CPU / 64000;
	} 
	else if (prescaler == 256) 
	{
		prescalerBits = (1 << CS12);
		tickCount = F_CPU / 256000;
	} 
	else 
	{ // 1024
		prescalerBits = (1 << CS12) | (1 << CS10);
		tickCount = F_CPU / 1024000;
	}

	switch (timer) 
	{
		case TIMER1:
			TCCR1B |= (1 << WGM12);  // Set CTC mode
			TCCR1B |= prescalerBits; // Set prescaler
			OCR1A = (uint16_t)((milliseconds * tickCount) - 1); // Set the compare value
			TIMSK1 |= (1 << OCIE1A); // Enable compare interrupt
			break;
		case TIMER2:
			TCCR2A |= (1 << WGM21);  // Set CTC mode
			TCCR2B |= prescalerBits; // Set prescaler
			OCR2A = (uint16_t)((milliseconds * tickCount) - 1); // Set the compare value
			TIMSK2 |= (1 << OCIE2A); // Enable compare interrupt
			break;
		case TIMER3:
			TCCR3B |= (1 << WGM32);  // Set CTC mode
			TCCR3B |= prescalerBits; // Set prescaler
			OCR3A = (uint16_t)((milliseconds * tickCount) - 1); // Set the compare value
			TIMSK3 |= (1 << OCIE3A); // Enable compare interrupt
			break;
		case TIMER4:
			TCCR4B |= (1 << WGM42);  // Set CTC mode
			TCCR4B |= prescalerBits; // Set prescaler
			OCR4A = (uint16_t)((milliseconds * tickCount) - 1); // Set the compare value
			TIMSK4 |= (1 << OCIE4A); // Enable compare interrupt
			break;
		case TIMER5:
			TCCR5B |= (1 << WGM52);  // Set CTC mode
			TCCR5B |= prescalerBits; // Set prescaler
			OCR5A = (uint16_t)((milliseconds * tickCount) - 1); // Set the compare value
			TIMSK5 |= (1 << OCIE5A); // Enable compare interrupt
			break;
	}
	
	if (callback != NULL) timerInterruptCallbacks[timer] = callback;
}


/************************************************************************/
void init32BitTimer(Timer16Bit timer1, Timer16Bit timer2, ...)
{
	uint32_t milliseconds = 0;
	uint8_t seconds = 0;
	uint8_t minutes = 0;
	uint8_t hours = 0;
	
	va_list args;
	va_start(args, timer2);
		milliseconds = va_arg(args, MS_t);
		seconds = va_arg(args, SS_t);
		minutes = va_arg(args, MM_t);
		hours = va_arg(args, HH_t);
	
	milliseconds = ((uint32_t)hours * 3600000) + ((uint32_t)minutes * 60000) + ((uint32_t)seconds * 1000) + milliseconds;

	va_end(args);

	init32BitTimer(timer1, timer2, NULL, (MS_t)milliseconds); 
}


/************************************************************************/
void init32BitTimerCallback(Timer16Bit timer1, Timer16Bit timer2, TimerInterruptCallback callback, ...) 
{
	uint32_t milliseconds = 0;
	uint8_t seconds = 0;
	uint8_t minutes = 0;
	uint8_t hours = 0;
	
	va_list args;
	va_start(args, timer2);
		milliseconds = va_arg(args, MS_t);
		seconds = va_arg(args, SS_t);
		minutes = va_arg(args, MM_t);
		hours = va_arg(args, HH_t);
	
	va_end(args);

	// Initialize timer1
	init16BitTimer(timer1, hours, minutes, seconds, milliseconds);

	// Calculate the overflow time for timer1
	uint32_t overflow_time_ms = (uint32_t)65535 * 1000 / (F_CPU / calculatePrescaler(milliseconds));

	// Calculate the number of timer1 overflows required to reach the desired time for timer2
	uint32_t overflow_count = milliseconds / overflow_time_ms;

	// Initialize timer2
	init16BitTimerCallback(timer2, callback, overflow_count * overflow_time_ms);
}


/************************************************************************/
uint16_t calculatePrescaler(uint32_t time_ms) 
{
	uint32_t max_ticks = 65535; // Maximum ticks for 16-bit timer

	if (time_ms * (F_CPU / 1000) < max_ticks) 
	{
		return 1;
	} 
	else if (time_ms * (F_CPU / 8000) < max_ticks) 
	{
		return 8;
	} 
	else if (time_ms * (F_CPU / 64000) < max_ticks) 
	{
		return 64;
	} 
	else if (time_ms * (F_CPU / 256000) < max_ticks) 
	{
		return 256;
	} 
	else 
	{
		return 1024;
	}
}


/************************************************************************/
