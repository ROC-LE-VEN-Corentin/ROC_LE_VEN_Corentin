#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "ChipConfig.h"
#include "IO.h"
#include "timer.h"
#include "PWM.h"
#include "ADC.h"
#include "robot.h"

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


 
LED_BLANCHE = 0;
LED_BLEUE = 0;
LED_ORANGE = 0;

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
        float volts2 = ((float) result[2])*3.3/4096*3.2;
        robotState.distanceTelemetreDroit = 34 /volts2-5;
        float volts1 = ((float) result[1])*3.3/4096*3.2;
        robotState.distanceTelemetreCentre = 34 /volts1-5;
        float volts0 = ((float) result[0])*3.3/4096*3.2;
        robotState.distanceTelemetreGauche = 34 /volts0-5;
        if (robotState.distanceTelemetreDroit < 30)
        {
            LED_BLANCHE = 1;
        }
        else
        {
            LED_BLANCHE = 0;
        }
        if (robotState.distanceTelemetreCentre < 30)
        {
            LED_BLEUE = 1;
        }
        else 
        {
            LED_BLEUE = 0;
        }
        if (robotState.distanceTelemetreGauche < 30)
        {
            
            LED_ORANGE = 1;
        }
        else 
        {
            LED_ORANGE = 0;
        }
    }
   
} // fin main
}