#include "usart.h"
#include "uart_driver.h"

#define Myhuart     huart1

uint8_t TxData[] = "uart1 trans it\r\n";
uint8_t RxData[2];

void UART_Transmit_IT_Test(void)
{
  HAL_UART_Transmit_IT(&huart1, TxData, 16);
}

void UART_Receive_IT_Test(void)
{
  HAL_UART_Receive_IT(&huart1, RxData, 2);    // 需要extern uint8_t RxData才可使用
}

int fputc(int ch, FILE *f)
{
  uint8_t temp[1] = {ch};
  HAL_UART_Transmit(&Myhuart, temp, 1, 2);
  return ch;
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
  if (huart->Instance == USART1)
  {
    printf("uart1 int callback\r\n");
  }
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  if (huart->Instance == USART1)
  {
    printf("rxdata[0] = %x, rxdata[1] = %x\r\n", RxData[0], RxData[1]);
    UART_Receive_IT_Test();
  }
}
