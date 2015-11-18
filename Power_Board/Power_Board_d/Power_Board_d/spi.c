//spi.c
//created by John Fritz 11/17/2015

void spi_master_init(void) {
	DDR_SPI = (1 << MOSI) | (1 << SCK);
}

void spi_slave_init(void) {
	
}

uint8_t spi_master_exchange(uint8_t data) {
	SPDR = data;	//load data into SPI transmit register and start transmission
	while(!(SPSR & (1 << SPIF)));	//wait until transmission completes
}