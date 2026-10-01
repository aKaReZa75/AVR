#ifndef _ev1527_H_
#define _ev1527_H_

#include "aKaReZa.h"

#define EV_Timer_Reset TCNT1 = 0x0000
#define EV_Timer_Value TCNT1
#define EV_maxIndexData  23

#define EV_PrembleCheck(_tickLow, _tickHigh)  ((_tickLow  >= 25*_tickHigh) && (_tickLow <= 40*_tickHigh))
#define EV_bitCheck(_tickLow, _tickHigh)      ((_tickHigh >= 2*_tickLow) ? 1:0)

void ev1527_Init(void);
void ev1527_deInit(void);

#endif