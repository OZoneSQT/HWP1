/*
 * @file spi.c
 *
 * @Origin Date : 30/04/2023 14.21.40
 * @Author : Michel Sommer, 273966
 */
	 
#include "comLib2560.h"


/************************************************************************/
/** Initialization of SPI */
spi_t *spi_init(uint16_t *pin, ...)
{
	spi_t *spi = malloc(sizeof(spi_t));

	/** Read optional arguments */
	va_list args;
		va_start(args, pin);
		spi->speed = (spi_speed_t)va_arg(args, spi_speed_t);
		spi->edge = (spi_edge_t)va_arg(args, spi_edge_t);
		spi->format = (spi_format_t)va_arg(args, spi_format_t);
		spi->mode = (spi_mode_t)va_arg(args, spi_mode_t);
	va_end(args);

	/** Set SS pin */
	spi->ss_pin = *pin;

	/** Set MOSI and SCK as output */
	DDRB |= (1 << MOSI_PIN) | (1 << SCLK_PIN);

	/** Set MISO as input */
	DDRB &= ~(1 << MISO_PIN);

	/** Set SPI mode */
	if (spi->mode == SPI_MASTER)
	{
		/** Set SS and SCK as output */
		DDRB |= (1 << spi->ss_pin) | (1 << SCLK_PIN);
		PORTB |= (1 << spi->ss_pin);
		SPCR = (1 << SPE) | (1 << MSTR);
		} else {
		/** Set SS and MOSI as input */
		DDRB &= ~((1 << spi->ss_pin) | (1 << MOSI_PIN));
		SPCR = (1 << SPE);
	}

	/** Set SPI speed */
	SPCR |= spi->speed;

	/** Set SPI edge */
	if (spi->edge == SPI_SCLK_MODE_1_TRAIL_RISE || spi->edge == SPI_SCLK_MODE_3_TRAIL_FALL)
	{
		SPCR |= (1 << CPHA);
	}
	if (spi->edge == SPI_SCLK_MODE_2_LEAD_FALL || spi->edge == SPI_SCLK_MODE_3_TRAIL_FALL)
	{
		SPCR |= (1 << CPOL);
	}

	/** Set SPI format */
	if (spi->format == SPI_LSB_FIRST)
	{
		SPCR |= (1 << DORD);
	}

	return spi;
}


/************************************************************************/
/** Function to Send data via SPI */
void spi_tx(spi_t *spi, uint8_t data)
{
	PORTB &= ~(1 << spi->ss_pin);	/**< Assert Slave Select */
	SPDR = data;					/**< Start transmission */
	while (!(SPSR & (1 << SPIF)));	/**< Wait for transmission to complete */
	PORTB |= (1 << spi->ss_pin);	/**< Unselect Slave Select */
}


/************************************************************************/
/** Function to receive data via SPI */
uint8_t spi_rx(spi_t *spi)
{
	PORTB &= ~(1 << spi->ss_pin);	/**< Assert Slave Select */
	SPDR = 0x00;					/**< Start transmission to receive data */
	while (!(SPSR & (1 << SPIF)));	/**< Wait for reception to complete */
	PORTB |= (1 << spi->ss_pin);	/**< Unselect Slave Select */
	return SPDR;					/**< Return received data */
}


/************************************************************************/
/** Frees memory used by the SPI configuration struct */
void spi_delete(spi_t *spi)
{
	free(spi);
}


/************************************************************************/

/** @} */