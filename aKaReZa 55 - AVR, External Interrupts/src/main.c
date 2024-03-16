#include "aKaReZa.h"

uint8_t Delay = 0;
uint16_t Counter = 0;

int main(void)
{
  GPIO_Init();
  Seg7_init();
  eINT0_Init (Initialize);
  eINT1_Init (Initialize);
  pcINT0_Init(Initialize);

  globalInt_Enable;
  while(1)
  {
    Delay++;
    if(Delay>250) 
    {
      Delay = 0;
      Counter++;
    };  
    if(Counter>9999) Counter = 0;
    Seg7_Puts(Counter); // 4ms
  };
};
