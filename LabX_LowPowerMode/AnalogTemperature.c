/*
**	AnalogTemperature.c
**	This file contains initialisation of Analog-digital converter with internal CPU temperature sensor
**  activation. Also file contains reading temperature from ADC buffer and converting analog value
**	to Celsius.
*/

/* IMPORTS */
#include <stdio.h>
#include "AnalogTemperature.h"
#include "tm4c123gh6pm.h"

/* FUNCTIONS */

/*
**	Initialisation of temperature sensor.
**
**  This function activate temperature sensor by initialisation of ADC0 with additional initialisation
**  of SS3(Sample Sequencer) with special setting of TS0 bit
*/
void Temp_Sensor_Init(void) { volatile unsigned long delay;
	/*ADC0 with SS3 initialization*/
}

/*
**	Read value from temperature sensor.
**
**  This function activate ADC0 converter and read value from temperature sensor
**  in the ADC FIFO buffer.
**  
**  Function returns 0-4095 analog value that represents the temperature of CPU
*/
unsigned long ADC0_In(void){  
	unsigned long result;
  ADC0_PSSI_R = 0x0008;							// 1) initiate SS3
  while(!(ADC0_RIS_R & 0x08));			// 2) wait for conversion done
  result = ADC0_SSFIFO3_R & 0xFFF;	// 3) read result
  ADC0_ISC_R = 0x0008;							// 4) acknowledge completion

  return result;
}

/*
**	Convert analog value to Celsius
**
**  Function use expression from Tiva C Series TM4C123GH6PM datasheet (p. 813) 
**  
**	Argument sample represents the analog sample, that has been recieved 
**  from ADC0_In() functions
**
**  Function returns float value, that represents temperature of CPU in Celsius
*/
float Convert_To_Cel (unsigned long sample) {
	return (147.5 - ((75 * 3.3 * sample) / 4096));
}


/*
**	Print temperature in Celsius on LCD display
**
*/
void Print_Temp() {
	unsigned long result = 0;
	float celsius = 0.0f;
	
	/*Read analog value from temperature sensor*/
	
  /*Convert analog value in Celsius degrees format*/
	
	printf("\nADC temperature code: %lu\n", result);
	printf("Temperature in C: %.1f\n", celsius);
}
