/*
 * DFT.c
 *
 *  Created on: Apr 16, 2018
 *      Author: ABC
 */

#include "DFT.h"

void vfnDFT(unsigned char *bSenalEntrada,unsigned long *wDFTArrayResultado,unsigned short wSize)
{
	unsigned short wSizeIndex = 0;
	unsigned short wSizeIndexTotal = wSize-1;
	unsigned char bVelocidadArreglo = 1;
	unsigned short wVelocidad = 0;
	do
	{
		*wDFTArrayResultado = 0;	
		do
		{
			wVelocidad = wSizeIndex * bVelocidadArreglo;
			if(wVelocidad > wSize-1)
			{
				wVelocidad -= wSize; 
			}
			*wDFTArrayResultado += (*bSenalEntrada * wfnCoseno(wVelocidad)) - (*bSenalEntrada * wfnSeno(wVelocidad));
		
		}while(wSizeIndex++ < wSize-1);
		*++wDFTArrayResultado = 0;
		bVelocidadArreglo++;
	}while(wSizeIndexTotal-- > 0);
}
