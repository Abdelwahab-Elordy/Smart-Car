/*
 * TIMER1_Program.c
 *
 *  Created on: Jul 28, 2025
 *      Author: tohami
 */
#include "../../../Lib/Definition.h"
#include "../../../Lib/BitMath.h"

#include "../HDR/TIMER1_Register.h"
#include "../HDR/TIMER1_Private.h"
#include "../HDR/TIMER1_Config.h"
#include "../HDR/TIMER1_Interface.h"

static u8 prescalerValue = T1_PrescalerSelect;
static void (*G_OVF1)(void) = NULL;
static void (*G_ICU)(void)=NULL;
void  T1FastPWM_Config()
{
	//selec
	Clear_bit(T1_TCCR1A,WGM10);
	Set_bit(T1_TCCR1A,WGM11);
	Set_bit(T1_TCCR1B,WGM12);
	Set_bit(T1_TCCR1B,WGM13);
   //non invert
	Clear_bit(T1_TCCR1A,COM1A0);
	Set_bit(T1_TCCR1A,COM1A1);

	// OC1B non-inverting
	Clear_bit(T1_TCCR1A, COM1B0);
	Set_bit(T1_TCCR1A, COM1B1);

	//prescaler
	prescalerValue &=0x07;
	T1_TCCR1B &=0xF8;
	T1_TCCR1B |=prescalerValue;



}
void Timer1_SetICR(u16 Top)
{
	T1_ICR1=Top;

}
void Timer1_SetOCR1A(u16 Compare)
{
	T1_OCR1A=Compare;

}

void Timer1_SetOCR1B(u16 Compare)
{
    T1_OCR1B = Compare;
}

void Timer1_ICU_Config()
{
	//select Normal Mode
	Clear_bit(T1_TCCR1A,WGM10);
	Clear_bit(T1_TCCR1A,WGM11);
	Clear_bit(T1_TCCR1B,WGM12);
	Clear_bit(T1_TCCR1B,WGM13);

	//select edge
	Set_bit(T1_TCCR1B,ICES1);

	//enable interrupt
	Set_bit(T1_TIMSK,TICIE1);

	Set_bit(T1_TIMSK, TOIE1);  // Enable Timer1 overflow interrupt

	//prescaler
	prescalerValue &=0x07;
	T1_TCCR1B &=0xF8;
	T1_TCCR1B |=prescalerValue;

	T1_TCNT1 = 0 ;

}
void Timr1_ICU_CallBack(void(*PF)(void))
{
	if(PF!=NULL)
	{
		G_ICU=PF;
	}
}
void __vector_6()
{
	if(G_ICU!=NULL)
	{
		G_ICU();
	}
}


void Timer1_Overflow_Callback(void (*PF)(void))
{
	if (PF != NULL)
	{
		G_OVF1 = PF;
	}
}

void __vector_9()
{
	if (G_OVF1 != NULL)
	{
		G_OVF1();
	}
}
