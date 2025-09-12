#include "../Lib/Definition.h"
#include "../Lib/BitMath.h"
#include"../MCAL/DIO/Header/DIO_Private.h"
#include"../MCAL/DIO/Header/DIO_Interface.h"
#include "../MCAL/GIE/Header/GIE.h"
#include "../MCAL/TIMER0/HDR/TIMER0_Interface.h"
#include"../MCAL/TIMER1/HDR/TIMER1_Interface.h"
#include"../Hal/MOTORDR/HDR/MDR_Interface.h"
#include"../Hal/ULtrasonic/HDR/ULTRA_Config.h"
#include"../Hal/ULtrasonic/HDR/ULTRA_Interface.h"
#include"../MCAL/USART/USART_Register.h"
#include"../MCAL/USART/USART_Interface.h"
#include<util/delay.h>


u8  distance = 0;
u8  mode  ;

static u8 speed = 30;
void Carr_Stopp();
void Car_AutoControl();
void Car_ManualControl();
void USART_InterruptHandler(){
	mode = USART_u8ReceiveData();

	if( mode =='m'){ Car_ManualControl();}
	else if( mode == 's'){
		 Carr_Stopp();
					}


}


int main(void)
{

    USART_voidInit();
    ULTRASONIC_Init();
    MDR_Config();

    USART_SetCallBack(USART_InterruptHandler);
        GIE_Enable();
    MDR_SetSpeed(speed);

    while(1){

    	if (mode == 'm') {
    	    Car_ManualControl();
    	}
    	else if (mode == 's') {
    		 Carr_Stopp();



    	}
    	else {
    	    Car_AutoControl();
    	}

    	}






    }

void Car_ManualControl()
{
	while('a' != mode )
	{
		mode = USART_u8ReceiveData();

		        switch (mode)
		        {
		            case 'f':
		            	USART_voidSendString("the direction is : ");
		            	USART_voidSendString("Forward  ");
		            	USART_voidSendString("speed : ");
		            	USART_Sendnumber(speed);

		                    Car_Forward();

		                break;

		            case 'b':
		            USART_voidSendString("the direction is : ");
		         	USART_voidSendString("Backward  ");
		            USART_voidSendString("speed : ");
		        	USART_Sendnumber(speed);

		                Car_Backward();
		                break;

		            case 'l':
			            USART_voidSendString("the direction is : ");
			         	USART_voidSendString("Left  ");
			            USART_voidSendString("speed : ");
			        	USART_Sendnumber(speed);
		                Car_Left();
		                break;

		            case 'r':
		            	   USART_voidSendString("the direction is : ");
		            	 	USART_voidSendString("Right   ");
		            	   USART_voidSendString("speed : ");
		                	USART_Sendnumber(speed);
		                Car_Right();


		                break;

		            case 'w':

		                USART_voidSendString("  Car Stopped ");
		                Car_Stop();
		                break;

		            case '+':
		                if (speed < 100) speed += 5;
		                MDR_SetSpeed(speed);
		         	   USART_voidSendString("speed : ");
		         		   USART_Sendnumber(speed);
		                break;

		            case '-':
		                if (speed > 10) speed -= 5;
		                MDR_SetSpeed(speed);
		                USART_voidSendString("speed : ");
		                 USART_Sendnumber(speed);
		                break;
		        }
		    }
	}

 void Car_AutoControl()
{
	  	   Car_Stop();

    distance = ULTRASONIC_GetDistance();


          if (distance == 999)
          {
              distance = 100;
          }
          while( distance >30)

    {


              MDR_SetSpeed(45);
               Car_Forward();
             _delay_ms(20);
			    distance = ULTRASONIC_GetDistance();

    }

          USART_voidSendString("  There's an obstacle in the way.  ");
          USART_voidSendString("Distance : ");
            USART_Sendnumber(distance);


        	  MDR_SetSpeed(0);
                  Car_Stop();
                  MDR_SetSpeed(40);
                  Car_Backward();
                  _delay_ms(700);
                  MDR_SetSpeed(4);
                  Car_Right();
                  _delay_ms(500);
                  MDR_SetSpeed(45);
                  Car_Forward();

                  USART_voidSendString("   Distance : ");
                              USART_Sendnumber(distance);

}

 Carr_Stopp()
 {
	 while(mode != 'a' ){
		 mode = USART_u8ReceiveData();

         USART_voidSendString("  waiting ");
	 Car_Stop();
	 }


 }
