/*
 * counterTest.cpp
 *
 * Created: 07/03/2023 22.19.15
 *  Author: skrue
 */ 

/*
#include "gtest/gtest.h"

extern "C"
{
	#include <avr/io.h>
	#include "irqCounter.h"

	void ISR_INT2_vect();
	void ISR_INT3_vect();
}

class irqCounterTest : public ::testing::Test {
	protected:
	void SetUp() override
	{
		init_counter();
	}
	void TearDown() override
	{

	}
};

TEST_F(irqCounterTest, Test_PORTA_set_to_output_and_leds_off) {
	EXPECT_EQ(0xff, DDRA);
	EXPECT_EQ(0xff, PORTA);
}

TEST_F(irqCounterTest, Test_PORTA_increments_on_IRQ2) {
	uint8_t _cnt = 0;
	EXPECT_EQ((uint8_t)_cnt, (uint8_t)~PORTA);
	ISR_INT2_vect();
	_cnt++;
	EXPECT_EQ((uint8_t)_cnt, (uint8_t)~PORTA);
}
TEST_F(irqCounterTest, Test_PORTA_decrements_on_IRQ3) {
	uint8_t _cnt = 5;
	uint8_t _leds_off = 0;

	// Test initial state of counter
	EXPECT_EQ(_leds_off, (uint8_t)~PORTA);

	// Increment counter
	for(int i=0; i<_cnt; i++)
	ISR_INT2_vect();
	EXPECT_EQ((uint8_t)_cnt, (uint8_t)~PORTA);

	// Decrement counter
	ISR_INT3_vect();
	EXPECT_EQ((uint8_t)_cnt-1, (uint8_t)~PORTA);
}
*/