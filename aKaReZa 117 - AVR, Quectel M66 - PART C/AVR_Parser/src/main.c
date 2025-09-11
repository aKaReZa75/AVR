#include "aKaReZa.h"

char M66_Buffer[] = "\r\n+CMGR: \"REC UNREAD\",\"+989355282124\",\"\",\"2025/05/19 10:34:08+14\"\r\nHello my name is aKaReZa\r\n\r\nOK\r\n";
char PhoneNumber[14];
char IncomeTex[50];

uint8_t Temp = 10;
uint8_t Status = 0;
char alcd_Buffer[17];
int main(void)
{
  alcd_init();

  usart_Init(Initialize);
  usart_Puts(M66_Buffer);
  usart_Putsln("--------------------------");

  Status = sscanf(M66_Buffer, "\r\n+CMGR: \"%*[^\"]\",\"%[^\"]\",\"\",\"%*[^\"]\"\r\n%[^\r]\r\n", PhoneNumber, IncomeTex);
  sprintf(alcd_Buffer, "SSCANF: %d", Status);
  alcd_puts(alcd_Buffer);


  usart_Puts("PhoneNumber: ");
  usart_Putsln(PhoneNumber);
  usart_Putsln("--------------------------");


  usart_Puts("IncomeTex: ");
  usart_Putsln(IncomeTex);
  usart_Putsln("--------------------------");

  while(1)
  {
    
  };
};