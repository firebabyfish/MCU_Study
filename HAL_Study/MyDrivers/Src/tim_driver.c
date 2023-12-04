#include "tim_driver.h"
#include "tim.h"

uint8_t IC_Falling_Flag = 0;      // 下降沿捕获标记位
uint32_t  Capture_Value = 0;

void Systick_Test(void)
{
  static uint16_t i = 0;
  if (++i == 1000)
  {
    printf("systick int\r\n");
    i = 0;
  }
}

void TIM_Base_Start_IT_Test(TIM_HandleTypeDef *htim)
{
  HAL_TIM_Base_Start_IT(htim);
}

void HAL_TIM_IC_Start_IT_Test(TIM_HandleTypeDef *htim, uint32_t Channel)
{
  HAL_TIM_IC_Start_IT(htim, TIM_CHANNEL_3);
}

void HAL_SYSTICK_Callback(void)       // 需要添加HAL_SYSTICK_IRQHandler()到SysTick_Handler()中
{
  Systick_Test();
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if (htim->Instance == TIM2)
  {
    if (IC_Falling_Flag)
    {
      Capture_Value += 1000;
    }
  }
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
  if (htim->Instance == TIM2)
  {
    if (!IC_Falling_Flag)
    {
      IC_Falling_Flag = 1;
      __HAL_TIM_DISABLE(htim);      // 关闭定时器

      __HAL_TIM_SET_COUNTER(htim, 0);       // 设置计数器的值为0

      TIM_RESET_CAPTUREPOLARITY(htim, TIM_CHANNEL_3);         // 清除原来的设置

      TIM_SET_ICPRESCALERVALUE(htim, TIM_CHANNEL_3, TIM_INPUTCHANNELPOLARITY_RISING);       //设置为上升沿捕获

      __HAL_TIM_ENABLE(htim);       // 使能定时器
    }
    else 
    {
      IC_Falling_Flag = 0;
      Capture_Value = (Capture_Value + HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_3));
      // printf("低电平持续的时间：%ds:%dms:%us\r\n", Capture_Value/1000000, Capture_Value%1000000/1000, Capture_Value%1000);
      __HAL_TIM_DISABLE(htim);      // 关闭定时器

      TIM_RESET_CAPTUREPOLARITY(htim, TIM_CHANNEL_3);         // 清除原来的设置

      TIM_SET_ICPRESCALERVALUE(htim, TIM_CHANNEL_3, TIM_INPUTCHANNELPOLARITY_FALLING);       //设置为下降沿捕获

      __HAL_TIM_ENABLE(htim);       // 使能定时器
    }
  }
}
