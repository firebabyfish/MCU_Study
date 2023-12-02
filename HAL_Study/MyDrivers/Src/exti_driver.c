#include "exti_driver.h"

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if (GPIO_Pin == KEY_2_Pin)
  {
    printf("key2 exti\r\n");
  }
}
