/*
 * MDR_Interface.h
 *
 *  Created on: Aug 4, 2025
 *      Author: toham
 */

#ifndef HAL_MOTORDR_HDR_MDR_INTERFACE_H_
#define HAL_MOTORDR_HDR_MDR_INTERFACE_H_

void MDR_Config(void);
void Car_Forward(void);
void Car_Backward(void);
void Car_Left(void);
void Car_Right(void);
void Car_Stop(void);
void MDR_SetSpeed(u8 speed);
#endif /* HAL_MOTORDR_HDR_MDR_INTERFACE_H_ */
