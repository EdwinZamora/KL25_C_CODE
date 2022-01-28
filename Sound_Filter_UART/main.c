#include "ADC.h"
#include "DAC.h"
#include "PIT.h"
#include "UART0.h"



#define FREQ_MUESTRO 1050
#define MUESTRAS 1000

int main(void){
	
   // Inicializacion
	vfnPITInit();
	vfnPitSetValue(FREQ_MUESTRO);
    vfnADCInit(); 
    vfndac_Init();
    UART_vfnInitialization();
    
    unsigned short wCounter = MUESTRAS;
   
    
    for(;;) 
	{	
    	
    	while(wCounter > 0)
    	{
    		if(bPIT_Valid())
    		{
    			UART_vfnTransmitBuffer(bfnADCLectura(8));//3 bfnADCLectura(ADC_CANAL_POT)
    			wCounter--;
    		}
    	}
    	wCounter = MUESTRAS;
    	while(wCounter > 0)
    	{
    		if(bPIT_Valid())
    		{
    			vfndac_Output(UART_bfnReceiveBuffer());
    			wCounter--;
    		}
    	}
    	wCounter = MUESTRAS;
	}
    return 0;
}
