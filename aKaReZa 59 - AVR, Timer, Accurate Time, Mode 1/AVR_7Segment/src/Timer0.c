#include "Timer0.h"

extern uint16_t Counter;

ISR(TIMER0_OVF_vect)
{
    static uint16_t timCount = 0;
    Seg7_Puts(Counter); 
    timCount++;
    if(timCount == 977)
    {
        Counter++;
        if(Counter>9999) Counter = 0;
        timCount = 0;
    };
};

void Timer0_Init(bool _initStatus)
{
    if(_initStatus)
    {
        // Timer0 => Mode(0) => Normal
        bitClear(TCCR0A, WGM00);
        bitClear(TCCR0A, WGM01);
        bitClear(TCCR0B, WGM02);
        // Prescaler = 64 => 16Mhz/64=250KHz
        bitSet  (TCCR0B, CS00);
        bitSet  (TCCR0B, CS01);
        bitClear(TCCR0B, CS02);
        bitSet  (TIMSK0, TOIE0);  // Enbale Timer0 ovfInt 1.024ms
        intFlag_clear(TIMSK0, TOIE0);   
    }
    else
    {
        bitClear(TCCR0A, WGM00);
        bitClear(TCCR0A, WGM01);
        bitClear(TCCR0B, WGM02);
        bitClear(TCCR0B, CS00);
        bitClear(TCCR0B, CS01);
        bitClear(TCCR0B, CS02);
        bitClear(TIMSK0, TOIE0);
    };
};
