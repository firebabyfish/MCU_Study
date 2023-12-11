#ifndef __SPI_DRIVER_H
#define __SPI_DRIVER_H

#include "main.h"
#include "spi.h"

#define SPI1_NSS_LOW()           HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_RESET)
#define SPI1_NSS_HIGH()          HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_SET)

#endif
