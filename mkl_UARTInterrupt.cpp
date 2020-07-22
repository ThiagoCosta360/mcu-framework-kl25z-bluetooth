#include "mkl_UARTInterrupt.h"
#include <cassert>

mkl_UARTInterrupt::mkl_UARTInterrupt()
{
    //this = mkl_UARTInterrupt(mkl_UART_t::mkl_UART0);
}

/*!
 *  @fn  mkl_UARTInterrupt
 *
 *  @brief  Configura a uart com interrupÃ§Ãµes.
 *
 *  @param[in] uart - perifÃ©rico UART.
 */
mkl_UARTInterrupt::mkl_UARTInterrupt(mkl_UART_t uart)
{
    if (uart == mkl_UART_t::mkl_UART0)
    {
        this->UARTx_IRQn = UART0_IRQn;
    }
    else if (uart == mkl_UART_t::mkl_UART0)
    {
        this->UARTx_IRQn = UART1_IRQn;
    }
    else
    {
        this->UARTx_IRQn = UART2_IRQn;
    }
    this->addressUARTxC2 = reinterpret_cast<uint8_t *>(0x4006A003 +
                                                       (0x00001000 * uart));
}

/*!
 *  @fn  setPriority
 *
 *  @brief  Estabelece uma prioridade para a interrupÃ§Ã£o.
 *
 *  @param[in] prior - prioridade.
 */
void mkl_UARTInterrupt::setPriority(uart_Priority_t prior)
{
    this->priority = prior;
    NVIC_SetPriority(this->UARTx_IRQn, prior);
}

/*!
 *  @fn  getPriority
 *
 *  @brief  Retorna a prioridade configurada.
 *
 *  @return Prioridade da interrupÃ§Ã£o.
 */
uart_Priority_t mkl_UARTInterrupt::getPriority()
{
    return this->priority;
}

/*!
 *  @fn  setInterruptMode
 *
 *  @brief  MÃ©todo que determina o modo de interrupÃ§Ã£o.
 *
 *  @param[in] mode - modo de interrupÃ§Ã£o.
 */
void mkl_UARTInterrupt::setInterruptMode(uart_InterruptMode_t mode)
{
    *addressUARTxC2 |= UART_C2_RIE_MASK;
}

/*!
 *  @fn  enableInterrupt
 *
 *  @brief  Habilita a interrupÃ§Ã£o.
 */
void mkl_UARTInterrupt::enableInterrupt()
{
    NVIC_EnableIRQ(this->UARTx_IRQn);
}

/*!
 *  @fn  disableInterrupt
 *
 *  @brief  Desabilita a interrupÃ§Ã£o.
 */
void mkl_UARTInterrupt::disableInterrupt()
{
    NVIC_DisableIRQ(this->UARTx_IRQn);
}

/*!
 *  @fn  isSettedInterruptFlag
 *
 *  @brief  Verifica a situaÃ§Ã£o da flag de interrupÃ§Ã£o.
 */
bool mkl_UARTInterrupt::isSettedInterruptFlag()
{
    //! this->interrupt = memcmp(this->addressUARTxC2, UART_C2_RIE_MASK);
    //! TODO(Francisco): implementar.
    return this->interrupt;
}