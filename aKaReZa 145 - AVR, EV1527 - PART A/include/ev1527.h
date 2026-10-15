#ifndef _ev1527_H_
#define _ev1527_H_

#include "aKaReZa.h"

#define EV_Timer_Reset TCNT1 = 0x0000
#define EV_Timer_Value TCNT1
#define EV_maxIndexData  23
#define HPL_min          450    /* Min tick of High plus Low*/
#define HPL_Max          8500   /* Max tick of High plus Low*/

#define EV_pulseIsValid(_tickLow, _tickHigh)  (((_tickLow + _tickHigh) > HPL_min) && ((_tickLow + _tickHigh) < HPL_Max))
#define EV_PrembleCheck(_tickLow, _tickHigh)  ((_tickLow  >= 25*_tickHigh) && (_tickLow <= 40*_tickHigh))
#define EV_bitCheck(_tickLow, _tickHigh)      ((_tickHigh >= 1.5*_tickLow) ? 1:0)

typedef union 
{
    uint32_t rawValue;
    struct
    {
        uint32_t Address:20;
        uint32_t Keys:4;
        uint32_t Detect:1;
        uint32_t Reserve:7;
    }Bits;
} ev1527_T;

void ev1527_Init(void);
void ev1527_deInit(void);

#endif