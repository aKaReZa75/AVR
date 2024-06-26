#ifndef _aKaReZa_H_
#define _aKaReZa_H_

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <stdbool.h>
#include "Seg7.h"
#include "eInterrupt.h"
#include "Timer0.h"

#define bitSet(Reg, Bit)    (Reg |= (1<<Bit))
#define bitClear(Reg, Bit)  (Reg &= ~(1<<Bit))
#define bitToggle(Reg, Bit) (Reg ^= 1<<Bit)
#define bitCheck(Reg, Bit)  ((Reg>>Bit) & 0x01)
#define bitChange(Reg, Bit, Value) (Value == 1 ? bitSet(Reg, Bit) : bitClear(Reg, Bit))

#define delay_ms(delay_msValue) _delay_ms(delay_msValue)
#define GPIO_Config_OUTPUT(Reg, Bit) bitSet(Reg, Bit)
#define GPIO_Config_INPUT(Reg, Bit)  bitClear(Reg, Bit)
#define globalInt_Enable    bitSet  (SREG, SREG_I)
#define globalInt_Disable   bitClear(SREG, SREG_I)
#define intFlag_clear(Reg, Bit) bitSet(Reg, Bit)
#define Initialize   true
#define deInitialize false

#define SW1_Control DDRD
#define SW1_Status  PIND
#define SW1_Pin 2   // eINT0
#define SW1_isPressed bitCheck(SW1_Status, SW1_Pin)

#define SW2_Control DDRD
#define SW2_Status  PIND
#define SW2_Pin 3   // eINT1
#define SW2_isPressed bitCheck(SW2_Status, SW2_Pin)

#define SW3_Control DDRB
#define SW3_Status  PINB
#define SW3_Pin 5   //pcINT5
#define SW3_isPressed bitCheck(SW3_Status, SW3_Pin)

void GPIO_Init(void);

#endif