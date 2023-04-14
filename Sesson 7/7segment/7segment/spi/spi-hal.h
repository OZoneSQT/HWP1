/*
 * spi_hal.h
 *
 * Created: 14/04/2023 11.05.53
 *  Author: skrue
 */ 

#pragma once

#include "../settings.h"
#include <stdarg.h>

typedef struct SPI
{
	
} spi_t;

/************************************************************************/
/* Transfer speed														*/
/* SPI2x	SPIR1	SPR0	SCK freq.									*/
/* 0		0		0		f_osc/4										*/
/* 0		0		1		f_osc/16									*/
/* 0		1		0		f_osc/64									*/
/* 0		1		1		f_osc/128									*/
/* 1		0		0		f_osc/2										*/
/* 1		0		1		f_osc/8										*/
/* 1		1		0		f_osc/32									*/
/* 1		1		1		f_osc/64									*/
/************************************************************************/
typedef enum
{
	SPI_OCS2,  /** f_osc/2 */
	SPI_OCS4,  /** f_osc/4 */
	SPI_OCS8,  /** f_osc/8 */
	SPI_OCS16, /** f_osc/16 */
	SPI_OCS32, /** f_osc/32 */
	SPI_OCS64, /** f_osc/64 */
	SPI_OCS128 /** f_osc/128 */
} spi_speed_t;

/************************************************************************/
/* 	SCLK Edge															*/
/* 		SPI transfer format with CPHA = 1                               */
/* 		Mode 1:	CPOL = 0                                                */
/* 		Mode 3: CPOL = 1                                                */
/* 																		*/
/* 	SCLK Edge															*/
/* 		SPI transfer format with CPHA = 0                               */
/* 		Mode 0:	CPOL = 0                                                */
/* 		Mode 3: CPOL = 1                                                */
/************************************************************************/
typedef enum
{
	SPI_SCLK_MODE_0_LEAD_RISE,   /** CPHA = 0, CPOL = 0 */
	SPI_SCLK_MODE_1_TRAIL_RISE,  /** CPHA = 1, CPOL = 0 */
	SPI_SCLK_MODE_2_LEAD_FALL,   /** CPHA = 0, CPOL = 1 */
	SPI_SCLK_MODE_3_TRAIL_FALL,  /** CPHA = 1, CPOL = 1 */
} spi_edge_t;

/************************************************************************/
/* MSB sent first (DORD = 0)											*/
/* LSB sent first (DORD = 1)                                            */
/************************************************************************/
typedef enum
{
	SPI_MSB_FIRST,   /** DORD = 0, MSB sent first*/
	SPI_LSB_FIRST,   /** DORD = 1, LSB sent first*/
} spi_format_t;

/************************************************************************/
/* Set mode: Master/Slave	                                            */
/************************************************************************/
typedef enum
{
	SPI_MASTER,   /** Master */
	SPI_SLAVE,    /** Slave */
} spi_mode_t;

/************************************************************************/
/* Initialization of spi, taking a variable number of arguments         *
/* Returns pointer to struct								            */
/************************************************************************/
spi_t* spi_init(uint16_t* pin, ...);


/************************************************************************/
/* Sends argument to spi										        */
/************************************************************************/
void spi_write(spi_t* spi, ...);


/************************************************************************/
/* Gets argument from spi										        */
/************************************************************************/
char* spi_read(spi_t* spi, ...);


/************************************************************************/
/* Delete spi													        */
/************************************************************************/
char* spi_delete(spi_t* spi);
