#ifndef _Timer2_H_
#define _Timer2_H_

#include "aKaReZa.h"

#define Timer2_Reset TCNT2 = 0x00

void Timer2_Init(bool _initStatus);

#endif