#include "i2c.h"

void i2c_Init(void)
{
    /* I2C Prescaler = 1  */
    bitClear(TWSR, TWPS0);
    bitClear(TWSR, TWPS1);

    /* I2C CLK Freq: 100KHz */
    TWBR = 72;

   bitSet(TWCR, TWEN);    
};


void i2c_Start(void)
{
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTA);
    bitWaitHigh(TWCR, TWINT);
};


void i2c_Stop(void)
{
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
};


void i2c_Write(uint8_t _Data)
{
    TWDR = _Data;
    TWCR = (1<<TWINT) | (1<<TWEN);
    bitWaitHigh(TWCR, TWINT);    
};

void i2c_writeAddress(uint8_t _address, uint8_t* _Data, uint16_t _dataLength)
{
  i2c_Start();
  i2c_Write(_address<<1 | __i2c_WriteCmd);

  while(_dataLength)
  {
    i2c_Write(*_Data++);
    _dataLength--;
  };

  i2c_Stop();
};


uint8_t i2c_Read(bool _ackNack)
{
    TWCR = (1<<TWINT) | ( _ackNack << TWEA) | (1<<TWEN);
    bitWaitHigh(TWCR, TWINT);    
    return TWDR;
};


void i2c_readAdress(uint8_t _address, uint8_t* _Data, uint16_t _dataLength)
{
  i2c_Start();
  i2c_Write(_address<<1 | __i2c_ReadCmd);

  while(_dataLength)
  {
    *_Data++ = i2c_Read(_dataLength == 1 ? __i2c_nackCmd : __i2c_ackCmd);
    _dataLength--;
  };

  i2c_Stop();
};


void i2c_readSequential(uint8_t _address, uint8_t *_txData, uint16_t _txDataLenght, uint8_t *_rxData, uint16_t _rxDataLenght)
{
  i2c_Start();
  i2c_Write(_address<<1 | __i2c_WriteCmd);
  while(_txDataLenght)
  {
    i2c_Write(*_txData++);
    _txDataLenght--;
  };

  i2c_Start();
  i2c_Write(_address<<1 | __i2c_ReadCmd);
  while(_rxDataLenght)
  {
    *_rxData++ = i2c_Read(_rxDataLenght == 1 ? __i2c_nackCmd : __i2c_ackCmd);
    _rxDataLenght--;
  };

  i2c_Stop();
};