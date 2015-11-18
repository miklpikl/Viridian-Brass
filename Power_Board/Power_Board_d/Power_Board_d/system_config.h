//system_config.h
//Created by John Fritz 11/17/2015

#warning Modify this section with proper values before continuing
#define MCU ATMEGA328	//redefine to any of the following 
						//	ATMEGA328
						//	ATTINY48 (not yet implemented) 

#define ADC_SAMPLES				10
#define CURRENT_THRESHOLD		2500	//in mA

#define BATTERY_ADC_CH_V		0
#define BATTERY_ADC_CH_I		1
#define LOWPOWER_ADC_CH_V		2
#define LOWPOWER_ADC_CH_I		3
#define HIGHPOWER_ADC_CH_V		4
#define HIGHPOWER_ADC_CH_I		5

