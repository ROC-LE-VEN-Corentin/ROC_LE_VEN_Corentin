

#ifndef PWM_H
#define	PWM_H

void InitPWM(void);
/*void PWMSetSpeed(float vitesseEnPourcents, unsigned char nbMoteur);*/
void PWMUpdateSpeed();
#define MOTEUR_DROIT 0
#define MOTEUR_GAUCHE 1

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* PWM_H */

