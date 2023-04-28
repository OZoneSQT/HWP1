/*
 * timer.c
 *
 * Created: 28/04/2023 18.39.45
 *  Author: skrue
 */ 

#include "TimerLib2560.h"

uint32_t calculatePrescaler(uint32_t ms);

void init8BitTimer(uint32_t ms);
void init16BitTimer(Timer16Bit timer, ...);
void init32BitTimer(Timer32Bit timer, ...);

/*
int main() {
	// Example usage
	init8BitTimer0(10); // 10 ms
	init16BitTimer(TIMER1, 0, 0, 1, 500); // 1 s 500 ms
	Timer32Bit timer32 = {TIMER2, TIMER3};
	init32BitTimer(timer32, 1, 30, 10); // 1 h 30 m 10 s

	while (1) {
	}
	return 0;
}
*/

uint32_t calculatePrescaler(uint32_t ms) {
	uint32_t prescalerValues[] = {1, 8, 64, 256, 1024};
	uint32_t bestPrescaler = 1;

	for (uint8_t i = 0; i < sizeof(prescalerValues) / sizeof(prescalerValues[0]); i++) {
		if (ms >= prescalerValues[i]) {
			bestPrescaler = prescalerValues[i];
		}
	}
	return bestPrescaler;
}

void init8BitTimer(uint32_t ms) {
	uint32_t prescaler = calculatePrescaler(ms);

	TCCR0A |= (1 << WGM01); // Set CTC mode
	TCCR0B &= ~(1 << WGM02);

	uint8_t prescalerSetting;
	switch (prescaler) {
		case 1: prescalerSetting = 0x01; break;
		case 8: prescalerSetting = 0x02; break;
		case 64: prescalerSetting = 0x03; break;
		case 256: prescalerSetting = 0x04; break;
		case 1024: prescalerSetting = 0x05; break;
		default: prescalerSetting = 0x00; break;
	}
	TCCR0B |= prescalerSetting; // Set prescaler

	uint32_t compareValue = (F_CPU / prescaler / 1000) * ms - 1;
	if (compareValue > 255) {
		compareValue = 255;
	}
	OCR0A = (uint8_t)compareValue;
}

void init16BitTimer(Timer16Bit timer, ...) {
	va_list args;
	va_start(args, timer);

	uint8_t hours = va_arg(args, int);
	uint8_t minutes = va_arg(args, int);
	uint8_t seconds = va_arg(args, int);
	uint16_t ms = va_arg(args, int);

	va_end(args);

	uint32_t totalTimeMs = ((uint32_t)hours * 3600 + (uint32_t)minutes * 60 + (uint32_t)seconds) * 1000 + ms;
	uint32_t prescaler = calculatePrescaler(totalTimeMs);

	uint16_t prescalerSetting;
	switch (prescaler) {
		case 1: prescalerSetting = 0x01; break;
		case 8: prescalerSetting = 0x02; break;
		case 64: prescalerSetting = 0x03; break;
		case 256: prescalerSetting = 0x04; break;
		case 1024: prescalerSetting = 0x05; break;
		default: prescalerSetting = 0x00; break;
	}

	uint32_t compareValue = (F_CPU / prescaler / 1000) * totalTimeMs - 1;
	if (compareValue > 65535) {
		compareValue = 65535;
	}

	uint16_t compareValue16 = (uint16_t)compareValue;

	switch (timer) {
		case TIMER1:
		TCCR1A &= ~(1 << WGM10);
		TCCR1A &= ~(1 << WGM11);
		TCCR1B |= (1 << WGM12);
		TCCR1B &= ~(1 << WGM13);
		TCCR1B |= prescalerSetting;
		OCR1A = compareValue16;
		break;
		case TIMER2:
		// Implement TIMER2 case
		break;
		case TIMER3:
		// Implement TIMER3 case
		break;
		case TIMER4:
		// Implement TIMER4 case
		break;
		case TIMER5:
		// Implement TIMER5 case
		break;
	}
}

void init32BitTimer(Timer32Bit timer, ...) {
	va_list args;
	va_start(args, timer);

	uint8_t hours = va_arg(args, int);
	uint8_t minutes = va_arg(args, int);
	uint8_t seconds = va_arg(args, int);
	uint16_t ms = va_arg(args, int);

	va_end(args);

	uint32_t totalTimeMs = ((uint32_t)hours * 3600 + (uint32_t)minutes * 60 + (uint32_t)seconds) * 1000 + ms;

	// Split the 32-bit value into two 16-bit values
	uint16_t upper16 = totalTimeMs >> 16;
	uint16_t lower16 = totalTimeMs & 0xFFFF;

	// Initialize the two 16-bit timers
	init16BitTimer(timer.timer1, 0, 0, upper16 / 1000, upper16 % 1000);
	init16BitTimer(timer.timer2, 0, 0, lower16 / 1000, lower16 % 1000);
}
