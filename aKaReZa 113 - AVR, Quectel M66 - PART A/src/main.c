#include "aKaReZa.h"

int main(void)
{
  alcd_init();
  usart_Init(Initialize);
  globalInt_Enable;

  alcd_puts("aKaReZa");
  
  M66_Init();
  // M66_SendSMS("+989355282124", "Hey my name is RCS");

  while(1)
  {
    
  };
};