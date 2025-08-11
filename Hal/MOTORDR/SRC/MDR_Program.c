/*
 * MDR_Program.c
 *
 *  Created on: Aug 4, 2025
 *      Author: tohami
 */

#include <util/delay.h>
#include "../../../Lib/Definition.h"
#include "../../../Lib/BitMath.h"
#include "../../../MCAL/DIO/Header/DIO_Private.h"
#include "../../../MCAL/DIO/Header/DIO_Interface.h"
#include "../../../MCAL/TIMER0/HDR/TIMER0_Interface.h"
#include "../HDR/MDR_Config.h"
#include "../HDR/MDR_Interface.h"

void MDR_Config()
{
	DIO_SelectDirectionforPin(MDR_Port, MDR_PA1, Output);
	DIO_SelectDirectionforPin(MDR_Port, MDR_PA2, Output);
	DIO_SelectDirectionforPin(MDR_Port, MDR_PB3, Output);
	DIO_SelectDirectionforPin(MDR_Port, MDR_PB4, Output);

	DIO_SelectDirectionforPin(MOTOR_PWM_PORT, MOTOR_PWM_PIN, Output); // OC0

	T0FastPWM_Config();
	//T0FastPWM_DutyCycle(60);
}

void Car_Forward()
{
	DIO_SelectOutputforPin(MDR_Port, MDR_PA1, Low);
	DIO_SelectOutputforPin(MDR_Port, MDR_PA2, High);
	DIO_SelectOutputforPin(MDR_Port, MDR_PB3, High);
	DIO_SelectOutputforPin(MDR_Port, MDR_PB4, Low);
}

void Car_Backward()
{
	DIO_SelectOutputforPin(MDR_Port, MDR_PA1, High);
	DIO_SelectOutputforPin(MDR_Port, MDR_PA2, Low);
	DIO_SelectOutputforPin(MDR_Port, MDR_PB3, Low);
	DIO_SelectOutputforPin(MDR_Port, MDR_PB4, High);
}

void Car_Right()
{
	DIO_SelectOutputforPin(MDR_Port, MDR_PA1, Low);
	DIO_SelectOutputforPin(MDR_Port, MDR_PA2, High);
	DIO_SelectOutputforPin(MDR_Port, MDR_PB3, Low);
	DIO_SelectOutputforPin(MDR_Port, MDR_PB4, Low);
}

void Car_Left()
{
	DIO_SelectOutputforPin(MDR_Port, MDR_PA1, Low);
	DIO_SelectOutputforPin(MDR_Port, MDR_PA2, Low);
	DIO_SelectOutputforPin(MDR_Port, MDR_PB3, High);
	DIO_SelectOutputforPin(MDR_Port, MDR_PB4, Low);
}

void Car_Stop()
{
	DIO_SelectOutputforPin(MDR_Port, MDR_PA1, Low);
	DIO_SelectOutputforPin(MDR_Port, MDR_PA2, Low);
	DIO_SelectOutputforPin(MDR_Port, MDR_PB3, Low);
	DIO_SelectOutputforPin(MDR_Port, MDR_PB4, Low);
}

void MDR_SetSpeed(u8 speed)
{


	T0FastPWM_DutyCycle(speed);
}



