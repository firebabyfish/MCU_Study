#ifndef __W25Q64_DRIVER_H
#define __W25Q64_DRIVER_H

#include "spi_drtiver.h"

#define W25Q64_ID                                 0XEF4017
#define W25Q64_ADRESS                             0X00000

#define W25Q64_WRITE_ENABLE							          0x06
#define W25Q64_WRITE_DISABLE						          0x04
#define W25Q64_READ_STATUS_REGISTER				        0x05
#define W25Q64_WRITE_STATUS_REGISTER				      0x01
#define W25Q64_PAGE_PROGRAM							          0x02
#define W25Q64_QUAD_PAGE_PROGRAM			      		  0x32
#define W25Q64_BLOCK_ERASE_64KB				      		  0xD8
#define W25Q64_BLOCK_ERASE_32KB				      		  0x52
#define W25Q64_SECTOR_ERASE_4KB				      		  0x20
#define W25Q64_CHIP_ERASE							            0xC7
#define W25Q64_ERASE_SUSPEND					      	    0x75
#define W25Q64_ERASE_RESUME						      	    0x7A
#define W25Q64_POWER_DOWN							            0xB9
#define W25Q64_HIGH_PERFORMANCE_MODE		      		0xA3
#define W25Q64_CONTINUOUS_READ_MODE_RESET		    	0xFF
#define W25Q64_RELEASE_POWER_DOWN_HPM_DEVICE_ID		0xAB
#define W25Q64_MANUFACTURER_DEVICE_ID		      		0x90
#define W25Q64_READ_UNIQUE_ID					          	0x4B
#define W25Q64_JEDEC_ID							            	0x9F
#define W25Q64_READ_DATA						            	0x03
#define W25Q64_FAST_READ					            		0x0B
#define W25Q64_FAST_READ_DUAL_OUTPUT			      	0x3B
#define W25Q64_FAST_READ_DUAL_IO				        	0xBB
#define W25Q64_FAST_READ_QUAD_OUTPUT			      	0x6B
#define W25Q64_FAST_READ_QUAD_IO				        	0xEB
#define W25Q64_OCTAL_WORD_READ_QUAD_IO				    0xE3
#define W25Q64_DUMMY_BYTE							            0xFF
#define W25Q64_BUSY_FLAG                          0x01

#define W25Q64_MAX_PAGESIZE                       256

#define W25Q64_SPI          hspi1

#define W25Q64_NSS_LOW()          SPI1_NSS_LOW()
#define W25Q64_NSS_HIGH()         SPI1_NSS_HIGH()

uint8_t W25Q64_SendByte(uint8_t byte);
void W25Q64_WriteEnable(void);
void W25Q64_WaitEnd(void);
uint32_t W25Q64_ReadDeviceID(void);
uint32_t W25Q64_ReadID(void);
void W25Q64_SectorErase(uint32_t SectorAddr);
void W25Q64_PageWrite(uint8_t *pBuffer, uint32_t WriteAddr, uint32_t ByteNumber);
void W25Q64_BufferWrite(uint8_t *pBuffer, uint32_t WriteAddr, uint32_t ByteNumber);
void W25Q64_BufferRead(uint8_t *pBuffer, uint32_t ReadAdder, uint32_t ByteNumber);

void W25Q64_Start_Test(void);

#endif
