
#include "aKaReZa.h"

#define Timer1_Reset TCNT1 = 0x0000

volatile bool measureDone = false;
volatile uint16_t Signal_Period_Tick = 0; 
volatile uint16_t Signal_High_Tick   = 0;
volatile uint16_t Signal_Low_Tick   = 0;
float Singal_Period = 0.0;
float Signal_Frequency = 0.0;
float Signal_Duty = 0.0;
char debugBuffer[100];


/* External interrupt service routine for INT0 */
ISR(INT0_vect) 
{
  static bool firstTime_Trigger = true;
  if(firstTime_Trigger)
  {
    Timer1_Reset;
    firstTime_Trigger = false;
    bitClear(EICRA, ISC00); // Falling Edge
  }
  else
  {
    if(bitCheck(EICRA, ISC00)) // Rising Edge
    {
      Signal_Low_Tick = TCNT1;
      measureDone = true;
      firstTime_Trigger = true;
    }
    else  // Falling edge
    {
      Signal_High_Tick = TCNT1;
      Timer1_Reset;
      bitSet(EICRA, ISC00); // Rising Edge
    }
  };
};


int main(void)
{
  usart_Init(Initialize);
  usart_Putsln("aKaReZa"); 

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

  globalInt_Enable;

  while(1)
  {
    if(measureDone)
    {
      Signal_Period_Tick = Signal_Low_Tick + Signal_High_Tick;
      Singal_Period = (float)(Signal_Period_Tick * 0.5e-6);
      Signal_Frequency = (float)(1.0/Singal_Period);
      Signal_Duty = (float)(Signal_High_Tick*100/Signal_Period_Tick);
      sprintf(debugBuffer, "Period: %u Tick, Period: %1.10f S, Freq: %1.2f Hz, duty:%1.2f%%", Signal_Period_Tick, Singal_Period, Signal_Frequency, Signal_Duty);
      usart_Putsln(debugBuffer);
      measureDone = false;
    };
    delay_ms(100);
  };
};