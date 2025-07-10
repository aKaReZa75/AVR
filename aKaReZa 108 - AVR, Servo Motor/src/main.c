#include "aKaReZa.h"

#define _servoDeg(x) OCR1A = 8.556*x + 575

uint8_t deg = 0;

int main(void)
{
  // Mode: phase, TOP:ICR1
  bitClear(TCCR1A, WGM10);
  bitSet(TCCR1A, WGM11);
  bitClear(TCCR1B, WGM12);
  bitSet(TCCR1B, WGM13);

  // Prescalre: 8
  bitClear(TCCR1B, CS10);
  bitSet(TCCR1B, CS11);
  bitClear(TCCR1B, CS12);

  // OCR0A -> Non-inv
  bitClear(TCCR1A, COM1A0);
  bitSet(TCCR1A, COM1A1);

  GPIO_Config_OUTPUT(DDRB, 1);

  ICR1  = 20000;
  OCR1A = 10000;
  while(1)
  {
    
    _servoDeg(0);
    delay_ms(1000);

    _servoDeg(90);
    delay_ms(1000);

    _servoDeg(180);
    delay_ms(1000); 

    _servoDeg(90);
    delay_ms(1000);

    _servoDeg(0);
    delay_ms(1000);

    for(deg = 0; deg < 180; deg++)
    {
      _servoDeg(deg); 
      delay_ms(25);
    };
      
    for(deg = 180; deg > 1; deg--)
    {
      _servoDeg(deg); 
      delay_ms(25);
    }; 
  };
};