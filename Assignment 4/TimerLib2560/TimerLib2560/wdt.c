/*
 * @file wdt.c
 *
 * @Origin Date : 28/04/2023 18.47.21
 * @Author : Michel Sommer, 273966
 */ 

#include "timerLib2560.h"


/************************************************************************/
// Initialization of functions
void initWDTInterrupt(uint32_t ms);


/************************************************************************/
void initWDTInterrupt(uint32_t ms) 
{
	uint8_t wdt_setting;

	if (ms <= 16) 
	{
		wdt_setting = WDTO_15MS;
		} 
		else if (ms <= 32) 
		{
		wdt_setting = WDTO_30MS;
		} 
		else if (ms <= 64) 
		{
		wdt_setting = WDTO_60MS;
		} 
		else if (ms <= 125) 
		{
		wdt_setting = WDTO_120MS;
		} 
		else if (ms <= 250) 
		{
		wdt_setting = WDTO_250MS;
		} 
		else if (ms <= 500) 
		{
		wdt_setting = WDTO_500MS;
		} 
		else if (ms <= 1000) 
		{
		wdt_setting = WDTO_1S;
		} 
		else if (ms <= 2000) 
		{
		wdt_setting = WDTO_2S;
		} 
		else if (ms <= 4000) 
		{
		wdt_setting = WDTO_4S;
		} 
		else 
		{
		wdt_setting = WDTO_8S;
	}

	cli(); // Disable global interrupts

	wdt_reset(); // Reset the WDT

	// Set up WDT interrupt
	WDTCSR |= (1 << WDCE) | (1 << WDE); // Enable WDT change
	WDTCSR = (1 << WDIE) | (1 << wdt_setting); // Set WDT interrupt and time period

	sei(); // Enable global interrupts
}

/************************************************************************/
