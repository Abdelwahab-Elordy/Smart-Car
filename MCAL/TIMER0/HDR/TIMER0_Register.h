/*
 * TIMER0_Register.h
 *
 *  Created on: Jul 27, 2025
 *      Author: tohami
 */

#ifndef MCAL_TIMER0_HDR_TIMER0_REGISTER_H_
#define MCAL_TIMER0_HDR_TIMER0_REGISTER_H_

#define T0_TCCR0 *((volatile u8*)0x53)

#define T0_TCNT0 *((volatile u8*)0x52)

#define T0_OCR0 *((volatile u8*)0x5C)

#define T0_TIMSK *((volatile u8*)0x59)

#define T0_TIFR0 *((volatile u8*)0x58)


#endif /* MCAL_TIMER0_HDR_TIMER0_REGISTER_H_ */
