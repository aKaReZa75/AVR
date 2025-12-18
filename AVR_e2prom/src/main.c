#include "aKaReZa.h"

int main(void)
{
  usart_Init(Initialize);
  usart_Putsln("aKaReZa");

  uint8_t _uint8 = 0x50;
  e2prom_uint8_Write(0x0000, _uint8);

  uint16_t _uint16 = 20000;
  e2prom_uint16_Write(0x0010, _uint16);

  uint32_t _uint32 = 400000;
  e2prom_uint32_Write(0x0020, _uint32);

  while(1)
  {
    
  };
};