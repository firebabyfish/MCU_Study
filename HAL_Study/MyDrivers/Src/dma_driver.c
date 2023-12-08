#include "dma_driver.h"

uint16_t dma_adc[2];

void DMA_ADC_Test(void)
{
  HAL_ADC_Start_DMA(&hadc1, (uint32_t *)&dma_adc, 2);     // 开启DMA传输
  printf("ADC1 = %d, ADC2 = %d\r\n", dma_adc[0], dma_adc[1]);
  HAL_Delay(1000);
}
