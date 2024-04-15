/* @file     eInterrupt.h                             */                      
/* @brief    AVR External Interrupt Library           */
/* @note     This file is for _AVR_ microcontrollers  */   
/* @author   Hossein Bagheri                          */
/* @github   aKaReZa75                                */
/* @youtube  aKaReZa75                                */
/* @linkedin aKaReZa75                                */
/* @email    aKaReZa75@gmail.com                      */

#ifndef _eInterrupt_H_
#define _eInterrupt_H_

#include "aKaReZa.h"

void eINT0_Init (bool _initStatus);
void eINT1_Init (bool _initStatus);
void pcINT0_Init(bool _initStatus);

#endif