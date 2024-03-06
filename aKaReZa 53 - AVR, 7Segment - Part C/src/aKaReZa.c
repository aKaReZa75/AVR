#include "aKaReZa.h"

extern uint8_t Delay;
extern uint16_t Counter;

void GPIO_Init(void)
{
  GPIO_Config_INPUT(SW1_Control, SW1_Pin);
  GPIO_Config_INPUT(SW2_Control, SW2_Pin);
  GPIO_Config_INPUT(SW3_Control, SW3_Pin);
};

void softDelay(void)
{
    Delay++;
    if(Delay>250) 
    {
        Delay = 0;
        Counter++;
    };     
};