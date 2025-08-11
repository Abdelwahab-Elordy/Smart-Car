/*
 * TIMER0_Program.c
 *
 *  Created on: Jul 27, 2025
 *      Author: tohami
 */
#include "../../../Lib/Definition.h"
#include "../../../Lib/BitMath.h"

#include "../HDR/TIMER0_Register.h"
#include "../HDR/TIMER0_Private.h"
#include "../HDR/TIMER0_Config.h"
#include "../HDR/TIMER0_Interface.h"

static u8 T0_PrescalerValue=T0_PrescalerSelect;
static u8 T0_PreloadValue=PreloadValue;
static u32 T0_No_ofcounts=No_Of_Count;

static void(*GOF)(void)=0;

void  T0NormalMode_Config()
{
	//select mode
	Clear_bit(T0_TCCR0,WGM00);
	Clear_bit(T0_TCCR0,WGM01);

	//set preload
	T0_TCNT0=T0_PreloadValue;

	//interrupt enable
	Set_bit(T0_TIMSK,TOIE);

	//Select prescaler

	T0_PrescalerValue &=0x07;
	T0_TCCR0 &=0xF8;
	T0_TCCR0 |=T0_PrescalerValue;


}
void T0NormalMode_CallBack(void(*PF)(void))
{
	if(PF!=0)
	{
		GOF=PF;
	}

}

void __vector_11()
{
	 static u32 Counter =0 ;
	 Counter++;
	 if(Counter==T0_No_ofcounts)
	 {
		 if (GOF!=0)
		 {
			 GOF();
		 }

       Counter=0;
		 T0_TCNT0=T0_PreloadValue;
	 }


}

static u8 CTC_value = CompareValue;
static u32 CTC_Counts = No_CTC_Counts;

static void (*GCTC)(void)=NULL;

void  T0CTCMode_Config()
{
	//select mode
		Clear_bit(T0_TCCR0,WGM00);
		Set_bit(T0_TCCR0,WGM01);

#if OC0_TypeSelect == OC0_Disconnect
		Clear_bit(T0_TCCR0,COM00);
		Clear_bit(T0_TCCR0,COM01);
#elif OC0_TypeSelect == OC0_Toggle
		Set_bit(T0_TCCR0,COM00);
		Clear_bit(T0_TCCR0,COM01);

#elif OC0_TypeSelect == OC0_Set
		Clear_bit(T0_TCCR0,COM00);
		Set_bit(T0_TCCR0,COM01);
#elif OC0_TypeSelect == OC0_Clear
		Set_bit(T0_TCCR0,COM00);
		Set_bit(T0_TCCR0,COM01);
#endif


		T0_OCR0=CTC_value;

		//interrupt enable
		Set_bit(T0_TIMSK,OCIE);

		//Select prescaler

		T0_PrescalerValue &=0x07;
		T0_TCCR0 &=0xF8;
		T0_TCCR0 |=T0_PrescalerValue;



}
void T0CTCMode_CallBack(void(*PF)(void))
{
	if(PF!=NULL)
		{
		GCTC=PF;
		}


}

void __vector_10()
{
	 static u32 Counter = 0 ;
		 Counter++;
		 if(Counter==CTC_Counts)
		 {
			 if (GCTC!= NULL)
			 {
				 GCTC();
			 }

	       Counter=0;

		 }



}


void T0FastPWM_Config()
{
	//Waveform Generation Mode
	Set_bit(T0_TCCR0,WGM01);
	Set_bit(T0_TCCR0,WGM00);
	//inverting
#if PWMFast_Mode == InvertingMode
	SET_BIT(T0_TCCR0,COM01);
	SET_BIT(T0_TCCR0,COM00);
	//non-inverting
#elif PWMFast_Mode == NonInvertingMode
	Set_bit(T0_TCCR0,COM01);
	Clear_bit(T0_TCCR0,COM00);
#else
#error "Invalid PWMfast option "
#endif
	//default value for duty cycle
	T0FastPWM_DutyCycle(PWMFast_Dutycycledefault);

	//TIMER0_prescaler
	T0_PrescalerValue &=0x07;
	T0_TCCR0   &=0xF8;
	T0_TCCR0 |=T0_PrescalerValue;


}
void T0FastPWM_DutyCycle(u8 Dutycycle)
{

#if PWMFast_Mode == NonInvertingMode
	T0_OCR0=(u8)(((u16)Dutycycle*255UL)/100UL);
#elif PWMFast_Mode == InvertingMode
	T0_OCR0=((1-(u16)Dutycycle)*256)/100;
#else
#error "Invalid PWMfast option "
#endif
}

/*=====================PWM Phase correct mode===================================*/

void T0PhcorrectPWM_Config()
{
	//Waveform Generation Mode
	Clear_bit(T0_TCCR0,WGM01);
	Set_bit(T0_TCCR0,WGM00);

#if PWMPhcorrect_Mode == OC0ph_Set
	SET_BIT(T0_TCCR0,COM01);
	SET_BIT(T0_TCCR0,COM00);

#elif PWMPhcorrect_Mode == OC0ph_Clear
	Set_bit(T0_TCCR0,COM01);
	Clear_bit(T0_TCCR0,COM00);
#else
#error "Invalid PWM phase correct option "
#endif
	//default value for duty cycle
	T0PhcorrectPWM_DutyCycle(PWMPhcorrect_Dutycycledefault);
	//TIMER0_prescaler
	T0_PrescalerValue &=0x07;
	T0_TCCR0   &=0xF8;
	T0_TCCR0 |=T0_PrescalerValue;
}
void T0PhcorrectPWM_DutyCycle(u8 Dutycycle)
{
	Dutycycle/=100;
#if PWMPhcorrect_Mode == OC0ph_Set
	T0_OCR0=(u8)(((u16)Dutycycle*255)/100);
#elif PWMPhcorrect_Mode == OC0ph_Clear
	T0_OCR0=((1-(u16)Dutycycle)*256)/100;
#else
#error "Invalid PWM phase correct option "
#endif

}

