#include "Timer0.h"

ISR(TIMER0_OVF_vect)
{
    TCNT0 = 6;
};

void Timer0_Init(bool _initStatus)
{
    if(_initStatus)
    {
        // Timer0 => Mode(0) => Normal
        bitClear(TCCR0A, WGM00);
        bitClear(TCCR0A, WGM01);
        bitClear(TCCR0B, WGM02);
        // OC0A in toogle Mode
        bitSet  (TCCR0A, COM0A0);
        bitClear(TCCR0A, COM0A1);
        GPIO_Config_OUTPUT(DDRD, 6);
        // Prescaler = 64 => 16Mhz/64=250KHz
        bitSet  (TCCR0B, CS00);
        bitSet  (TCCR0B, CS01);
        bitClear(TCCR0B, CS02);
        bitSet  (TIMSK0, TOIE0);  // Enbale Timer0 ovfInt
        globalInt_Enable;

        OCR0A = 0xFF;
        TCNT0 = 6;
    }
    else
    {

    };
};
