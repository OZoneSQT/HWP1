/*
 * delayTimer.c
 *
 * Created: 10/03/2023 08.50.54
 *  Author: skrue
 */ 
#include "delayTimer.h"
volatile uint8_t tot_overflow;
uint8_t halt = 0;

/*
	Description:    The pre-scaler and the timer count divide the timer-counter
	clock frequency to give a timer overflow interrupt rate:

	Interrupt rate =  16MHz / (prescaler * (255 - TCNT2))

	TCCR2B[b2:0]   Prescaler    Freq [KHz], Period [usec] after prescale
	0x0            (TC stopped)     0         0
	0x1                1        16000.        0.0625
	0x2                8         2000.        0.500
	0x3               32          500.        2.000
	0x4               64          250.        4.000
	0x5              128          125.        8.000
	0x6              256           62.5      16.000
	0x7             1024           15.625    64.000
 */
void init_delay_timer(uint8_t ms)
{
    // Setup Timer2 overflow to fire every 8ms (125Hz)
    // period [sec] = (1 / f_clock [sec]) * prescale * (255-count)
    // (1/16000000)  * 1024 * (255-130) = .008 sec

    TCCR2B = 0x00;        // Disable Timer2 while we set it up

    TCNT2  = 130;         // Reset Timer Count  (255-130) = execute ev 125-th T/C clock
    TIFR2  = 0x00;        // Timer2 INT Flag Reg: Clear Timer Overflow Flag
    TIMSK2 = 0x01;        // Timer2 INT Reg: Timer2 Overflow Interrupt Enable
    TCCR2A = 0x00;        // Timer2 Control Reg A: Wave Gen Mode normal
}

void delay()
{
	TCCR2B = 0x07;        // Timer2 Control Reg B: Timer Prescaler set to 1024
	
	while(halt == 1)
	{
		halt = 0;
	}
	
	TCCR2B = 0x00;        // Disable Timer2
}

ISR(TIMER2_OVF_vect) {
	
	halt = 1;

	TCNT2 = 130;     // reset timer ct to 130 out of 255
	TIFR2 = 0x00;    // timer2 int flag reg: clear timer overflow flag
};