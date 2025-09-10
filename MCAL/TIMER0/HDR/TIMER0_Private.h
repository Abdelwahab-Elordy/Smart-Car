/*
 * TIMER0_Private.h
 *
 *  Created on: Jul 27, 2025
 *      Author: tohami
 */

#ifndef MCAL_TIMER0_HDR_TIMER0_PRIVATE_H_
#define MCAL_TIMER0_HDR_TIMER0_PRIVATE_H_

#define FOC0 7
#define WGM00 6
#define COM01 5
#define COM00 4
#define WGM01 3
#define CS02 2
#define CS01 1
#define CS00 0

#define OCIE 1
#define TOIE 0

#define OCF0 1
#define TOVF0 0

typedef enum
{
	TimerStopped,
	No_Prescaler,
	T0_Prescaler_8,
	T0_Prescaler_64,
	T0_Prescaler_256,
	T0_Prescaler_1024,
	EXT_Rising,
    EXT_Falling,
}T0_Prescaler;


#endif /* MC1AL_TIMER0_HDR_TIMER0_PRIVATE_H_ */
