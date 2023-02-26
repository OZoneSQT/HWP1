/*
 * Assignment 1.c
 *
 * Created: 25/02/2023 20.40.53
 * Author : skrue
 */ 

#include <avr/io.h>

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
	--pin_number;
	
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
	--pin;
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
	// Compute the bitwise operations
	uint8_t and = (inputA & inputB);
	uint8_t or = (inputA | inputB);
	uint8_t xor = (inputA ^ inputB);
	uint8_t nand = ~(inputA & inputB);
	uint8_t nor = ~(inputA | inputB);
	uint8_t xnor = ~(inputA ^ inputB);
	
	//setting output
	set_led(1, and);
	set_led(2, or);
	set_led(3, xor);
	set_led(4, nand);
	set_led(5, nor);
	set_led(6, xnor);
}

int main(void)
{
	init_keys();
	init_led();
	
	uint8_t s1 = 0;
	uint8_t s2 = 0;
	
	while(1)
	{
		s1 = get_state(1);
		s2 = get_state(2);
		
		set_logical_operators(s1,s2);
	}
	
	return 0;
}