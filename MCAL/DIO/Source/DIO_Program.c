/*
 * DIO_Program.c
 *
 *  Created on: Jul 17, 2025
 *      Author: tohami
 */
#include<stdio.h>
#include "../../../Lib/Definition.h"
#include "../../../Lib/BitMath.h"
#include"../Header/DIO_Register.h"
#include"../Header/DIO_Private.h"
#include"../Header/DIO_Interface.h"

void DIO_SelectDirectionforGroup(u8 GroupName,u8 DirectionState)
{


 switch(GroupName){
  case DIO_GROUPA : DIO_DDRA = DirectionState;break;
  case DIO_GROUPB : DIO_DDRB = DirectionState;break;
  case DIO_GROUPC : DIO_DDRC = DirectionState;break;
  case DIO_GROUPD : DIO_DDRD = DirectionState;break;

  }

	}

void DIO_SelectDirectionforPin(u8 GroupName,u8 PinNumber,u8 DirectionState)
{
	if(DirectionState == Input)
		{

	 switch(GroupName){
	  case DIO_GROUPA : Clear_bit(DIO_DDRA,PinNumber);break;
	  case DIO_GROUPB : Clear_bit(DIO_DDRB,PinNumber);break;
	  case DIO_GROUPC : Clear_bit(DIO_DDRC,PinNumber);break;
	  case DIO_GROUPD : Clear_bit(DIO_DDRD,PinNumber);break;

	  }
	}
		else if (DirectionState==Output)
		{
			 switch(GroupName){
			  case DIO_GROUPA : Set_bit(DIO_DDRA,PinNumber);break;
			  case DIO_GROUPB : Set_bit(DIO_DDRB,PinNumber);break;
			  case DIO_GROUPC : Set_bit(DIO_DDRC,PinNumber);break;
			  case DIO_GROUPD : Set_bit(DIO_DDRD,PinNumber);break;


			  }
		}
}
void DIO_SelectOutputforGroup (u8 GroupName,u8 State)
{

    	switch(GroupName){
    	    	    	  case DIO_GROUPA : DIO_PORTA=State;break;
    	    	    	  case DIO_GROUPB : DIO_PORTB=State;break;
    	    	    	  case DIO_GROUPC : DIO_PORTC=State;break;
    	    	    	  case DIO_GROUPD : DIO_PORTD=State;break;
    	}


}
void DIO_SelectOutputforPin (u8 GroupName,u8 PinNumber,u8 State)
{
	if(State== Low){
	    	switch(GroupName){
	    	      case DIO_GROUPA : Clear_bit(DIO_PORTA,PinNumber);break;
	    		  case DIO_GROUPB : Clear_bit(DIO_PORTB,PinNumber);break;
	    		  case DIO_GROUPC : Clear_bit(DIO_PORTC,PinNumber);break;
	    		  case DIO_GROUPD : Clear_bit(DIO_PORTD,PinNumber);break;

	    	  }
	    }
	    else if(State==High){
	    	 switch(GroupName){
			  case DIO_GROUPA : Set_bit(DIO_PORTA,PinNumber);break;
			  case DIO_GROUPB : Set_bit(DIO_PORTB,PinNumber);break;
			  case DIO_GROUPC : Set_bit(DIO_PORTC,PinNumber);break;
			  case DIO_GROUPD : Set_bit(DIO_PORTD,PinNumber);break;

	    	    	  }
	    }
}

u8   DIO_ReadInputValueforGroup (u8 GroupName)
{
    u8 GroupState = 0 ;
    switch(GroupName){
   			  case DIO_GROUPA : GroupState = DIO_PINA;break;
   			  case DIO_GROUPB : GroupState = DIO_PINB;break;
   			  case DIO_GROUPC : GroupState = DIO_PINC;break;
   			  case DIO_GROUPD : GroupState = DIO_PIND;break;

   	    	    	  }
   return GroupState ;

}
u8   DIO_ReadInputValueforPin (u8 GroupName,u8 PinNumber)
{
  u8 PinState = 0;
  switch(GroupName){
    			  case DIO_GROUPA : PinState = Get_bit(DIO_PINA,PinNumber);break;
    			  case DIO_GROUPB : PinState = Get_bit(DIO_PINB,PinNumber);break;
    			  case DIO_GROUPC : PinState = Get_bit(DIO_PINC,PinNumber);break;
    			  case DIO_GROUPD : PinState = Get_bit(DIO_PIND,PinNumber);break;

    	    	    	  }
    return PinState ;

}

