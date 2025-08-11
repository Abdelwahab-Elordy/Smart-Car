/*
 * GIE.h
 *
 *  Created on: Jul 23, 2025
 *      Author: tohami
 */

#ifndef MCAL_GIE_HEADER_GIE_H_
#define MCAL_GIE_HEADER_GIE_H_

#define GIE_SREG *((volatile u8*)0x5f)


#define GIE_Ibit 7

void GIE_Enable();

void GIE_Disable();

#endif /* MCAL_GIE_HEADER_GIE_H_ */
