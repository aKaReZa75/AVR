/* @file     alcd.h                                   */
/* @brief    16x2 Alphanumeric LCD display Library    */
/* @note     This file is for _AVR_ microcontrollers  */   
/* @author   Hossein Bagheri                          */
/* @github   aKaReZa75                                */
/* @youtube  aKaReZa75                                */
/* @linkedin aKaReZa75                                */
/* @email    aKaReZa75@gmail.com                      */
#ifndef _alcd_H
#define _alcd_H

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

#ifdef __alcd_useBL
    #define __alcd_BL_Config   DDRB
    #define __alcd_BL_Control  PORTB
    #define __alcd_BL_Pin      2
#endif

#define __alcd_delay(_alcd_delayValue) delay_ms(_alcd_delayValue)
#define __alcd_delay_powerON 15 
#define __alcd_delay_modeSet  5 
#define __alcd_delay_CMD      2

#define __alcd_writeCmd           0
#define __alcd_writeData          1      
#define __alcd_DISPLAY_CLEAR      0x01
#define __alcd_DISPLAY_OFF        0x08
#define __alcd_DISPLAY_ON         0x0C
#define __alcd_CURSOR_OFF         0x0C
#define __alcd_CURSOR_ON          0x0E
#define __alcd_CURSOR_BLINK       0x0D
#define __alcd_CURSOR_dashBLINK   0x0F


void alcd_init(void);
void alcd_clear(void);
void alcd_gotoxy(uint8_t _alcd_x_position, uint8_t _alcd_y_position);
void alcd_puts(char *_alcd_str);
void alcd_cursor(_Bool _alcd_Cursor, _Bool _alcd_Blink);
void alcd_display(_Bool _alcd_displayStatus);
void alcd_write(uint8_t _alcd_write_value, bool _alcd_cmdData);
void alcd_putc(char _alcd_putcr);
void alcd_customChar(uint8_t _alcd_CGRAMadd, const uint8_t *_alcd_CGRAMdata);

#ifdef __alcd_useBL
    void alcd_backLight(bool _alcd_backLightStatus);
#endif

#endif
