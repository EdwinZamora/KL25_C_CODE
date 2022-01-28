
#include "SenoCoseno.h" 

#define PRIMER_CUADRANTE 	1
#define SEGUNDO_CUADRANTE 	2
#define TERCER_CUADRANTE 	3
#define CUARTO_CUADRANTE 	4

#define PRIMER_CUADRANTE_GRADOS (sizeof(kaSinTable)/2)-1//31
#define SEGUNDO_CUADRANTE_GRADOS PRIMER_CUADRANTE_GRADOS*2//63
#define TERCER_CUADRANTE_GRADOS PRIMER_CUADRANTE_GRADOS*3//95
#define CUARTO_CUADRANTE_GRADOS PRIMER_CUADRANTE_GRADOS*4//127


signed short wfnSeno(unsigned short wGradosPosicion)
{
		//Encontrar el cuadrante de trabajo y regresar valor
	if(wGradosPosicion > TERCER_CUADRANTE_GRADOS && wGradosPosicion <= CUARTO_CUADRANTE_GRADOS)
	{
		return kaSinTable[CUARTO_CUADRANTE_GRADOS-wGradosPosicion]*(-1);
	}
	else if(wGradosPosicion > SEGUNDO_CUADRANTE_GRADOS && (wGradosPosicion <= TERCER_CUADRANTE_GRADOS))
	{
		return kaSinTable[wGradosPosicion-(SEGUNDO_CUADRANTE_GRADOS+1)]*(-1);
	}
	else if(wGradosPosicion > PRIMER_CUADRANTE_GRADOS && (wGradosPosicion <= SEGUNDO_CUADRANTE_GRADOS))
	{
		return kaSinTable[SEGUNDO_CUADRANTE_GRADOS-wGradosPosicion];
	}
	else
	{
		return kaSinTable[wGradosPosicion];
	}
	
	return 0;
}

signed short wfnCoseno(unsigned short wGradosPosicion)
{
	//Encontrar el cuadrante de trabajo y regresar valor
	if(wGradosPosicion > TERCER_CUADRANTE_GRADOS && wGradosPosicion <= CUARTO_CUADRANTE_GRADOS)
		{
			return kaSinTable[wGradosPosicion-(TERCER_CUADRANTE_GRADOS+1)];
		}
		else if(wGradosPosicion > SEGUNDO_CUADRANTE_GRADOS && (wGradosPosicion <= TERCER_CUADRANTE_GRADOS))
		{
			return kaSinTable[TERCER_CUADRANTE_GRADOS-wGradosPosicion]*(-1);
		}
		else if(wGradosPosicion > PRIMER_CUADRANTE_GRADOS && (wGradosPosicion <= SEGUNDO_CUADRANTE_GRADOS))
		{
			return kaSinTable[wGradosPosicion-(PRIMER_CUADRANTE_GRADOS+1)]*(-1);
		}
		else
		{
			return kaSinTable[(SEGUNDO_CUADRANTE_GRADOS-1)-wGradosPosicion];
		}
		
		return 0;
}
