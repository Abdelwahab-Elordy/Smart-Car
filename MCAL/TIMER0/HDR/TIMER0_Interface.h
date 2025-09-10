/*
 * TIMER0_Interface.h
 *
 *  Created on: Jul 27, 2025
 *      Author: tohami
 */

#ifndef MCAL_TIMER0_HDR_TIMER0_INTERFACE_H_
#define MCAL_TIMER0_HDR_TIMER0_INTERFACE_H_

void  T0NormalMode_Config();
void T0NormalMode_CallBack(void(*PF)(void));

void __vector_11() __attribute__((signal));

void  T0CTCMode_Config();
void T0CTCMode_CallBack(void(*PF)(void));

void __vector_10() __attribute__((signal));

/*=====================PWM fast mode===================================*/


void T0FastPWM_Config();
void T0FastPWM_DutyCycle(u8 Dutycycle);

/*=====================PWM Phase correct mode===================================*/


void T0PhcorrectPWM_Config();
void T0PhcorrectPWM_DutyCycle(u8 Dutycycle);


#endif /* MCAL_TIMER0_HDR_TIMER0_INTERFACE_H_ */
