/*
 * USART_Program.c
 *
 *  Created on: Jul 30, 2025
 *      Author: tohami
 */
#include "../../Lib/BitMath.h"
#include "../../Lib/Definition.h"
#include"../DIO/Header/DIO_Private.h"
#include"../DIO/Header/DIO_Config.h"
#include"../DIO/Header/DIO_Interface.h"
#include "../USART/USART_Interface.h"
#include "../USART/USART_Register.h"
static void (*RXC_InterruptHandler)(void) = NULL;
void USART_voidInit()
{
	UCSRC = 0b10000110;

	UBRRL = 51;

	Set_bit(UCSRB,UCSRB_RXEN);
	Set_bit(UCSRB,UCSRB_TXEN);

    // Enable RX Complete Interrupt
    Set_bit(UCSRB, UCSRB_RXCIE);
}

void USART_voidSendData(u8 Copy_u8Data)
{
	while( Get_bit(UCSRA,UCSRA_UDRE) == 0 );

	UDR = Copy_u8Data;
}

u8 USART_u8ReceiveData()
{
	while( Get_bit(UCSRA,UCSRA_RXC) == 0 );

	return UDR;
}

void USART_voidSendString(u8* Copy_pString)
{
	while(*Copy_pString != '\0')
	{
		USART_voidSendData(*Copy_pString);
		Copy_pString++;
	}
}

void USART_voidReceiveStaring(u8* Return_pString)
{

}
void USART_SetCallBack(void (*fun)(void)){
	RXC_InterruptHandler = fun;
}
void __vector_13(){
	if(RXC_InterruptHandler != NULL){
		RXC_InterruptHandler();
	}
}
void USART_TransmiteByte_BLOCKING(u8 data){
	while(!(Get_bit(UCSRA, UCSRA_UDRE  )));
	UDR = data;
}

u8 USART_ReceiveByte_BLOCKING(){
	while(!(Get_bit(UCSRA, UCSRA_RXC)));
	return UDR;
}
void USART_Sendnumber(long int num)
{

	u8 reverse[16];
	    u8 i = 0;

	    if (num == 0) {
	    	USART_voidSendData('0');
	        return;
	    }

	    // Extract digits in reverse and store as characters
	    while (num != 0 && i < 10) {
	    	if(num%10==0){
	    	    		reverse[i++]='0';
	    	    	num=(num/10);
	    	    }else{
	        reverse[i++] =(num % 10) + '0';  // Convert digit to char
	        num=(num/10);
	    }}

	    reverse[i] = '\0';  // Null-terminate the string

	    // Print characters from reverse buffer in reverse order
	    while (i > 0) {
	    	USART_voidSendData(reverse[--i]);  // Print digits in original order
	    }



}
