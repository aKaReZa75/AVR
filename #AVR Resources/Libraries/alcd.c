/* @file     alcd.c                                   */
/* @brief    16x2 Alphanumeric LCD display Library    */
/* @note     This file is for _AVR_ microcontrollers  */   
/* @author   Hossein Bagheri                          */
/* @github   aKaReZa75                                */
/* @youtube  aKaReZa75                                */
/* @linkedin aKaReZa75                                */
/* @email    aKaReZa75@gmail.com                      */
#include "alcd.h"

uint8_t alcd_x_position = 0;
uint8_t alcd_y_position = 0;

void alcd_write(uint8_t _alcd_write_value, bool _alcd_cmdData)
{
	bitChange(__alcd_RS_Control, __alcd_RS_Pin, _alcd_cmdData); //cmd = 0; Data = 1

	bitChange(__alcd_DB7_Control, __alcd_DB7_Pin, bitCheck(_alcd_write_value, 7));
	bitChange(__alcd_DB6_Control, __alcd_DB6_Pin, bitCheck(_alcd_write_value, 6));
	bitChange(__alcd_DB5_Control, __alcd_DB5_Pin, bitCheck(_alcd_write_value, 5));
	bitChange(__alcd_DB4_Control, __alcd_DB4_Pin, bitCheck(_alcd_write_value, 4));

	bitSet(__alcd_EN_Control, __alcd_EN_Pin);
	__alcd_delay(__alcd_delay_CMD);
	bitClear(__alcd_EN_Control, __alcd_EN_Pin);

	bitChange(__alcd_DB7_Control, __alcd_DB7_Pin, bitCheck(_alcd_write_value, 3));
	bitChange(__alcd_DB6_Control, __alcd_DB6_Pin, bitCheck(_alcd_write_value, 2));
	bitChange(__alcd_DB5_Control, __alcd_DB5_Pin, bitCheck(_alcd_write_value, 1));
	bitChange(__alcd_DB4_Control, __alcd_DB4_Pin, bitCheck(_alcd_write_value, 0));
	
	bitSet(__alcd_EN_Control, __alcd_EN_Pin);
	__alcd_delay(__alcd_delay_CMD);
	bitClear(__alcd_EN_Control, __alcd_EN_Pin);	
};


void alcd_putc(char _alcd_putcr)
{
	alcd_write(_alcd_putcr, __alcd_writeData);
	if(++alcd_x_position == 16)	alcd_gotoxy(0, ++alcd_y_position);	
};


void alcd_puts(char *_alcd_str)
{
	while(*_alcd_str != 0)
	{
		alcd_write(*_alcd_str++, __alcd_writeData);
		if(++alcd_x_position == 16)	alcd_gotoxy(0, ++alcd_y_position);	
	};
};

void alcd_customChar(uint8_t _alcd_CGRAMadd, const uint8_t *_alcd_CGRAMdata)
{
	uint8_t _forCounter = 0;
	_alcd_CGRAMadd = 0x40 + (_alcd_CGRAMadd << 3);
	for(_forCounter=0; _forCounter < 8; _forCounter++)
	{	
		alcd_write(_alcd_CGRAMadd++  , __alcd_writeCmd );
		alcd_write(*_alcd_CGRAMdata++, __alcd_writeData);
	};
	alcd_gotoxy(alcd_x_position, alcd_y_position);
};


void alcd_init(void)
{
	__alcd_delay(__alcd_delay_powerON);

	GPIO_Config_OUTPUT(__alcd_DB4_Config, __alcd_DB4_Pin);
	GPIO_Config_OUTPUT(__alcd_DB5_Config, __alcd_DB5_Pin);
	GPIO_Config_OUTPUT(__alcd_DB6_Config, __alcd_DB6_Pin);
	GPIO_Config_OUTPUT(__alcd_DB7_Config, __alcd_DB7_Pin);
	GPIO_Config_OUTPUT(__alcd_RS_Config , __alcd_RS_Pin);
	GPIO_Config_OUTPUT(__alcd_EN_Config , __alcd_EN_Pin);

	#ifdef __alcd_useBL
		GPIO_Config_OUTPUT(__alcd_BL_Config , __alcd_BL_Pin);
		bitSet(__alcd_BL_Control, __alcd_BL_Pin);
	#endif

	alcd_write(0x33, __alcd_writeCmd);
	__alcd_delay(__alcd_delay_modeSet);
	alcd_write(0x32, __alcd_writeCmd);
	__alcd_delay(__alcd_delay_modeSet);
	alcd_write(0x28, __alcd_writeCmd); 					/* Two Row 4bit */
	__alcd_delay(__alcd_delay_modeSet);
	alcd_write(0x0C, __alcd_writeCmd); 					/* Display on and cursor off */
	alcd_write(0x06, __alcd_writeCmd); 					/* Auto increment cursor */
	alcd_write(__alcd_DISPLAY_CLEAR, __alcd_writeCmd);  /* Display clear */
	alcd_x_position = 0;
	alcd_y_position = 0;	
};


void alcd_clear(void)
{
	alcd_write(__alcd_DISPLAY_CLEAR, __alcd_writeCmd);
	alcd_x_position = 0;
	alcd_y_position = 0;	
};


void alcd_gotoxy(uint8_t _alcd_x_position, uint8_t _alcd_y_position)
{	
	if(_alcd_y_position == 2)
	{
		alcd_x_position = 0;
		alcd_y_position = 0;
	}
	else
	{
		alcd_x_position = _alcd_x_position;
		alcd_y_position = _alcd_y_position;	
	};
	bitSet   (_alcd_x_position, 7);						/* if y==0 */
	bitChange(_alcd_x_position, 6, _alcd_y_position);	/* if y==1 */
	alcd_write(_alcd_x_position, __alcd_writeCmd);
};


void alcd_cursor(_Bool _alcd_Cursor, _Bool _alcd_Blink)
{
	uint8_t _lcdCursorCMD = 0x0C;
	bitChange(_lcdCursorCMD, 1, _alcd_Cursor);
	bitChange(_lcdCursorCMD, 0, _alcd_Blink);
	alcd_write(_lcdCursorCMD, __alcd_writeCmd);
};


void alcd_display(_Bool _alcd_displayStatus)
{
	uint8_t _lcdDisplayStatus = 0x08;
	bitChange(_lcdDisplayStatus, 2, _alcd_displayStatus);
	alcd_write(_lcdDisplayStatus, __alcd_writeCmd);
};


#ifdef __alcd_useBL
	void alcd_backLight(bool _alcd_backLightStatus)
	{
		bitChange(__alcd_BL_Control, __alcd_BL_Pin, _alcd_backLightStatus);
	};
#endif
