/*
 * Neurona.c
 *
 *  Created on: Apr 11, 2018
 *      Author: ABC
 */
#include "Neurona.h"


void vfnNeuronaOutput( tNeurona *pNeurona )
{
	do
	{
		*pNeurona->dwResultadoCapa += (unsigned long)pNeurona->wpPeso * (unsigned long)pNeurona->wpEntrada++;
	}while(pNeurona->wpPeso++ != 0);
	*pNeurona->dwResultadoCapa = pNeurona->vfnFunciones(*pNeurona->dwResultadoCapa);
}

unsigned long vfnLogSig(unsigned long dwResNeurona)
{
	return dwResNeurona;//Funcion LogSig
}
unsigned long vfnActivacion(unsigned long dwResNeurona)
{
	return dwResNeurona;//Funcion LogSig
}
	
