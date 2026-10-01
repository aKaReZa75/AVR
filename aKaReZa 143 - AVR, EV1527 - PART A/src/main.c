#include "aKaReZa.h"

char debugBuffer[100];

extern volatile bool ev1527_Detec;
extern volatile uint32_t ev1527_Data;

int main(void)
{
  usart_Init(Initialize);
  usart_Putsln("aKaReZa");

  ev1527_Init();
  globalInt_Enable;

  while(1)
  {
    if(ev1527_Detec)
    { 
      sprintf(debugBuffer, "ev1527 => Data: 0x%lX", ev1527_Data);
      usart_Putsln(debugBuffer);
      ev1527_Detec = false;
    };
  };
};