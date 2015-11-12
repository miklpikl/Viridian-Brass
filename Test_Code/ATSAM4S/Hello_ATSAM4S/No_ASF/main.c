/*
 * Hello_ATSAM4S.c
 *
 * Created: 11/11/2015 8:15:28 PM
 * Author : John Fritz
 * 			fritz2@purdue.edu
 * 
 * Hello World on the ATSAM4S MCU over USB (device) and/or UART (debug port)
 * 
 */ 

#define USB_Hello
#define UART_Hello

#include "sam.h"
#include "lipsum_string.h"


int main(void) {
    /* Initialize the SAM system */
    SystemInit();
	
	#ifdef USB_Hello
	
	#endif
	
	#ifdef UART_Hello
	
	#endif

	/* Start main loop */
    while(1) {
		#ifdef USB_Hello
			
		#endif
		
		#ifdef UART_Hello
			
		#endif
    }
}
