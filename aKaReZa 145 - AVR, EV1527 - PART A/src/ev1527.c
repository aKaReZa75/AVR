#include "ev1527.h"

volatile ev1527_T ev1527_Data = {.rawValue = 0x0};

/* External interrupt service routine for INT0 */
ISR(INT0_vect) 
{
  GPIO_Config_OUTPUT(DDRC, 0);
  bitSet(PORTC, 0);
  bitClear(PORTC, 0);
  static bool firstTime_Trigger = true;
  static bool measureDone = false;
  static bool preambleDetec = false;
  static uint8_t _Index = 0;
  static uint16_t Signal_High_Tick   = 0;
  static uint16_t Signal_Low_Tick   = 0;

  if(firstTime_Trigger)
  {
    Signal_High_Tick = 0x00;
    Signal_Low_Tick  = 0x00;
    _Index = 0;
    ev1527_Data.rawValue = 0x0;
    preambleDetec = false;
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
      if(EV_pulseIsValid(Signal_Low_Tick, Signal_High_Tick))
      {
        bitChange(ev1527_Data.rawValue, _Index, EV_bitCheck(Signal_Low_Tick, Signal_High_Tick));
        _Index++;

        if(_Index > EV_maxIndexData)
        {
          ev1527_Data.Bits.Detect = true;
          firstTime_Trigger = true;
          preambleDetec     = false;
          ev1527_deInit();
        };
      }
      else
      {
        firstTime_Trigger = true;
        preambleDetec     = false;
        bitSet(EICRA, ISC00); // Rising Edge        
      };
    }
    else
    {
        if(EV_PrembleCheck(Signal_Low_Tick, Signal_High_Tick))
        {   
            preambleDetec = true;
        }
        else
        {

        } ; 
    };
    
    EV_Timer_Reset;
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