#include "ledArray.h"

void init_leds() {
	DDRA = 0xFF;
	PORTA = 0xFF;
}