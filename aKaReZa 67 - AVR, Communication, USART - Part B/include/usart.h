#ifndef _usart_H_
#define _usart_H_

#include "aKaReZa.h"

#define __usart_RxBufferSize 33 // 32 byte Data + 1 null

#define usart_frameError  bitCheck(UCSR0A, FE0 ) 
#define usart_daraOverRun bitCheck(UCSR0A, DOR0) 

#define __usart_TX_Config  DDRD
#define __usart_TX_Control PORTD
#define __usart_TX_Pin     1

#define __usart_RX_Config  DDRD
#define __usart_RX_Control PORTD
#define __usart_RX_Pin     0

void usart_Init(bool _initStatus);
void usart_Write(uint8_t  _Data);
void usart_Puts(char* _Data);
void usart_Putsln(char* _Data);
uint8_t usart_getChar(void);
void usart_Flush(void);

#endif