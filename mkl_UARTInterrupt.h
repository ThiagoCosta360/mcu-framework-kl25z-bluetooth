#ifndef INCLUDES_MKL_UARTINTERRUPT_H_
#define INCLUDES_MKL_UARTINTERRUPT_H_

#include "mkl_UART.h"

/*!
 *  @class mkl_UARTInterrupt
 *
 *  @brief    Classe de implementaÃ§Ã£o do perifÃ©rico UART para a placa KL25Z128.
 *
 *  @details  Esta classe Ã© usada para configuraÃ§Ã£o do protocolo UART
 *            de comunicaÃ§Ã£o com interrupÃ§Ã£o. O pino de transmissÃ£o (Tx)
 *            do protocolo envia um pacote de bits que serÃ¡ interpretado bit
 *            a bit pelo pino receptor. Cada pacote enviado contÃ©m 1 start
 *            bit que indica o inÃ­cio da mensagem, 1 ou 2 stop bits para
 *            indicar o final da mensagem, 5 a 9 bits de informaÃ§Ã£o e 1
 *            bit de paridade para evitar a recepÃ§Ã£o de erros.
 *
 *  @section  EXAMPLES USAGE
 *
 *            Uso dos mÃ©todos de configuraÃ§Ã£o.
 *             +fn mkl_UARTInterrupt(mkl_UART_t::mkl_UART0);
 *             +fn void setPriority(uart_Priority_t::uart_Priority0);
 *             +fn void setInterruptMode(uart_InterruptMode_t::uart_Rx);
 */
class mkl_UARTInterrupt
{
public:
   mkl_UARTInterrupt();
   /*!
     * Construtor responsÃ¡vel por configurar a porta UART escolhida.
     */
   explicit mkl_UARTInterrupt(mkl_UART_t uart);
   /*!
     * Construtor responsÃ¡vel por configurar a porta UART escolhida.
     */
   void setPriority(uart_Priority_t prior);
   /*!
     * Estabelce uma prioridade para a interrupÃ§Ã£o.
     */
   uart_Priority_t getPriority();
   /*!
     * Ajusta o modo de geraÃ§Ã£o de interrupÃ§Ã£o.
     */
   void setInterruptMode(uart_InterruptMode_t mode);
   /*!
     * Habilita geraÃ§Ã£o de interrupÃ§Ã£o.
     */
   void enableInterrupt();
   /*!
     * Desabilita geraÃ§Ã£o de interrupÃ§Ã£o.
     */
   void disableInterrupt();
   /*!
     * Verifica se o flag de interrupÃ§Ã£o estÃ¡ ativa.
     */
   bool isSettedInterruptFlag();

protected:
   /*!
     * Prioridade da interrupÃ§Ã£o.
     */
   volatile uart_Priority_t priority;
   /*!
     * Flag de habilataÃ§Ã£o da interrupÃ§Ã£o.
     */
   volatile bool interrupt;
   /*!
     * EndereÃ§o do registrador de controle 2
     * */
   volatile uint8_t *addressUARTxC2;
   /*!
     * Canal de comunicaÃ§Ã£o
     * */
   volatile IRQn_Type UARTx_IRQn;
};

#endif /* INCLUDES_MKL_UARTINTERRUPT_H_ */
