/*
 * @file  Macros.c
 *
 * @brief  Assigning value to a register
 *
 * @note  
 *
 */

#define setBit(Reg, Bit) (Reg |= (1<<Bit))
#define clearBit(Reg, Bit) (Reg &= ~(1<<Bit))
#define toggleBit(Reg, Bit) (Reg ^= 1<<Bit)
#define checkBit(Reg, Bit) ((Reg>>Bit) & 0x01)
#define changeBit(Reg, Bit, Value) (Value == 1 ? setBit(Reg, Bit) : clearBit(Reg, Bit))
