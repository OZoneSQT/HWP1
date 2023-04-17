#include "timer-advanced.h"
#include <avr/io.h>
#include <avr/interrupt.h>

#define F_CPU 16000000UL

void timer_calc_prescaler_and_ocr(uint32_t time_ms, uint16_t *ocr, uint8_t *prescaler);

ISR(TIMER1_OVF_vect) {
	// Handle Timer1 overflow interrupt here
}

ISR(TIMER3_OVF_vect) {
	// Handle Timer3 overflow interrupt here
}

void timer_init_8bit(uint8_t time_ms) {
	uint16_t ocr;
	uint8_t prescaler;

	timer_calc_prescaler_and_ocr(time_ms, &ocr, &prescaler);

	TCCR1A = 0;
	TCCR1B = prescaler;
	TCNT1 = 0;
	OCR1A = ocr;

	TIMSK1 |= (1 << TOIE1); // Enable Timer1 overflow interrupt
	sei(); // Enable global interrupts
}

void timer_init_16bit(uint8_t time_ms, timer_t timer_number) {
	uint16_t ocr;
	uint8_t prescaler;

	timer_calc_prescaler_and_ocr(time_ms, &ocr, &prescaler);

	if (timer_number == TIMER_1) {
		TCCR1A = 0;
		TCCR1B = prescaler;
		TCNT1 = 0;
		OCR1A = ocr;

		TIMSK1 |= (1 << TOIE1); // Enable Timer1 overflow interrupt
		} else if (timer_number == TIMER_3) {
		TCCR3A = 0;
		TCCR3B = prescaler;
		TCNT3 = 0;
		OCR3A = ocr;

		TIMSK3 |= (1 << TOIE3); // Enable Timer3 overflow interrupt
	}

	sei(); // Enable global interrupts
}

void timer_init_32bit(uint32_t time_ms) {
	uint32_t overflow_count;

	overflow_count = (F_CPU / 1024) * (uint32_t)time_ms / 1000;

	TCCR1A = 0;
	TCCR1B = (1 << CS12) | (1 << CS10); // Prescaler 1024
	TCNT1 = 0;

	TCCR3A = 0;
	TCCR3B = (1 << CS32) | (1 << CS30); // Prescaler 1024
	TCNT3 = 0;

	OCR1A = overflow_count & 0xFFFF;
	OCR3A = (overflow_count >> 16) & 0xFFFF;

	TIMSK1 |= (1 << TOIE1); // Enable Timer1 overflow interrupt
	TIMSK3 |= (1 << TOIE3); // Enable Timer3 overflow interrupt

	sei(); // Enable global interrupts
}

void timer_calc_prescaler_and_ocr(uint32_t time_ms, uint16_t *ocr, uint8_t *prescaler) {
	uint32_t overflow_count;
	uint32_t prescalers[5] = {1, 8, 64, 256, 1024};
	uint8_t prescaler_bits[5] = {(1 << CS10), (1 << CS11), (1 << CS11) | (1 << CS10), (1 << CS12), (1 << CS12) | (1 << CS10)};
	uint8_t i;

	for (i = 0; i < 5; i++) {
		overflow_count = (F_CPU / prescalers[i]) * (uint32_t)time_ms / 1000;

		if (overflow_count <= 65535) {
			*ocr = (uint16_t)overflow_count;
			*prescaler = prescaler_bits[i];
			break;
		}
	}
}