#ifndef INCLUDE_MKL_UART_H_
#define INCLUDE_MKL_UART_H_

#include <cstddef>
#include "MKL25Z4.h"

/*!
 * DefiniÃ§Ã£o de pinos implementados para transferÃªncia
 * */
typedef enum
{
    uart0_PTA2 = 0,
    uart1_PTC4 = 1,
    uart2_PTD3 = 2,
    uart0_PTD7 = 3,
    uart1_PTE0 = 4,
    uart2_PTD5 = 5,
    uart0_PTE20 = 6,
    uart2_PTE22 = 7
} uart_PinTx_t;

/*!
 * DefiniÃ§Ã£o de pinos implementados para recepÃ§Ã£o
 * */
typedef enum
{
    uart0_PTA1 = 0,
    uart1_PTC3 = 1,
    uart2_PTD2 = 2,
    uart0_PTD6 = 3,
    uart1_PTE1 = 4,
    uart2_PTD4 = 5,
    uart0_PTE21 = 6,
    uart2_PTE23 = 7
} uart_PinRx_t;

/*!
 * DefiniÃ§Ã£o do tamanho da dado
 * */
typedef enum
{
    mkl_7bit = 7,
    mkl_8bit = 8,
    mkl_9bit = 9
} uart_LengthData_t;

/*!
 * DefiniÃ§Ã£o dos tipos de paridade
 * */
typedef enum
{
    mkl_Odd = 0,
    mkl_Even = 1,
    mkl_None = 2
} uart_Parity_t;

/*!
 * DefiniÃ§Ã£o dos tipos de parada
 * */
typedef enum
{
    mkl_One = 1,
    mkl_Two = 2
} uart_StopBit_t;

/*!
 * DefiniÃ§Ã£o do bit mais significativo
 * */
typedef enum
{
    mkl_LSB = 0,
    mkl_MSB = 1
} uart_FistBit_t;

/*!
 * DefiniÃ§Ã£o dos canais UART implementados
 * */
typedef enum
{
    mkl_UART0 = 0,
    mkl_UART1 = 1,
    mkl_UART2 = 2
} mkl_UART_t;

/*!
 * DefiniÃ§Ã£o dos tipos de exceÃ§Ã£o
 * */
typedef enum
{
    mkl_Ok = 0,
    mkl_OverWriteError = 1,
    mkl_ParityError = 2,
    mkl_TimeOutError = 3,
    mkl_FramingError = 4,
    mkl_NoiseError = 5,
    mkl_OverrunError = 6
} uart_Exception_t;

/*!
 * DefiniÃ§Ã£o das prioridades na interrupÃ§Ã£o
 * */
typedef enum
{
    uart_Priority0 = 0,
    uart_Priority1 = 1,
    uart_Priority2 = 2,
    uart_Priority3 = 3
} uart_Priority_t;

/*!
 * DefiniÃ§Ã£o dos modos de interrupÃ§Ã£o
 * */
typedef enum
{
    uart_Rx = 0,
    uart_Tx = 1,
    uart_TxRx = 2,
    uart_None = 3
} uart_InterruptMode_t;

#endif /* INCLUDE_MKL_UART_H_ */