#ifndef MKL_GPIOPORT_H_
#define MKL_GPIOPORT_H_

#include "mkl_GPIO.h"

/*!
 *  @class    mkl_GPIOPort.
 *
 *  @brief    A classe implementa o perif�rico GPIO sem interrup��o.
 *
 *  @details  Esta classe � derivada da classe m�e "mkl_GPIO" e implementa
 *            o perif�rico GPIO com o modo de opera��o sem interrup��o.
 *
 */
class mkl_GPIOPort : public mkl_GPIO
{
public:
  /*!
   * Construtor padr�o da classe.
   */
  explicit mkl_GPIOPort(gpio_Pin pin = gpio_PTA1);
};

#endif //  MKL_GPIOPORT_H_
