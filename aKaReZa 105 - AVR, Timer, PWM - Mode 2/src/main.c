#include "aKaReZa.h"

#define _duty(x) ((x*250)/100)

int main(void)
{
  // Mode: phase, TOP:255
  bitSet(TCCR0A, WGM00);
  bitSet(TCCR0A, WGM01);
  bitClear(TCCR0B, WGM02);
  // Prescalre: 64
  bitSet(TCCR0B, CS00);
  bitSet(TCCR0B, CS01);
  bitClear(TCCR0B, CS02);
  // OCR0A -> non inv
  bitClear(TCCR0A, COM0A0);
  bitSet(TCCR0A, COM0A1);

  // OCR0B -> inv
  bitSet(TCCR0A, COM0B0);
  bitSet(TCCR0A, COM0B1);

  GPIO_Config_OUTPUT(DDRD, 6);
  GPIO_Config_OUTPUT(DDRD, 5);

  OCR0A = _duty(50);
  OCR0B = _duty(51);
  while(1)
  {
    
  };
};