#ifndef _i2c_H_
#define _i2c_H_

#include "aKaReZa.h"

#define __i2c_WriteCmd 0x00
#define __i2c_ReadCmd  0x01
#define __i2c_ackCmd   0x01
#define __i2c_nackCmd  0x00

void i2c_Init(void);
void i2c_Start(void);
void i2c_Stop(void);
void i2c_Write(uint8_t _Data);
void i2c_writeAddress(uint8_t _address, uint8_t* _Data, uint16_t _dataLength);
uint8_t i2c_Read(bool _ackNack);
void i2c_readAdress(uint8_t _address, uint8_t* _Data, uint16_t _dataLength);
void i2c_readSequential(uint8_t _address, uint8_t *_txData, uint16_t _txDataLenght, uint8_t *_rxData, uint16_t _rxDataLenght);

#endif