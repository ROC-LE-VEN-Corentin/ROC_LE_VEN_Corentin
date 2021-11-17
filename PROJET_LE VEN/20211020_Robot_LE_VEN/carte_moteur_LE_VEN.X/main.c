#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "ChipConfig.h"
#include "IO.h"
#include "timer.h"
#include "PWM.h"
#include "ADC.h"

int main (void){
InitIO();
InitPWM();
/***************************************************************************************************/
//Initialisation de l?oscillateur
/****************************************************************************************************/
InitOscillator();
//Initialisation des timers
InitTimer23();
InitTimer1();
// Initialisation du convertisseur
InitADC1();
/****************************************************************************************************/
// Configuration des entrées sorties
/****************************************************************************************************/


 
LED_BLANCHE = 1;
LED_BLEUE = 1;
LED_ORANGE = 1;

/****************************************************************************************************/
// Boucle Principale
/****************************************************************************************************/
while(1)
{   
    
    if ( ADCIsConversionFinished() == 1)
    {
        unsigned int * result = ADCGetResult();
        float ADCValue0 =  result[0];
        float ADCValue1 =  result[1];
        float ADCValue2 =  result[2];
        ADCClearConversionFinishedFlag();
    }
    //LED_BLANCHE=!LED_BLANCHE;
} // fin main
}