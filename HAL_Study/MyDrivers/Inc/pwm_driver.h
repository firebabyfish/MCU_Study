#ifndef __PWM_DRIVER_H
#define __PWM_DRIVER_H

#include <main.h>

#define PWM_TIM       TIM2

void PWM_Set_Compare(uint32_t compare);
void PWM_Test(void);

#endif
