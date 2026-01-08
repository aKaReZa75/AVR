#ifndef _e2prom_H_
#define _e2prom_H_

#include "aKaReZa.h"

typedef union
{
    uint16_t u16;
    int16_t  i16;
    uint8_t  u8[2];
}e2p_data16_t;


typedef union
{
    uint32_t u32;
    int32_t  i32;
    float    f32;
    uint8_t  u8[4];
}e2p_data32_t;


void e2prom_uint8_Write (uint16_t _address, uint8_t  _Value);
void e2prom_uint16_Write(uint16_t _address, uint16_t _Value);
void e2prom_uint32_Write(uint16_t _address, uint32_t _Value);
void e2prom_float_Write (uint16_t _address, float _Value);
void e2prom_block_Write (uint16_t _address, uint8_t *_Data, uint16_t _length);


void e2prom_uint8_Read (uint16_t _adress, uint8_t* _Value);
void e2prom_uint16_Read(uint16_t _adress, uint16_t* _Value);
void e2prom_uint32_Read(uint16_t _adress, uint32_t* _Value);
void e2prom_float_Read (uint16_t _adress, float* _Value);
void e2prom_block_Read (uint16_t _address, uint8_t *_Data, uint16_t _length);


void e2prom_uint8_Upate (uint16_t _address, uint8_t  _Value);
void e2prom_uint16_Upate(uint16_t _address, uint16_t _Value);
void e2prom_uint32_Upate(uint16_t _address, uint32_t _Value);
void e2prom_float_Upate (uint16_t _address, float _Value);
void e2prom_block_Upate (uint16_t _address, uint8_t *_Data, uint16_t _length);


void e2prom_int8_Write (uint16_t _address, int8_t _Value);
void e2prom_int16_Write(uint16_t _address, int16_t _Value);
void e2prom_int32_Write(uint16_t _address, int32_t _Value);

void e2prom_int8_Read (uint16_t _address, int8_t* _Value);
void e2prom_int16_Read(uint16_t _address, int16_t* _Value);
void e2prom_int32_Read(uint16_t _address, int32_t* _Value);

void e2prom_int8_Upate (uint16_t _address, int8_t  _Value);
void e2prom_int16_Upate(uint16_t _address, int16_t  _Value);
void e2prom_int32_Upate(uint16_t _address, int32_t  _Value);

void e2prom_Format(void);

#endif