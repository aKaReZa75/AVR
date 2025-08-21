#include "Timer2.h"

void Timer2_Init(bool _initStatus)
{
    if(_initStatus)
    {
        /* Mode: Normal */
        bitClear(TCCR2A, WGM20);
        bitClear(TCCR2A, WGM21);
        bitClear(TCCR2B, WGM22);

        /* Reset Timer2 int Flag */
        intFlag_clear(TIFR2, TOV2);

        /* Enbale Timer2 OVF */
        bitSet(TIMSK2, TOIE2);

        TCNT2 = 0x00;

        /* Prescaler: 8 => 16Mhz/8= 128uS */
        bitClear(TCCR2B, CS20);   
        bitSet(TCCR2B, CS21); 
        bitClear(TCCR2B, CS22);
        
        GPIO_Config_OUTPUT(DDRD, 2);
        bitSet(PORTD, 2);
    }
    else
    {
        bitClear(TCCR2A, WGM20);
        bitClear(TCCR2A, WGM21);
        bitClear(TCCR2B, WGM22);
        bitClear(TIMSK2, TOIE2);
        bitClear(TCCR2B, CS20);   
        bitClear(TCCR2B, CS21); 
        bitClear(TCCR2B, CS22);  
        TCNT2 = 0x00;
        bitClear(PORTD, 2);
    };
};