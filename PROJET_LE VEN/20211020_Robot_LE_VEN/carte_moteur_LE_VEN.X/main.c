#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "ChipConfig.h"
#include "IO.h"
#include "timer.h"
#include "PWM.h"

int main (void){
/***************************************************************************************************/
//Initialisation de l?oscillateur
/****************************************************************************************************/
InitOscillator();
//Initialisation des timers
InitTimer23();
InitTimer1();
/****************************************************************************************************/
// Configuration des entrées sorties
/****************************************************************************************************/
InitIO();
InitPWM();
PWMSetSpeed(0,MOTEUR_DROIT);
PWMSetSpeed(0,MOTEUR_GAUCHE);
_T3Interrupt();
LED_BLANCHE = 1;
LED_BLEUE = 1;
LED_ORANGE = 1;

/****************************************************************************************************/
// Boucle Principale
/****************************************************************************************************/
while(1){    
    //LED_BLANCHE=!LED_BLANCHE;
} // fin main
}