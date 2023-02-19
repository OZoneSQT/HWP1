#include "gtest/gtest.h"

extern "C" 
{
#include <avr/io.h>
#include ""
}

class AssignmentTest : public ::testing::Test
{
protected:
		void SetUp() override 
		{
			init_keys();
			logic_indicator_leds();
		}
		void TearDown() override {}
};


TEST_F(AssignmentTest, Test_DDRA_is_output_after_init) {
  EXPECT_EQ(DDRA, 0xFF);
}

TEST_F(AssignmentTest, Test_leds_are_off_after_init) {
	EXPECT_EQ(PORTA, 0xFF);
}