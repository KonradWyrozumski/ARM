#ifndef _UART_H
#define _UART_H
#define CORTEXM3_STM32W108
#include "stdio.h"
#include "stdlib.h"
#include <yfuns.h>
#include <stdint.h>
#include "iar.h"

/** 
 * @brief struct for parity used for communication
**/

typedef enum
{
  PARITY_NONE = 0,
  PARITY_ODD = 1,
  PARITY_EVEN = 2
} SerialParity;

/**
 * @brief Function to initialize UART communication
 *
 * @param baudrate  Baudrate used for communication
 *
 * @param databits  The number of bits used for communication
 *
 * @param parity    The type of parity used for communication
 *
 * @param stopbits  The number of stop bits used for communication
**/

void uartInit(int32u baudrate, int8u databits, SerialParity parity, int8u stopbits);

/**
 * @brief Read the input byte if any. 
 **/

boolean __io_getcharNonBlocking(int8u *data);
void __io_putchar( char c );
int __io_getchar(void);
void __io_flush( void );


#endif //__UART_MIN_H__
