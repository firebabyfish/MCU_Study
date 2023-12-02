#include "led_driver.h"
#include "gpio.h"

void LED_1_Flash(void)
{
  HAL_GPIO_TogglePin(LED_1_GPIO_Port, LED_1_Pin);
  HAL_Delay(500);
}

void LED_1_ON(void)
{
  HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_RESET);
}

void LED_1_OFF(void)
{
  HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_SET);
}

void LED_1_Toggle(void)
{
  HAL_GPIO_TogglePin(LED_1_GPIO_Port, LED_1_Pin);
}

void LED_2_Flash(void)
{
  HAL_GPIO_TogglePin(LED_2_GPIO_Port, LED_2_Pin);
  HAL_Delay(500);
}

void LED_2_ON(void)
{
  HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_RESET);
}

void LED_2_OFF(void)
{
  HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_SET);
}

void LED_2_Toggle(void)
{
  HAL_GPIO_TogglePin(LED_2_GPIO_Port, LED_2_Pin);
}
