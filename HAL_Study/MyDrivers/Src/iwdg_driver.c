#include "iwdg_driver.h"

void IWDG_Test(void)
{
  HAL_IWDG_Refresh(&hiwdg);
}
