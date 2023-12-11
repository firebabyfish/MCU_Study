#include "w25q64_driver.h"

uint8_t W25Q64_SendByte(uint8_t byte)
{
  uint8_t TxData = byte;
  uint8_t RxData = 0;
  HAL_SPI_TransmitReceive(&W25Q64_SPI, &TxData, &RxData, 1, 100);
  return RxData;
}

void W25Q64_WriteEnable(void)
{
  W25Q64_NSS_LOW();
  W25Q64_SendByte(W25Q64_WRITE_ENABLE);
  W25Q64_NSS_HIGH();
}

/* 等待擦除或数据写完成 */
void W25Q64_WaitEnd(void)
{
  W25Q64_NSS_LOW();
  W25Q64_SendByte(W25Q64_READ_STATUS_REGISTER_1);
  while ((W25Q64_SendByte(W25Q64_DUMMY_BYTE) & 0x01) == 0x01);
  W25Q64_NSS_HIGH();
}

uint32_t W25Q64_ReadDeviceID(void)
{
  uint32_t FLASH_ID = 0;
  W25Q64_NSS_LOW();
  W25Q64_SendByte(W25Q64_RELEASE_POWER_DOWN_HPM_DEVICE_ID);
  W25Q64_SendByte(W25Q64_DUMMY_BYTE);
  W25Q64_SendByte(W25Q64_DUMMY_BYTE);
  W25Q64_SendByte(W25Q64_DUMMY_BYTE);
  FLASH_ID = W25Q64_SendByte(W25Q64_DUMMY_BYTE);
  W25Q64_NSS_HIGH();
  return FLASH_ID;
}

uint32_t W25Q64_ReadID(void)
{
  uint32_t FLASH_ID = 0, hid = 0, mid = 0, lid = 0;
  W25Q64_NSS_LOW();
  W25Q64_SendByte(W25Q64_JEDEC_ID);
  hid = W25Q64_SendByte(W25Q64_DUMMY_BYTE);
  mid = W25Q64_SendByte(W25Q64_DUMMY_BYTE);
  lid = W25Q64_SendByte(W25Q64_DUMMY_BYTE);
  W25Q64_NSS_HIGH();
  FLASH_ID = (hid << 16) | (mid << 8) | lid;
  return FLASH_ID;
}

void W25Q64_SectorErase(uint32_t SectorAddr)
{
  W25Q64_WriteEnable();

  W25Q64_NSS_LOW();
  W25Q64_SendByte(W25Q64_SECTOR_ERASE_4KB);
  W25Q64_SendByte(SectorAddr >> 16);
  W25Q64_SendByte(SectorAddr >> 8);
  W25Q64_SendByte(SectorAddr);
  W25Q64_NSS_HIGH();

  W25Q64_WaitEnd();
}

void W25Q64_ReadBuffer(uint8_t *pBuffer, uint32_t ReadAdder, uint32_t ByteNumber)
{
  uint32_t i;
  W25Q64_NSS_LOW();
  W25Q64_SendByte(W25Q64_READ_DATA);
  W25Q64_SendByte(ReadAdder >> 16);
  W25Q64_SendByte(ReadAdder >> 8);
  W25Q64_SendByte(ReadAdder);
  for (i = 0; i < ByteNumber; i++)
  {
    pBuffer[i] = W25Q64_SendByte(W25Q64_DUMMY_BYTE);
  }
  W25Q64_NSS_HIGH();
}
