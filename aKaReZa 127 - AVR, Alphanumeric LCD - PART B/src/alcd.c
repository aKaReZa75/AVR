#include "alcd.h"

bool __alcd_initStatus = false;
uint8_t __alcd_x_position = 0;
uint8_t __alcd_y_position = 0; 


void alcd_gotoxy(uint8_t _alcd_x, uint8_t _alcd_y)
{
    uint8_t _address = 0x00;

    if(_alcd_x >= __alcd_max_x || _alcd_y >= __alcd_max_y)
    {
        __alcd_x_position = 0;
        __alcd_y_position = 0;
    }
    else
    {
        __alcd_x_position = _alcd_x;
        __alcd_y_position = _alcd_y;
    };

    _address = (__alcd_y_position == 0) ? __alcd_Line1_Start : __alcd_Line2_Start;
    _address = _address + __alcd_x_position;

    alcd_write(_address, __alcd_writeCmd);
};


void alcd_puts(char* _str)
{
    while (*_str != '\0')
    {
        alcd_putc(*_str++);
    };  
};


void alcd_putc(char _char)
{
    alcd_write(_char, __alcd_writeData);
    __alcd_x_position++;
    if(__alcd_x_position >=  __alcd_max_x)
    {
        __alcd_x_position = 0;
        __alcd_y_position++;
        alcd_gotoxy(__alcd_x_position, __alcd_y_position);
    };
};


void alcd_write(uint8_t _data, bool _alcd_cmdData)
{
    bitChange(__alcd_RS_Control, __alcd_RS_Pin, _alcd_cmdData);

    bitChange(__alcd_DB0_Control, __alcd_DB0_Pin, bitCheck(_data, 0));
	bitChange(__alcd_DB1_Control, __alcd_DB1_Pin, bitCheck(_data, 1));
	bitChange(__alcd_DB2_Control, __alcd_DB2_Pin, bitCheck(_data, 2));
	bitChange(__alcd_DB3_Control, __alcd_DB3_Pin, bitCheck(_data, 3));
	bitChange(__alcd_DB4_Control, __alcd_DB4_Pin, bitCheck(_data, 4));
	bitChange(__alcd_DB5_Control, __alcd_DB5_Pin, bitCheck(_data, 5));
	bitChange(__alcd_DB6_Control, __alcd_DB6_Pin, bitCheck(_data, 6));
	bitChange(__alcd_DB7_Control, __alcd_DB7_Pin, bitCheck(_data, 7));

    bitSet(__alcd_EN_Control, __alcd_EN_Pin);
    if(__alcd_initStatus == false)
    {
        __alcd_delay(__alcd_delay_modeSet);
    }
    else
    {
        __alcd_delay(__alcd_delay_CMD);
    }
    bitClear(__alcd_EN_Control, __alcd_EN_Pin);
};

void alcd_init(void)
{
    __alcd_initStatus = false;
	bitSet(__alcd_RS_Config , __alcd_RS_Pin);
	bitSet(__alcd_EN_Config , __alcd_EN_Pin);    
	bitSet(__alcd_DB0_Config, __alcd_DB0_Pin);
	bitSet(__alcd_DB1_Config, __alcd_DB1_Pin);
	bitSet(__alcd_DB2_Config, __alcd_DB2_Pin);
	bitSet(__alcd_DB3_Config, __alcd_DB3_Pin);    
	bitSet(__alcd_DB4_Config, __alcd_DB4_Pin);
	bitSet(__alcd_DB5_Config, __alcd_DB5_Pin);
	bitSet(__alcd_DB6_Config, __alcd_DB6_Pin);
	bitSet(__alcd_DB7_Config, __alcd_DB7_Pin);

    alcd_write(__alcd_Mode_8bit_2line_5x8, __alcd_writeCmd);
    __alcd_delay(__alcd_delay_modeSet);
    alcd_write(__alcd_Display_ON, __alcd_writeCmd); 
    __alcd_delay(__alcd_delay_modeSet);    
    alcd_write(__alcd_Cursor_OFF, __alcd_writeCmd); 
    __alcd_delay(__alcd_delay_modeSet);    
    alcd_write(__alcd_Entry_Inc, __alcd_writeCmd);
    __alcd_delay(__alcd_delay_modeSet);    
    alcd_write(__alcd_Display_Clear, __alcd_writeCmd);
    __alcd_delay(__alcd_delay_modeSet);    
    __alcd_initStatus = true;
};