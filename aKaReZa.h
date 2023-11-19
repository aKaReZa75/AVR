#ifndef _aKaReZa_H
#define _aKaReZa_H

#include <avr/io.h>
#include <util/delay.h>

#define delay_ms(delay_msValue) _delay_ms(delay_msValue)

#define setBit(Reg, Bit) (Reg |= (1<<Bit))
#define clearBit(Reg, Bit) (Reg &= ~(1<<Bit))
#define toggleBit(Reg, Bit) (Reg ^= (1<<Bit))
#define checkBit(Reg, Bit) ((Reg>>Bit) & 0x01)
#define Conv_16to8_MSB(Value) (Value >> 8)
#define Conv_16to8_LSB(Value) (Value & 0xFF)
#define Combine_8to16(valueHigh, valueLow) (valueLow + (valueHigh<<8))

int main(void)
{
  while(1)
  {

  };
};

#endif
