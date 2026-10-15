#include "aKaReZa.h"

char debugBuffer[100];

extern volatile bool ev1527_Detec;
extern volatile ev1527_T ev1527_Data;

int main(void)
{
  usart_Init(Initialize);
  usart_Putsln("aKaReZa");

  ev1527_Init();
  globalInt_Enable;

  while(1)
  {
    if(ev1527_Data.Bits.Detect)
    { 
      sprintf(debugBuffer, "ev1527 => Address: 0x%lX, Keys:%x", (uint32_t) ev1527_Data.Bits.Address, ev1527_Data.Bits.Keys);
      usart_Putsln(debugBuffer);
      ev1527_Data.Bits.Detect = false;
      ev1527_Init();
    };
  };
};