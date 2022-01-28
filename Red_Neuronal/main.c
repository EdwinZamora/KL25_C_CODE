/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */
#include "Neurona.h"

#define TOTAL_ENTRADAS 3


	
int main(void)
{
	//Capa 1
	unsigned short wPeso00[] = {1,0};
	unsigned long dwEntrada00[] = {2};
	unsigned short wPeso01[] = {5,0};
	unsigned long dwEntrada01[] = {3};
	unsigned long dwResult1[] = {0};
	//Capa 2
	unsigned short wPeso10[] = {1,2,0};
	unsigned short wPeso11[] = {3,4,0};
	unsigned short wPeso12[] = {5,6,0};
	unsigned short wPeso13[] = {7,8,0};
	unsigned long dwResult2[] = {0};
	//Capa 3
	unsigned short wPeso20[] = {1,2,3,4,0};
	unsigned short wPeso21[] = {5,6,7,8,0};
	unsigned long dwResult3[] = {0};
		
	
	 tNeurona saNeurona[] =
	{
			
			{&wPeso00[0],&dwEntrada00[0],&dwResult1[0],vfnLogSig},
			{&wPeso01[0],&dwEntrada01[0],&dwResult1[1],vfnLogSig},
			
			{&wPeso10[0],&dwResult1[0],&dwResult2[0],vfnActivacion},
			{&wPeso11[0],&dwResult1[0],&dwResult2[1],vfnActivacion},
			{&wPeso12[0],&dwResult1[0],&dwResult2[2],vfnActivacion},
			{&wPeso13[0],&dwResult1[0],&dwResult2[3],vfnActivacion},
			
			{&wPeso20[0],&dwResult2[0],&dwResult3[0],vfnLogSig},
			{&wPeso21[0],&dwResult2[0],&dwResult3[1],vfnLogSig},
			
			{0,0,0,0}
	};
	  tNeurona *pNeurona = &saNeurona[0];

	
	for(;;)
	{
		
		while(pNeurona->wpPeso != 0)
		{
			vfnNeuronaOutput(pNeurona++);
		}
	}
		
	return 0;
}
