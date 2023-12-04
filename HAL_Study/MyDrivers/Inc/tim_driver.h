#ifndef __TIM_DRIVER_H
#define __TIM_DRIVER_H

#include "main.h"

void Systick_Test(void);
void TIM_Base_Start_IT_Test(TIM_HandleTypeDef *htim);
void HAL_TIM_IC_Start_IT_Test(TIM_HandleTypeDef *htim, uint32_t Channel);

#endif
