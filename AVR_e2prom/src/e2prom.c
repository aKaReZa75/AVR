#include "e2prom.h"

void e2prom_uint8_Write(uint16_t _address, uint8_t _Value)
{
    bitWaitLow(EECR, EEPE);

    EEAR = _address;
    EEDR = _Value;

    /* Write and Erase */
    bitClear(EECR, EEPM0);
    bitClear(EECR, EEPM1);

    bitSet(EECR, EEMPE);

    bitSet(EECR, EEPE);
};



void e2prom_uint16_Write(uint16_t _address, uint16_t _Value)
{
    e2p_data16_t _data16;

    _data16.u16 = _Value;

    e2prom_uint8_Write((_address + 0), _data16.u8[0]);
    e2prom_uint8_Write((_address + 1), _data16.u8[1]);
};


void e2prom_uint32_Write(uint16_t _address, uint32_t _Value)
{
    e2p_data32_t _data32;

    _data32.u32 = _Value;

    e2prom_uint8_Write((_address + 0), _data32.u8[0]);
    e2prom_uint8_Write((_address + 1), _data32.u8[1]);    
    e2prom_uint8_Write((_address + 2), _data32.u8[2]);
    e2prom_uint8_Write((_address + 3), _data32.u8[3]);       
};