#ifndef __EEPROM_DRIVER_H
#define __EEPROM_DRIVER_H

#include "i2c_driver.h"

#define EEPROM_W_ENABLE      0   // 写控制位
#define EEPROM_R_ENABLE      1   // 读控制位

#define EEPROM_DEV_ADRESS        0xA0

#define EEPROM_SCL_GPIO_Port     GPIOA
#define EEPROM_SDA_GPIO_Port     GPIOA
#define EEPROM_SCL_GPIO_Pin      GPIO_PIN_2
#define EEPROM_SDA_GPIO_Pin      GPIO_PIN_3

#define EEPROM_SCL_1()      digitalH(EEPROM_SCL_GPIO_Port, EEPROM_SCL_GPIO_Pin)
#define EEPROM_SCL_0()      digitalL(EEPROM_SCL_GPIO_Port, EEPROM_SCL_GPIO_Pin)
#define EEPROM_SDA_1()      digitalH(EEPROM_SDA_GPIO_Port, EEPROM_SDA_GPIO_Pin)
#define EEPROM_SDA_0()      digitalL(EEPROM_SDA_GPIO_Port, EEPROM_SDA_GPIO_Pin)
#define EEPROM_SDA_READ()   // GPIO_ReadInputDataBit(EEPROM_SDA_GPIO_Port, EEPROM_SDA_GPIO_Pin)

#endif
