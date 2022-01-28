/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "SenoCoseno.h" 



int main(void)
{
	
	signed short wSin = 0;		
	signed short wCos = 0;	
	
	for(;;) {	   
		wSin = wfnSeno(90);
		wCos = wfnCoseno(1);
	}
	
	return 0;
}
