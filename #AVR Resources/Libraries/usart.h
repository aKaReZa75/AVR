#ifndef _usart_H_
#define _usart_H_

#include "aKaReZa.h"

#define __usart_RxBufferSize 33 //32 byte Data + 1 null

#define usart_frameError  bitCheck(UCSR0A, FE0) 
#define usart_dataOverRun bitCheck(UCSR0A, DOR0)

void usart_Init(bool _initStatus);
void usart_Write(uint8_t  _Data);
void usart_Puts(char* _Data);
void usart_Putsln(char* _Data);
char usart_getChar(void);
void usart_Flush(void);

#endif
