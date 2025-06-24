#include "adc.h"

int8_t adc_internalTemp(void)
{
    int8_t _Temp = 0;
    // Select Vbg(1.1v) as Refrence
    bitSet(ADMUX, REFS1);
    bitSet(ADMUX, REFS0);  
    // Set ADC Channel
    bitSet  (ADMUX, MUX3);
    bitClear(ADMUX, MUX2);
    bitClear(ADMUX, MUX1);
    bitClear(ADMUX, MUX0);
    delay_ms(10);
    bitSet(ADCSRA, ADSC);         // Start the ADC
    bitWaitHigh(ADCSRA, ADIF);    // Wait until ADC conversion
    intFlag_clear(ADCSRA, ADIF);  // Clear ADC Flag
    _Temp = 0.782*Combine_8to16(ADCH, ADCL) - 250;
    return _Temp;    
};

uint16_t adc_Read(uint8_t _adcChannel)
{
    // Select Avcc as Refrence
    bitClear(ADMUX, REFS1);
    bitSet  (ADMUX, REFS0);    
    // Set ADC Channel
    bitChange(ADMUX, MUX3, bitCheck(_adcChannel, 3));
    bitChange(ADMUX, MUX2, bitCheck(_adcChannel, 2));
    bitChange(ADMUX, MUX1, bitCheck(_adcChannel, 1));
    bitChange(ADMUX, MUX0, bitCheck(_adcChannel, 0));
    delay_ms(1);
    bitSet(ADCSRA, ADSC);          // Start the ADC
    bitWaitHigh(ADCSRA, ADIF);     // Wait until ADC conversion
    intFlag_clear(ADCSRA, ADIF);   // Clear ADC Flag
    return Combine_8to16(ADCH, ADCL);
};


void adc_Init(bool _initStatus)
{
    if(_initStatus)
    {
        // set Prescaler to 128
        bitSet(ADCSRA, ADPS2);
        bitSet(ADCSRA, ADPS1);
        bitSet(ADCSRA, ADPS0);
        // Select Avcc as Refrence
        bitClear(ADMUX, REFS1);
        bitSet  (ADMUX, REFS0);
        bitClear(ADMUX, ADLAR); // Right Adj resualt
        bitSet(ADCSRA , ADEN);   // Enbale the ADC
    }
    else
    {
        bitClear(ADCSRA, ADPS2);
        bitClear(ADCSRA, ADPS1);
        bitClear(ADCSRA, ADPS0);
        bitClear(ADMUX , REFS1);
        bitClear(ADMUX , REFS0);
        bitClear(ADCSRA, ADEN); 
    };
};
