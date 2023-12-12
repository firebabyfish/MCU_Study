#include "w25q64_driver.h"

volatile uint32_t Flash_ID = 0;
volatile uint32_t Device_ID = 0;

uint8_t RD_Buffer[4096] = { 0 };
uint8_t WR_Buffer[4096] = "Hello, this is a write test\r\n";

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
  uint8_t RD_Status = 0;
  W25Q64_NSS_LOW();
  W25Q64_SendByte(W25Q64_READ_STATUS_REGISTER);
  do {
    RD_Status = W25Q64_SendByte(W25Q64_DUMMY_BYTE);
  } while ((RD_Status & W25Q64_BUSY_FLAG) == SET);
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
  /* 必须开启写使能才能擦除 */
  W25Q64_WriteEnable();
  W25Q64_WaitEnd();

  /* 开始擦除扇区 */
  W25Q64_NSS_LOW();
  W25Q64_SendByte(W25Q64_SECTOR_ERASE_4KB);
  W25Q64_SendByte((SectorAddr & 0xFF0000) >> 16);
  W25Q64_SendByte((SectorAddr & 0xFF00) >> 8);
  W25Q64_SendByte(SectorAddr & 0xFF);
  W25Q64_NSS_HIGH();

  W25Q64_WaitEnd();
}

void W25Q64_PageWrite(uint8_t *pBuffer, uint32_t WriteAddr, uint32_t ByteNumber)
{
  if (ByteNumber > W25Q64_MAX_PAGESIZE)
  {
    ByteNumber = W25Q64_MAX_PAGESIZE;
    printf("The byte is too much!\r\n");
  }

  W25Q64_WriteEnable();   // 写使能

  W25Q64_NSS_LOW();
  W25Q64_SendByte(W25Q64_PAGE_PROGRAM);
  W25Q64_SendByte((WriteAddr & 0xFF0000) >> 16);
  W25Q64_SendByte((WriteAddr & 0xFF00) >> 8);
  W25Q64_SendByte(WriteAddr & 0xFF);
  while (ByteNumber--)
  {
    W25Q64_SendByte(*pBuffer);
    pBuffer++;
  }

  W25Q64_NSS_HIGH();
  W25Q64_WaitEnd();
}

void W25Q64_BufferWrite(uint8_t *pBuffer, uint32_t WriteAddr, uint32_t ByteNumber)
{
  uint16_t Bytes, Pages, offset, free;
  
  offset = WriteAddr % W25Q64_MAX_PAGESIZE;
  free = W25Q64_MAX_PAGESIZE - offset;
  if (offset && (ByteNumber > free))
  {
    W25Q64_PageWrite(pBuffer, WriteAddr, free);
    ByteNumber -= free;
    pBuffer += free;
    WriteAddr += free;
  }

  Pages = ByteNumber / W25Q64_MAX_PAGESIZE;   // 判断页数
  Bytes = ByteNumber % W25Q64_MAX_PAGESIZE;   // 判断剩余页的字节数

  if (Pages)    // 判断是否还需要写入一整页
  {
    while (Pages--)
    {
      W25Q64_PageWrite(pBuffer, WriteAddr, W25Q64_MAX_PAGESIZE);
      pBuffer += W25Q64_MAX_PAGESIZE;
      WriteAddr += W25Q64_MAX_PAGESIZE;
    }
  }
  if (Bytes)    // 写入最后一页所需要的字节数
  {
    W25Q64_PageWrite(pBuffer, WriteAddr, Bytes);
  }
}

void W25Q64_BufferRead(uint8_t *pBuffer, uint32_t ReadAdder, uint32_t ByteNumber)
{
  W25Q64_NSS_LOW();
  W25Q64_SendByte(W25Q64_READ_DATA);
  W25Q64_SendByte((ReadAdder & 0xFF0000) >> 16);
  W25Q64_SendByte((ReadAdder & 0xFF00) >> 8);
  W25Q64_SendByte(ReadAdder & 0xFF);
  while (ByteNumber--)
  {
    *pBuffer = W25Q64_SendByte(W25Q64_DUMMY_BYTE);
    pBuffer++;
  }
  W25Q64_NSS_HIGH();
}


void W25Q64_Start_Test(void)
{
  uint32_t i;
  printf("Flash_ID = %X, Device_ID = %x\r\n", W25Q64_ReadID(), W25Q64_ReadDeviceID());
  printf("Conncet W25Q64 success!\r\n");
  W25Q64_SectorErase(W25Q64_ADRESS);
  for (i = 0; i < 4096; i++)
  {
    WR_Buffer[i] = 0x55;
  }
  W25Q64_BufferWrite(WR_Buffer, 50, 1000);
  W25Q64_BufferRead(RD_Buffer, 50, 1000);
  for (i = 0; i < 1000; i++)
  {
    printf("%x ", RD_Buffer[i]);
  }
}
