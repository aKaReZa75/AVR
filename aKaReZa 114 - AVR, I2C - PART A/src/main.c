#include "aKaReZa.h"

uint8_t i2c_txBuffer[] = {0x00, 'a', 'K', 'a', 'R', 'e', 'Z', 'a'};
uint8_t i2c_rxBuffer[20] = {0};

int main(void)
{
  usart_Init(Initialize);
  // usart_Putsln("aKaReZa");
  i2c_Init();

  // i2c_Start();
  // i2c_Write(0x50<<1 | __i2c_WriteCmd);
  // i2c_Write(0x00);
  // i2c_Write('a');
  // i2c_Write('K');
  // i2c_Write('a');
  // i2c_Write('R');
  // i2c_Write('e');
  // i2c_Write('Z');
  // i2c_Write('a');   
  // i2c_Stop();

  //i2c_writeAddress(0x50, i2c_txBuffer, sizeof(i2c_txBuffer));

  // i2c_Start();
  // i2c_Write(0x50<<1 | __i2c_WriteCmd);
  // i2c_Write(0x00);
  // i2c_Stop();
  // i2c_Start();
  // i2c_Write(0x50<<1 | __i2c_ReadCmd);
  // i2c_rxBuffer[0] = i2c_Read(__i2c_ackCmd);
  // i2c_rxBuffer[1] = i2c_Read(__i2c_ackCmd);
  // i2c_rxBuffer[2] = i2c_Read(__i2c_ackCmd);
  // i2c_rxBuffer[3] = i2c_Read(__i2c_ackCmd);
  // i2c_rxBuffer[4] = i2c_Read(__i2c_ackCmd);
  // i2c_rxBuffer[5] = i2c_Read(__i2c_ackCmd);
  // i2c_rxBuffer[6] = i2c_Read(__i2c_nackCmd);
  // i2c_Stop();

  // i2c_writeAddress(0x50, 0x00, 1);
  // i2c_readAdress(0x50, i2c_rxBuffer, 7);

  i2c_readSequential(0x50, 0x00, 1, i2c_rxBuffer, 19);

  usart_Putsln((char*) i2c_rxBuffer);

  while(1)
  {
    
  };
};