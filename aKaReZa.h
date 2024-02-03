#ifndef _aKaReZa_H_
#define _aKaReZa_H_

#include <avr/io.h>
#include <util/delay.h>

#define bitSet(Reg, Bit) (Reg |= (1<<Bit))
#define bitClear(Reg, Bit) (Reg &= ~(1<<Bit))
#define bitToggle(Reg, Bit) (Reg ^= 1<<Bit)
#define bitCheck(Reg, Bit) ((Reg>>Bit) & 0x01)
#define bitChange(Reg, Bit, Value) (Value == 1 ? bitSet(Reg, Bit) : bitClear(Reg, Bit))
#define bitShiftLeft(Reg, Pos) (Reg = Reg << Pos)
#define bitShiftRight(Reg, Pos) (Reg = Reg >> Pos)
#define Conv_16to8_MSB(Value) (Value >> 8)
#define Conv_16to8_LSB(Value) (Value & 0xFF)
#define Combine_8to16(valueHigh, valueLow) (valueLow + (valueHigh<<8))

#define delay_ms(delay_msValue) _delay_ms(delay_msValue)
#define GPIO_Config_OUTPUT(Reg, Bit) bitSet(Reg, Bit)
#define GPIO_Config_INPUT(Reg, Bit) bitClear(Reg, Bit)

#endif
