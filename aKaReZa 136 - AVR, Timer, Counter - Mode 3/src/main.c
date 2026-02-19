#include "aKaReZa.h"

char debugBuffer[30];
volatile uint32_t Frequency = 0;
volatile bool measureDone = false;
volatile uint16_t Timer1_OVF_Coutner = 0;

ISR(TIMER1_OVF_vect)
{
  Timer1_OVF_Coutner++;
};


ISR(TIMER2_OVF_vect)
{
  Frequency = (Timer1_OVF_Coutner*65536) + TCNT1;
  Frequency *= 16;
  TCNT1 = 0;
  Timer1_OVF_Coutner = 0;
  measureDone = true;
};


int main(void)
{
  usart_Init(Initialize);

  /* Timer1, Mode: Normal */
  bitClear(TCCR1A, WGM10);
  bitClear(TCCR1A, WGM11);
  bitClear(TCCR1B, WGM12);

  /* Prescaler: None, Clock Soure: T1-Rising Edge */
  bitSet(TCCR1B, CS10);
  bitSet(TCCR1B, CS11);
  bitSet(TCCR1B, CS12); 

  bitSet(TIMSK1, TOIE1);

  /* Timer2, Mode: External Oscilator */
  bitClear(ASSR, EXCLK);        
  bitSet(ASSR, AS2);   
  bitWaitLow(ASSR, TCR2AUB);
  bitWaitLow(ASSR, TCR2BUB);
  bitClear(TCCR2A, WGM20);
  bitClear(TCCR2A, WGM21);
  bitClear(TCCR2B, WGM22);

  /* Prescaler: 128, 32768Hz/128=256Hz */
  bitClear(TCCR2B, CS20);
  bitSet  (TCCR2B, CS21);
  bitClear(TCCR2B, CS22);  

  bitSet(TIMSK2, TOIE2);

  globalInt_Enable;

  usart_Putsln("Ready...");
  while(1)
  {
    if(measureDone)
    {
      sprintf(debugBuffer, "Frequency: %lu", Frequency);
      usart_Putsln(debugBuffer);
      measureDone = false;
    }
  };
};