#ifndef __UART_DRIVER_H
#define __UART_DRIVER_H

#include "main.h"

#ifdef USER_MAIN_DEBUG
#define user_main_printf(format, ...)   printf(format "\r\n", ##__VA_ARGS__)
#define user_main_info(format, ...)     printf("[main]info:" format "\r\n", ##__VA_ARGS__)
#define user_main_debug(format, ...)    printf("[main]debug:" format "\r\n", ##__VA_ARGS__)
#define user_main_error(format, ...)    printf("[main]error:" format "\r\n", ##__VA_ARGS__)
#else
#define user_main_printf(format, ...)
#define user_main_info(format, ...)
#define user_main_debug(format, ...)
#define user_main_error(format, ...)
#endif

#endif
