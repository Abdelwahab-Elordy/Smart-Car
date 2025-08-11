/*
 * GIE.c
 *
 *  Created on: Jul 23, 2025
 *      Author: tohami
 */
#include "../../../Lib/Definition.h"
#include "../../../Lib/BitMath.h"
#include "../Header/GIE.h"


void GIE_Enable()
{
	Set_bit(GIE_SREG,GIE_Ibit);
}

void GIE_Disable()
{
	Clear_bit(GIE_SREG,GIE_Ibit);
}

