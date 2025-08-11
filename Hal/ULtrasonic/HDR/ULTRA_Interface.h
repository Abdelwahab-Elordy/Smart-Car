/*
 * ULTRA_Interface.h
 *
 *  Created on: Aug 4, 2025
 *      Author: tohami
 */

#ifndef HAL_ULTRASONIC_HDR_ULTRA_INTERFACE_H_
#define HAL_ULTRASONIC_HDR_ULTRA_INTERFACE_H_



void ULTRASONIC_Init(void);
void ULTRASONIC_Trigger(void);
u16  ULTRASONIC_GetDistance(void);



#endif /* HAL_ULTRASONIC_HDR_ULTRA_INTERFACE_H_ */
