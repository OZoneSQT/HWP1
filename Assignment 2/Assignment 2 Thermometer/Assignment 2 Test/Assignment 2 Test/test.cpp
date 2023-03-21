/*
 * file/ gTest
 *
 * Created: 21/03/2023 11.01.23
 * Author: Michel Sommer, 273966
 *
 * IMPORTANT:	Import avr toolchain from: "C:\Program Files (x86)\Arduino\hardware\tools\avr\avr"
 *				Insted of using: "C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\avr\include"
 */

// Include test frameworks
#include "gtest/gtest.h"
#include "../../../../../fff/fff.h"

extern "C"
{
	#include <stdint.h>
	#include <avr/io.h>

	#include "adc/adc.h"
	#include "keys/keys.h"
	#include "leds/leds.h"
	#include "leds/lightbar.h"
	#include "leds/logic.h"
	#include "timer/pmw.h"
	#include "leds/segment-display.h"
	#include "thermometer/thermometer.h"
	#include "timer/timer.h"
}


// Setup FFF functions
DEFINE_FFF_GLOBALS;

//ADC
FAKE_VOID_FUNC(adc_init_8bit, adcPin_t);
FAKE_VOID_FUNC(adc_init_10bit, adcPin_t);
FAKE_VALUE_FUNC(uint16_t, adc_read, adcPin_t);

//KEYS
FAKE_VOID_FUNC(keys_init);
FAKE_VOID_FUNC(keys_isr_init);
FAKE_VOID_FUNC(keys_isr_init_pd2);
FAKE_VOID_FUNC(keys_isr_init_pd3);
FAKE_VALUE_FUNC(uint8_t, keys_get_state, uint8_t);

//LEDS
FAKE_VOID_FUNC(leds_init);
FAKE_VOID_FUNC(leds_set, uint8_t, uint8_t);

//LIGHT_BAR
FAKE_VOID_FUNC(lightbar_init);
FAKE_VOID_FUNC(lightbar_isr_keys_init);
FAKE_VOID_FUNC(lightbar_scan_key);
FAKE_VOID_FUNC(lightbar_level, uint8_t);

//LOGIC
FAKE_VOID_FUNC(logic_indicator_leds);
FAKE_VOID_FUNC(logic_set_operators, uint8_t, uint8_t);

//PWM
FAKE_VOID_FUNC(pwm_pulse, PWM_PIN, uint8_t);
FAKE_VOID_FUNC(pwm_percentage, PWM_PIN, uint16_t);
FAKE_VOID_FUNC(pwm_percentage_pulselength, PWM_PIN, uint8_t, uint16_t);
FAKE_VOID_FUNC(pwm_stop, PWM_PIN);

//SEGMENT_DISPLAY
FAKE_VOID_FUNC(display_init);
FAKE_VOID_FUNC(display_printint_4s, uint16_t);

//THERMOMETER
FAKE_VOID_FUNC(thermometer_init, uint16_t);
FAKE_VOID_FUNC(thermometer_run, uint16_t);

//TIMER
FAKE_VOID_FUNC(timer_init_16bit, uint8_t, timer_t);
FAKE_VOID_FUNC(timer_init_8bit, uint8_t);


class TestDummy : public ::testing::Test
{
	void SetUp() { FFF_RESET_HISTORY(); }
	void TearDown() {}
};


TEST(TestDummy, DummyTest) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}


/****************************************************************************/


class AssignmentKeyTest : public ::testing::Test
{
protected:
	void SetUp() override
	{
		keys_init();
	}
	void TearDown() override {}
};


/*
 * KEY / SWITCH Driver tests
 */
TEST_F(AssignmentKeyTest, Test_DDRC_is_input_after_init)
{
	EXPECT_EQ(DDRC, 0x3f);
}

TEST_F(AssignmentKeyTest, Test_PINC_if_PUD_is_enabled_after_init)
{
	EXPECT_EQ(PINC, 0x3f);
}

TEST_F(AssignmentKeyTest, Test_PC0_if_buttons_is_not_pressed)
{
	EXPECT_EQ(1, !(PINC & PC0));
}

TEST_F(AssignmentKeyTest, Test_PC1_if_buttons_is_not_pressed)
{
	EXPECT_EQ(1, !(PINC & PC1));
}

TEST_F(AssignmentKeyTest, Test_PC2_if_buttons_is_not_pressed)
{
	EXPECT_EQ(1, !(PINC & PC2));
}

TEST_F(AssignmentKeyTest, Test_PC3_if_buttons_is_not_pressed)
{
	EXPECT_EQ(1, !(PINC & PC3));
}

TEST_F(AssignmentKeyTest, Test_PC4_if_buttons_is_not_pressed)
{
	EXPECT_EQ(1, !(PINC & PC4));
}

TEST_F(AssignmentKeyTest, Test_PC5_if_buttons_is_not_pressed)
{
	EXPECT_EQ(1, !(PINC & PC5));
}


/****************************************************************************/


class AssignmentIsrKeyTest : public ::testing::Test
{
protected:
	void SetUp() override
	{
		keys_isr_init();
	}
	void TearDown() override {}
};

/*
 * Test ISR keys, PD2, PD3
 */
TEST_F(AssignmentIsrKeyTest, Test_DDRD_is_input_after_init)
{
	EXPECT_EQ(DDRC, 0xc);
}

TEST_F(AssignmentIsrKeyTest, Test_PIND_if_PUD_is_enabled_after_init)
{
	EXPECT_EQ(PINC, 0xc);
}

TEST_F(AssignmentIsrKeyTest, Test_PD2_if_buttons_is_not_pressed)
{
	EXPECT_EQ(1, !(PIND & PD2));
}

TEST_F(AssignmentIsrKeyTest, Test_PD3_if_buttons_is_not_pressed)
{
	EXPECT_EQ(1, !(PIND & PD3));
}


/****************************************************************************/


class AssignmentLogicTest : public ::testing::Test
{
protected:
	void SetUp() override
	{
		logic_indicator_leds();
	}

	void TearDown() override {}
};


/*
 * Logic tests
 */
TEST_F(AssignmentLogicTest, Test_DDRA_is_output_after_init)
{
	EXPECT_EQ(DDRA, 0xc0);
}

TEST_F(AssignmentLogicTest, Test_leds_are_off_after_init)
{
	EXPECT_EQ(PORTA, 0x3f);
}


//AND
TEST_F(AssignmentLogicTest, Test_AND_PA0_leds_OFFinputA_OFFinputB_true)
{
	uint8_t inputA = 0;
	uint8_t inputB = 0;

	logic_set_operators(inputA, inputB);

	EXPECT_EQ(PA0, !(PINA & PA0));
}

TEST_F(AssignmentLogicTest, Test_AND_PA0_leds_ONinputA_OFFinputB_true)
{
	uint8_t inputA = 1;
	uint8_t inputB = 0;

	logic_set_operators(inputA, inputB);

	EXPECT_EQ(PA0, !(PINA & PA0));
}

TEST_F(AssignmentLogicTest, Test_AND_PA0_leds_OFFinputA_ONinputB_true)
{
	uint8_t inputA = 0;
	uint8_t inputB = 1;

	logic_set_operators(inputA, inputB);

	EXPECT_EQ(PA0, !(PINA & PA0));
}

TEST_F(AssignmentLogicTest, Test_AND_PA0_leds_ONinputA_ONinputB_true)
{
	uint8_t inputA = 1;
	uint8_t inputB = 1;

	logic_set_operators(inputA, inputB);

	EXPECT_EQ(PA0, PINA & PA0);
}


//OR
TEST_F(AssignmentLogicTest, Test_OR_PA1_leds_OFFinputA_OFFinputB_true)
{
	uint8_t inputA = 0;
	uint8_t inputB = 0;

	logic_set_operators(1, inputB);

	EXPECT_EQ(PA0, !(PINA & PA1));
}

TEST_F(AssignmentLogicTest, Test_OR_PA1_leds_ONinputA_OFFinputB_true)
{
	uint8_t inputA = 1;
	uint8_t inputB = 0;

	logic_set_operators(inputA, inputB);

	EXPECT_EQ(PA0, PINA & PA1);
}

TEST_F(AssignmentLogicTest, Test_OR_PA1_leds_OFFinputA_ONinputB_true)
{
	uint8_t inputA = 0;
	uint8_t inputB = 1;

	logic_set_operators(inputA, inputB);

	EXPECT_EQ(PA0, PINA & PA1);
}

TEST_F(AssignmentLogicTest, Test_OR_PA1_leds_ONinputA_ONinputB_true)
{
	uint8_t inputA = 1;
	uint8_t inputB = 1;

	logic_set_operators(inputA, inputB);

	EXPECT_EQ(PA0, PINA & PA1);
}


//XOR
TEST_F(AssignmentLogicTest, Test_XOR_PA2_leds_OFFinputA_OFFinputB_true)
{
	uint8_t inputA = 0;
	uint8_t inputB = 0;

	logic_set_operators(1, inputB);

	EXPECT_EQ(PA0, PINA & PA2);
}

TEST_F(AssignmentLogicTest, Test_XOR_PA2_leds_ONinputA_OFFinputB_true)
{
	uint8_t inputA = 1;
	uint8_t inputB = 0;

	logic_set_operators(inputA, inputB);

	EXPECT_EQ(PA0, !(PINA & PA0));
}

TEST_F(AssignmentLogicTest, Test_XOR_PA2_leds_OFFinputA_ONinputB_true)
{
	uint8_t inputA = 0;
	uint8_t inputB = 1;

	logic_set_operators(inputA, inputB);

	EXPECT_EQ(PA0, !(PINA & PA2));
}

TEST_F(AssignmentLogicTest, Test_XOR_PA2_leds_ONinputA_ONinputB_true)
{
	uint8_t inputA = 1;
	uint8_t inputB = 1;

	logic_set_operators(inputA, inputB);

	EXPECT_EQ(PA0, PINA & PA2);
}


//NAND
TEST_F(AssignmentLogicTest, Test_NAND_PA3_leds_OFFinputA_OFFinputB_true)
{
	uint8_t inputA = 0;
	uint8_t inputB = 0;

	logic_set_operators(inputA, inputB);

	EXPECT_EQ(PA0, PINA & PA3);
}

TEST_F(AssignmentLogicTest, Test_NAND_PA3_leds_ONinputA_OFFinputB_true)
{
	uint8_t inputA = 1;
	uint8_t inputB = 0;

	logic_set_operators(inputA, inputB);

	EXPECT_EQ(PA0, PINA & PA3);
}

TEST_F(AssignmentLogicTest, Test_NAND_PA3_leds_OFFinputA_ONinputB_true)
{
	uint8_t inputA = 0;
	uint8_t inputB = 1;

	logic_set_operators(inputA, inputB);

	EXPECT_EQ(PA0, PINA & PA3);
}

TEST_F(AssignmentLogicTest, Test_NAND_PA3_leds_ONinputA_ONinputB_true)
{
	uint8_t inputA = 1;
	uint8_t inputB = 1;

	logic_set_operators(inputA, inputB);

	EXPECT_EQ(PA0, !(PINA & PA3));
}


//NOR
TEST_F(AssignmentLogicTest, Test_NOR_PA4_leds_OFFinputA_OFFinputB_true)
{
	uint8_t inputA = 0;
	uint8_t inputB = 0;

	logic_set_operators(1, inputB);

	EXPECT_EQ(PA0, !(PINA & PA4));
}

TEST_F(AssignmentLogicTest, Test_NOR_PA4_leds_ONinputA_OFFinputB_true)
{
	uint8_t inputA = 1;
	uint8_t inputB = 0;

	logic_set_operators(inputA, inputB);

	EXPECT_EQ(PA0, !(PINA & PA4));
}

TEST_F(AssignmentLogicTest, Test_NOR_PA4_leds_OFFinputA_ONinputB_true)
{
	uint8_t inputA = 0;
	uint8_t inputB = 1;

	logic_set_operators(inputA, inputB);

	EXPECT_EQ(PA0, !(PINA & PA4));
}

TEST_F(AssignmentLogicTest, Test_NOR_PA4_leds_ONinputA_ONinputB_true)
{
	uint8_t inputA = 1;
	uint8_t inputB = 1;

	logic_set_operators(inputA, inputB);

	EXPECT_EQ(PA0, PINA & PA4);
}


//XNOR
TEST_F(AssignmentLogicTest, Test_XNOR_PA5_leds_OFFinputA_OFFinputB_true)
{
	uint8_t inputA = 0;
	uint8_t inputB = 0;

	logic_set_operators(1, inputB);

	EXPECT_EQ(PA0, !(PINA & PA5));
}

TEST_F(AssignmentLogicTest, Test_XNOR_PA5_leds_ONinputA_OFFinputB_true)
{
	uint8_t inputA = 1;
	uint8_t inputB = 0;

	logic_set_operators(inputA, inputB);

	EXPECT_EQ(PA0, PINA & PA5);
}

TEST_F(AssignmentLogicTest, Test_XNOR_PA5_leds_OFFinputA_ONinputB_true)
{
	uint8_t inputA = 0;
	uint8_t inputB = 1;

	logic_set_operators(inputA, inputB);

	EXPECT_EQ(PA0, PINA & PA5);
}

TEST_F(AssignmentLogicTest, Test_XNOR_PA5_leds_ONinputA_ONinputB_true)
{
	uint8_t inputA = 1;
	uint8_t inputB = 1;

	logic_set_operators(inputA, inputB);

	EXPECT_EQ(PA0, !(PINA & PA5));
}


/****************************************************************************/


class AssignmentTest : public ::testing::Test
{
protected:
	void SetUp() override
	{
		leds_init();
	}

	void TearDown() override {}
};


/*
 * LED Driver tests
 */
TEST_F(AssignmentTest, Test_DDRA_is_output_after_init)
{
	EXPECT_EQ(DDRA, 0b00111111);
}

TEST_F(AssignmentTest, Test_leds_are_off_after_init)
{
	EXPECT_EQ(PORTA, 0b00111111);
}

TEST_F(AssignmentTest, First_PA0_turn_on)
{
	uint8_t ledPin = 1;

	leds_set(ledPin, 1);

	EXPECT_EQ(0b11111110, PORTA);
}

TEST_F(AssignmentTest, First_PA1_turn_on)
{
	uint8_t ledPin = 2;

	leds_set(ledPin, 1);

	EXPECT_EQ(0b11111101, PORTA);
}

TEST_F(AssignmentTest, First_PA2_turn_on)
{
	uint8_t ledPin = 3;

	leds_set(ledPin, 1);

	EXPECT_EQ(0b11111011, PORTA);
}

TEST_F(AssignmentTest, First_PA3_turn_on)
{
	uint8_t ledPin = 4;

	leds_set(ledPin, 1);

	EXPECT_EQ(0b11110111, PORTA);
}

TEST_F(AssignmentTest, First_PA4_turn_on)
{
	uint8_t ledPin = 5;

	leds_set(ledPin, 1);

	EXPECT_EQ(0b11101111, PORTA);
}

TEST_F(AssignmentTest, First_PA5_turn_on)
{
	uint8_t ledPin = 6;

	leds_set(ledPin, 1);

	EXPECT_EQ(0b11011111, PORTA);
}

TEST_F(AssignmentTest, First_PA6_turn_on)
{
	uint8_t ledPin = 7;

	leds_set(ledPin, 1);

	EXPECT_EQ(0b10111111, PORTA);
}

TEST_F(AssignmentTest, First_PA7_turn_on)
{
	uint8_t ledPin = 8;

	leds_set(ledPin, 1);

	EXPECT_EQ(0b01111111, PORTA);
}

TEST_F(AssignmentTest, Turn_on_invalid_led)
{
	uint8_t ledPin = 9;

	leds_set(ledPin, 1);

	EXPECT_EQ(0b11111111, PORTA);
}


/****************************************************************************/


class AssignmentLightBarTest : public ::testing::Test
{
protected:
	void SetUp() override
	{
		lightbar_init();
		lightbar_isr_keys_init();
	}
	void TearDown() override {}
};


/*
 * Lightbar tests
 */
TEST_F(AssignmentLightBarTest, Test_Lightbar_DDRA_is_output_after_init)
{
	EXPECT_EQ(DDRA, 0xff);
	EXPECT_EQ(DDRC, 0xc);
	EXPECT_EQ(DDRD, 0xc);
}

TEST_F(AssignmentLightBarTest, Test_Lightbar_leds_are_off_after_init)
{
	EXPECT_EQ(PORTA, 0xff);
	EXPECT_EQ(PORTC, 0xc);
	EXPECT_EQ(PORTD, 0xc);
}

TEST_F(AssignmentLightBarTest, Test_Lightbar_scan_keys_off_not_pressed)
{
	EXPECT_EQ(PORTA, 0xff);
}

TEST_F(AssignmentLightBarTest, Test_Lightbar_output_all_keys_pressed)
{
	PORTC = PORTC |= 0b00000000;
	PORTD = PORTD |= 0b00000000;

	EXPECT_EQ(PORTA, 0b11111111);
}

TEST_F(AssignmentLightBarTest, Test_Lightbar_output_PC0_pressed)
{
	PORTC = PORTC |= 0b00111110;
	PORTD = PORTD |= 0b00001100;

	EXPECT_EQ(PORTA, 0b11111110);
}

TEST_F(AssignmentLightBarTest, Test_Lightbar_output_PC1_pressed)
{
	PORTC = PORTC |= 0b00111101;
	PORTD = PORTD |= 0b00001100;

	EXPECT_EQ(PORTA, 0b11111110);
}

TEST_F(AssignmentLightBarTest, Test_Lightbar_output_PD2_pressed)
{
	PORTC = PORTC |= 0b00111111;
	PORTD = PORTD |= 0b00001000;

	EXPECT_EQ(PORTA, 0b11111110);
}

TEST_F(AssignmentLightBarTest, Test_Lightbar_output_PC0_PC1_PC2_PC4_PD2_pressed)
{
	PORTC = PORTC |= 0b00101100;
	PORTD = PORTD |= 0b00001000;

	EXPECT_EQ(PORTA, 0b11110000);
}


/****************************************************************************/


class ThermometerTest : public ::testing::Test
{
	void SetUp() 
	{ 
		FFF_RESET_HISTORY();
		thermometer_init(10);
	}
	void TearDown() {}
};


TEST(ThermometerTest, create_thermometer_ok)
{

}

TEST(ThermometerTest, create_thermometer_fail_swap_min_max)
{

}

TEST(ThermometerTest, create_Thermometer_fail_low_min)
{

}

TEST(ThermometerTest, create_Thermometer_fail_low_min_low_max)
{

}


//
 /*

TEST(ThermometerTest, run_thermometer_ok)
{
	/*
	therm_create_Fake:thermometer_init(10);
	adc_get_fake:adc_read(ADC15);
	thermometer_run();
	*/ /*
}
*/
TEST(ThermometerTest, run_thermometer_fail_low_get)
{

}


/****************************************************************************/


class TimerTest : public ::testing::Test
{
	void SetUp() {}
	void TearDown() {}
};


/****************************************************************************/


class SegmentDisplayTest : public ::testing::Test
{
	void SetUp() {}
	void TearDown() {}
};


/****************************************************************************/


class PWMTest : public ::testing::Test
{
	void SetUp() {}
	void TearDown() {}
};


/****************************************************************************/


class ADCTest : public ::testing::Test
{
	void SetUp() {}
	void TearDown() {}
};


/****************************************************************************/


/****************************************************************************/

