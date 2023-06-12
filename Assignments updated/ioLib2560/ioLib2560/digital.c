/*
 * @file digital.c
 *
 * @Origin Date : 28/04/2023 19.59.28
 * @Author : Michel Sommer, 273966
 */ 

#include "ioLib2560.h"


/************************************************************************/
// Set output pin high
void setOutputPinHigh(uint8_t pin) 
{
	volatile uint8_t* port = NULL;
	
	// Determine the appropriate PORTx register based on the pin number
	if (pin >= D0 && pin <= D7) 
	{
		port = &PORTE;
	} 
	else if (pin >= D8 && pin <= D13) 
	{
		port = &PORTB;
	} 
	else if (pin >= D14 && pin <= D19) 
	{
		port = &PORTJ;
	} 
	else if (pin >= D20 && pin <= D29) 
	{
		port = &PORTA;
	} 
	else if (pin >= D30 && pin <= D37) 
	{
		port = &PORTC;
	} 
	else if (pin >= D38 && pin <= D41) 
	{
		port = &PORTD;
	} 
	else if (pin >= D42 && pin <= D49)
	{
		port = &PORTL;
	} 
	else if (pin >= D50 && pin <= D53) 
	{
		port = &PORTB;
	}
	
	if (port != NULL) 
	{
		// Set the pin high
		*port |= (1 << (pin % 8));
	}
}

/************************************************************************/
// Set output pin low
void setOutputPinLow(uint8_t pin) 
{
	volatile uint8_t* port = NULL;
	
	// Determine the appropriate PORTx register based on the pin number
	if (pin >= D0 && pin <= D7) 
	{
		port = &PORTE;
	} 
	else if (pin >= D8 && pin <= D13) 
	{
		port = &PORTB;
	} 
	else if (pin >= D14 && pin <= D19) 
	{
		port = &PORTJ;
	} 
	else if (pin >= D20 && pin <= D29) 
	{
		port = &PORTA;
	} 
	else if (pin >= D30 && pin <= D37) 
	{
		port = &PORTC;
	} 
	else if (pin >= D38 && pin <= D41) 
	{
		port = &PORTD;
	} 
	else if (pin >= D42 && pin <= D49) 
	{
		port = &PORTL;
	} 
	else if (pin >= D50 && pin <= D53)
	{
		port = &PORTB;
	}
	
	if (port != NULL) 
	{
		// Set the pin low
		*port &= ~(1 << (pin % 8));
	}
}

/************************************************************************/
// Initialize output pin
void initOutputPin(uint8_t pin) 
{
	volatile uint8_t* ddr = NULL;
	
	// Determine the appropriate DDRx register based on the pin number
	if (pin >= D0 && pin <= D7) 
	{
		ddr = &DDRE;
	} 
	else if (pin >= D8 && pin <= D13) 
	{
		ddr = &DDRB;
	} 
	else if (pin >= D14 && pin <= D19) 
	{
		ddr = &DDRJ;
	} 
	else if (pin >= D20 && pin <= D29) 
	{
		ddr = &DDRA;
	} 
	else if (pin >= D30 && pin <= D37) 
	{
		ddr = &DDRC;
	} 
	else if (pin >= D38 && pin <= D41) 
	{
		ddr = &DDRD;
	} 
	else if (pin >= D42 && pin <= D49) 
	{
		ddr = &DDRL;
	} 
	else if (pin >= D50 && pin <= D53) 
	{
		ddr = &DDRB;
	}
	
	if (ddr != NULL) 
	{
		// Set the pin as an output
		*ddr |= (1 << (pin % 8));
	}
}

/************************************************************************/
// Initialize input pin
void initInputPin(uint8_t pin) 
{
	volatile uint8_t* ddr = NULL;
	
	// Determine the appropriate DDRx register based on the pin number
	if (pin >= D0 && pin <= D7) 
	{
		ddr = &DDRE;
	} 
	else if (pin >= D8 && pin <= D13) 
	{
		ddr = &DDRB;
	} 
	else if (pin >= D14 && pin <= D19) 
	{
		ddr = &DDRJ;
	} 
	else if (pin >= D20 && pin <= D29) 
	{
		ddr = &DDRA;
	} 
	else if (pin >= D30 && pin <= D37) 
	{
		ddr = &DDRC;
	} 
	else if (pin >= D38 && pin <= D41) 
	{
		ddr = &DDRD;
	} 
	else if (pin >= D42 && pin <= D49) 
	{
		ddr = &DDRL;
	} 
	else if (pin >= D50 && pin <= D53) 
	{
		ddr = &DDRB;
	}
	
	if (ddr != NULL) 
	{
		// Set the pin as an input
		*ddr &= ~(1 << (pin % 8));
	}
}


/************************************************************************/
// Read input pin status
uint8_t readInputPinStatus(uint8_t pin) 
{
	volatile uint8_t* pinRegister = NULL;
	
	// Determine the appropriate PINx register based on the pin number
	if (pin >= D0 && pin <= D7) 
	{
		pinRegister = &PINE;
	} 
	else if (pin >= D8 && pin <= D13) 
	{
		pinRegister = &PINB;
	} 
	else if (pin >= D14 && pin <= D19) 
	{
		pinRegister = &PINJ;
	} 
	else if (pin >= D20 && pin <= D29) 
	{
		pinRegister = &PINA;
	} 
	else if (pin >= D30 && pin <= D37) 
	{
		pinRegister = &PINC;
	} 
	else if (pin >= D38 && pin <= D41) 
	{
		pinRegister = &PIND;
	} 
	else if (pin >= D42 && pin <= D49) 
	{
		pinRegister = &PINL;
	} 
	else if (pin >= D50 && pin <= D53) 
	{
		pinRegister = &PINB;
	}
	
	if (pinRegister != NULL) 
	{
		// Read the status of the pin
		return (*pinRegister >> (pin % 8)) & 0x01;
	}
	
	return 0; // Return 0 for invalid pins
}

/************************************************************************/
// Read input pin status, debounce protected
uint8_t readInputPinStatusDebounce(uint8_t pin)
{
	uint8_t pressed = readInputPinStatus(pin);
	
	if (pressed) 
	{
		_delay_ms(DEBOUNCE_DELAY);
		pressed = readInputPinStatus(pin);
	}

	return pressed;
}

/************************************************************************/
// Toggle output pin
void toggleOutputPin(uint8_t pin) 
{
	volatile uint8_t* port = NULL;
	
	// Determine the appropriate PORTx register based on the pin number
	if (pin >= D0 && pin <= D7) 
	{
		port = &PORTE;
	} 
	else if (pin >= D8 && pin <= D13) 
	{
		port = &PORTB;
	} 
	else if (pin >= D14 && pin <= D19) 
	{
		port = &PORTJ;
	} 
	else if (pin >= D20 && pin <= D29) 
	{
		port = &PORTA;
	} 
	else if (pin >= D30 && pin <= D37) 
	{
		port = &PORTC;
	} 
	else if (pin >= D38 && pin <= D41) 
	{
		port = &PORTD;
	} 
	else if (pin >= D42 && pin <= D49) 
	{
		port = &PORTL;
	} 
	else if (pin >= D50 && pin <= D53) 
	{
		port = &PORTB;
	}
	
	if (port != NULL) 
	{
		// Toggle the state of the pin
		*port ^= (1 << (pin % 8));
	}
}

/************************************************************************/
