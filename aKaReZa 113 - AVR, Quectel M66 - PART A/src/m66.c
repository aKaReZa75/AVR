#include "M66.h"

extern volatile bool usart_RxFlag;   /**< True: Data has been received completely */   
extern char usart_RxBuffer[__usart_RxBufferSize]; /* Buffer to store received data, with defined size */

void M66_Init(void)
{
    M66_SendAtCmd(__M66_CMD_EchoOff, __M66_Okey);

    M66_SendAtCmd(__M66_CMD_fullFunc, __M66_Okey);

    M66_SendAtCmd(__M66_CMD_textMode, __M66_Okey);

    M66_SendAtCmd(__M66_CMD_charSetting, __M66_Okey);

    M66_SendAtCmd(__M66_CMD_Settings, __M66_Okey); 
};


void M66_SendSMS(char* _PhoneNumber, char* _Text)
{
    char _CMD[25];

    sprintf(_CMD, "AT+CMGS=\"%s\"", _PhoneNumber);
    M66_SendAtCmd(_CMD,">"); 

    usart_Puts(_Text);
    usart_Write(__M66_CtrlZ);
};


M66_Res_T M66_SendAtCmd(char* _CMD, char* _Reponse)
{
    M66_Res_T _Res = M66_Res_OK;

    usart_Putsln(_CMD);

    while(!usart_RxFlag);

    if(strstr(usart_RxBuffer, __M66_Okey))
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