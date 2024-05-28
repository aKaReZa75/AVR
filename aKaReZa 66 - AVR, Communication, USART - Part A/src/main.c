#include "aKaReZa.h"

char lcd[17]; // 16 data + 1 null
uint8_t Counter = 0;

int main(void)
{
  usart_Init(Initialize);
  alcd_init();

  alcd_puts("aKaReZa");
  usart_Putsln("aKaReZa");
  delay_ms(2000);

  while(1)
  {
    sprintf(lcd, "Counter = %d", Counter++);
    alcd_gotoxy(0, 0);
    alcd_puts(lcd);
    usart_Putsln(lcd);
    delay_ms(1000);
  };
};