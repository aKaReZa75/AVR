#include "aKaReZa.h"

uint8_t Delay = 0;
uint16_t Counter = 0;

int main(void)
{
  GPIO_Init();
  Seg7_init();
  while(1)
  {
    if(SW3_isPressed)
    {
      while(SW3_isPressed) 
      {
        Seg7_Puts(Counter);
        softDelay();       
      };
      Counter +=10;
    };

    if(SW2_isPressed)
    {
      while(SW2_isPressed) 
      {
        Seg7_Puts(Counter);
        softDelay();              
      };      
      Counter += 100;
    };

    if(SW1_isPressed)
    {
      while(SW1_isPressed)
      {
        Seg7_Puts(Counter);
        softDelay();          
      };
      Counter += 1000;
    };

    if(Counter>9999) Counter = 0;
    Seg7_Puts(Counter); // 4ms
    softDelay();
  };
};
