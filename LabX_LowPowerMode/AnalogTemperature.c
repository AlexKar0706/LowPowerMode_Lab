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
