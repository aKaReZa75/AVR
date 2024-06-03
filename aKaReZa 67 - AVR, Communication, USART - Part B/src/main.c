#include "aKaReZa.h"

volatile extern bool usart_RxFlag;
extern bool usart_errFlag;
extern char usart_RxBuffer[__usart_RxBufferSize];

char lcd[17]; // 16 data + 1 null
uint8_t Counter = 0;
uint8_t RXdata;

int main(void)
{
  usart_Init(Initialize);
  alcd_init();
  globalInt_Enable;
  usart_Putsln("aKaReZa");
  
  while(1)
  {
    sprintf(lcd, "Counter = %3d", Counter++);
    alcd_gotoxy(0, 0);
    alcd_puts(lcd);
    usart_Putsln(lcd);
    delay_ms(10);

    if(usart_RxFlag)
    {
      usart_Putsln("if(usart_RxFlag)");
      alcd_clear();
      alcd_puts(usart_RxBuffer);
      usart_Flush();
    };

    if(usart_errFlag)
    {
      usart_Putsln("if(usart_errFlag)");
      alcd_clear();
      alcd_puts("usart_errFlag");
      usart_Flush();
    }
  };
};
  