/* @file     usart.c                                  */                      
/* @brief    AVR microcontollers usart sourceFile     */
/* @note     This file is for _AVR_ microcontrollers  */   
/* @author   Hossein Bagheri                          */
/* @github   aKaReZa75                                */
/* @youtube  aKaReZa75                                */
/* @linkedin aKaReZa75                                */
/* @email    aKaReZa75@gmail.com                      */

#include "usart.h"

bool usart_RxFlag = false;     // True: Rx Compelete
bool RxBufferOVR_Flag = false; // True: OverFllow
bool usart_errFlag = false;    // True: Error occur
char usart_RxBuffer[__usart_RxBufferSize];
uint8_t RXbufferIndex = 0;

void usart_Init(bool _initStatus)
{
    if(_initStatus)
    {
        // Baud Rate => 115200
        UBRR0H = 0;
        UBRR0L = 16;
        bitSet  (UCSR0A, U2X0);   // Double Speed, UBRR0L = 16
        // Mode => Asynchronous
        bitClear(UCSR0C, UMSEL01);
        bitClear(UCSR0C, UMSEL00);
        // Parity => Disable
        bitClear(UCSR0C, UPM01);
        bitClear(UCSR0C, UPM00);
        bitClear(UCSR0C, USBS0);   // StopBit = 1'bit
        // Data = 8Bit
        bitClear(UCSR0B, UCSZ02);
        bitSet  (UCSR0C, UCSZ01);
        bitSet  (UCSR0C, UCSZ00);
        bitSet  (UCSR0B, RXEN0);   // Enable Receive Mode
        bitSet  (UCSR0B, TXEN0);   // Enable Transmit Mode
        bitSet  (UCSR0B, RXCIE0);  // Enable Receive Intrrupts
        usart_Flush();
    }
    else
    {
        bitClear(UCSR0B, RXEN0);   
        bitClear(UCSR0B, TXEN0);   
        bitClear(UCSR0B, RXCIE0);            
        bitClear(UCSR0A, U2X0);
        bitClear(UCSR0C, UMSEL01);
        bitClear(UCSR0C, UMSEL00);
        bitClear(UCSR0C, UPM01);
        bitClear(UCSR0C, UPM00);
        bitClear(UCSR0C, USBS0); 
        bitClear(UCSR0B, UCSZ02);
        bitClear(UCSR0C, UCSZ01);
        bitClear(UCSR0C, UCSZ00);
        UBRR0H = 0;
        UBRR0L = 0;        
    };
};

ISR(USART_RX_vect)
{
    uint8_t _RXdata;
    
    usart_errFlag = false;
    usart_errFlag = __usart_frameError | __usart_dataOverRun | RxBufferOVR_Flag | usart_RxFlag ;
    
    _RXdata = UDR0;

    if(!usart_errFlag)
    {            
        if(_RXdata == '\n')
        {
            usart_RxBuffer[RXbufferIndex++] = '\0';
            usart_RxFlag = true;   
        } 
        else
        {
            if(_RXdata != '\r')
            {
                usart_RxBuffer[RXbufferIndex++] = _RXdata;
                if(RXbufferIndex == (__usart_RxBufferSize)) RxBufferOVR_Flag = true;
            };
        };
    };
};

void usart_Write(uint8_t  _Data)
{
    while(!bitCheck(UCSR0A, UDRE0));
    UDR0 = _Data;   
    while(!bitCheck(UCSR0A, TXC0));
};

void usart_Puts(char* _Data)
{
    while(*_Data != 0) usart_Write(*_Data++);
};

void usart_Putsln(char* _Data)
{
    usart_Puts (_Data);
    usart_Write('\r');
    usart_Write('\n');            
};

char usart_getChar(void)
{
    while(!bitCheck(UCSR0A, RXC0));
    return UDR0;
};

void usart_Flush(void)
{
    //__attribute__((unused)) uint8_t _dummy = 0;
    uint8_t _forIndex = 0;
    
    for(_forIndex = 0; _forIndex<__usart_RxBufferSize; _forIndex++)
    {
        usart_RxBuffer[_forIndex] = '\0';
    };

    RXbufferIndex    = 0;
    usart_RxFlag     = false;
    usart_errFlag    = false;
    RxBufferOVR_Flag = false;
};
