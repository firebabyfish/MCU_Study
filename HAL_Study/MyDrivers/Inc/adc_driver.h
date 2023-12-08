#ifndef __ADC_DRTVER_H
#define __ADC_DRTVER_H

#include "main.h"
#include "adc.h"

void ADC_Init(ADC_HandleTypeDef* hadc);
uint32_t ADC_Value(ADC_HandleTypeDef* hadc);
void ADC_Test(ADC_HandleTypeDef* hadc);
void ADC_IT_Test(ADC_HandleTypeDef* hadc);

#endif
