#include "aKaReZa.h"

uint16_t Counter = 0;

int main(void)
{
  GPIO_Init();
  Seg7_init();
  eINT0_Init (Initialize);
  eINT1_Init (Initialize);
  pcINT0_Init(Initialize);
  Timer0_Init(Initialize);
  globalInt_Enable;
  while(1)
  {
      
  };
};
