/*
 * @file  Macros.c
 *
 * @brief  Assigning value to a register
 *
 * @note  
 *
 */

#define bitSet(_Reg, _Bit) (_Reg |= (1<<_Bit))
#define bitClear(_Reg, _Bit) (_Reg &= ~(1<<_Bit))
#define bitToggle(_Reg, _Bit) (_Reg ^= 1<<_Bit)
#define bitCheck(_Reg, _Bit) ((_Reg>>_Bit) & 0x01)
#define bitChange(_Reg, _Bit, Value) (Value == 1 ? bitSet(_Reg, _Bit) : bitClear(_Reg, _Bit))

#define GPIO_Config_OUTPUT(_Reg, _Bit) bitSet(_Reg, _Bit)
#define GPIO_Config_INPUT(_Reg, _Bit) bitClear(_Reg, _Bit)
#define delay_ms(_delay_msValue) _delay_ms(_delay_msValue)
