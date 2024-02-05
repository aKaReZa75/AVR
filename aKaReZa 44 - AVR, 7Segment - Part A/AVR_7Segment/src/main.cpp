#include <avr/io.h>
#include <util/delay.h>

#define bitSet(Reg, Bit) (Reg |= (1<<Bit))
#define bitClear(Reg, Bit) (Reg &= ~(1<<Bit))
#define bitToggle(Reg, Bit) (Reg ^= 1<<Bit)
#define bitCheck(Reg, Bit) ((Reg>>Bit) & 0x01)
#define bitChange(Reg, Bit, Value) (Value == 1 ? bitSet(Reg, Bit) : bitClear(Reg, Bit))
#define delay_ms(delay_msValue) _delay_ms(delay_msValue)

#define Seg7_A_Control PORTC
#define Seg7_A_Config  DDRC
#define Seg7_A_Pin     0

#define Seg7_B_Control PORTC
#define Seg7_B_Config  DDRC
#define Seg7_B_Pin     1

#define Seg7_C_Control PORTC
#define Seg7_C_Config  DDRC
#define Seg7_C_Pin     2

#define Seg7_D_Control PORTC
#define Seg7_D_Config  DDRC
#define Seg7_D_Pin     3

#define Seg7_E_Control PORTD
#define Seg7_E_Config  DDRD
#define Seg7_E_Pin     0

#define Seg7_F_Control PORTD
#define Seg7_F_Config  DDRD
#define Seg7_F_Pin     1

#define Seg7_G_Control PORTD
#define Seg7_G_Config  DDRD
#define Seg7_G_Pin     4

#define Seg7_DP_Control PORTD
#define Seg7_DP_Config  DDRD
#define Seg7_DP_Pin     7

#define Seg7_Digit1_Control PORTB
#define Seg7_Digit1_Config DDRB
#define Seg7_Digit1_Pin 0

#define Seg7_Digit2_Control PORTB
#define Seg7_Digit2_Config DDRB
#define Seg7_Digit2_Pin 1

#define Seg7_Digit3_Control PORTB
#define Seg7_Digit3_Config DDRB
#define Seg7_Digit3_Pin 2

#define Seg7_Digit4_Control PORTB
#define Seg7_Digit4_Config DDRB
#define Seg7_Digit4_Pin 4

uint8_t Segments_CC[16] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};
uint8_t Counter[4] = {1, 2, 3, 4};
uint8_t i = 0;

int main(void)
{
  bitSet(Seg7_A_Config, Seg7_A_Pin); 
  bitSet(Seg7_B_Config, Seg7_B_Pin); 
  bitSet(Seg7_C_Config, Seg7_C_Pin); 
  bitSet(Seg7_D_Config, Seg7_D_Pin); 
  bitSet(Seg7_E_Config, Seg7_E_Pin); 
  bitSet(Seg7_F_Config, Seg7_F_Pin); 
  bitSet(Seg7_G_Config, Seg7_G_Pin); 
  bitSet(Seg7_DP_Config, Seg7_DP_Pin); 
  bitSet(Seg7_Digit1_Config, Seg7_Digit1_Pin);
  bitSet(Seg7_Digit2_Config, Seg7_Digit2_Pin);
  bitSet(Seg7_Digit3_Config, Seg7_Digit3_Pin);
  bitSet(Seg7_Digit4_Config, Seg7_Digit4_Pin);

  bitSet(Seg7_Digit1_Control, Seg7_Digit1_Pin); 
  bitSet(Seg7_Digit2_Control, Seg7_Digit2_Pin); 
  bitSet(Seg7_Digit3_Control, Seg7_Digit3_Pin); 
  bitSet(Seg7_Digit4_Control, Seg7_Digit4_Pin); 

  while(1)
  {
    for(i = 0; i <= 3; i++)
    {
      bitChange(Seg7_A_Control,  Seg7_A_Pin,  bitCheck(Segments_CC[Counter[i]], 0));
      bitChange(Seg7_B_Control,  Seg7_B_Pin,  bitCheck(Segments_CC[Counter[i]], 1));
      bitChange(Seg7_C_Control,  Seg7_C_Pin,  bitCheck(Segments_CC[Counter[i]], 2));
      bitChange(Seg7_D_Control,  Seg7_D_Pin,  bitCheck(Segments_CC[Counter[i]], 3));
      bitChange(Seg7_E_Control,  Seg7_E_Pin,  bitCheck(Segments_CC[Counter[i]], 4));
      bitChange(Seg7_F_Control,  Seg7_F_Pin,  bitCheck(Segments_CC[Counter[i]], 5));
      bitChange(Seg7_G_Control,  Seg7_G_Pin,  bitCheck(Segments_CC[Counter[i]], 6));
      switch (i)
      {
        case 0:
          bitSet(  Seg7_Digit1_Control, Seg7_Digit1_Pin); 
          bitClear(Seg7_Digit2_Control, Seg7_Digit2_Pin); 
          bitClear(Seg7_Digit3_Control, Seg7_Digit3_Pin); 
          bitClear(Seg7_Digit4_Control, Seg7_Digit4_Pin); 
        break;

        case 1:
          bitClear(Seg7_Digit1_Control, Seg7_Digit1_Pin); 
          bitSet(  Seg7_Digit2_Control, Seg7_Digit2_Pin); 
          bitClear(Seg7_Digit3_Control, Seg7_Digit3_Pin); 
          bitClear(Seg7_Digit4_Control, Seg7_Digit4_Pin); 
        break;

        case 2:
          bitClear(Seg7_Digit1_Control, Seg7_Digit1_Pin); 
          bitClear(Seg7_Digit2_Control, Seg7_Digit2_Pin); 
          bitSet(  Seg7_Digit3_Control, Seg7_Digit3_Pin); 
          bitClear(Seg7_Digit4_Control, Seg7_Digit4_Pin); 
        break;

        case 3:
          bitClear(Seg7_Digit1_Control, Seg7_Digit1_Pin); 
          bitClear(Seg7_Digit2_Control, Seg7_Digit2_Pin); 
          bitClear(Seg7_Digit3_Control, Seg7_Digit3_Pin); 
          bitSet(  Seg7_Digit4_Control, Seg7_Digit4_Pin); 
        break;                        
      };
      delay_ms(1);
    };
  };
};