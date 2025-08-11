/*
 * DIO_Interface.h
 *
 *  Created on: Jul 17, 2025
 *      Author: tohami
 */

#ifndef MCAL_DIO_HEADER_DIO_INTERFACE_H_
#define MCAL_DIO_HEADER_DIO_INTERFACE_H_


void DIO_SelectDirectionforGroup(u8 GroupName,u8 DirectionState);
void DIO_SelectDirectionforPin(u8 GroupName,u8 PinNumber,u8 DirectionState);

void DIO_SelectOutputforGroup (u8 GroupName,u8 State);
void DIO_SelectOutputforPin (u8 GroupName,u8 PinNumber,u8 State);

u8   DIO_ReadInputValueforGroup (u8 GroupName);
u8   DIO_ReadInputValueforPin (u8 GroupName,u8 PinNumber);












#endif /* MCAL_DIO_HEADER_DIO_INTERFACE_H_ */

