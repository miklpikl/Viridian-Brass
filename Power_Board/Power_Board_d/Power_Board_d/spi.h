//spi.h
//created by John Fritz 11/17/2015

#warning Define SPI configuration in spi.h

#define DDR_SPI			DDRB	//data direction register of hardware spi
#define MOSI			3		//MOSI location in DDR_SPI
#define MISO			4		//MISO location in DDR_SPI
#define SCK				5		//SCK location in DDR_SPI
#define SCK_DIV			16		//SCK clock divider

#if ((SCK_DIV != 2) && (SCK_DIV != 4) && (SCK_DIV != 8) && (SCK_DIV != 16) && (SCK_DIV != 32) && (SCK_DIV != 64) && (SCK_DIV != 128))
	#error Define clock divider for SPI SCK as 2, 4, 8, 16, 32, 64, or 128
#endif