#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "ChipConfig.h"
#include "IO.h"
#include "timer.h"
#include "PWM.h"

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
/****************************************************************************************************/
// Configuration des entr�es sorties
/****************************************************************************************************/


 
LED_BLANCHE = 1;
LED_BLEUE = 1;
LED_ORANGE = 1;

/****************************************************************************************************/
// Boucle Principale
/****************************************************************************************************/
while(1)
{
    //LED_BLANCHE=!LED_BLANCHE;
} // fin main
}