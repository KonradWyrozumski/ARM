#include "GPIO.h"

void configureGPIO(int32u whichGPIO, int32u config)
{
  static volatile int32u *const configRegs[] = 
    { (volatile int32u *)GPIO_PACFGL_ADDR,
      (volatile int32u *)GPIO_PACFGH_ADDR,
      (volatile int32u *)GPIO_PBCFGL_ADDR,
      (volatile int32u *)GPIO_PBCFGH_ADDR,
      (volatile int32u *)GPIO_PCCFGL_ADDR,
      (volatile int32u *)GPIO_PCCFGH_ADDR };
  int32u portcfg;
  portcfg = *configRegs[io/4];                // get current config                   
  portcfg = portcfg & ~((0xF)<<((io&3)*4));   // mask out config of this pin
  *configRegs[io/4] = portcfg | (config <<((io&3)*4));
}