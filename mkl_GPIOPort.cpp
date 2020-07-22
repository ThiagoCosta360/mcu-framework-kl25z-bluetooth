#include "mkl_GPIOPort.h"

/*!
 *   @fn       mkl_GPIOPort
 *
 *   @brief    Construtor padr�o da classe.
 *
 *   O construtor padr�o da classe obt�m o n�mero do pino e do GPIO a partir
 *   do pino desejado, associa fisicamento o objeto de software ao perif�rico
 *   de hardware, habilita o clock do GPIO e seleciona o modo GPIO de opera��o
 *   do pino.
 *
 *   @remarks  Siglas e p�ginas do Manual de Refer�ncia KL25:
 *             - PortxPCRn: Pin Control Register.P�g. 183 (Mux) and 185 (Pull).
 */
mkl_GPIOPort::mkl_GPIOPort(gpio_Pin pin)
{
  uint32_t pinNumber;
  uint32_t gpio;

  setGPIOParameters(pin, gpio, pinNumber);
  bindPeripheral(gpio, pinNumber);
  enableModuleClock(gpio);
  selectMuxAlternative();
}
