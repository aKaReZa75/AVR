#ifndef _adc_H_
#define _adc_H_

#include "aKaReZa.h"

void     adc_Init(bool _initStatus);
int8_t   adc_internalTemp(void);
uint16_t adc_Read(uint8_t _adcChannel);

#endif