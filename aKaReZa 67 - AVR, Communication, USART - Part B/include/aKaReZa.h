/* @file     aKaReZa.h                                */                      
/* @brief    AVR microcontollers headfile             */
/* @note     This file is for _AVR_ microcontrollers  */   
/* @author   Hossein Bagheri                          */
/* @github   aKaReZa75                                */
/* @youtube  aKaReZa75                                */
/* @linkedin aKaReZa75                                */
/* @email    aKaReZa75@gmail.com                      */

#ifndef _aKaReZa_H_
#define _aKaReZa_H_

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include "usart.h"
#include "alcd.h"

#define bitSet(_Reg, _Bit)    (_Reg |= (1<<_Bit))
#define bitClear(_Reg, _Bit)  (_Reg &= ~(1<<_Bit))
#define bitToggle(_Reg, _Bit) (_Reg ^= 1<<_Bit)
#define bitCheck(_Reg, _Bit)  ((_Reg>>_Bit) & 0x01)
#define bitChange(_Reg, _Bit, Value) (Value == 1 ? bitSet(_Reg, _Bit) : bitClear(_Reg, _Bit))
#define bitShiftLeft(_Reg, _Pos)  (_Reg = _Reg << _Pos)
#define bitShiftRight(_Reg, _Pos) (_Reg = _Reg >> _Pos)
#define Conv_16to8_MSB(_Value) (_Value >> 8)
#define Conv_16to8_LSB(_Value) (_Value & 0xFF)
#define Combine_8to16(_valueHigh, _valueLow) (_valueLow + (_valueHigh<<8))

#define GPIO_Config_OUTPUT(_Reg, _Bit) bitSet(_Reg, _Bit)
#define GPIO_Config_INPUT(_Reg, _Bit) bitClear(_Reg, _Bit)
#define delay_ms(_delay_msValue) _delay_ms(_delay_msValue)
#define globalInt_Enable    bitSet  (SREG, SREG_I)
#define globalInt_Disable   bitClear(SREG, SREG_I)
#define intFlag_clear(Reg, Bit) bitSet(Reg, Bit)
#define Initialize   true
#define deInitialize false

#define Math_Const_PI  3.14159265358979
#define MATH_Const_EXP 2.71828182845904

#endif
