/*
 * avrTimers.c
 *
 * Created: 07/03/2023 20.22.16
 * Author : skrue
 */ 

#include <avr/io.h>


int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
    }
}



/**
	atmega2560:
	
	8bit counter
	
	TCCR0A – Timer/Counter Control Register A
	
	 Compare Output Mode, non-PWM Mode
	 COM0A1 COM0A0
	 0		0		Normal port operation, OC0A disconnected
	 0		1		Toggle OC0A on Compare Match
	 1		0		Clear OC0A on Compare Match
	 1		1		Set OC0A on Compare Match
	 
	 Compare Output Mode, Fast PWM Mode
	 COM0A1 COM0A0
	 0		0		Normal port operation, OC0A disconnected
	 0		1		WGM02 = 0: Normal Port Operation, OC0A Disconnected
					WGM02 = 1: Toggle OC0A on Compare Match
	 1		0		Clear OC0A on Compare Match, set OC0A at BOTTOM (non-inverting mode)
	 1		1		Set OC0A on Compare Match, clear OC0A at BOTTOM (inverting mode)
	 
	 Compare Output Mode, Phase Correct PWM Mode
	 COM0A1 COM0A0
	 0		0		Normal port operation, OC0A disconnected
	 0		1		WGM02 = 0: Normal Port Operation, OC0A Disconnected
					WGM02 = 1: Toggle OC0A on Compare Match
	 1		0		Clear OC0A on Compare Match when up-counting. Set OC0A on Compare Match when down-counting
	 1		1		Set OC0A on Compare Match when up-counting. Clear OC0A on Compare Match when down-counting
	 

	 
	TCCR0B – Timer/Counter Control Register B
	
	Compare Output Mode, non-PWM Mode
	COM0B1	COM0B0
	0		0		Normal port operation, OC0B disconnected
	0		1		Toggle OC0B on Compare Match
	1		0		Clear OC0B on Compare Match
	1		1		Set OC0B on Compare Match
	
	Compare Output Mode, Fast PWM Mode
	COM0B1	COM0B0
	0		0		Normal port operation, OC0B disconnected
	0		1		Reserved
	1		0		Clear OC0B on Compare Match, set OC0B at BOTTOM (non-inverting mode)
	1		1		Set OC0B on Compare Match, clear OC0B at BOTTOM (inverting mode)
	
	Compare Output Mode, Phase Correct PWM Mode
	COM0B1	COM0B0
	0		0		Normal port operation, OC0B disconnected
	0		1		Reserved
	1		0		Clear OC0B on Compare Match when up-counting. Set OC0B on Compare Match when down-counting
	1		1		Set OC0B on Compare Match when up-counting. Clear OC0B on Compare Match when down-counting
	
	
	 Waveform Generation Mode Bit Description
	 Mode	WGM2	WGM1	WGM0	Timer/Counter Mode of Operation		TOP		Update of OCRx at	TOV Flag Set on	
	 0		0		0		0		Normal								0xFF	Immediate			MAX
	 1		0		0		1		PWM, Phase Correct					0xFF	TOP					BOTTOM
	 2		0		1		0		CTC									OCRA	Immediate			MAX
	 3		0		1		1		Fast PWM							0xFF	TOP					MAX
	 4		1		0		0		Reserved							–		–					–
	 5		1		0		1		PWM, Phase Correct					OCRA	TOP					BOTTOM
	 6		1		1		0		Reserved							–		–					–
	 7		1		1		1		Fast PWM							OCRA	BOTTOM				TOP
	 
	 Note:  1. MAX = 0xFF
			2. BOTTOM = 0x00
	 
	 
	 CS02:0: Clock Select
	 Clock Select Bit Description
	 CS02	CS01	CS00	Description
	 0		0		0		No clock source (Timer/Counter stopped)
	 0		0		1		clkI/O/(No prescaling)
	 0		1		0		clkI/O/8 (From prescaler)
	 0		1		1		clkI/O/64 (From prescaler)
	 1		0		0		clkI/O/256 (From prescaler)
	 1		0		1		clkI/O/1024 (From prescaler)
	 1		1		0		External clock source on T0 pin. Clock on falling edge
	 1		1		1		External clock source on T0 pin. Clock on rising edge
	 
	 
	 TCNT0 – Timer/Counter Register 
	 OCR0A – Output Compare Register A
	 OCR0B – Output Compare Register B
	 
	 
	 
	 
	 
	 
	 