#ifndef __I2C_DRIVER_H
#define __I2C_DRIVER_H

#include "main.h"

#define I2C_W_ENABLE      0   // 写控制位
#define I2C_R_ENABLE      1   // 读控制位

#define I2C_SCL_GPIO_Port     GPIOA
#define I2C_SDA_GPIO_Port     GPIOA
#define I2C_SCL_GPIO_Pin      GPIO_PIN_2
#define I2C_SDA_GPIO_Pin      GPIO_PIN_3

/* 直接操作寄存器的方法控制 IO */
#define digitalH(p,i) {p->BSRR=i;} //设置为高电平
#define digitalL(p,i) {p->BSRR=(uint32_t)i << 16;}//输出低电平

#define I2C_SCL_1()      digitalH(I2C_SCL_GPIO_Port, I2C_SCL_GPIO_Pin)
#define I2C_SCL_0()      digitalL(I2C_SCL_GPIO_Port, I2C_SCL_GPIO_Pin)
#define I2C_SDA_1()      digitalH(I2C_SDA_GPIO_Port, I2C_SDA_GPIO_Pin)
#define I2C_SDA_0()      digitalL(I2C_SDA_GPIO_Port, I2C_SDA_GPIO_Pin)
#define I2C_SDA_READ()   //GPIO_ReadInputDataBit(I2C_SDA_GPIO_Port, I2C_SDA_GPIO_Pin)

void I2C_Start(void);
void I2C_Stop(void);
void I2C_SendByte(uint8_t Byte);
uint8_t I2C_ReadByte(void);
uint8_t I2C_WaitAck(void);
void I2C_SendAck(void);
void I2C_SendNoAck(void);

#endif
