#include "usart.h"

bool usart_RxFlag      = false; // True: Rx Compelete     
bool usart_RxBUfferOVF = false; // True: OverFllow
bool usart_errFlag     = false; // True: Error occur
uint8_t bufferIndex    = 0;
char usart_RxBuffer[__usart_RxBufferSize];

void usart_Init(bool _initStatus)
{
    if(_initStatus)
    {
        // bitSet  (__usart_TX_Config , __usart_TX_Pin);  // Tx -> OUTPUT
        // bitSet  (__usart_TX_Control, __usart_TX_Pin);  // Tx -> high Level
        // bitClear(__usart_RX_Config , __usart_RX_Pin);  // Rx <- INPUT
        // bitSet  (__usart_RX_Control, __usart_RX_Pin);  // Rx -> Pulled-UP        
        // Mode => Asynchronous
        bitClear(UCSR0C, UMSEL01);
        bitClear(UCSR0C, UMSEL00);
        // Parity => Disable
        bitClear(UCSR0C, UPM01);
        bitClear(UCSR0C, UPM00);
        bitClear(UCSR0C, USBS0);  // StopBit = 1'bit
        // Data = 8Bit
        bitClear(UCSR0B, UCSZ02);
        bitSet  (UCSR0C, UCSZ01);
        bitSet  (UCSR0C, UCSZ00);
        bitSet  (UCSR0B, TXEN0);  // Enable Transmit Mode
        bitSet  (UCSR0B, RXEN0);  // Enable Receive Mode
        bitSet  (UCSR0B, RXCIE0); // Enable Receive Intrrupts
        bitSet  (UCSR0A, U2X0);   // Double Speed
        // Baud Rate => 115200
        UBRR0H = 0;
        UBRR0L = 16; 
        usart_Flush();
    }
    else
    {
        bitClear(__usart_TX_Config , __usart_TX_Pin); 
        bitClear(__usart_TX_Control, __usart_TX_Pin);  
        bitClear(__usart_RX_Config , __usart_RX_Pin); 
        bitClear(__usart_RX_Control, __usart_RX_Pin);         
        bitClear(UCSR0C, UMSEL01);
        bitClear(UCSR0C, UMSEL00);
        bitClear(UCSR0C, UPM01);
        bitClear(UCSR0C, UPM00);
        bitClear(UCSR0C, USBS0);  
        bitClear(UCSR0B, UCSZ02);
        bitClear(UCSR0C, UCSZ01);
        bitClear(UCSR0C, UCSZ00);
        bitClear(UCSR0B, TXEN0);  
        bitClear(UCSR0B, RXEN0); 
        bitClear(UCSR0B, RXCIE0); 
        bitClear(UCSR0A, U2X0);  
        UBRR0H = 0;
        UBRR0L = 0; 
    };
};

ISR(USART_RX_vect)
{
    uint8_t _RxData;
    usart_errFlag = false;

    usart_errFlag = usart_RxBUfferOVF | __usart_frameError | usart_daraOverRun;

    _RxData = UDR0;

    if(!usart_errFlag)
    {
        if(_RxData == '\n')
        {
            usart_RxBuffer[bufferIndex++] = '\0';
            usart_RxFlag = true;
        }
        else
        {
            if(_RxData != '\r')
            {
                usart_RxBuffer[bufferIndex++] = _RxData;
                if(bufferIndex > __usart_RxBufferSize) usart_RxBUfferOVF = true;
            };
        };
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
    usart_Write('\r');  // Carraige Return (CR)
    usart_Write('\n');  // NewLine (NL)
};

uint8_t usart_getChar(void)
{
    while(!bitCheck(UCSR0A, RXC0));    
    return UDR0;
};

void usart_Flush(void)
{
    uint8_t _Index = 0;
    
    for(_Index = 0; _Index < __usart_RxBufferSize; _Index++)
    {
        usart_RxBuffer[_Index] = '\0';
    };

    bufferIndex = 0;
    usart_RxBUfferOVF = false;
    usart_RxFlag      = false;
    usart_errFlag     = false;
};
