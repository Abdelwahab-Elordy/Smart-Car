/*
 * TIMER1_Interface.h
 *
 *  Created on: Jul 28, 2025
 *      Author: tohami
 */

#ifndef MCAL_TIMER1_HDR_TIMER1_INTERFACE_H_
#define MCAL_TIMER1_HDR_TIMER1_INTERFACE_H_

void  T1FastPWM_Config();
void Timer1_SetICR(u16 Top);
void Timer1_SetOCR1A(u16 Compare);
void Timer1_SetOCR1B(u16 Compare);

void Timer1_Overflow_Callback(void (*PF)(void));
void __vector_9() __attribute__((signal));

void Timer1_ICU_Config();
void Timr1_ICU_CallBack(void(*PF)(void));
void __vector_6() __attribute__((signal));


#endif /* MCAL_TIMER1_HDR_TIMER1_INTERFACE_H_ */
