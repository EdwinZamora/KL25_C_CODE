/*
 * PIT.c
 *
 *  Created on: Jan 22, 2018
 *      Author: User
 */


#include "PIT.h"


void vfnPITInit(void)
{
	SIM_SCGC6 |= SIM_SCGC6_PIT_MASK;
	PIT_MCR = 0; 
	PIT_TCTRL0 = PIT_TCTRL_TEN_MASK;
	 
}
void vfnPitSetValue(unsigned long dwTime)
{
	PIT_LDVAL0 = dwTime;
}
unsigned char bPIT_Valid(void)
{
	if(PIT_TFLG0 & PIT_TFLG_TIF_MASK)
	{
		PIT_TFLG0 &= PIT_TFLG_TIF_MASK;
		return 1; 
	}
	else
	{
		return 0;
	}
}
