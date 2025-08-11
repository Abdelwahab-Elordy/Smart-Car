/*
 * BitMath.h
 *
 *  Created on: Jul 17, 2025
 *      Author: tohami
 */

#ifndef LIB_BITMATH_H_
#define LIB_BITMATH_H_


#define Set_bit(reg,bitno)    reg|=(1<<bitno)
#define Clear_bit(reg,bitno)  reg&=~(1<<bitno)
#define Toggle_bit(reg,bitno)  reg^=(1<<bitno)
#define Get_bit(reg,bitno)    (1&(reg>>bitno))



#endif /* LIB_BITMATH_H_ */
