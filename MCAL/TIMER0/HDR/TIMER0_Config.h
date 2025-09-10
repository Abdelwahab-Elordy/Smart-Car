/*
 * TIMER0_Config.h
 *
 *  Created on: Jul 27, 2025
 *      Author: tohami
 */

#ifndef MCAL_TIMER0_HDR_TIMER0_CONFIG_H_
#define MCAL_TIMER0_HDR_TIMER0_CONFIG_H_

#define T0_PrescalerSelect T0_Prescaler_64


#define PreloadValue 0

#define No_Of_Count 31

#define CompareValue 250
#define No_CTC_Counts 4000

#define OC0_Disconnect 1
#define OC0_Toggle     2
#define OC0_Set        3
#define OC0_Clear      4

#define OC0_TypeSelect  OC0_Disconnect
/*Fast Pwm*/

#define InvertingMode      1
#define NonInvertingMode   2

#define PWMFast_Mode   NonInvertingMode

#define PWMFast_Dutycycledefault   60
/*pwm phase correct */

#define OC0ph_Clear 1
#define OC0ph_Set   2

#define PWMPhcorrect_Mode  OC0ph_Clear

#define PWMPhcorrect_Dutycycledefault 200

#endif /* MCAL_TIMER0_HDR_TIMER0_CONFIG_H_ */
