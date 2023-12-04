#include "mydrivers.h"

void test1(void)
{
  IWDG_Test();
}

void test2(void)
{
  LED_2_Toggle();
  Buzzer_Solo();
}
