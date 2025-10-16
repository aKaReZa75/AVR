#include "aKaReZa.h"

extern volatile uint32_t System_millis;

void Task1(void)
{
  static millis_T Task1_Millis = {.Delta=0, .Interval=1000, .Previous = 0};
  Task1_Millis.Delta = System_millis - Task1_Millis.Previous;
  if(Task1_Millis.Delta > Task1_Millis.Interval)
  {
    Task1_Millis.Previous = System_millis;
    bitToggle(PORTC, 0);
  };
};

void Task2(void)
{
  static millis_T Task2_Millis = {.Delta=0, .Interval=350, .Previous = 0};
  Task2_Millis.Delta = System_millis - Task2_Millis.Previous;
  if(Task2_Millis.Delta > Task2_Millis.Interval)
  {
    Task2_Millis.Previous = System_millis;
    bitToggle(PORTC, 1);
  };
};

void Task3(void)
{
  static millis_T Task3_Millis = {.Delta=0, .Interval=5000, .Previous = 0};
  Task3_Millis.Delta = System_millis - Task3_Millis.Previous;
  if(Task3_Millis.Delta > Task3_Millis.Interval)
  {
    Task3_Millis.Previous = System_millis;
    bitClear(PORTC, 2);
  };
};

void Task4(void)
{
  static millis_T Task4_Millis = {.Delta = 0, .Interval = 100, .Previous = 0};
  char alcd_Buffer[17];
  Task4_Millis.Delta = System_millis - Task4_Millis.Previous;
  if(Task4_Millis.Delta >= Task4_Millis.Interval)
  {
    Task4_Millis.Previous = System_millis;
    sprintf(alcd_Buffer, "miilis=%ld", System_millis);
    alcd_gotoxy(0, 0);
    alcd_puts(alcd_Buffer);
  };
};

int main(void)
{
  millis_Init();
  globalInt_Enable;

  alcd_init();
  alcd_puts("aKaReZa");
  GPIO_Config_OUTPUT(DDRC, 0);
  GPIO_Config_OUTPUT(DDRC, 1);
  GPIO_Config_OUTPUT(DDRC, 2);
  bitSet(PORTC, 2);
  while(1)
  {
    Task1();
    Task2();
    Task3();
    Task4();
  };
};