#include "aKaReZa.h"

const uint8_t customChar0[] = {0x00, 0x00, 0x0A, 0x00, 0x11, 0x0E, 0x00, 0x00};  // smiley
const uint8_t customChar1[] = {0x0E, 0x0E, 0x04, 0x0E, 0x15, 0x04, 0x0A, 0x0A};  // Robo
const uint8_t customChar2[] = {0x00, 0x00, 0x0A, 0x15, 0x11, 0x0E, 0x04, 0x00};  // Heart
const uint8_t customChar3[] = {0x00, 0x15, 0x15, 0x1F, 0x10, 0x10, 0x10, 0x00};  // Num 3
const uint8_t customChar4[] = {0x00, 0x00, 0x00, 0x00, 0x03, 0x14, 0x13, 0x1E};  // I
const uint8_t customChar5[] = {0x00, 0x00, 0x00, 0x00, 0x03, 0x02, 0x04, 0x18};  // R
const uint8_t customChar6[] = {0x05, 0x00, 0x07, 0x05, 0x1F, 0x00, 0x00, 0x00};  // Q
const uint8_t customChar7[] = {0x10, 0x10, 0x10, 0x11, 0x1F, 0x00, 0x06, 0x06};  // B A

char alcd[17];

int main(void)
{
    alcd_init();
    alcd_customChar(0, customChar0);
    alcd_customChar(1, customChar1);
    alcd_customChar(2, customChar2);
    alcd_customChar(3, customChar3);
    alcd_customChar(4, customChar4);
    alcd_customChar(5, customChar5);
    alcd_customChar(6, customChar6);
    alcd_customChar(7, customChar7);

    alcd_gotoxy(0, 0);
    alcd_puts("alcd Custom Char");
    alcd_gotoxy(9, 1);
    alcd_puts("Hossein");

    alcd_gotoxy(8, 1); 
    alcd_putc(7); // B A
    alcd_gotoxy(7, 1); 
    alcd_putc(6); // Q
    alcd_gotoxy(6, 1); 
    alcd_putc(5); // R
    alcd_gotoxy(5, 1);
    alcd_putc(4); // I

    alcd_gotoxy(3, 1); 
    alcd_putc(3); // Clock
    alcd_gotoxy(2, 1); 
    alcd_putc(2); // Heart
    alcd_gotoxy(1, 1); 
    alcd_putc(1); // Robo
    alcd_gotoxy(0, 1); 
    alcd_putc(0); // smiley  
    while(1)
    {

    };
};
