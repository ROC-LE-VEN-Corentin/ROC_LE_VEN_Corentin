/* 
 * File:   ADC.h
 * Author: Table2
 *
 * Created on 17 novembre 2021, 10:04
 */

#ifndef ADC_H
#define	ADC_H

void InitADC1(void);
void __attribute__((interrupt, no_auto_psv)) _AD1Interrupt(void);
void ADC1StartConversionSequence();
unsigned int * ADCGetResult(void);
unsigned char ADCIsConversionFinished(void);
void ADCClearConversionFinishedFlag(void);
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* ADC_H */

