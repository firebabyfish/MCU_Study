#include "tim_driver.h"

void Systick_Test(void)
{
  static uint16_t i = 0;
  if (++i == 1000)
  {
    printf("systick int\r\n");
    i = 0;
  }
}

void HAL_SYSTICK_Callback(void)       // 需要添加HAL_SYSTICK_IRQHandler()到SysTick_Handler()中
{
  Systick_Test();
}
