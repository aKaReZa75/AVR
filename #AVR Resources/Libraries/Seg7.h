/* @file     Seg7.h                                   */                      
/* @brief    AVR microcontollers 7Segment Library     */
/* @note     This file is for _AVR_ microcontrollers  */   
/* @author   Hossein Bagheri                          */
/* @github   aKaReZa75                                */
/* @youtube  aKaReZa75                                */
/* @linkedin aKaReZa75                                */
/* @email    aKaReZa75@gmail.com                      */

#ifndef _Seg7_H_
#define _Seg7_H_

#include "aKaReZa.h"

#define _7Seg_A_Control PORTC
#define _7Seg_A_Config  DDRC
#define _7Seg_A_Pin     0

#define _7Seg_B_Control PORTC
#define _7Seg_B_Config  DDRC
#define _7Seg_B_Pin     1

#define _7Seg_C_Control PORTC
#define _7Seg_C_Config  DDRC
#define _7Seg_C_Pin     2

#define _7Seg_D_Control PORTC
#define _7Seg_D_Config  DDRC
#define _7Seg_D_Pin     3

#define _7Seg_E_Control PORTD
#define _7Seg_E_Config  DDRD
#define _7Seg_E_Pin     0

#define _7Seg_F_Control PORTD
#define _7Seg_F_Config  DDRD
#define _7Seg_F_Pin     1

#define _7Seg_G_Control PORTD
#define _7Seg_G_Config  DDRD
#define _7Seg_G_Pin     4

#define _7Seg_DP_Control PORTD
#define _7Seg_DP_Config  DDRD
#define _7Seg_DP_Pin     7

#define _7Seg_Digit1_Control PORTB
#define _7Seg_Digit1_Config DDRB
#define _7Seg_Digit1_Pin 0

#define _7Seg_Digit2_Control PORTB
#define _7Seg_Digit2_Config DDRB
#define _7Seg_Digit2_Pin 1

#define _7Seg_Digit3_Control PORTB
#define _7Seg_Digit3_Config DDRB
#define _7Seg_Digit3_Pin 2

#define _7Seg_Digit4_Control PORTB
#define _7Seg_Digit4_Config DDRB
#define _7Seg_Digit4_Pin 4

#define _7Seg_refreshDelay delay_ms(1)

void Seg7_init(void);
void Seg7_Puts(uint16_t _7SegValue);

#endif
