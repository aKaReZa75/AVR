#include "aKaReZa.h"

uint8_t customChar0[] = {0x00, 0x00, 0x0A, 0x00, 0x11, 0x0E, 0x00, 0x00};  // smiley

char alcdBuffer[16];
uint32_t Counter = 0;

int main(void)
{
  alcd_init();
  alcd_display(true , false, true);
  //alcd_customChar(0, customChar0);
  //alcd_write('x', __alcd_writeData);
  // alcd_putc('a');
  // alcd_putc('K');
  // alcd_putc('a');
  // alcd_putc('R');
  // alcd_putc('e');      
  // alcd_putc('Z');  
  // alcd_putc('a');  
  //alcd_puts("aKaReZa");

  //alcd_puts("aKaReZa75@gmail.com");
  
  // alcd_gotoxy(20, 1);
  // alcd_putc('X');
  // delay_ms(1000);
  // alcd_clear();
  // alcd_putc('Z');

  //alcd_display(true , false, true);
  //alcd_putc(0);
  while(1)
  {
    // alcd_backLight(true);
    // delay_ms(1000);
    // alcd_backLight(false);
    // delay_ms(1000);
    sprintf(alcdBuffer, "Counter = %lu", Counter++);
    alcd_gotoxy(0, 0);
    alcd_puts(alcdBuffer);
  };
};