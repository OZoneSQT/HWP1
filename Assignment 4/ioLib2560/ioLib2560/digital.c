/*
 * digital.c
 *
 * Created: 28/04/2023 19.59.28
 *  Author: skrue
 */ 

#include "ioLib2560.h"


// Function prototypes
void initOutputPin(Pin pin);
bool readPinStatus(Pin pin);

/*
	int main() {
		// Example usage for PB0
		Pin pb0 = {&DDRB, &PORTB, &PINB, 0};
		initOutputPin(pb0);

		bool status = readPinStatus(pb0);

		while (1) {
		}
		return 0;
	}
*/

void initOutputPin(Pin pin) {
	*pin.ddr |= (1 << pin.bit);
}

bool readPinStatus(Pin pin) {
	return (*pin.pin & (1 << pin.bit)) != 0;
}