/*
 * @file adc_hal.c
 * @brief ADC hal
 *
 * @Origin : 31/03/2023 09.31.32
 * @Author : Author: Michel Sommer, 273966
 *
 * \defgroup adc library
 * @{
	 */

 #include "adc-hal.h"


 /** Array to store ADC values for each pin */
 volatile uint16_t adc_values[16] = {0};


 /*******************************************************************************/
 /** Interrupt service routine to update the adc_values array with the ADC result */
 ISR(ADC_vect)
 {
	 uint8_t pin = ADMUX & 0x0F;
	 adc_values[pin] = ADC; /** Read the 10-bit ADC value
	 ADCSRA |= (1 << ADSC); /** Start the next ADC conversion
 }
 
 /*******************************************************************************/
 /** Common initialization code for 8-bit and 10-bit functions */
void init_adc_continuous_common(adcPin_t pin)
 {
	if (pin >= ADC_8)
	{
		/** If pin is ADC8 or higher, set the MUX5 bit in the ADCSRB register */
		ADCSRB = (1 << MUX5);
	}
	else
	{
		/** If pin is ADC7 or lower, clear the MUX5 bit in the ADCSRB register */
		ADCSRB = 0;
	}

	/** Enable ADC, set the prescaler to 128, enable auto-triggering, and enable the ADC interrupt */
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0) | (1 << ADATE) | (1 << ADIE);

	/** Set the ADC trigger source to free running mode */
	ADCSRB &= ~((1 << ADTS2) | (1 << ADTS1) | (1 << ADTS0));

	/** Start the first ADC conversion */
	ADCSRA |= (1 << ADSC);
 }
 
 /*******************************************************************************/
 /** Function to initialize continuous readings of an ADC pin with 8-bit resolution */
 void adc_init_8bit(adcPin_t pin)
 {
	/** Configure the ADMUX register for the specified pin and 8-bit resolution */
	ADMUX = (1 << REFS0) | (1 << ADLAR) | (pin & 0x0F); /** Use AVcc as the reference voltage, left-adjust the result, and select the ADC pin */

	/** Call the common initialization code */
	init_adc_continuous_common(pin);
 }
 
 /*******************************************************************************/
 /** Function to initialize continuous readings of an ADC pin with 10-bit resolution */
 void adc_init_10bit(adcPin_t pin)
 {
	/** Configure the ADMUX register for the specified pin and 10-bit resolution */
	ADMUX = (1 << REFS0) | (pin & 0x0F); /** Use AVcc as the reference voltage, right-adjust the result, and select the ADC pin */

	/** Call the common initialization code */
	init_adc_continuous_common(pin);
 }

 /*******************************************************************************/
 /** Function to retrieve the ADC value for a specified pin */
 uint16_t adc_read(adcPin_t pin)
 {
	return adc_values[pin];
 }

 /*******************************************************************************/

/** @} */