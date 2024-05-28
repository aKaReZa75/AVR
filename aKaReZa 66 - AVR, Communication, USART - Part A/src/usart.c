#include "usart.h"

void usart_Init(bool _initStatus)
{
    if(_initStatus)
    {
        bitSet(__usart_TX_Config,  __usart_TX_Pin);  // Tx -> OUTPUT
        bitSet(__usart_TX_Control, __usart_TX_Pin); // Tx -> high Level
        // Mode => Asynchronous
        bitClear(UCSR0C, UMSEL01);
        bitClear(UCSR0C, UMSEL00);
        // Parity => Disable
        bitClear(UCSR0C, UPM01);
        bitClear(UCSR0C, UPM00);
        bitClear(UCSR0C, USBS0); // StopBit = 1'bit
        // Data = 8Bit
        bitClear(UCSR0B, UCSZ02);
        bitSet  (UCSR0C, UCSZ01);
        bitSet  (UCSR0C, UCSZ00);
        bitSet  (UCSR0B, TXEN0); // Enable Transmit Mode
        // Baud Rate => 115200
        UBRR0H = 0;
        UBRR0L = 8; 
    }
    else
    {

    };
};

void usart_Write(uint8_t _Data)
{
    while(!bitCheck(UCSR0A, UDRE0));
    UDR0 = _Data;
    while(!bitCheck(UCSR0A, TXC0));
};

void usart_Puts(char* _Data)
{
    while(*_Data != '\0')  usart_Write(*_Data++);
};

void usart_Putsln(char* _Data)
{
    usart_Puts(_Data);
    usart_Write('\r');
    usart_Write('\n');
};