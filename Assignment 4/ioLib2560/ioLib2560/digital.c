/*
 * @file digital.c
 *
 * @Origin Date : 28/04/2023 19.59.28
 * @Author : Michel Sommer, 273966
 */ 

#include "ioLib2560.h"


/************************************************************************/
// Set output pin high
void setOutputPinHigh(Pin pin)
{
	if (pin <= PA7)
	{
		PORTA |= (1 << (pin % 8));
	}
	else if (pin <= PB7)
	{
		PORTB |= (1 << (pin % 8));
	}
	else if (pin <= PC7)
	{
		PORTC |= (1 << (pin % 8));
	}
	else if (pin <= PD7)
	{
		PORTD |= (1 << (pin % 8));
	}
	else if (pin <= PE7)
	{
		PORTE |= (1 << (pin % 8));
	}
	else if (pin <= PF7)
	{
		PORTF |= (1 << (pin % 8));
	}
	else if (pin <= PG5)
	{
		PORTG |= (1 << (pin % 8));
	}
	else if (pin <= PH7)
	{
		PORTH |= (1 << (pin % 8));
	}
	else
	{
		return;
	}
}

/************************************************************************/
// Set output pin low
void setOutputPinLow(Pin pin)
{
	if (pin <= PA7)
	{
		PORTA &= ~(1 << (pin % 8));
	}
	else if (pin <= PB7)
	{
		PORTB &= ~(1 << (pin % 8));
	}
	else if (pin <= PC7)
	{
		PORTC &= ~(1 << (pin % 8));
	}
	else if (pin <= PD7)
	{
		PORTD &= ~(1 << (pin % 8));
	}
	else if (pin <= PE7)
	{
		PORTE &= ~(1 << (pin % 8));
	}
	else if (pin <= PF7)
	{
		PORTF &= ~(1 << (pin % 8));
	}
	else if (pin <= PG5)
	{
		PORTG &= ~(1 << (pin % 8));
	}
	else if (pin <= PH7)
	{
		PORTH &= ~(1 << (pin % 8));
	}
	else
	{
		return;
	}
}

/************************************************************************/
// Initialize output pin
void initOutputPin(Pin pin) 
{
	if (pin <= PA7) 
	{
		DDRA |= (1 << (pin % 8));
	} 
	else if (pin <= PB7) 
	{
		DDRB |= (1 << (pin % 8));
	} 
	else if (pin <= PC7) 
	{
		DDRC |= (1 << (pin % 8));
	} 
	else if (pin <= PD7) 
	{
		DDRD |= (1 << (pin % 8));
	} 
	else if (pin <= PE7) 
	{
		DDRE |= (1 << (pin % 8));
	} 
	else if (pin <= PF7) 
	{
		DDRF |= (1 << (pin % 8));
	} 
	else if (pin <= PG5) 
	{
		DDRG |= (1 << (pin % 8));
	} 
	else if (pin <= PH7) 
	{
		DDRH |= (1 << (pin % 8));
	}
	else
	{
		return;
	}
	
	setOutputPinLow(pin); // Set output low
}

/************************************************************************/
// Initialize input pin
void initInputPin(Pin pin) 
{
	if (pin <= PA7) 
	{
		DDRA &= ~(1 << (pin % 8));
	} 
	else if (pin <= PB7) 
	{
		DDRB &= ~(1 << (pin % 8));
	} 
	else if (pin <= PC7) 
	{
		DDRC &= ~(1 << (pin % 8));
	} else if (pin <= PD7) 
	{
		DDRD &= ~(1 << (pin % 8));
	} 
	else if (pin <= PE7) 
	{
		DDRE &= ~(1 << (pin % 8));
	} 
	else if (pin <= PF7) 
	{
		DDRF &= ~(1 << (pin % 8));
	} 
	else if (pin <= PG5) 
	{
		DDRG &= ~(1 << (pin % 8));
	} 
	else if (pin <= PH7) 
	{
		DDRH &= ~(1 << (pin % 8));
	}
	else
	{
		return;
	}

	setOutputPinHigh(pin); // Activates pull up resistor
}

/************************************************************************/
// Read input pin status
bool readInputPinStatus(Pin pin) 
{
	bool result = false;

	if (pin <= PA7) 
	{
		result = PINA & (1 << (pin % 8));
	} 
	else if (pin <= PB7) 
	{
		result = PINB & (1 << (pin % 8));
	} 
	else if (pin <= PC7) 
	{
		result = PINC & (1 << (pin % 8));
	} 
	else if (pin <= PD7) 
	{
		result = PIND & (1 << (pin % 8));
	}
	else if (pin <= PE7) 
	{
		result = PINE & (1 << (pin % 8));
	} 
	else if (pin <= PF7) 
	{
		result = PINF & (1 << (pin % 8));
	} 
	else if (pin <= PG5) 
	{
		result = PING & (1 << (pin % 8));
	} 
	else if (pin <= PH7) 
	{
		result = PINH & (1 << (pin % 8));
	}
	
	return result;
}

/************************************************************************/
// Read input pin status, debounce protected
bool readInputPinStatusDebounce(Pin pin)
{
	bool pressed = readInputPinStatus(pin);
	
	if (pressed) 
	{
		_delay_ms(DEBOUNCE_DELAY);
		pressed = readInputPinStatus(pin);
	}

	return pressed;
}

/************************************************************************/
// Toggle output pin
void toggleOutputPin(Pin pin) 
{
	if (pin <= PA7) 
	{
		PORTA ^= (1 << (pin % 8));
	} 
	else if (pin <= PB7) 
	{
		PORTB ^= (1 << (pin % 8));
	} 
	else if (pin <= PC7) 
	{
		PORTC ^= (1 << (pin % 8));
	} 
	else if (pin <= PD7) 
	{
		PORTD ^= (1 << (pin % 8));
	} 
	else if (pin <= PE7) 
	{
		PORTE ^= (1 << (pin % 8));
	} 
	else if (pin <= PF7) 
	{
		PORTF ^= (1 << (pin % 8));
	} 
	else if (pin <= PG5) 
	{
		PORTG ^= (1 << (pin % 8));
	} 
	else if (pin <= PH7) 
	{
		PORTH ^= (1 << (pin % 8));
	}
	else
	{
		return;
	}
}

/************************************************************************/
