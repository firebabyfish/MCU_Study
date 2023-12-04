#include "pwm_driver.h"

int32_t count = 0;
uint8_t flag = 0;

void PWM_Set_Compare(uint32_t compare)
{
  PWM_TIM->CCR3 = compare;
}

void PWM_Test(void)
{
  if (!flag)
  {
    count += 10;
    if (count >= 1000)
    {
      count = 1000 - 1;
      flag = 1;
    }
  }
  else 
  {
    count -= 10;
    if (count <= 0)
    {
      count = 0;
      flag = 0;
    }
  }
  PWM_Set_Compare(count);
  HAL_Delay(20);
}
