/*
 * TIMER1_Private.h
 *
 *  Created on: Jul 28, 2025
 *      Author: tohami
 */

#ifndef MCAL_TIMER1_HDR_TIMER1_PRIVATE_H_
#define MCAL_TIMER1_HDR_TIMER1_PRIVATE_H_

//T1_TCCR1A
#define COM1A1 7
#define COM1A0 6
#define COM1B1 5
#define COM1B0 4
#define FOC1A  3
#define FOC1B  2
#define WGM11  1
#define WGM10  0

//T1_TCCR1B
#define ICNC1  7
#define ICES1  6
#define WGM13  4
#define WGM12  3
#define CS12   2
#define CS11   1
#define CS10   0

//T1_TIMSK
#define  TICIE1 5
#define  OCIE1A 4
#define  OCIE1B 3
#define  TOIE1  2

//T1_TIFR0
#define  ICF1   5
#define  OCF1A  4
#define  OCF1B  3
#define  TOV1   2

#define Rising   1
#define Falling  0



typedef enum
{
	T1_Stopped,
	T1_No_Prescaler,
	T1_Prescaler_8,
	T1_Prescaler_64,
	T1_Prescaler_256,
	T1_Prescaler_1024,
    T1_EXT_Falling,
	T1_EXT_Rising,
}T1_Prescaler;




#endif /* MCAL_TIMER1_HDR_TIMER1_PRIVATE_H_ */
