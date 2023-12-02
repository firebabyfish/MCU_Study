#ifndef __KEY_DRIVER_H
#define __KEY_DRIVER_H

#include "main.h"

#define  KEY_1_ON        HAL_GPIO_ReadPin(KEY_1_GPIO_Port, KEY_1_Pin)
#define  KEY_2_ON        HAL_GPIO_ReadPin(KEY_2_GPIO_Port, KEY_2_Pin)
#define  KEY_ON          (KEY_1_ON || KEY_2_ON)
#define  KEY_FALLING     0      // 下降沿触发
#define  KEY_RISING      1      // 上升沿触发
#define  KEY_1_FLAG      1
#define  KEY_2_FLAG      2

uint8_t Key_Value(void);
uint8_t KEY_Scan(uint8_t KEY_MODE);
void Key_Action(uint8_t KeyMode);

#endif
