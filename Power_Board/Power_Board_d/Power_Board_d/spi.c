//spi.c
//created by John Fritz 11/17/2015

#include "spi.h"

void spi_master_init(void) {
	DDR_SPI = (1 << MOSI) | (1 << SCK);	//set MOSI and sck to output
	SPCR = (1 << SPE) | (1 << MSTR);	//enable spi, master
	
	#if SCK_DIV == 2
		SPCR |= (1 << SPI2X);
	#endif
	#if SCK_DIV == 4
		SPCR |= (SPCR);
	#endif
	#if SCK_DIV == 8
		SPCR |= (1 << SPI2X) | (1 << SPR0);
	#endif
	#if SCK_DIV == 16
		SPCR |= (1 << SPR0);
	#endif
	#if SCK_DIV == 32
		SPCR |= (1 << SPI2X) | (1 << SPR1);
	#endif
	#if SCK_DIV == 64
		SPCR |= (1 << SPI2X) | (1 << SPR1) | (1 << SPR0);
	#endif
	#if SCK_DIV == 128
		SPCR |= (1 << SPR1) | (1 << SPR0);
	#endif
}

void spi_slave_init(void) {
	DDR_SPI = (1 << MISO);	//set MISO to output
	SPCR = (1 << SPE);	//enable spi
}

uint8_t spi_master_transmit(uint8_t data) {
	SPDR = data;	//load data into SPI transmit register and start transmission
	while(!(SPSR & (1 << SPIF)));	//wait until transmission completes
	return SPDR;
}