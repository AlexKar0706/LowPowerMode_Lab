/*
**	SysTick.c
**	This file have basic initialisation of NVIC with interrupt handling function
*/

/* IMPORTS */
#include "SysTick.h"
#include "tm4c123gh6pm.h"

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
