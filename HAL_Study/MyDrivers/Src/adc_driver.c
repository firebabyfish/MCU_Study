#include "adc_driver.h"

void ADC_Init(ADC_HandleTypeDef* hadc)
{
  HAL_ADCEx_Calibration_Start(hadc);    // ADC采样校准，只需要校准一次便可重复采样
}

uint32_t ADC_Value(ADC_HandleTypeDef* hadc)
{
  HAL_ADC_Start(hadc);    // 开始ADC采集
  /* 轮询方式 */
  HAL_ADC_PollForConversion(hadc, 500);      // 等待采集结束
  if (HAL_IS_BIT_SET(HAL_ADC_GetState(hadc), HAL_ADC_STATE_REG_EOC))    // 读取ADC完成标志位
  {
    return HAL_ADC_GetValue(hadc);      // 读出ADC数值并返回
  }
  return 0;
}

void ADC_Test(ADC_HandleTypeDef* hadc)
{
  printf("adc_value = %d\r\n", ADC_Value(hadc));      // 将采集到的ADC数值打印到串口
  HAL_Delay(1000);
}

void ADC_IT_Test(ADC_HandleTypeDef* hadc)
{
  HAL_ADC_Start_IT(hadc);       // 开始ADC采集，每次开始采集都触发一次中断
  HAL_Delay(1000);
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
  if (hadc->Instance == ADC1)     // 判断中断来源
  {
    printf("adc_value = %d\r\n", HAL_ADC_GetValue(hadc));
  }
}
