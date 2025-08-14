#ifndef _M66_H_
#define _M66_H_

#include "aKaReZa.h"

#define __M66_CMD_EchoOff     "ATE0"
#define __M66_CMD_AT          "AT"
#define __M66_CMD_fullFunc    "AT+CFUN=1"
#define __M66_CMD_VError      "AT+CMEE=2"
#define __M66_CMD_textMode    "AT+CMGF=1"
#define __M66_CMD_Settings    "AT+CSMP=17,167,0,0" 
#define __M66_CMD_charSetting "AT+CSCS=\"GSM\""
#define __M66_CMD_SMSdellAll  "AT+CMGD=1,4"
#define __M66_CMD_SignalQua   "AT+CSQ"
#define __M66_CMD_NetReg      "AT+CREG?"
#define __M66_CMD_Operator    "AT+COPS?"
#define __M66_CMD_Restart     "AT+QPOWD=0"
#define __M66_CtrlZ           0x1A
#define __M66_Okey            "OK"
#define __M66_ERR             "ERROR"

typedef enum
{
    M66_Res_OK,
    M66_Res_ERR,
    M66_Res_TimeOut
} M66_Res_T;

void M66_Init(void);

void M66_SendSMS(char* _PhoneNumber, char* _Text);

M66_Res_T M66_SendAtCmd(char* _CMD, char* _Reponse);

#endif