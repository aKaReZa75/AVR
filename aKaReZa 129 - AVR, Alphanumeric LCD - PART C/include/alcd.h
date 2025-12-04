#ifndef _alcd_H_
#define _alcd_H_

#include "aKaReZa.h"

#define __alcd_useBL  true

#define __alcd_RS_Config   DDRB     
#define __alcd_RS_Control  PORTB    
#define __alcd_RS_Pin      0        

#define __alcd_EN_Config   DDRB      
#define __alcd_EN_Control  PORTB    
#define __alcd_EN_Pin      1        

#define __alcd_DB4_Config  DDRD     
#define __alcd_DB4_Control PORTD     
#define __alcd_DB4_Pin     4         

#define __alcd_DB5_Config  DDRD      
#define __alcd_DB5_Control PORTD     
#define __alcd_DB5_Pin     5         

#define __alcd_DB6_Config  DDRD     
#define __alcd_DB6_Control PORTD    
#define __alcd_DB6_Pin     6        

#define __alcd_DB7_Config  DDRD      
#define __alcd_DB7_Control PORTD     
#define __alcd_DB7_Pin     7     

#if __alcd_useBL == true
    #define __alcd_BL_Config   DDRB 
    #define __alcd_BL_Control  PORTB 
    #define __alcd_BL_Pin      2    
#endif


// Command/Data Selection
#define __alcd_writeCmd   0
#define __alcd_writeData  1

#define __alcd_max_x  16
#define __alcd_max_y  2

#define __alcd_delay(_delayValue)  _delay_us(_delayValue)
#define __alcd_delay_CMD      50
#define __alcd_delay_modeSet  5000
#define __alcd_delay_powerON  50000 

// Function Set Commands (for reference)
#define __alcd_Mode_8bit_2line_5x8   0x38
#define __alcd_Mode_8bit_1line_5x8   0x30
#define __alcd_Mode_4bit_2line_5x8   0x28
#define __alcd_Mode_4bit_1line_5x8   0x20
#define __alcd_Mode_4bit_Step1       0x33  // Initialize LCD for 4-bit mode (sends 0x03 twice)
#define __alcd_Mode_4bit_Step2       0x32  // Set 4-bit mode (sends 0x03 then 0x02)

// Display Control Commands
#define __alcd_Display_Clear 0x01  // Clear display
#define __alcd_Display_Home  0x02  // Return cursor to home position
#define __alcd_Display_OFF   0x08  // Display OFF, cursor OFF, blink OFF
#define __alcd_Display_ON    0x0C  // Display ON, cursor OFF, blink OFF

// Cursor Control Commands
#define __alcd_Cursor_OFF    0x0C  // Display ON, cursor OFF, blink OFF
#define __alcd_Cursor_ON     0x0E  // Display ON, cursor ON, blink OFF
#define __alcd_Cursor_Blink  0x0D  // Display ON, cursor OFF, blink ON
#define __alcd_Cursor_dashBLINK   0x0F  // Display ON, cursor ON, blink ON (underline + blink)

// Entry Mode Set Commands
#define __alcd_Entry_Inc     0x06  // Increment cursor (shift cursor to right)
#define __alcd_Entry_Dec     0x04  // Decrement cursor (shift cursor to left)
#define __alcd_Entry_Shift   0x07  // Increment with display shift

// DDRAM Address Commands (Line positioning)
#define __alcd_Line1_Start   0x80  // Start address of line 1
#define __alcd_Line2_Start   0xC0  // Start address of line 2

// CGRAM Address Command
#define __alcd_CGRAM_Start   0x40  // Start address for custom character

void alcd_init(void);
void alcd_write(uint8_t _data, bool _alcd_cmdData);
void alcd_putc(char _char);
void alcd_puts(char* _str);
void alcd_gotoxy(uint8_t _alcd_x, uint8_t _alcd_y);
void alcd_clear(void);
void alcd_display(bool _alcd_Display, bool _alcd_Cursor, bool _alcd_Blink);
void alcd_customChar(uint8_t _alcd_CGRAMadd, const uint8_t *_alcd_CGRAMdata);


#if __alcd_useBL == true
    void alcd_backLight(bool _alcd_BL);
#endif

#endif