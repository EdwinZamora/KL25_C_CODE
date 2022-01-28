/*
 * DAC.c
 *
 *  Created on: Nov 27, 2017
 *      Author: User
 */

#include "DAC.h"

void vfndac_Init(void)
{
 // DAC0 clock enabled
 SIM_SCGC6 |= SIM_SCGC6_DAC0_MASK;
 SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK; 
 
 PORTE_PCR30 |= PORT_PCR_MUX(0);
 GPIOE_PDDR |= (1<<30);
 
 DAC0_C0 |= DAC_C0_DACEN_MASK;
}

void vfndac_Output(unsigned short bValue)
{
    DAC0_DAT0L = (bValue & 0xFF);
    DAC0_DAT0H = (bValue>>8);
}
