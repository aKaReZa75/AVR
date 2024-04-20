#include "eInterrupt.h"

extern uint16_t Counter;


ISR(INT0_vect)  //eInt0 (SW1)
{
    Counter += 1000;
};


ISR(INT1_vect)  //eInt0 (SW2)
{
    Counter += 100;
};


ISR(PCINT0_vect) //pcInt0 (SW3)
{
    static bool _pcINT0_Status = true; // true => falling edge, false => rising edge
    _pcINT0_Status = !_pcINT0_Status;
    if(_pcINT0_Status)   Counter +=10;
};


void eINT0_Init(bool _initStatus)
{
    if(_initStatus)  // Init
    {    
        bitSet(EIMSK, INT0);    // Enbale eInt0 (SW1)
        // Falling edge on eInt0
        bitSet(EICRA, ISC01);
        bitClear(EICRA, ISC00);
    }
    else
    {
        bitClear(EIMSK, INT0);   
        bitClear(EICRA, ISC01);
        bitClear(EICRA, ISC00);
    };
};


void eINT1_Init(bool _initStatus)
{
    if(_initStatus)  // Init
    {
        bitSet(EIMSK, INT1);    // Enbale eInt1 (SW2)
        // Rising edge on eInt1
        bitSet(EICRA, ISC11);
        bitSet(EICRA, ISC10);
        intFlag_clear(EIFR, INTF1);
    }
    else    // deInit
    {
        bitClear(EIMSK, INT1);   
        bitClear(EICRA, ISC11);
        bitClear(EICRA, ISC10);        
    };
};


void pcINT0_Init(bool _initStatus)
{
    if(_initStatus)  // Init
    {      
        bitSet(PCICR , PCIE0);   // Enbale pcInt0 (SW3)
        bitSet(PCMSK0, PCINT5); // Enbale pcInt5    
    }
    else    // deInit
    {
        bitClear(PCICR ,  PCIE0);   
        bitClear(PCMSK0, PCINT5);   
    }
};
