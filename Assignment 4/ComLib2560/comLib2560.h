/*
 * @file comLib2560.h
  * @brief Header for Wired communication library
 *
 * @Origin Date : 30/04/2023 14.10.46
 * @Author : Michel Sommer, 273966
 *
 * \defgroup Communication library
 * @{
	 */

#pragma once


#include "types.h"


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


/************************************************************************/

/************************************************************************/
/* @brief TODO add I2C / TWI functionality                              */
/************************************************************************/


/************************************************************************/

/************************************************************************/
/* @brief TODO add 1-Wire functionality                                 */
/************************************************************************/


/************************************************************************/

/** @} */
