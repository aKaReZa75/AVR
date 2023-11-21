#include <avr/io.h>
#include <util/delay.h>

#define setBit(Reg, Bit) (Reg |= (1<<Bit))
#define clearBit(Reg, Bit) (Reg &= ~(1<<Bit))
#define toggleBit(Reg, Bit) (Reg ^= (1<<Bit))
#define checkBit(Reg, Bit) ((Reg>>Bit) & 0x01)

int main(void)
{
    setBit(DDRB, 0); // Config PB0 as Output
    clearBit(DDRD, 0); // Config PD0 as Input
    clearBit(DDRD, 4); // Config PD4 as Input
    setBit(PORTD, 4); // Enable Internal Pull-up PD4
    clearBit(MCUCR, PUD); // Enbale Internal Pull-Up Feature
    while(1)
    {
        if(checkBit(PIND, 0)) // check if pushbutton is pressed (PD0 is Active High)
        {
            while(checkBit(PIND, 0)); // wait until pushbutton is release (PD0 is Active High)
            setBit(PORTB, 0); // Turn the led On
        };

        if(!checkBit(PIND, 4)) // check if pushbutton is pressed (PD4 is Active Low)
        {
            while(!checkBit(PIND, 4)); // wait until pushbutton is release (PD4 is Active Low)
            clearBit(PORTB, 0); // Turn the led Off
        };
    };
};