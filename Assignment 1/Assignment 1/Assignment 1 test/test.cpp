#include "gtest/gtest.h"

extern "C" 
{
#include <stdint.h>
#include <avr/io.h>
#include "leds/led_driver.h"
#include "leds/lightbar.h"
#include "keys/keys.h"
#include "logic/logic.h"
}

class AssignmentTest : public ::testing::Test
{
protected:
		void SetUp() override {}
		void TearDown() override {}
};

/*
 * LED Driver tests
 */
TEST_F(AssignmentTest, Test_DDRA_is_output_after_init) 
{
	init_leds();
	EXPECT_EQ(DDRA, 0x3f);
}

TEST_F(AssignmentTest, Test_leds_are_off_after_init) 
{
	init_leds();
	EXPECT_EQ(PORTA, 0x3f);
}

TEST_F(AssignmentTest, First_PA0_turn_on)
{
	init_leds();
	uint8_t ledPin = 1;

	set_led(ledPin, 1);

	EXPECT_EQ(0xfe, PORTA);	// 11111110
}

TEST_F(AssignmentTest, First_PA1_turn_on)
{
	init_leds();
	uint8_t ledPin = 2;

	set_led(ledPin, 1);

	EXPECT_EQ(0xfd, PORTA);	// 11111101
}

TEST_F(AssignmentTest, First_PA2_turn_on)
{
	init_leds();
	uint8_t ledPin = 3;

	set_led(ledPin, 1);

	EXPECT_EQ(0xfb, PORTA);	// 11111011
}

TEST_F(AssignmentTest, First_PA3_turn_on)
{
	init_leds();
	uint8_t ledPin = 4;

	set_led(ledPin, 1);

	EXPECT_EQ(0xf7, PORTA);	// 11110111
}

TEST_F(AssignmentTest, First_PA4_turn_on)
{
	init_leds();
	uint8_t ledPin = 5;

	set_led(ledPin, 1);

	EXPECT_EQ(0xef, PORTA); // 11101111
}

TEST_F(AssignmentTest, First_PA5_turn_on)
{
	init_leds();
	uint8_t ledPin = 6;

	set_led(ledPin, 1);

	EXPECT_EQ(0xdf, PORTA); // 11011111
}

TEST_F(AssignmentTest, First_PA6_turn_on)
{
	init_leds();
	uint8_t ledPin = 7;

	set_led(ledPin, 1);

	EXPECT_EQ(0xbf, PORTA);	// 10111111
}

TEST_F(AssignmentTest, First_PA7_turn_on)
{
	init_leds();
	uint8_t ledPin = 8;

	set_led(ledPin, 1);

	EXPECT_EQ(0x7f, PORTA); // 01111111
}

TEST_F(AssignmentTest, Turn_on_invalid_led)
{
	init_leds();
	uint8_t ledPin = 9;

	set_led(ledPin, 1);

	EXPECT_EQ(0xff, PORTA); // 11111111
}


/*
 * Lightbar tests
 */
TEST_F(AssignmentTest, Test_Lightbar_DDRA_is_output_after_init)
{
	init_lightbar();

	EXPECT_EQ(DDRA, 0xff);
	EXPECT_EQ(DDRC, 0xc);
	EXPECT_EQ(DDRD, 0xc);
}

TEST_F(AssignmentTest, Test_Lightbar_leds_are_off_after_init)
{
	init_lightbar();

	EXPECT_EQ(PORTA, 0xff);
	EXPECT_EQ(PORTC, 0xc);
	EXPECT_EQ(PORTD, 0xc);
}

TEST_F(AssignmentTest, Test_Lightbar_scan_keys_off_not_pressed)
{
	init_lightbar();

	EXPECT_EQ(0, scan_key());
}

TEST_F(AssignmentTest, Test_Lightbar_scan_keys_PC2_pressed)
{
	init_lightbar();
	PORTC = PORTC |= 0b00111011;

	EXPECT_EQ(1, scan_key());
}

TEST_F(AssignmentTest, Test_Lightbar_scan_keys_PC4_pressed)
{
	init_lightbar();
	PORTC = PORTC |= 0b00101111;

	EXPECT_EQ(1, scan_key());
}

TEST_F(AssignmentTest, Test_Lightbar_scan_keys_PD2_pressed)
{
	init_lightbar();
	PORTD = PORTD |= 0b00001000;

	EXPECT_EQ(1, scan_key());
}

TEST_F(AssignmentTest, Test_Lightbar_scan_keys_PC4_and_PD2_pressed)
{
	init_lightbar();
	PORTC = PORTC |= 0b00101111;
	PORTD = PORTD |= 0b00001000;

	EXPECT_EQ(2, scan_key());
}

TEST_F(AssignmentTest, Test_Lightbar_all_keys_pressed)
{
	init_lightbar();
	PORTC = PORTC |= 0b00000000;
	PORTD = PORTD |= 0b00000000;
	
	EXPECT_EQ(8, scan_key());
}

TEST_F(AssignmentTest, Test_Lightbar_output_all_keys_pressed)
{
	init_lightbar();
	PORTC = PORTC |= 0b00000000;
	PORTD = PORTD |= 0b00000000;

	EXPECT_EQ(PORTA, 0b11111111);
}

TEST_F(AssignmentTest, Test_Lightbar_output_PC0_pressed)
{
	init_lightbar();
	PORTC = PORTC |= 0b00111110;
	PORTD = PORTD |= 0b00001100;

	EXPECT_EQ(PORTA, 0b11111110);
}

TEST_F(AssignmentTest, Test_Lightbar_output_PC1_pressed)
{
	init_lightbar();
	PORTC = PORTC |= 0b00111101;
	PORTD = PORTD |= 0b00001100;

	EXPECT_EQ(PORTA, 0b11111110);
}

TEST_F(AssignmentTest, Test_Lightbar_output_PD2_pressed)
{
	init_lightbar();
	PORTC = PORTC |= 0b00111111;
	PORTD = PORTD |= 0b00001000;

	EXPECT_EQ(PORTA, 0b11111110);
}

TEST_F(AssignmentTest, Test_Lightbar_output_PC0_PC1_PC2_PC4_PD2_pressed)
{
	init_lightbar();
	PORTC = PORTC |= 0b00101100;
	PORTD = PORTD |= 0b00001000;

	EXPECT_EQ(PORTA, 0b11110000);
}


/*
 * KEY / SWITCH Driver tests
 */
TEST_F(AssignmentTest, Test_DDRC_is_input_after_init) 
{
	init_keys();

	EXPECT_EQ(DDRC, 0x3f);
}

TEST_F(AssignmentTest, Test_PINC_if_PUD_is_enabled_after_init) 
{
	init_keys();

	EXPECT_EQ(PINC, 0x3f);
}

TEST_F(AssignmentTest, Test_PC0_if_buttons_is_not_pressed) 
{
	EXPECT_EQ(1, !(PINC & PC0));
}

TEST_F(AssignmentTest, Test_PC1_if_buttons_is_not_pressed)
{
	init_keys();
	
	EXPECT_EQ(1, !(PINC & PC1));
}

TEST_F(AssignmentTest, Test_PC2_if_buttons_is_not_pressed)
{
	init_keys();
	
	EXPECT_EQ(1, !(PINC & PC2));
}

TEST_F(AssignmentTest, Test_PC3_if_buttons_is_not_pressed)
{
	init_keys();
	
	EXPECT_EQ(1, !(PINC & PC3));
}

TEST_F(AssignmentTest, Test_PC4_if_buttons_is_not_pressed)
{
	init_keys();
	
	EXPECT_EQ(1, !(PINC & PC4));
}

TEST_F(AssignmentTest, Test_PC5_if_buttons_is_not_pressed)
{
	init_keys();
	
	EXPECT_EQ(1, !(PINC & PC5));
}


/*
 * Test ISR keys, PD2, PD3 
 */
TEST_F(AssignmentTest, Test_DDRD_is_input_after_init)
{
	init_isrKeys();

	EXPECT_EQ(DDRC, 0xc);
}

TEST_F(AssignmentTest, Test_PIND_if_PUD_is_enabled_after_init)
{
	init_isrKeys();

	EXPECT_EQ(PINC, 0xc);
}

TEST_F(AssignmentTest, Test_PD2_if_buttons_is_not_pressed)
{
	init_keys();

	EXPECT_EQ(1, !(PIND & PD2));
}

TEST_F(AssignmentTest, Test_PD3_if_buttons_is_not_pressed)
{
	init_keys();

	EXPECT_EQ(1, !(PIND & PD3));
}

 /*
  * Logic tests
  */
TEST_F(AssignmentTest, Test_DDRA_is_output_after_init) 
{
	logic_indicator_leds();
	EXPECT_EQ(DDRA, 0xc0);
}

TEST_F(AssignmentTest, Test_leds_are_off_after_init) 
{
	logic_indicator_leds();
	EXPECT_EQ(PORTA, 0x3f);
}

//AND
TEST_F(AssignmentTest, Test_AND_PA0_leds_OFFinputA_OFFinputB_true) 
{
	logic_indicator_leds();
	uint8_t inputA = 0;
	uint8_t inputB = 0;

	set_logical_operators(inputA, inputB);

	EXPECT_EQ(PA0, !(PINA & PA0));
}

TEST_F(AssignmentTest, Test_AND_PA0_leds_ONinputA_OFFinputB_true) 
{
	logic_indicator_leds();
	uint8_t inputA = 1;
	uint8_t inputB = 0;

	set_logical_operators(inputA, inputB);

	EXPECT_EQ(PA0, !(PINA & PA0));
}

TEST_F(AssignmentTest, Test_AND_PA0_leds_OFFinputA_ONinputB_true) 
{
	logic_indicator_leds();
	uint8_t inputA = 0;
	uint8_t inputB = 1;

	set_logical_operators(inputA, inputB);

	EXPECT_EQ(PA0, !(PINA & PA0));
}

TEST_F(AssignmentTest, Test_AND_PA0_leds_ONinputA_ONinputB_true) 
{
	logic_indicator_leds();
	uint8_t inputA = 1;
	uint8_t inputB = 1;

	set_logical_operators(inputA, inputB);

	EXPECT_EQ(PA0, PINA & PA0);
}

//OR
TEST_F(AssignmentTest, Test_OR_PA1_leds_OFFinputA_OFFinputB_true) 
{
	logic_indicator_leds();
	uint8_t inputA = 0;
	uint8_t inputB = 0;

	set_logical_operators(1, inputB);

	EXPECT_EQ(PA0, !(PINA & PA1));
}

TEST_F(AssignmentTest, Test_OR_PA1_leds_ONinputA_OFFinputB_true) 
{
	logic_indicator_leds();
	uint8_t inputA = 1;
	uint8_t inputB = 0;

	set_logical_operators(inputA, inputB);

	EXPECT_EQ(PA0, PINA & PA1);
}

TEST_F(AssignmentTest, Test_OR_PA1_leds_OFFinputA_ONinputB_true) 
{
	logic_indicator_leds();
	uint8_t inputA = 0;
	uint8_t inputB = 1;

	set_logical_operators(inputA, inputB);

	EXPECT_EQ(PA0, PINA & PA1);
}

TEST_F(AssignmentTest, Test_OR_PA1_leds_ONinputA_ONinputB_true) 
{
	logic_indicator_leds();
	uint8_t inputA = 1;
	uint8_t inputB = 1;

	set_logical_operators(inputA, inputB);

	EXPECT_EQ(PA0, PINA & PA1);
}

//XOR
TEST_F(AssignmentTest, Test_XOR_PA2_leds_OFFinputA_OFFinputB_true) 
{
	logic_indicator_leds();
	uint8_t inputA = 0;
	uint8_t inputB = 0;

	set_logical_operators(1, inputB);

	EXPECT_EQ(PA0, PINA & PA2);
}

TEST_F(AssignmentTest, Test_XOR_PA2_leds_ONinputA_OFFinputB_true) 
{
	logic_indicator_leds();
	uint8_t inputA = 1;
	uint8_t inputB = 0;

	set_logical_operators(inputA, inputB);

	EXPECT_EQ(PA0, !(PINA & PA0));
}

TEST_F(AssignmentTest, Test_XOR_PA2_leds_OFFinputA_ONinputB_true) 
{
	logic_indicator_leds();
	uint8_t inputA = 0;
	uint8_t inputB = 1;

	set_logical_operators(inputA, inputB);

	EXPECT_EQ(PA0, !(PINA & PA2));
}

TEST_F(AssignmentTest, Test_XOR_PA2_leds_ONinputA_ONinputB_true) 
{
	logic_indicator_leds();
	uint8_t inputA = 1;
	uint8_t inputB = 1;

	set_logical_operators(inputA, inputB);

	EXPECT_EQ(PA0, PINA & PA2);
}

//NAND
TEST_F(AssignmentTest, Test_NAND_PA3_leds_OFFinputA_OFFinputB_true) 
{
	logic_indicator_leds();
	uint8_t inputA = 0;
	uint8_t inputB = 0;

	set_logical_operators(inputA, inputB);

	EXPECT_EQ(PA0, PINA & PA3);
}

TEST_F(AssignmentTest, Test_NAND_PA3_leds_ONinputA_OFFinputB_true) 
{
	logic_indicator_leds();
	uint8_t inputA = 1;
	uint8_t inputB = 0;

	set_logical_operators(inputA, inputB);

	EXPECT_EQ(PA0, PINA & PA3);
}

TEST_F(AssignmentTest, Test_NAND_PA3_leds_OFFinputA_ONinputB_true) 
{
	logic_indicator_leds();
	uint8_t inputA = 0;
	uint8_t inputB = 1;

	set_logical_operators(inputA, inputB);

	EXPECT_EQ(PA0, PINA & PA3);
}

TEST_F(AssignmentTest, Test_NAND_PA3_leds_ONinputA_ONinputB_true) 
{
	logic_indicator_leds();
	uint8_t inputA = 1;
	uint8_t inputB = 1;

	set_logical_operators(inputA, inputB);

	EXPECT_EQ(PA0, !(PINA & PA3));
}

//NOR
TEST_F(AssignmentTest, Test_NOR_PA4_leds_OFFinputA_OFFinputB_true) 
{
	logic_indicator_leds();
	uint8_t inputA = 0;
	uint8_t inputB = 0;

	set_logical_operators(1, inputB);

	EXPECT_EQ(PA0, !(PINA & PA4));
}

TEST_F(AssignmentTest, Test_NOR_PA4_leds_ONinputA_OFFinputB_true) 
{
	logic_indicator_leds();
	uint8_t inputA = 1;
	uint8_t inputB = 0;

	set_logical_operators(inputA, inputB);

	EXPECT_EQ(PA0, !(PINA & PA4));
}

TEST_F(AssignmentTest, Test_NOR_PA4_leds_OFFinputA_ONinputB_true) 
{
	logic_indicator_leds();
	uint8_t inputA = 0;
	uint8_t inputB = 1;

	set_logical_operators(inputA, inputB);

	EXPECT_EQ(PA0, !(PINA & PA4));
}

TEST_F(AssignmentTest, Test_NOR_PA4_leds_ONinputA_ONinputB_true) 
{
	logic_indicator_leds();
	uint8_t inputA = 1;
	uint8_t inputB = 1;

	set_logical_operators(inputA, inputB);

	EXPECT_EQ(PA0, PINA & PA4);
}

//XNOR
TEST_F(AssignmentTest, Test_XNOR_PA5_leds_OFFinputA_OFFinputB_true) 
{
	logic_indicator_leds();
	uint8_t inputA = 0;
	uint8_t inputB = 0;

	set_logical_operators(1, inputB);

	EXPECT_EQ(PA0, !(PINA & PA5));
}

TEST_F(AssignmentTest, Test_XNOR_PA5_leds_ONinputA_OFFinputB_true) 
{
	logic_indicator_leds();
	uint8_t inputA = 1;
	uint8_t inputB = 0;

	set_logical_operators(inputA, inputB);

	EXPECT_EQ(PA0, PINA & PA5);
}

TEST_F(AssignmentTest, Test_XNOR_PA5_leds_OFFinputA_ONinputB_true) 
{
	logic_indicator_leds();
	uint8_t inputA = 0;
	uint8_t inputB = 1;

	set_logical_operators(inputA, inputB);

	EXPECT_EQ(PA0, PINA & PA5);
}

TEST_F(AssignmentTest, Test_XNOR_PA5_leds_ONinputA_ONinputB_true) 
{
	logic_indicator_leds();
	uint8_t inputA = 1;
	uint8_t inputB = 1;
	
	set_logical_operators(inputA, inputB);

	EXPECT_EQ(PA0, !(PINA & PA5));
}
