/*
 * USART_Interface.h
 *
 *  Created on: Jul 30, 2025
 *      Author: tohami
 */

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

void USART_voidInit();

void USART_voidSendData(u8 Copy_u8Data);

u8 USART_u8ReceiveData();

void USART_voidSendString(u8* Copy_pString);

void USART_voidReceiveStaring(u8* Return_pString);

void USART_SetCallBack(void (*fun)(void));

void __vector_13() __attribute__((signal));

void USART_Sendnumber(long int num);

void USART_TransmiteByte_BLOCKING(u8 data);
u8 USART_ReceiveByte_BLOCKING();
#endif /* USART_INTERFACE_H_ */
