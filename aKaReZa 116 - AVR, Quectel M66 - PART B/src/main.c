#include "aKaReZa.h"

#define Key_Learn_Config DDRD
#define Key_Learn_Status PIND 
#define Key_Learn_Pin    3

int main(void)
{
  alcd_init();
  usart_Init(Initialize);
  globalInt_Enable;

  alcd_puts("aKaReZa");
  
  M66_Init();

  GPIO_Config_INPUT(Key_Learn_Config, Key_Learn_Pin);

  while(1)
  {
    if(bitCheckLow(Key_Learn_Status, Key_Learn_Pin))
    {
      bitWaitHigh(Key_Learn_Status, Key_Learn_Pin);
      M66_SendSMS("+989355282124", "Hey my name is RCS");
    };
  };
};