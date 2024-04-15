#include "Seg7.h"

const uint8_t Segments_CC[16] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};
uint8_t Segment[4] = {0, 0, 0, 0};
uint8_t fourLoopCounter = 0;

void Seg7_init(void)
{
  GPIO_Config_OUTPUT(_7Seg_A_Config, _7Seg_A_Pin); 
  GPIO_Config_OUTPUT(_7Seg_B_Config, _7Seg_B_Pin); 
  GPIO_Config_OUTPUT(_7Seg_C_Config, _7Seg_C_Pin); 
  GPIO_Config_OUTPUT(_7Seg_D_Config, _7Seg_D_Pin); 
  GPIO_Config_OUTPUT(_7Seg_E_Config, _7Seg_E_Pin); 
  GPIO_Config_OUTPUT(_7Seg_F_Config, _7Seg_F_Pin); 
  GPIO_Config_OUTPUT(_7Seg_G_Config, _7Seg_G_Pin); 
  GPIO_Config_OUTPUT(_7Seg_DP_Config, _7Seg_DP_Pin); 
  GPIO_Config_OUTPUT(_7Seg_Digit1_Config, _7Seg_Digit1_Pin);
  GPIO_Config_OUTPUT(_7Seg_Digit2_Config, _7Seg_Digit2_Pin);
  GPIO_Config_OUTPUT(_7Seg_Digit3_Config, _7Seg_Digit3_Pin);
  GPIO_Config_OUTPUT(_7Seg_Digit4_Config, _7Seg_Digit4_Pin);

  GPIO_Config_OUTPUT(_7Seg_Digit1_Control, _7Seg_Digit1_Pin); 
  GPIO_Config_OUTPUT(_7Seg_Digit2_Control, _7Seg_Digit2_Pin); 
  GPIO_Config_OUTPUT(_7Seg_Digit3_Control, _7Seg_Digit3_Pin); 
  GPIO_Config_OUTPUT(_7Seg_Digit4_Control, _7Seg_Digit4_Pin); 
};


void Seg7_Puts(uint16_t _7SegValue)
{
    uint8_t _Digit = 1;

    Segment[0] = (_7SegValue/1000);       // Hezargan (Digit1)
    Segment[1] = ((_7SegValue%1000)/100); // Sadgan (Digit2)
    Segment[2] = ((_7SegValue%100)/10);   // Dahgan (Digit3)
    Segment[3] = (_7SegValue%10);         // Yekan (Digit4)

    for(fourLoopCounter=0; fourLoopCounter<4; fourLoopCounter++)
    {
        bitChange(_7Seg_A_Control,  _7Seg_A_Pin,  bitCheck(Segments_CC[Segment[fourLoopCounter]], 0));
        bitChange(_7Seg_B_Control,  _7Seg_B_Pin,  bitCheck(Segments_CC[Segment[fourLoopCounter]], 1));
        bitChange(_7Seg_C_Control,  _7Seg_C_Pin,  bitCheck(Segments_CC[Segment[fourLoopCounter]], 2));
        bitChange(_7Seg_D_Control,  _7Seg_D_Pin,  bitCheck(Segments_CC[Segment[fourLoopCounter]], 3));
        bitChange(_7Seg_E_Control,  _7Seg_E_Pin,  bitCheck(Segments_CC[Segment[fourLoopCounter]], 4));
        bitChange(_7Seg_F_Control,  _7Seg_F_Pin,  bitCheck(Segments_CC[Segment[fourLoopCounter]], 5));
        bitChange(_7Seg_G_Control,  _7Seg_G_Pin,  bitCheck(Segments_CC[Segment[fourLoopCounter]], 6));
        
        _Digit = 1 << fourLoopCounter; // 0001 0010 0100 1000

        bitChange(_7Seg_Digit1_Control, _7Seg_Digit1_Pin, bitCheck(_Digit, 0));
        bitChange(_7Seg_Digit2_Control, _7Seg_Digit2_Pin, bitCheck(_Digit, 1));
        bitChange(_7Seg_Digit3_Control, _7Seg_Digit3_Pin, bitCheck(_Digit, 2));
        bitChange(_7Seg_Digit4_Control, _7Seg_Digit4_Pin, bitCheck(_Digit, 3));

        _7Seg_refreshDelay;
    };
};