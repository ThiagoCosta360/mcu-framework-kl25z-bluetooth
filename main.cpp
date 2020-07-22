#include <assert.h>
#include "./mkl_HC06BluetoothSlave.h"
#include "./mkl_GPIOPort.h"

mkl_HC06BluetoothSlave bt(uart0_PTA2, uart0_PTA1); //! Bluetooth na UART 0
mkl_GPIOPort ledVerde(gpio_PTB19);				   //! LED da placa
uint8_t buf = '0';								   //! Armazenar dado recebido
uart_Exception_t exc;							   //! Armazenar exceÃ§Ã£o

/*!
 *   @fn delayMs
 *
 *   @brief      Realiza um delay de n ms.
 */
void delayMs(uint16_t n)
{
	for (uint16_t i = 0; i < n; i++)
		for (uint16_t j = 0; j < 7000; j++)
		{
		}
}

/*!
 *   @fn setupLedRGB
 *
 *   @brief      Realiza a configuraÃ§Ã£o do perifÃ©rico para a entrada e saÃ­da.
 *               Este procedimento realiza a configuraÃ§Ã£o do pino PTD1 para o
 *               modo saÃ­da (RGB)
 *
 *   @details    O led RGB Ã© do tipo anodo comum.
 */
void setupLedRGB()
{
	ledVerde.setPortMode(gpio_output);
	ledVerde.writeBit(true);
}

/*!
 *   @fn setupBluetooth
 *
 *   @brief      Realiza a configuraÃ§Ã£o do perifÃ©rico Bluetooth.
 *
 *   @details    Prioridade 0 e modo de interrupÃ§Ã£o no RX.
 */
void setupBluetooth()
{
	bt.setInterruptMode(uart_Rx);
	bt.setPriority(uart_Priority0);
	bt.enableInterrupt();
}

/*!
 *   @fn UART0_IRQHandler
 *
 *   @brief      Rotina de serviÃ§o de interrupÃ§Ã£o.
 *
 *   @details    Recebe os dados atravÃ©s da UART.
 */
extern "C"
{
	void UART0_IRQHandler()
	{
		buf = bt.receive8Bits();
	}
}

/*!
 *   @fn main
 *
 *   @brief      Este programa implementa uma conexÃ£o bluetooth.
 *
 *   @return Sempre retorna 0.
 */
int main()
{

	__disable_irq();
	setupLedRGB();	  //! Configura o LED RGB
	setupBluetooth(); //! Configura o perifÃ©rico bluetooth
	__enable_irq();

	/*!
	 * Caso o dado enviado seja igual ao recebido
	 * o LED verde da placa acenderÃ¡.
	 */
	while (true)
	{
		if (buf == '1')
			ledVerde.writeBit(false);
		if (buf == '2')
			ledVerde.writeBit(true);
	}
	return 0;
}
