// #include "i2c_driver.h"

// /* 开启I2C总线信号 */
// void I2C_Start(void)
// {
//   I2C_SDA_1();
//   I2C_SCL_1();
//   Delay_us(5);
//   I2C_SDA_0();
//   Delay_us(5);
//   I2C_SCL_0();
//   Delay_us(5);
// }

// /* 停止I2C总线信号 */
// void I2C_Stop(void)
// {
//   I2C_SDA_0();
//   I2C_SCL_1();
//   Delay_us(5);
//   I2C_SDA_1();
// }

// /* 主机向从机发送8bit位数据 */
// void I2C_SendByte(uint8_t Byte)
// {
//   for (uint8_t i = 0; i < 8; i++)
//   {
//     if (Byte & (0x80 >> i))
//     {
//       I2C_SDA_1();
//     }
//     else 
//     {
//       I2C_SDA_0();
//     }
//     Delay_us(5);
//     I2C_SCL_1();
//     Delay_us(5);
//     I2C_SCL_0();
//     Delay_us(5);
//   }
//   I2C_SDA_1();
// }

// uint8_t I2C_ReadByte(void)
// {
//   uint8_t rdbyte = 0;
//   for (uint8_t i = 0; i < 8; i++)
//   {
//     rdbyte <<= 1;
//     if (I2C_SDA_READ())
//     {
//       rdbyte++;
//     }
//     I2C_SCL_1();
//     Delay_us(5);
//     I2C_SCL_0();
//     Delay_us(5);
//   }
//   return rdbyte;
// }

// uint8_t I2C_WaitAck(void)
// {
//   uint8_t AckValue;
//   I2C_SDA_1();
//   Delay_us(5);
//   I2C_SCL_1();
//   Delay_us(5);
//   if (I2C_SDA_READ())
//   {
//     AckValue = 1;
//   }
//   else
//   {
//     AckValue = 0;
//   }
//   I2C_SCL_0();
//   Delay_us(5);
//   return AckValue;
// }

// void I2C_SendAck(void)
// {
//   I2C_SDA_0()
//   Delay_us(5);
//   I2C_SCL_1()
//   Delay_us(5);
//   I2C_SCL_0()
//   Delay_us(5);
//   I2C_SDA_1()
//   Delay_us(5);
// }

// void I2C_SendNoAck(void)
// {
//   I2C_SDA_1()
//   Delay_us(5);
//   I2C_SCL_1()
//   Delay_us(5);
//   I2C_SCL_0()
//   Delay_us(5);
// }
