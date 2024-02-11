/*
 * @file   7Segments_Oled.h
 *
 * @brief  7Segments, OLED, and switches defines
 *
 * @note  
 *
 */

#define __RGB_R_Config  DDRB
#define __RGB_R_Control PORTB
#define __RGB_R_Pin 3

#define __RGB_G_Config  DDRD
#define __RGB_G_Control PORTD
#define __RGB_G_Pin 5

#define __RGB_B_Config  DDRD
#define __RGB_B_Control PORTD
#define __RGB_B_Pin 6

#define __SW1_Config      DDRD      
#define __SW1_Status      PIND
#define __SW1_Pin         2
#define __SW1_isPressed   bitCheck(__SW1_Status, __SW1_Pin)

#define __SW2_Config      DDRD      
#define __SW2_Status      PIND
#define __SW2_Pin         3
#define __SW2_isPressed   bitCheck(__SW2_Status, __SW2_Pin)

#define __SW3_Config      DDRB      
#define __SW3_Status      PINB
#define __SW3_Pin         5
#define __SW3_isPressed   bitCheck(__SW3_Status, __SW3_Pin)

#define ___7seg_A_Control PORTC
#define ___7seg_A_Config  DDRC
#define ___7seg_A_Pin     0

#define ___7seg_B_Control PORTC
#define ___7seg_B_Config  DDRC
#define ___7seg_B_Pin     1

#define __7seg_C_Control PORTC
#define __7seg_C_Config  DDRC
#define __7seg_C_Pin     2

#define __7seg_D_Control PORTC
#define __7seg_D_Config  DDRC
#define __7seg_D_Pin     3

#define __7seg_E_Control PORTD
#define __7seg_E_Config  DDRD
#define __7seg_E_Pin     0

#define __7seg_F_Control PORTD
#define __7seg_F_Config  DDRD
#define __7seg_F_Pin     1

#define __7seg_G_Control PORTD
#define __7seg_G_Config  DDRD
#define __7seg_G_Pin     4

#define __7seg_DP_Control PORTD
#define __7seg_DP_Config  DDRD
#define __7seg_DP_Pin     7

#define __7seg_Digit1_Control PORTB
#define __7seg_Digit1_Config DDRB
#define __7seg_Digit1_Pin 0

#define __7seg_Digit2_Control PORTB
#define __7seg_Digit2_Config DDRB
#define __7seg_Digit2_Pin 1

#define __7seg_Digit3_Control PORTB
#define __7seg_Digit3_Config DDRB
#define __7seg_Digit3_Pin 2

#define __7seg_Digit4_Control PORTB
#define __7seg_Digit4_Config DDRB
#define __7seg_Digit4_Pin 4

const uint8_t Segments[16] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};
