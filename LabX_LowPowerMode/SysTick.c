/*
**	SysTick.c
**	This file have basic initialisation of NVIC with interrupt handling function
*/

/* IMPORTS */
#include "SysTick.h"
#include "tm4c123gh6pm.h"
#include "AnalogTemperature.h"

/* FUNCTIONS */

/*
**	NVIC initialisation
**
**	To initialise NVIC, single element should be pass to this function.
** 
**  Argument period represents 24-bit reload value of NVIC system, 0x000000 - 0xFFFFFF
**
*/
void SysTick_Init(unsigned long period){
	/*All needed SysTick setting*/
}

/*
**	NVIC interrupt handler
**
**	Function print CPU Temperature in the debbug console every 5 seconds
**
*/
void SysTick_Handler(void){ 
	Print_Temp();                   // Print Temperature
}
