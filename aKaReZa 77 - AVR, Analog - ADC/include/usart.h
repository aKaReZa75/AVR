/* @file     usart.h                                  */                      
/* @brief    AVR microcontollers usart Library        */
/* @note     This file is for _AVR_ microcontrollers  */   
/* @author   Hossein Bagheri                          */
/* @github   aKaReZa75                                */
/* @youtube  aKaReZa75                                */
/* @linkedin aKaReZa75                                */
/* @email    aKaReZa75@gmail.com                      */

#ifndef _usart_H_
#define _usart_H_

#include "aKaReZa.h"

#define __usart_RxBufferSize 33 //32 byte Data + 1 null

#define __usart_frameError  bitCheck(UCSR0A, FE0) 
#define __usart_dataOverRun bitCheck(UCSR0A, DOR0)

void usart_Init(bool _initStatus);
void usart_Write(uint8_t  _Data);
void usart_Puts(char* _Data);
void usart_Putsln(char* _Data);
char usart_getChar(void);
void usart_Flush(void);

#endif
