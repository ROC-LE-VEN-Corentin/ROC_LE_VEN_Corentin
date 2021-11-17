

#ifndef PWM_H
#define	PWM_H
#define MOTEUR_DROIT 0
#define MOTEUR_GAUCHE 1

void InitPWM(void);
/*void PWMSetSpeed(float vitesseEnPourcents, unsigned char nbMoteur);*/
void PWMUpdateSpeed(void);
void PWMSetSpeedConsigne(float vitesseEnPourcents, unsigned char nbMoteur);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* PWM_H */

