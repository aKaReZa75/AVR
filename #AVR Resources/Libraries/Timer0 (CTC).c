/* @file     Timer0.c                                 */                      
/* @brief    AVR microcontollers Tiemr0_CTC Source    */
/* @note     This file is for _AVR_ microcontrollers  */   
/* @author   Hossein Bagheri                          */
/* @github   aKaReZa75                                */
/* @youtube  aKaReZa75                                */
/* @linkedin aKaReZa75                                */
/* @email    aKaReZa75@gmail.com                      */

#include "Timer.h"

ISR(TIMER0_COMPA_vect)
{
    static uint16_t timCont = 0;
    timCont++; 
    if(timCont == 1000)
    {
        bitToggle(DDRB, 5);
        timCont = 0;
    };
};

void Timer0_Init(bool _initStatus)
{
    if(_initStatus)
    {
        // Timer0 => Mode(2) => CTC
        bitClear(TCCR0A, WGM00);
        bitSet  (TCCR0A, WGM01);
        bitClear(TCCR0B, WGM02);
        // OC0A in toogle Mode
        bitSet  (TCCR0A, COM0A0);
        bitClear(TCCR0A, COM0A1);
        GPIO_Config_OUTPUT(DDRD, 6);
        // Prescaler = 64 => 16Mhz/64=250KHz
        bitSet  (TCCR0B, CS00);
        bitSet  (TCCR0B, CS01);
        bitClear(TCCR0B, CS02);
        bitSet(TIMSK0, OCIE0A); // Compare match int
        intFlag_clear(TIFR0, OCF0A);       
        OCR0A = 249;  // 1mS
        
        globalInt_Enable;

        GPIO_Config_OUTPUT(DDRB, 5);
    
    }
    else
    {
        bitClear(TCCR0A, WGM00);
        bitClear(TCCR0A, WGM01);
        bitClear(TCCR0B, WGM02);
        bitClear  (TCCR0A, COM0A0);
        bitClear(TCCR0A, COM0A1);
        GPIO_Config_INPUT(DDRD, 6);
        bitClear(TCCR0B, CS00);
        bitClear(TCCR0B, CS01);
        bitClear(TCCR0B, CS02);
        bitClear(TIMSK0, OCIE0A); 
        OCR0A = 0; 
    };
};
