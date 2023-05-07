/*
 * Assignment 2 Thermometer.c
 *
 * Created: 19/03/2023 10.55.30
 * Author: Michel Sommer, 273966
 */ 

#include "settings.h"
#include <stdint.h>
#include "thermometer/thermometer.h"


/*******************************************************************************/
int main(void)
{
    /* KISS - Keep It Simpel S****d */
	
	// Set timer in ms
	thermometer_init(DELAY_S);
	
    // Run thermometer
	thermometer_run();
	
	return 0;
}

/*******************************************************************************/