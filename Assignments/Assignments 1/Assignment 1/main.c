/*
 * Assignment 1.c
 *
 * Created: 25/02/2023 20.40.53
 * Author : skrue
 */ 

#include <avr/io.h>
#include <util/delay.h>

void init_keys(){
	DDRC = DDRC & 0b11000000;
	PORTC |= 0b00111111;
}

void init_led(){
	DDRA = DDRA | 0b001111111;
	PORTA = 0b001111111; 
}

uint8_t get_state(uint8_t pin_number) 
{
	if (PINC & (1 << pin_number)) 
	{
		return 1;
	} 
		else 
	{
		return 0;
	}
}

void set_led(uint8_t pin, uint8_t state)
{
	if(state == 0)
	{
		PORTA &= ~(1 << pin);
	}
	else
	{
		PORTA |= (1 << pin);
	}
}


void set_logical_operators(uint8_t inputA, uint8_t inputB)
{	
	//AND
	if(inputA & inputB) set_led(1, 1); // setPortState(PORTA, PA0);
	
	//OR
	if( (inputA | inputB) && !(inputA & inputB) ) set_led(2, 1); // setPortState(PORTA, PA1);
	
	//XOR
	if(inputA ^ inputB) set_led(3, 1); // setPortState(PORTA, PA2);
	
	//NAND
	if(!(inputA & inputB)) set_led(4, 1); // setPortState(PORTA, PA3);
	
	//NOR
	if(!(inputA | inputB)) set_led(5, 1); // setPortState(PORTA, PA4);
	
	//XNOR
	if(!(inputA ^ inputB)) set_led(6, 1); // setPortState(PORTA, PA5);
}

/*
void logic(uint8_t inputA, uint8_t inputB)
{
	 while (1) {
		 // Read the state of pins 0 and 1 on PORTC
		 uint8_t c = PINC & ((1 << PINC0) | (1 << PINC1));
		 // Compute the bitwise operations
		 uint8_t and = (c & 0x03);
		 uint8_t or = (c != 0x00);
		 uint8_t xor = (c ^ 0x03);
		 uint8_t nand = ~(c & 0x03);
		 uint8_t nor = ~(c != 0x00);
		 uint8_t xnor = ~(c ^ 0x03);
		 // Output the results on PORTA
		 PORTA = (and << PINA0) | (or << PINA1) | (xor << PINA2) |
		 (nand << PINA3) | (nor << PINA4) | (xnor << PINA5);
	 }
}
*/

int main(void)
{
	
	//init_keys();
	//init_led();
	
	
	while(1)
	{
		//set_led(0,get_state(0));
		//set_led(1,get_state(1));
		
		//logic(get_state(0),get_state(1));
		set_logical_operators(get_state(0),get_state(1));
		
	}
	
	return 0;
	
}