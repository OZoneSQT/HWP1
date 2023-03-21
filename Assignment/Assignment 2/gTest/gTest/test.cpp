
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

using namespace std;
#include <iostream>


extern "C"
{
#include <stdint.h>
#include <avr/io.h>

#include "adc/adc.h"
#include "key/key.h"
#include "led/bar.h"
#include "led/segment.h"
#include "thermometer.h"
#include "timer/timer.h"
}

/*
 * There is an issue with registers
 */

// Setup FFF functions
DEFINE_FFF_GLOBALS;

//ADC
FAKE_VOID_FUNC(adc_init_8bit, adcPin_t);
FAKE_VOID_FUNC(adc_init_10bit, adcPin_t);
FAKE_VALUE_FUNC(uint16_t, adc_read, adcPin_t);

//KEYS
FAKE_VOID_FUNC(keys_isr_init_pd2);
FAKE_VOID_FUNC(keys_isr_init_pd3);

//LIGHT_BAR
FAKE_VOID_FUNC(lightbar_init);
FAKE_VOID_FUNC(lightbar_level, uint8_t);

//SEGMENT_DISPLAY
FAKE_VOID_FUNC(display_init);
FAKE_VOID_FUNC(display_printint_4s, uint16_t);

//THERMOMETER
FAKE_VOID_FUNC(thermometer_init, uint16_t);
FAKE_VOID_FUNC(thermometer_run);

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


class AssignmentLightBarTest : public ::testing::Test
{
protected:
	void SetUp() override
	{
		lightbar_init();
	}
	void TearDown() override {}
};

void print_DDRA() 
{
	cout << DDRA;
	cout << PORTA;
}

/*
 * Lightbar tests
 */
TEST_F(AssignmentLightBarTest, Test_Lightbar_DDRA_is_output_after_init)
{
	print_DDRA();
	EXPECT_EQ(DDRA, 0);
}

TEST_F(AssignmentLightBarTest, Test_Lightbar_leds_are_off_after_init)
{
	print_DDRA();
	EXPECT_EQ(PORTA, 0);
}

TEST_F(AssignmentLightBarTest, Test_Lightbar_Output_Zero)
{
	lightbar_level(0);
	print_DDRA();
	EXPECT_EQ(PORTA, 0);
}

TEST_F(AssignmentLightBarTest, Test_Lightbar_Output_One)
{
	lightbar_level(1);
	print_DDRA();
	EXPECT_EQ(PORTA, 0);
}

TEST_F(AssignmentLightBarTest, Test_Lightbar_Output_Two)
{
	lightbar_level(2);
	print_DDRA();
	EXPECT_EQ(PORTA, 0);
}

TEST_F(AssignmentLightBarTest, Test_Lightbar_Output_Eight)
{
	lightbar_level(8);
	print_DDRA();
	EXPECT_EQ(PORTA, 0);
}

TEST_F(AssignmentLightBarTest, Test_Lightbar_output_ERROR_HIGH)
{
	lightbar_level(127);
	print_DDRA();
	EXPECT_EQ(PORTA, 0);
}

TEST_F(AssignmentLightBarTest, Test_Lightbar_output_ERROR_LOW)
{
	lightbar_level(-1);
	print_DDRA();
	EXPECT_EQ(PORTA, 0);
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


/****************************************************************************/





/****************************************************************************/
