#include "aKaReZa.h"

#define Vref 5.143
#define Volt_Gain  0.005027  // Vref/1023
#define LM35_Gain  0.5027    // (Vref/1023)/10

char usart_Buffer[10];
uint16_t ADC_Raw = 0;
float Voltage = 0.0;
float Temp = 0.0;

int main(void)
{
  usart_Init(Initialize);
  adc_Init  (Initialize);
  while(1)
  {
    usart_Putsln("----------------");

    ADC_Raw = adc_Read(0);
    Voltage = ADC_Raw * Volt_Gain;
    sprintf(usart_Buffer, "POT: %u, %0.3f", ADC_Raw, Voltage);
    usart_Putsln(usart_Buffer);

    ADC_Raw = adc_Read(1);
    sprintf(usart_Buffer, "LDR: %u", ADC_Raw);
    usart_Putsln(usart_Buffer);  

    ADC_Raw = adc_Read(2);
    Temp = ADC_Raw * LM35_Gain;
    sprintf(usart_Buffer, "LM35: %u, %0.1f", ADC_Raw, Temp);
    usart_Putsln(usart_Buffer); 
    
    ADC_Raw = adc_Read(14);
    Voltage = ADC_Raw * Volt_Gain;
    sprintf(usart_Buffer, "1.1V: %u, %0.3f", ADC_Raw, Voltage);
    usart_Putsln(usart_Buffer); 

    sprintf(usart_Buffer, "Temp: %d", adc_internalTemp());
    usart_Putsln(usart_Buffer);

    delay_ms(500);
  };
};