/*
 * @file   7Segments_Oled.h
 *
 * @brief  7Segments, OLED, and switches defines
 *
 * @note  
 *
 */

#define RGB_R_Config  DDRB
#define RGB_R_Control PORTB
#define RGB_R_Pin 3

#define RGB_G_Config  DDRD
#define RGB_G_Control PORTD
#define RGB_G_Pin 5

#define RGB_B_Config  DDRD
#define RGB_B_Control PORTD
#define RGB_B_Pin 6

#define SW1_Config      DDRD      
#define SW1_Status      PIND
#define SW1_Pin         2
#define SW1_isPressed   bitCheck(SW1_Status, SW1_Pin)

#define SW2_Config      DDRD      
#define SW2_Status      PIND
#define SW2_Pin         3
#define SW2_isPressed   bitCheck(SW2_Status, SW2_Pin)

#define SW3_Config      DDRB      
#define SW3_Status      PINB
#define SW3_Pin         5
#define SW3_isPressed   bitCheck(SW3_Status, SW3_Pin)

#define _7Seg_A_Control PORTC
#define _7Seg_A_Config  DDRC
#define _7Seg_A_Pin     0

#define _7Seg_B_Control PORTC
#define _7Seg_B_Config  DDRC
#define _7Seg_B_Pin     1

#define _7Seg_C_Control PORTC
#define _7Seg_C_Config  DDRC
#define _7Seg_C_Pin     2

#define _7Seg_D_Control PORTC
#define _7Seg_D_Config  DDRC
#define _7Seg_D_Pin     3

#define _7Seg_E_Control PORTD
#define _7Seg_E_Config  DDRD
#define _7Seg_E_Pin     0

#define _7Seg_F_Control PORTD
#define _7Seg_F_Config  DDRD
#define _7Seg_F_Pin     1

#define _7Seg_G_Control PORTD
#define _7Seg_G_Config  DDRD
#define _7Seg_G_Pin     4

#define _7Seg_DP_Control PORTD
#define _7Seg_DP_Config  DDRD
#define _7Seg_DP_Pin     7

#define _7Seg_Digit1_Control PORTB
#define _7Seg_Digit1_Config DDRB
#define _7Seg_Digit1_Pin 0

#define _7Seg_Digit2_Control PORTB
#define _7Seg_Digit2_Config DDRB
#define _7Seg_Digit2_Pin 1

#define _7Seg_Digit3_Control PORTB
#define _7Seg_Digit3_Config DDRB
#define _7Seg_Digit3_Pin 2

#define _7Seg_Digit4_Control PORTB
#define _7Seg_Digit4_Config DDRB
#define _7Seg_Digit4_Pin 4
