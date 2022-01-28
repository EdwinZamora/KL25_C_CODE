/*
 * main implementation: use this 'C' sample to create your own application
 *
 */


#include "derivative.h" /* include peripheral declarations */
#include "ADC.h"
#include "PIT.h"
#include "DFT.h"

#define TARGET_TIME_10k 1050
#define TAMANO_SENAL_ENTRADA 128
#define CANAL 3


int main(void)
{
	unsigned long dwaDFTResult[TAMANO_SENAL_ENTRADA];
	unsigned char baSenalEntrada[TAMANO_SENAL_ENTRADA];
	unsigned char bIndex = 0;
	
	vfnPITInit();
	vfnADCInit();
	
	
	for(;;) 
	{	   
		vfnPitSetValue(TARGET_TIME_10k);
		while(bIndex++ < TAMANO_SENAL_ENTRADA-1)
		{
			while(!bPIT_Valid());
			baSenalEntrada[bIndex] = bfnADCLectura(CANAL);//3 bfnADCLectura
			
		}
		
		vfnDFT(&baSenalEntrada[0],&dwaDFTResult[0],TAMANO_SENAL_ENTRADA);
	}
	
	return 0;
}
