/*
 * Neurona.h
 *
 *  Created on: Apr 11, 2018
 *      Author: ABC
 */

#ifndef NEURONA_H_
#define NEURONA_H_

typedef struct{

	unsigned short *wpPeso;// = {4,5,6};
	unsigned long *wpEntrada;// = {1,2,3};
	unsigned long *dwResultadoCapa;
	unsigned long (*vfnFunciones)( unsigned long baParametro); 

	}tNeurona;
	
	extern tNeurona *pNeurona;


	void vfnNeuronaOutput( tNeurona *pNeurona );
	unsigned long vfnLogSig(unsigned long dwResNeurona);
unsigned long vfnActivacion(unsigned long dwResNeurona);
#endif /* NEURONA_H_ */
