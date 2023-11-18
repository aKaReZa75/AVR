#include <avr/io.h>
#include <util/delay.h>

#define setBit(Reg, Bit) (Reg |= (1<<Bit))
#define clearBit(Reg, Bit) (Reg &= ~(1<<Bit))
#define toggleBit(Reg, Bit) (Reg ^= (1<<Bit))

int main(void)
{
  setBit(DDRB, 0); // Init PB0 as an Output
  while(1)
  {
    setBit(PORTB, 0); // Turn the Led On
    _delay_ms(1000); // 1Sec Delay
    clearBit(PORTB, 0); // Turn the Led Off
    _delay_ms(1000); // 1Sec Delay
  };
};
