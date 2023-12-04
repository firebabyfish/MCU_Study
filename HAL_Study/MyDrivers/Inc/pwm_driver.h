#ifndef __PWM_DRIVER_H
#define __PWM_DRIVER_H

#include <main.h>

#define PWM_CCR       TIM2->CCR3

void PWM_Set_Compare(uint32_t compare);
void PWM_Test(void);

#endif
