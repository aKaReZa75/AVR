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



ISR(TIMER1_CAPT_vect)
{
  static bool firstTime_Trigger = true;
  Timer1_Reset;  
  if(firstTime_Trigger)
  {
    firstTime_Trigger = false;
    bitClear(TCCR1B, ICES1); /* Capture on Falling Edge */
  }
  else
  {
    if(bitCheck(TCCR1B, ICES1)) // Rising Edge
    {
      bitSet(TCCR1B, ICES1); /* Capture on Risiing Edge */
      Signal_Low_Tick = ICR1;
      measureDone = true;
      firstTime_Trigger = true;
    }
    else  // Falling edge
    {
      Signal_High_Tick = ICR1;
      bitSet(TCCR1B, ICES1); /* Capture on Risiing Edge */
    }
  };
};




int main(void)
{
  usart_Init(Initialize);
  usart_Putsln("aKaReZa"); 

  /* Timer1: Mode Normal*/
  bitClear(TCCR1A, WGM10);
  bitClear(TCCR1A, WGM11);
  bitClear(TCCR1B, WGM12);

  /* Timer1: Prescaler: 8 => Fclk/N => 16Mhz/8=2Mhz or 0.5uS*/
  bitClear(TCCR1B, CS10);
  bitSet(TCCR1B, CS11);
  bitClear(TCCR1B, WGM12); 

  bitSet(TCCR1B, ICES1); /* Capture on Risiing Edge */
  bitSet(TIMSK1, ICIE1); /* Enable Capture interrupt*/

  intFlag_clear(TIFR1, ICF1);

  globalInt_Enable;

  while(1)
  {
    if(measureDone)
    {
      Signal_Period_Tick = Signal_Low_Tick + Signal_High_Tick;
      Singal_Period = (float)(Signal_Period_Tick * 0.5e-6);
      Signal_Frequency = (float)(1.0/Singal_Period);
      Signal_Duty = (float)(Signal_High_Tick*100.0/Signal_Period_Tick);
      sprintf(debugBuffer, "High: %u, Low: %u, Period: %u Tick, Period: %1.10f S, Freq: %1.2f Hz, duty:%1.2f%%", Signal_High_Tick, Signal_Low_Tick ,Signal_Period_Tick, Singal_Period, Signal_Frequency, Signal_Duty);
      usart_Putsln(debugBuffer);
      measureDone = false;
    };
    delay_ms(100);
  };
};