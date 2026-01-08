#include "e2prom.h"

void e2prom_uint8_Write(uint16_t _address, uint8_t _Value)
{
    bitWaitLow(EECR, EEPE);

    EEAR = _address;
    EEDR = _Value;

    /* Write and Erase Mode*/
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


void e2prom_float_Write (uint16_t _address, float _Value)
{
    e2p_data32_t _data32;
    
    _data32.f32 = _Value;

    e2prom_uint8_Write((_address + 0), _data32.u8[0]);
    e2prom_uint8_Write((_address + 1), _data32.u8[1]);    
    e2prom_uint8_Write((_address + 2), _data32.u8[2]);
    e2prom_uint8_Write((_address + 3), _data32.u8[3]);      
};

void e2prom_block_Write (uint16_t _address, uint8_t *_Data, uint16_t _length)
{
    uint16_t _Index = 0;

    for(_Index = 0; _Index < _length; _Index++ )
    {
        e2prom_uint8_Write((_address + _Index), _Data[_Index]);
    }
};






void e2prom_uint8_Read (uint16_t _adress, uint8_t* _Value)
{
    bitWaitLow(EECR, EEPE);

    EEAR = _adress;

    bitSet(EECR, EERE);

    *_Value = EEDR;
};



void e2prom_uint16_Read(uint16_t _adress, uint16_t* _Value)
{
    e2p_data16_t _data16;

    e2prom_uint8_Read((_adress + 0), &_data16.u8[0]);
    e2prom_uint8_Read((_adress + 1), &_data16.u8[1]);

    *_Value = _data16.u16;
};


void e2prom_uint32_Read(uint16_t _adress, uint32_t* _Value)
{
    e2p_data32_t _data32;

    e2prom_uint8_Read((_adress + 0), &_data32.u8[0]);
    e2prom_uint8_Read((_adress + 1), &_data32.u8[1]);
    e2prom_uint8_Read((_adress + 2), &_data32.u8[2]);
    e2prom_uint8_Read((_adress + 3), &_data32.u8[3]);

    *_Value = _data32.u32;
};


void e2prom_float_Read(uint16_t _adress, float* _Value)
{
    e2p_data32_t _data32;

    e2prom_uint8_Read((_adress + 0), &_data32.u8[0]);
    e2prom_uint8_Read((_adress + 1), &_data32.u8[1]);
    e2prom_uint8_Read((_adress + 2), &_data32.u8[2]);
    e2prom_uint8_Read((_adress + 3), &_data32.u8[3]);

    *_Value = _data32.f32;
};


void e2prom_block_Read (uint16_t _address, uint8_t *_Data, uint16_t _length)
{
    uint16_t _Index = 0;

    for(_Index = 0; _Index < _length; _Index++ )
    {
        e2prom_uint8_Read((_address + _Index), &_Data[_Index]);
    };

};



void e2prom_uint8_Upate(uint16_t _address, uint8_t  _Value)
{
    uint8_t _Data = 0x00;

    e2prom_uint8_Read(_address, &_Data);

    if(_Data != _Value)
    {
        e2prom_uint8_Write(_address, _Value);
    };
};


void e2prom_uint16_Upate(uint16_t _address, uint16_t  _Value)
{
    uint16_t _Data = 0x00;

    e2prom_uint16_Read(_address, &_Data);
    
    if(_Data != _Value)
    {
        e2prom_uint16_Write(_address, _Value);
    };
};


void e2prom_uint32_Upate(uint16_t _address, uint32_t  _Value)
{
    uint32_t _Data = 0x00;

    e2prom_uint32_Read(_address, &_Data);
    
    if(_Data != _Value)
    {
        e2prom_uint32_Write(_address, _Value);
    };
};



void e2prom_float_Upate(uint16_t _address, float  _Value)
{
    float _Data = 0.0;

    e2prom_float_Read(_address, &_Data);
    
    if((_Data - _Value) < 0.0000001)
    {
        e2prom_float_Write(_address, _Value);
    };
};


void e2prom_block_Upate (uint16_t _address, uint8_t *_Data, uint16_t _length)
{
    uint16_t _Index = 0;
    for(_Index = 0; _Index < _length; _Index++ )
    {
        e2prom_uint8_Upate((_address + _Index), _Data[_Index]);
    };
};






void e2prom_int8_Write(uint16_t _address, int8_t _Value)
{
    bitWaitLow(EECR, EEPE);

    EEAR = _address;
    EEDR = (uint8_t) _Value;

    /* Write and Erase Mode*/
    bitClear(EECR, EEPM0);
    bitClear(EECR, EEPM1);

    bitSet(EECR, EEMPE);

    bitSet(EECR, EEPE);
};


void e2prom_int16_Write(uint16_t _address, int16_t _Value)
{
    e2p_data16_t _data16;

    _data16.i16 = _Value;

    e2prom_int8_Write((_address + 0), _data16.u8[0]);
    e2prom_int8_Write((_address + 1), _data16.u8[1]);
};


void e2prom_int32_Write(uint16_t _address, int32_t _Value)
{
    e2p_data32_t _data32;

    _data32.i32 = _Value;

    e2prom_int8_Write((_address + 0), _data32.u8[0]);
    e2prom_int8_Write((_address + 1), _data32.u8[1]);
    e2prom_int8_Write((_address + 2), _data32.u8[2]);
    e2prom_int8_Write((_address + 3), _data32.u8[3]);        
};



void e2prom_int8_Read (uint16_t _address, int8_t* _Value)
{
    bitWaitLow(EECR, EEPE);

    EEAR = _address;

    bitSet(EECR, EERE);

    *_Value = (int8_t) EEDR;
};


void e2prom_int16_Read(uint16_t _address, int16_t* _Value)
{
    e2p_data16_t _data16;

    e2prom_uint8_Read((_address + 0), &_data16.u8[0]);
    e2prom_uint8_Read((_address + 1), &_data16.u8[1]);

    *_Value = _data16.i16;
};


void e2prom_int32_Read(uint16_t _address, int32_t* _Value)
{
    e2p_data32_t _data32;

    e2prom_uint8_Read((_address + 0), &_data32.u8[0]);
    e2prom_uint8_Read((_address + 1), &_data32.u8[1]);
    e2prom_uint8_Read((_address + 2), &_data32.u8[2]);
    e2prom_uint8_Read((_address + 3), &_data32.u8[3]);

    *_Value = _data32.i32;
};






void e2prom_int8_Upate(uint16_t _address, int8_t  _Value)
{
    int8_t _Data = 0x00;

    e2prom_int8_Read(_address, &_Data);

    if(_Data != _Value)
    {
        e2prom_int8_Write(_address, _Value);
    };
};


void e2prom_int16_Upate(uint16_t _address, int16_t  _Value)
{
    int16_t _Data = 0x00;

    e2prom_int16_Read(_address, &_Data);

    if(_Data != _Value)
    {
        e2prom_int16_Write(_address, _Value);
    };
};


void e2prom_int32_Upate(uint16_t _address, int32_t  _Value)
{
    int32_t _Data = 0x00;

    e2prom_int32_Read(_address, &_Data);

    if(_Data != _Value)
    {
        e2prom_int32_Write(_address, _Value);
    };
};




void e2prom_Format(void)
{
    uint16_t _Index = 0;
    for(_Index = 0; _Index < 1024; _Index++ )
    {
        e2prom_uint8_Write((_Index), 0xFF);
    };    
};