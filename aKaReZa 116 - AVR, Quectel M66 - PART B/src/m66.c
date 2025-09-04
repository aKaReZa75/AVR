#include "M66.h"

extern volatile bool usart_RxFlag;   /**< True: Data has been received completely */   
extern char usart_RxBuffer[__usart_RxBufferSize]; /* Buffer to store received data, with defined size */

M66_Res_T M66_Init(void)
{
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

    M66_SendAtCmd(__M66_CMD_fullFunc, __M66_Okey, __M66_Default_TimeOut);
    if(_Res != M66_Res_OK)
    {
        return _Res;
    };

    M66_SendAtCmd(__M66_CMD_textMode, __M66_Okey, __M66_Default_TimeOut);
    if(_Res != M66_Res_OK)
    {
        return _Res;
    };

    M66_SendAtCmd(__M66_CMD_charSetting, __M66_Okey, __M66_Default_TimeOut);
    if(_Res != M66_Res_OK)
    {
        return _Res;
    };

    M66_SendAtCmd(__M66_CMD_Settings, __M66_Okey, __M66_Default_TimeOut); 
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
