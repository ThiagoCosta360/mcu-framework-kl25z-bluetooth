#ifndef INCLUDES_MKL_HC06BLUETOOTHSLAVE_H_
#define INCLUDES_MKL_HC06BLUETOOTHSLAVE_H_

#include "mkl_UARTPort.h"
#include "mkl_UARTInterrupt.h"

/*!
 *  @class mkl_HC06BluetoothSlave
 *
 *  @brief    Classe de implementaÃ§Ã£o do perifÃ©rico bluetooth para a placa KL25Z128.
 *
 *  @details  Classe para configuraÃ§Ã£o do perifÃ©rico bluetooth HC06.
 *
 *  @section  EXAMPLES USAGE
 *
 *            Uso dos mÃ©todos de configuraÃ§Ã£o.
 *             +fn mkl_HC06BluetoothSlave(uart_PinTx_t::uart0_PTA2, uart_PinRx_t::uart0_PTA1);
 *             +fn setSlaveName("bluetooth");
 *             +fn setSlavePassword ("123");
 */
class mkl_HC06BluetoothSlave : public mkl_UARTInterrupt
{
public:
   /*!
     * Configura o perifÃ©rico on-chip UART para comunicaÃ§Ã£o via rede bluetooth.
     */
   mkl_HC06BluetoothSlave(uart_PinTx_t pinTx, uart_PinRx_t pinRx);
   /*!
     * Configura um nome para o perifÃ©rico.
     */
   void setSlaveName(char *name);
   /*!
     * Configura uma senha para o perifÃ©rico.
     */
   void setSlavePassword(char *code);
   /*!
     * Verifica se ocorreu um erro na comunicaÃ§Ã£o.
     */
   uart_Exception_t checkException();
   /*!
     * Espera a chegada de um dado de comunicaÃ§Ã£o e, se
     * ocorrer alguma erro, retorna dfs_ParityError ou dsf_OverWriteError.
     */
   uart_Exception_t waitArrivedData();
   /*!
     * Retorna o dado recebido.
     */
   uint8_t receive8Bits();
   /*!
     * Envia um dado de 8-bits.
     */
   void send8BitTest(uint8_t bit);

private:
   /*!
     * Nome do perifÃ©rico.
     */
   volatile char *slaveName;
   /*!
     * Senha do perifÃ©rico.
     */
   volatile char *password;
   /*!
     * Canal de comunicaÃ§Ã£o.
     */
   mkl_UARTPort uartPort;
};

#endif /* INCLUDES_MKL_HC06BLUETOOTHSLAVE_H_ */