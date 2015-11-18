/*
 * Power_Board_d.c
 *
 * Created: 11/17/2015 7:24:58 PM
 * Author : John
 * TODO:: Add block here
 */ 

#include "system_config.h"	//must be the first include file
#include <avr/io.h>
#include "i2c.c"
#include "spi.c"

int main(void) {
    //TODO:: init stuff
	spi_master_init();
    while (1) {
		//TODO:: code stuff
		for (uint8_t i = 0; i <= 200; i++) {
			spi_master_transmit(i);
		}
    }
}