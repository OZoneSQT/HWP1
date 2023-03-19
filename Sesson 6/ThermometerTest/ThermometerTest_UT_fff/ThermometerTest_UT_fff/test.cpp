#include "gtest/gtest.h"
#include "../../../../../fff/fff.h"

extern "C" 
{
	#include "../../ThermometerTest/adc.h"
	#include "../../ThermometerTest/led.h"
	#include "../../ThermometerTest/thermometer.h"
}


// Setup FFF functions
DEFINE_FFF_GLOBALS;
FAKE_VOID_FUNC(adc_create, uint8_t);
FAKE_VALUE_FUNC(uint16_t, adc_get, uint8_t);
FAKE_VOID_FUNC(led_create, int16_t, int16_t);
FAKE_VOID_FUNC(led_bar, int16_t);
FAKE_VOID_FUNC(therm_create, int, int);
FAKE_VOID_FUNC(therm_run);


class ThermometerTest : public ::testing::Test
{
	void SetUp() { FFF_RESET_HISTORY(); }
	void TearDown() {}
};

/*************************************************************/
TEST(ThermometerTest, DummyTest) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

/*************************************************************/
TEST(ThermometerTest, create_thermometer_ok)
{
	therm_create(0, 99);
}

TEST(ThermometerTest, create_thermometer_fail_swap_min_max)
{
	therm_create(99, 0);
}

TEST(ThermometerTest, create_Thermometer_fail_low_min)
{
	therm_create(-9, 27);
}

TEST(ThermometerTest, create_Thermometer_fail_low_min_low_max)
{
	therm_create(36, 22);
}

/*************************************************************/
TEST(ThermometerTest, run_thermometer_ok)
{
	therm_create_Fake:therm_create(0, 99);
	adc_get_fake:adc_get(25);
	therm_run();
}

TEST(ThermometerTest, run_thermometer_fail_low_get)
{
	therm_create_Fake:therm_create(0, 99);
	adc_get_fake:adc_get(-5);
	therm_run();
}