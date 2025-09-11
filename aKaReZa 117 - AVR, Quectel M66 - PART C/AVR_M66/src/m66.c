#include "M66.h"

extern volatile bool usart_RxFlag;   /**< True: Data has been received completely */   
extern char usart_RxBuffer[__usart_RxBufferSize]; /* Buffer to store received data, with defined size */

#define _PUMP_Config  DDRB
#define _PUMP_Control PORTB
#define _PUMP_Pin     0

#define _Motor_Config  DDRB
#define _Motor_Control PORTB
#define _Motor_Pin     1

#define _Speed_Config  DDRB
#define _Speed_Control PORTB
#define _Speed_Pin     2

M66_Res_T M66_Init(void)
{
  GPIO_Config_OUTPUT(_PUMP_Config, _PUMP_Pin);
  GPIO_Config_OUTPUT(_Motor_Config, _Motor_Pin);
  GPIO_Config_OUTPUT(_Speed_Config, _Speed_Pin);

    M66_Res_T _Res = M66_Res_ERR;

    _Res = M66_Startup();
    if(_Res != M66_Res_OK)
    {
        return _Res;
    };

    _Res = M66_Config();
    if(_Res != M66_Res_OK)
    {
        return _Res;
    };

    alcd_clear();
    alcd_puts("Ready...");

    return M66_Res_OK;
};


M66_Res_T M66_Startup(void)
{
    M66_Res_T _Res = M66_Res_ERR;
    M66_SendAtCmd(__M66_CMD_Restart, "", __M66_Default_TimeOut);

    alcd_clear();
    alcd_puts("M66_Startup");  

    _Res = M66_SendAtCmd("", "RDY", __M66_StartUp_TimeOut);  
    if(_Res != M66_Res_OK)
    {
        return _Res;
    };
  
    _Res = M66_SendAtCmd("", "+CFUN", __M66_StartUp_TimeOut);
    if(_Res != M66_Res_OK)
    {
        return _Res;
    };
     
    _Res = M66_SendAtCmd("", "+CPIN", __M66_StartUp_TimeOut);
    if(_Res != M66_Res_OK)
    {
        return _Res;
    };

    _Res = M66_SendAtCmd("", "Call Ready", __M66_StartUp_TimeOut);
    if(_Res != M66_Res_OK)
    {
        return _Res;
    };
   
    _Res = M66_SendAtCmd("", "SMS Ready", __M66_StartUp_TimeOut);
    if(_Res != M66_Res_OK)
    {
        return _Res;
    }; 

    return M66_Res_OK;
};

M66_Res_T M66_Config(void)
{
    alcd_clear();
    alcd_puts("M66_Config");  
        
    M66_Res_T _Res = M66_Res_ERR;

    _Res = M66_SendAtCmd(__M66_CMD_EchoOff, "ATE0", __M66_Default_TimeOut);
    if(_Res != M66_Res_OK)
    {
        return _Res;
    };
    M66_SendAtCmd("", __M66_Okey, __M66_Default_TimeOut);

    _Res = M66_SendAtCmd(__M66_CMD_fullFunc, __M66_Okey, __M66_Default_TimeOut);
    if(_Res != M66_Res_OK)
    {
        return _Res;
    };

    _Res = M66_SendAtCmd(__M66_CMD_textMode, __M66_Okey, __M66_Default_TimeOut);
    if(_Res != M66_Res_OK)
    {
        return _Res;
    };

    _Res = M66_SendAtCmd(__M66_CMD_charSetting, __M66_Okey, __M66_Default_TimeOut);
    if(_Res != M66_Res_OK)
    {
        return _Res;
    };

    _Res = M66_SendAtCmd(__M66_CMD_Settings, __M66_Okey, __M66_Default_TimeOut); 
    if(_Res != M66_Res_OK)
    {
        return _Res;
    };

    _Res = M66_SendAtCmd(__M66_CMD_SMSdellAll, __M66_Okey, __M66_Default_TimeOut); 
    if(_Res != M66_Res_OK)
    {
        return _Res;
    };

    return M66_Res_OK;
};


M66_Res_T M66_SendSMS(char* _PhoneNumber, char* _Text)
{
    M66_Res_T _Res = M66_Res_ERR;
    char _CMD[25];
    
    sprintf(_CMD, "AT+CMGS=\"%s\"", _PhoneNumber);
    _Res = M66_SendAtCmd(_CMD, ">", __M66_Default_TimeOut); 
    switch (_Res)
    {
        case M66_Res_OK:
            alcd_puts("M66_Res_OK");
        break;
        case M66_Res_ERR:
            alcd_puts("M66_Res_ERR");
        break;        
        case M66_Res_TimeOut:
            alcd_puts("M66_Res_TimeOut");
        break;            
    }        
    if(_Res != M66_Res_OK)
    {
        return _Res;
    };

    usart_Puts(_Text);
    usart_Write(__M66_CtrlZ);

    return M66_Res_OK;
};


M66_Res_T M66_SendAtCmd(char* _CMD, char* _Reponse, int16_t _TimeOut)
{
    M66_Res_T _Res = M66_Res_TimeOut;
    uint16_t _Timer = 0;

    usart_Flush();

    if(*_CMD != '\0')
    {
        usart_Putsln(_CMD);
    };

    while(!usart_RxFlag)
    {
        _Timer++;
        if(_Timer > _TimeOut)
        {
            break;
        };
        delay_ms(1);
    };

    if(strstr(usart_RxBuffer, _Reponse))
    {
        _Res = M66_Res_OK;
    }
    else if(strstr(usart_RxBuffer, __M66_ERR))
    {
        _Res = M66_Res_ERR;
    };
    
    usart_Flush();

    return _Res;
};



M66_Res_T M66_CheckSMS(void)
{
    char PhoneNumber[14];
    char IncomeTex[241];
    uint8_t Status = 0;
    char alcd_Buffer[17];
        
    usart_Flush();
    M66_SendAtCmd("AT+CMGR=1", __M66_Okey, __M66_Default_TimeOut);
    while(!usart_RxFlag);

    Status = sscanf(usart_RxBuffer, "\r\n+CMGR: \"%*[^\"]\",\"%[^\"]\",\"\",\"%*[^\"]\"\r\n%[^\r]\r\n", PhoneNumber, IncomeTex);
    
    if(Status != 2)
    {
        return M66_Res_ERR;
    };

    alcd_clear();
    sprintf(alcd_Buffer, "SSCANF: %d", Status);
    alcd_puts(alcd_Buffer);

    delay_ms(2500);

    alcd_clear();
    alcd_gotoxy(0, 0);
    alcd_puts(PhoneNumber);

    delay_ms(2500);

    alcd_clear();
    alcd_gotoxy(0, 0);
    alcd_puts(IncomeTex);  

    if(strstr(IncomeTex,"P:OFF,M:OFF"))
    { 
        bitClear(_PUMP_Control, _PUMP_Pin);
        bitClear(_Motor_Control, _Motor_Pin);
        bitClear(_Speed_Control, _Speed_Pin);
    }         
    else if(strstr(IncomeTex,"P:ON,M:LOW"))
    { 
        bitSet(_PUMP_Control, _PUMP_Pin);
        bitSet(_Motor_Control, _Motor_Pin);
        bitClear(_Speed_Control, _Speed_Pin);
    }
    else if(strstr(IncomeTex,"P:ON,M:HIGH"))
    { 
        bitSet(_PUMP_Control, _PUMP_Pin);
        bitSet(_Motor_Control, _Motor_Pin);
        bitSet(_Speed_Control, _Speed_Pin);
    }        
    else if(strstr(IncomeTex,"P:OFF,M:LOW"))
    { 
        bitClear(_PUMP_Control, _PUMP_Pin);
        bitSet(_Motor_Control, _Motor_Pin);
        bitClear(_Speed_Control, _Speed_Pin);
    }     
    else if(strstr(IncomeTex,"P:OFF,M:HIGH"))
    { 
        bitClear(_PUMP_Control, _PUMP_Pin);
        bitSet(_Motor_Control, _Motor_Pin);
        bitSet(_Speed_Control, _Speed_Pin);
    };

    usart_Flush();

    return M66_Res_OK;
};