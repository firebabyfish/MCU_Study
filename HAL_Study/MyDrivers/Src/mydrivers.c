#include "mydrivers.h"

void test1(void)
{
  printf("FLASH_ID = %x\r\n", W25Q64_ReadID());
  HAL_Delay(1000);
}

void test2(void)
{
	
}
