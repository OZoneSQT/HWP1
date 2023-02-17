#include "gtest/gtest.h"

extern "C" 
{
#include <avr/io.h>
#include "ledArray.h"
}

class AssignmentTest : public ::testing::Test
{
protected:
		void SetUp() override 
		{
			init_leds();
		}
		void TearDown() override {}
};


TEST_F(AssignmentTest, Test_DDRA_is_output_after_init) {
  EXPECT_EQ(DDRA, 0xFF);
}

TEST_F(AssignmentTest, Test_leds_are_off_after_init) {
	EXPECT_EQ(PORTA, 0xFF);
}