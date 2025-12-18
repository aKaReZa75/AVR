#ifndef _e2prom_H_
#define _e2prom_H_

#include "aKaReZa.h"

typedef union
{
    uint16_t u16;
    uint8_t  u8[2];
}e2p_data16_t;


typedef union
{
    uint32_t u32;
    uint8_t  u8[4];
}e2p_data32_t;


void e2prom_uint8_Write(uint16_t _address , uint8_t  _Value);
void e2prom_uint16_Write(uint16_t _address, uint16_t _Value);
void e2prom_uint32_Write(uint16_t _address, uint32_t _Value);

#endif