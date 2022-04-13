/* 
 * File:   UART.h
 * Author: Table2
 *
 * Created on 13 avril 2022, 09:21
 */

#ifndef UART_H
#define	UART_H

void InitUART(void);
void SendMessageDirect(unsigned char* message , int length);
void __attribute__((interrupt, no_auto_psv))_U1RXInterrupt(void);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* UART_H */

