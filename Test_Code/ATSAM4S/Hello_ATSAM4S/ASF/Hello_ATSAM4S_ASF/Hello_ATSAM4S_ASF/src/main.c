/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * This is a bare minimum user application template.
 *
 * For documentation of the board, go \ref group_common_boards "here" for a link
 * to the board-specific documentation.
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# Minimal main function that starts with a call to board_init()
 * -# Basic usage of on-board LED and button
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
//#define UART_TEST
#define USB_TEST

#include <asf.h>
#include <string.h>

#ifdef UART_TEST
	#include "conf_uart.h"
#endif

#ifdef USB_TEST
	#include "conf_usb.h"
	
	static bool my_flag_autorize_cdc_transfert = false;
	
	//USB Specific Function Prototypes
	void usb_cdc_start(void);
	void usb_cdc_stop(void);
	bool my_callback_cdc_enable(void);
	void my_callback_cdc_disable(void);
	//void user_callback_vbus_action(bool);
	void usb_cdc_putc(char);
	uint8_t usb_cdc_getc(void);
	void usb_cdc_read(uint8_t*, uint32_t);
	void usb_cdc_write(const uint8_t*, uint32_t);
	uint8_t reverse_case(uint8_t);	
#endif

int main (void) {
	board_init();
	
	#ifdef UART_TEST
		/* UART initialization, implemented in uart_config.h */
		uart_init();
	#endif
	
	#ifdef USB_TEST
		sysclk_init();
		irq_initialize_vectors();
		cpu_irq_enable();
		
		//start
		usb_cdc_start();
	#endif

	while (1) {
		/* Is button pressed? */
		if (ioport_get_pin_level(BUTTON_0_PIN) == BUTTON_0_ACTIVE) {
			/* Yes, so turn LED on. */
			ioport_set_pin_level(LED_0_PIN, LED_0_ACTIVE);
		} else {
			/* No, so turn LED off. */
			ioport_set_pin_level(LED_0_PIN, !LED_0_ACTIVE);
		}
		
		//echo function
		usb_cdc_putc(reverse_case(usb_cdc_getc()));
	}
}

void usb_cdc_start(void){
	udc_start();
	UDC_VBUS_EVENT(true);
}
void usb_cdc_stop(void){
	UDC_VBUS_EVENT(false);
}

bool my_callback_cdc_enable(void){
	my_flag_autorize_cdc_transfert = true;
	return true;
}

void my_callback_cdc_disable(void){
	my_flag_autorize_cdc_transfert = false;
}

void user_callback_vbus_action(bool b_high){
	if(b_high){
		//attach usb device
		udc_attach();
	} else {
		//detach usb device
		udc_detach();
	}
}

void usb_cdc_putc(char c){
	if(my_flag_autorize_cdc_transfert) {
		//wait til tx is ready
		while(!udi_cdc_is_tx_ready);
		udi_cdc_putc(c);
	}
}

uint8_t usb_cdc_getc(void){
	//halt until a character is received
	return udi_cdc_getc();
}

void usb_cdc_read(uint8_t *buf, uint32_t buf_size){
	udi_cdc_read_buf(buf, buf_size);
}

void usb_cdc_write(const uint8_t *buf, uint32_t buf_size){
	udi_cdc_write_buf(buf, buf_size);	
}

uint8_t reverse_case(uint8_t c){
	if(c >= 'a' && c <= 'Z'){
		return c - ('a' - 'A');
	} else if(c >= 'A' && c <= 'Z'){
		return c + ('a' - 'A');
	} else {
		return c;
	}
}	











