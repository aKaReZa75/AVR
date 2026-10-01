#include "ev1527.h"

volatile bool     ev1527_Detec = false;
volatile uint16_t Signal_High_Tick   = 0;
volatile uint16_t Signal_Low_Tick   = 0;
volatile uint32_t ev1527_Data = 0x0;

/* External interrupt service routine for INT0 */
ISR(INT0_vect) 
{
  static bool firstTime_Trigger = true;
  static bool measureDone = false;
  static bool preambleDetec = false;
  static uint8_t _Index = 0;
  if(firstTime_Trigger)
  {
    EV_Timer_Reset;
    firstTime_Trigger = false;
    bitClear(EICRA, ISC00); // Falling Edge
  }
  else
  {
    if(bitCheck(EICRA, ISC00)) // Rising Edge
    {
      Signal_Low_Tick = EV_Timer_Value;
      measureDone = true;
      bitClear(EICRA, ISC00); // Falling Edge
    }
    else  // Falling edge
    {
      Signal_High_Tick = EV_Timer_Value;
      EV_Timer_Reset;
      bitSet(EICRA, ISC00); // Rising Edge
    }
  };

  if(measureDone)
  {
    if(preambleDetec)
    {
        bitChange(ev1527_Data, _Index, EV_bitCheck(Signal_Low_Tick, Signal_High_Tick));
        _Index++;

        if(_Index >= EV_maxIndexData)
        {
            ev1527_Detec = true;
            firstTime_Trigger = true;
            preambleDetec     = false;
            ev1527_deInit();
        };   
    }
    else
    {
        if(EV_PrembleCheck(Signal_Low_Tick, Signal_High_Tick))
        {   
            preambleDetec = true;
        };
    };

    measureDone = false;
  };
};


void ev1527_Init(void)
{
  /* Set INT0 to trigger on rising edge */
  bitSet(EICRA, ISC00);
  bitSet(EICRA, ISC01);

  /* Enable external interrupts for INT0*/
  bitSet(EIMSK, INT0);

  /* Timer1: Mode Normal*/
  bitClear(TCCR1A, WGM10);
  bitClear(TCCR1A, WGM11);
  bitClear(TCCR1B, WGM12);
  
  /* Timer1: Prescaler: 8 => Fclk/N => 16Mhz/8=2Mhz or 0.5uS*/
  bitClear(TCCR1B, CS10);
  bitSet(TCCR1B, CS11);
  bitClear(TCCR1B, WGM12); 
};


void ev1527_deInit(void)
{
  /* Disbale INT0 */
  bitClear(EICRA, ISC00);
  bitClear(EICRA, ISC01);

  /* Disable external interrupts for INT0*/
  bitClear(EIMSK, INT0);

  /* Disable Timer1*/
  bitClear(TCCR1A, WGM10);
  bitClear(TCCR1A, WGM11);
  bitClear(TCCR1B, WGM12);
  bitClear(TCCR1B, CS10);
  bitClear(TCCR1B, CS11);
  bitClear(TCCR1B, WGM12); 
};