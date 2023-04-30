/*
 * @file types.h
 *
 * @Origin Date : 30/04/2023 14.11.30
 * @Author : Michel Sommer, 273966
 */ 

#pragma once

#ifndef F_CPU
#define F_CPU 16000000
#endif /* F_CPU */

#ifndef SCLK_PIN
#define SCLK_PIN PORTB1
#endif /* SCLK_PIN */

#ifndef MOSI_PIN
#define MOSI_PIN PORTB2
#endif /* MOSI_PIN */

#ifndef MISO_PIN
#define MISO_PIN PORTB3
#endif /* MISO_PIN */

#ifndef SS_SHIFT_REGISTER
#define SS_SHIFT_REGISTER PORTB0
#endif /* SS_SHIFT_REGISTER */

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
