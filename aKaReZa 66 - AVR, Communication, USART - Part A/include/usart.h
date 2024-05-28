#ifndef _usart_H_
#define _usart_H_

#include "aKaReZa.h"

#define __usart_TX_Config  DDRD
#define __usart_TX_Control PORTD
#define __usart_TX_Pin     1

void usart_Init(bool _initStatus);
void usart_Write(uint8_t  _Data);
void usart_Puts(char* _Data);
void usart_Putsln(char* _Data);


#endif