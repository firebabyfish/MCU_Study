#include "key_driver.h"

/*
** mode: 
*/

uint8_t KEY_Scan(uint8_t Key_Mode)
{
  static uint8_t Key_Flag = 0;
  uint8_t key_ret;
  if (KEY_ON)
  {
    HAL_Delay(10);
    if (KEY_ON)
    {
      key_ret = Key_Value();
      if (Key_Mode == KEY_FALLING)
      {
        if (!Key_Flag)
        {
          Key_Flag++;
          return key_ret;
        }
        return 0;
      }
      else if (Key_Mode == KEY_RISING)
      {
        while (KEY_ON);
        return key_ret;
      }
    }
  }
  Key_Flag = 0;
  return 0;
}

uint8_t Key_Value(void)
{
  if (KEY_1_ON) { return KEY_1_FLAG; }
  else if (KEY_2_ON) { return KEY_2_FLAG; }
  return 0;
}

void Key_Action(uint8_t KeyMode)
{
	switch (KEY_Scan(KeyMode))
  {
  case KEY_1_FLAG:
    test1();
    break;
  case KEY_2_FLAG:
    test2();
    break;
   default:
    break;
  }
}
