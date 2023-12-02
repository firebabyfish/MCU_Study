#include "usart.h"
#include "uart_driver.h"

#define Myhuart     huart1

int fputc(int ch, FILE *f)
{
  uint8_t temp[1] = {ch};
  HAL_UART_Transmit(&Myhuart, temp, 1, 2);
  return ch;
}
