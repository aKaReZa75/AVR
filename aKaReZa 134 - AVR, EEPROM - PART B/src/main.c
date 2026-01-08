#include "aKaReZa.h"

char debugBuffer[25];

int main(void)
{
  usart_Init(Initialize);
  usart_Putsln("aKaReZa");  

  uint8_t _uint8 = 80;
  e2prom_uint8_Write(0x0000, _uint8);

  uint16_t _uint16 = 20000;
  e2prom_uint16_Write(0x0010, _uint16);

  uint32_t _uint32 = 400000;
  e2prom_uint32_Write(0x0020, _uint32);

  float _float = 3.1415;
  e2prom_float_Write(0x0030, _float);

  uint8_t _Array[] = {0x00, 0x01, 0x02, 0x03, 0x04};
  e2prom_block_Upate(0x0040, _Array, sizeof(_Array));

  char _String[] = "aKaReZa";
  e2prom_block_Write(0x0050, (uint8_t*)_String, sizeof(_String));

  int8_t _int8 = -50;
  e2prom_int8_Write(0x0060, _int8);

  int16_t _int16 = -20000;
  e2prom_int16_Write(0x0070, _int16);  

  int32_t _int32 = -400000;
  e2prom_int32_Write(0x0080, _int32);    


  _uint8 = 0;
  e2prom_uint8_Read(0x0000, &_uint8);
  sprintf(debugBuffer, "uint8_t: %d", _uint8);
  usart_Putsln(debugBuffer);

  _uint16 = 0;
  e2prom_uint16_Read(0x0010, &_uint16);
  sprintf(debugBuffer, "uint16_t: %u", _uint16);
  usart_Putsln(debugBuffer);

  _uint32 = 0;
  e2prom_uint32_Read(0x0020, &_uint32);
  sprintf(debugBuffer, "uint32_t: %lu", _uint32);
  usart_Putsln(debugBuffer);
  

  _float = 0;
  e2prom_float_Read(0x0030, &_float);
  sprintf(debugBuffer, "float: %1.4f", _float);
  usart_Putsln(debugBuffer);  

  memset(_Array, 0xFF, sizeof(_Array));
  e2prom_block_Read(0x0040, _Array, sizeof(_Array));
  sprintf(debugBuffer, "_Array: 0x%02d, 0x%02d, 0x%02d, 0x%02d, 0x%02d", _Array[0], _Array[1], _Array[2], _Array[3], _Array[4]);
  usart_Putsln(debugBuffer);

  memset(_String, '\0', sizeof(_String));
  e2prom_block_Read(0x0050, (uint8_t*)_String, sizeof(_String));
  sprintf(debugBuffer, "_String: %s", _String);
  usart_Putsln(debugBuffer);


  _int8 = 0x00;
  e2prom_int8_Read(0x0060, &_int8);
  sprintf(debugBuffer, "int8_t: %d", _int8);
  usart_Putsln(debugBuffer);  


  _int16 = 0x00;
  e2prom_int16_Read(0x0070, &_int16);
  sprintf(debugBuffer, "int16_t: %d", _int16);
  usart_Putsln(debugBuffer);  

  _int32 = 0x00;
  e2prom_int32_Read(0x0080, &_int32);
  sprintf(debugBuffer, "int32_t: %ld", _int32);
  usart_Putsln(debugBuffer);  

  e2prom_Format();

  while(1)
  {
    
  };
};