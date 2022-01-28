
#include "SenoCoseno.h" 

#define PRIMER_CUADRANTE 	1
#define SEGUNDO_CUADRANTE 	2
#define TERCER_CUADRANTE 	3
#define CUARTO_CUADRANTE 	4

#define PRIMER_CUADRANTE_GRADOS 90
#define SEGUNDO_CUADRANTE_GRADOS 180
#define TERCER_CUADRANTE_GRADOS 270
#define CUARTO_CUADRANTE_GRADOS 360

signed short wfnSeno(unsigned short wGrados)
{
		unsigned char bNumCuadrante = 0;	
//Encontrar el cuadrante de trabajo
	if(wGrados > TERCER_CUADRANTE_GRADOS && wGrados <= CUARTO_CUADRANTE_GRADOS)
	{
		bNumCuadrante = CUARTO_CUADRANTE;
	}
	else if(wGrados > SEGUNDO_CUADRANTE_GRADOS && (wGrados <= TERCER_CUADRANTE_GRADOS))
	{
		bNumCuadrante = TERCER_CUADRANTE;
	}
	else if(wGrados > PRIMER_CUADRANTE_GRADOS && (wGrados <= SEGUNDO_CUADRANTE_GRADOS))
	{
		bNumCuadrante = SEGUNDO_CUADRANTE;
	}
	else
	{
		bNumCuadrante = PRIMER_CUADRANTE;
	}
	//Asignar un val;or de tabla dependiendo el cuadrante
	if(bNumCuadrante == PRIMER_CUADRANTE)
	{
		return kaSinTable[wGrados];
	}
	else if(bNumCuadrante == SEGUNDO_CUADRANTE)
	{
			return kaSinTable[180-wGrados];
	}
	else if(bNumCuadrante == TERCER_CUADRANTE)
	{
		return kaSinTable[wGrados-180]*(-1);
	}
	else 
	{
		return kaSinTable[360-wGrados]*(-1);
	}
	
	return 0;
}

signed short wfnCoseno(unsigned short wGrados)
{
	unsigned char bNumCuadrante = 0;
			
	//Encontrar el cuadrante de trabajo
		if(wGrados > TERCER_CUADRANTE_GRADOS && wGrados <= CUARTO_CUADRANTE_GRADOS)
		{
			bNumCuadrante = CUARTO_CUADRANTE;
		}
		else if(wGrados > SEGUNDO_CUADRANTE_GRADOS && (wGrados <= TERCER_CUADRANTE_GRADOS))
		{
			bNumCuadrante = TERCER_CUADRANTE;
		}
		else if(wGrados > PRIMER_CUADRANTE_GRADOS && (wGrados <= SEGUNDO_CUADRANTE_GRADOS))
		{
			bNumCuadrante = SEGUNDO_CUADRANTE;
		}
		else
		{
			bNumCuadrante = PRIMER_CUADRANTE;
		}
		//Asignar un valor de tabla dependiendo el cuadrante
		if(bNumCuadrante == PRIMER_CUADRANTE)
		{
			return kaSinTable[90-wGrados];
		}
		else if(bNumCuadrante == SEGUNDO_CUADRANTE)
		{
				return kaSinTable[wGrados-90]*(-1);
		}
		else if(bNumCuadrante == TERCER_CUADRANTE)
		{
			return kaSinTable[wGrados-180]*(-1);
		}
		else 
		{
			return kaSinTable[wGrados-270];
		}
		
		return 0;
}
