/*
 * hwpDrivers.h
 *
 * Created: 28/04/2023 08.32.30
 *  Author: skrue
 */ 


#ifndef HWPDRIVERS_H_
#define HWPDRIVERS_H_

/*
 * @file adc_hal.h
 * @brief Header file for ADC hal
 *
 * @Origin Date : 31/03/2023 09.31.46
 * @Author : Michel Sommer, 273966
 *
 * \defgroup adc library
 * @{
	 */

 #pragma once
 
 #include "settings.h"
 #include <stdint.h>
 #include <avr/io.h>


  /** Enumeration to limit input options, and maps to pin */
  typedef enum AdcPin
  {
	 ADC_0 = PF0, 
	 ADC_1 = PF1, 
	 ADC_2 = PF2, 
	 ADC_3 = PF3,
	 ADC_4 = PF4, 
	 ADC_5 = PF5, 
	 ADC_6 = PF6, 
	 ADC_7 = PF7,
	 ADC_8 = PK0, 
	 ADC_9 = PK1, 
	 ADC_10 = PK2, 
	 ADC_11 = PK3,
	 ADC_12 = PK4, 
	 ADC_13 = PK5, 
	 ADC_14 = PK6, 
	 ADC_15 = PK7
  } adcPin_t;


 /************************************************************************/
 /* @brief Initialization of 8-bit adc on pin                            */
 /*																		 */
 /* @param[in] adcPin_t pin												 */
 /************************************************************************/
 void adc_init_8bit(adcPin_t pin);


 /************************************************************************/
 /* @brief Initialization of 10-bit adc on pin                           */
 /*																		 */
 /* @param[in] adcPin_t pin												 */
 /************************************************************************/
 void adc_init_10bit(adcPin_t pin);


 /************************************************************************/
 /* @brief Read adc value from pin                                       */
 /*        Note voltage reff. = 5VDC                                     */
 /*																		 */
 /* @param[in] adcPin_t pin												 */
 /*																		 */
 /* @param[out] uint16_t returns measured value on pin					 */
 /************************************************************************/
 uint16_t adc_read(adcPin_t pin);
 
 /** @} */

/*
 * @file key_hal.h
 * @brief Header file, for ISR buttons
 *
 * @Origin Date :31/03/2023 09.32.30
 * @Author : Michel Sommer, 273966
 *
 * \defgroup isr key library
 * @{
	 */

#pragma once

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>


/*
 *  Interrupt service routines:
 *	ISR(INT2_vect) { } // INT2 (PD2)
 *	ISR(INT3_vect) { } // INT3 (PD3)
 */


/************************************************************************/
/* @brief Initialization of isr keys									*/
/*	setting PORTD for PD2 as ext. interrupt								*/
/************************************************************************/
void keys_isr_init_pd2();


/************************************************************************/
/* Initialization of isr keys											*/
/*	setting PORTD for PD3 as ext. interrupt								*/
/************************************************************************/
void keys_isr_init_pd3();

/** @} */

/*
 * @file letters.h
 * @brief Letters for segment
 *
 * @Origin Date :´24/03/2023 10.39.53
 * @Author : Michel Sommer, 273966
 *
 * \defgroup segment library
 * @{
	 */

#pragma once

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"


/************************************************************************/
/* @brief Enumeration for mapping letters to segment                    */
/*	L for letter then value                                             */
/************************************************************************/
typedef enum Letter
{
/** ENUM = Value    Sign	binary value */
	 L1 = 0x60, /**< 1	0b01100000 */
	 L2 = 0xDA, /**< 2	0b11011010 */
	 L3 = 0x9E, /**< 3	0b10011110 */
	 L4 = 0x66, /**< 4	0b01100110 */
	 L5 = 0xE0, /**< 5	0b10110110 */
	 L6 = 0xB6, /**< 6	0b00110110 */
	 L7 = 0x36, /**< 7	0b11100000 */
	 L8 = 0xE0, /**< 8	0b11111110 */
	 L9 = 0xC6, /**< 9	0b11000110 */
	 L0 = 0xFC, /**< 0	0b11111100 */
	 LA = 0xEE, /**< A	0b11101110 */
	 LC = 0x9C, /**< B	0b10011100 */
	 LE = 0x9E, /**< E	0b10011110 */
	 LF = 0x8E, /**< F	0b10001110 */
	 LH = 0x6E, /**< H	0b01101110 */
	 LL = 0x0E, /**< L	0b00011100 */
	 LP = 0xCE, /**< P	0b11001110 */
	 LU = 0x7E, /**< U	0b01111100 */
	 LD = 0x01, /**< DOT	0b00000001 */
	 LN = 0x02, /**< -	ob00000010 */
	 LB = 0x00  /**< blank	ob00000000 */
} letters_t;

/** @} */

/*
 * @file segment.h
 * @brief Segment header file
 *
 * @Origin Date : 24/03/2023 10.54.15
 * @Author : Michel Sommer, 273966
 *
 * \defgroup segment library
 * @{
	 */

#pragma once

#include "letters.h"
#include "segment-hal.h"


/** Enumeration to set output */
typedef enum
{
	INT16_T,	/**< int16_t as printed data type */
	UINT16_T,	/**< uint16_t as printed data type */
	FLOAT		/**< float as printed data type */
} print_t;


/************************************************************************/
/* @brief Initialization of 7-segment display                           */
/*																		 */
/* @param[in] uint16_t refresh_ms										*/
/************************************************************************/
void segment_init(uint16_t refresh_ms);


/************************************************************************/
/* @brief Print float value to 7 segment display                        */
/*																		*/
/* @param[in] float value												*/
/* @param[in] print_t print format										*/
/* @param[in] uint8_t number of decimals								*/
/************************************************************************/
void segment_print(float value, print_t format, uint8_t decimals);


/************************************************************************/
/* @brief Prints value to 7 segment display                             */
/*																		*/
/* @param[in] letters_t value to segment1								*/
/* @param[in] letters_t value to segment2								*/
/* @param[in] letters_t value to segment3								*/
/* @param[in] letters_t value to segment4								*/
/************************************************************************/
void segment_print_letter(letters_t segment1, letters_t segment2, letters_t segment3, letters_t segment4);

/** @} */

/*
 * @file spi_hal.h
 * @brief Header for SPI communication
 *
 * @Origin Date : 14/04/2023 11.05.53
 * @Author : Michel Sommer, 273966
 *
 * \defgroup spi library
 * @{
	 */

#pragma once

#include "settings.h"
#include <avr/io.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>


/************************************************************************/
/* @brief Set transfer speed:					                        */
/*		SPI2x	SPIR1	SPR0	SCK freq.								*/
/*		0		0		0		f_osc/4									*/
/*		0		0		1		f_osc/16								*/
/*		0		1		0		f_osc/64								*/
/*		0		1		1		f_osc/128								*/
/*		1		0		0		f_osc/2									*/
/*		1		0		1		f_osc/8									*/
/*		1		1		0		f_osc/32								*/
/*		1		1		1		f_osc/64								*/
/************************************************************************/
typedef enum Speed
{
	SPI_OCS2,  /**< f_osc/2 */
	SPI_OCS4,  /**< f_osc/4 */
	SPI_OCS8,  /**< f_osc/8 */
	SPI_OCS16, /**< f_osc/16 */
	SPI_OCS32, /**< f_osc/32 */
	SPI_OCS64, /**< f_osc/64 */
	SPI_OCS128 /**< f_osc/128 */
} spi_speed_t;

/************************************************************************/
/* @brief Set trigger edge:					                            */
/*	SCLK Edge															*/
/* 		SPI transfer format with CPHA = 1                               */
/* 		Mode 1:	CPOL = 0                                                */
/* 		Mode 3: CPOL = 1                                                */
/* 																		*/
/*	SCLK Edge															*/
/* 		SPI transfer format with CPHA = 0                               */
/* 		Mode 0:	CPOL = 0                                                */
/* 		Mode 3: CPOL = 1                                                */
/************************************************************************/
typedef enum Edge
{
	SPI_SCLK_MODE_0_LEAD_RISE,   /**< CPHA = 0, CPOL = 0 */
	SPI_SCLK_MODE_1_TRAIL_RISE,  /**< CPHA = 1, CPOL = 0 */
	SPI_SCLK_MODE_2_LEAD_FALL,   /**< CPHA = 0, CPOL = 1 */
	SPI_SCLK_MODE_3_TRAIL_FALL,  /**< CPHA = 1, CPOL = 1 */
} spi_edge_t;

/************************************************************************/
/* @brief Set transfer format:				                            */
/*	MSB sent first (DORD = 0)											*/
/*	LSB sent first (DORD = 1)											*/
/************************************************************************/
typedef enum Format
{
	SPI_MSB_FIRST,   /**< DORD = 0, MSB sent first */
	SPI_LSB_FIRST,   /**< DORD = 1, LSB sent first */
} spi_format_t;

/************************************************************************/
/* @brief Set transfer mode: Master/Slave	                            */
/************************************************************************/
typedef enum Mode
{
	SPI_MASTER,   /**< Master */
	SPI_SLAVE,    /**< Slave */
} spi_mode_t;


/************************************************************************/
/* @brief SPI Configuration Struct                                      */
/************************************************************************/
typedef struct Spi {
	spi_speed_t speed;		/**< Speed: f_osc/x */
	spi_edge_t edge;		/**< SCLK Edge */
	spi_format_t format;	/**< Format: MSB/LSB First */
	spi_mode_t mode;		/**< Mode: Master/Slave */
	uint8_t ss_pin;			/**< Slave Select pin */
} spi_t;


/************************************************************************/
/* @brief Initialization of spi, taking a variable number of arguments  */
/*																		*/
/* @param[in] uint16_t* pointer to SS pin								*/
/* @param[in] spi_speed_t sets transfer speed (optional)				*/
/* @param[in] spi_edge_t sets trigger edge (optional)					*/
/* @param[in] spi_format_t sets	transfer format (optional)				*/
/* @param[in] spi_mode_t sets transfer mode (optional)					*/
/*																		*/
/* @param[out] spi_t pointer to SPI struct								*/
/************************************************************************/
spi_t* spi_init(uint16_t* pin, ...);


/************************************************************************/
/* @brief Sends argument to spi										    */
/*																		*/
/* @param[in] spi_t SPI struct											*/
/* @param[in] uint8_t data to send										*/
/************************************************************************/
void spi_tx(spi_t *spi, uint8_t data);


/************************************************************************/
/* @brief Get argument from spi										    */
/*																		*/
/* @param[in] spi_t SPI struct											*/
/*																		*/
/* @param[out] uint8_t read register value								*/
/************************************************************************/
uint8_t spi_rx(spi_t *spi);


/************************************************************************/
/* @brief Delete spi													*/
/*																		*/
/* @param[in] spi_t SPI struct											*/
/************************************************************************/
void spi_delete(spi_t *spi);

/** @} */

/*
 * @file thermometer.h
 * @brief Hesder file for Thermometer application
 *
 * @Origin Date : 31/03/2023 09.35.34
 * @Author : Michel Sommer, 273966
 *
 * \defgroup thermometer application
 * @{
	 */

#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include "key-hal.h"
#include "timer.h"
#include "segment.h"
#include "temperature-reader.h"


/***********************************************************************/
/* Sensor spec:														   */
/* Output voltage of the sensor is 10mV/°C and typically 750mV@25°C	   */
/* aka: 740 mV = 24 C, 730 mV = 23C e.g.							   */
/***********************************************************************/


/************************************************************************/
/* @brief Initialization of thermometer, setting timer                  */
/************************************************************************/
void thermometer_init();


/************************************************************************/
/* @brief run thermometer                                               */
/************************************************************************/
void thermometer_run();

/** @} */













#endif /* HWPDRIVERS_H_ */