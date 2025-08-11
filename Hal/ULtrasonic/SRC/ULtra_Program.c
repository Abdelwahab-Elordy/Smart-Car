/*
 * ULtra_Program.c
 *
 *  Created on: Aug 4, 2025
 *      Author: toham
 */
/*
 * ULTRA_Program.c
 *
 *  Created on: Aug 4, 2025
 *      Author: tohami
 */

#include "../../../Lib/BitMath.h"
#include "../../../Lib/Definition.h"
#include "../../../MCAL/DIO/Header/DIO_private.h"
#include "../../../MCAL/DIO/Header/DIO_interface.h"
#include "../../../MCAL/TIMER1/HDR/TIMER1_Interface.h"
#include "../../../MCAL/TIMER1/HDR/TIMER1_Register.h"
#include "../../../MCAL/TIMER1/HDR/TIMER1_Private.h"
#include "../../../MCAL/GIE/Header/GIE.h"

#include "../HDR/ULTRA_Config.h"
#include "../HDR/ULTRA_Interface.h"

#include <util/delay.h>

static volatile u8  edge_flag = 0;
static volatile u16 start_time = 0;
static volatile u16 end_time = 0;
static volatile u16 distance = 0;

void ICU_Handler(void)
{
    if (edge_flag == 0)
    {
        start_time = T1_ICR1;

        Clear_bit(T1_TCCR1B, ICES1);

        edge_flag = 1;
    }
    else if (edge_flag == 1)
    {
        end_time = T1_ICR1;

        edge_flag = 2;
    }
}

void ULTRASONIC_Init(void)
{
    DIO_SelectDirectionforPin(ULTRA_TRIGGER_PORT, ULTRA_TRIGGER_PIN, Output);

    Timer1_ICU_Config();

    Timr1_ICU_CallBack(ICU_Handler);

    GIE_Enable();

    Set_bit(T1_TCCR1B, ICES1);
}

void ULTRASONIC_Trigger(void)
{
    DIO_SelectOutputforPin(ULTRA_TRIGGER_PORT, ULTRA_TRIGGER_PIN, High);
    _delay_us(10);
    DIO_SelectOutputforPin(ULTRA_TRIGGER_PORT, ULTRA_TRIGGER_PIN, Low);
}

u16 ULTRASONIC_GetDistance(void)
{
    Set_bit(T1_TCCR1B, ICES1);
    edge_flag = 0;

    ULTRASONIC_Trigger();

        u32 timeout = 0;

        while (edge_flag < 2 && timeout < 30000)
        {
            timeout++;
        }

        if (timeout >= 30000)
        {
            return 999 ;
        }

    u16 time_taken = end_time - start_time;

    distance = time_taken / 58;

    return distance;
}
