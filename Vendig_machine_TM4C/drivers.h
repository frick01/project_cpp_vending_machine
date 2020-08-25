#ifndef __DRIVERS_H_
#define __DRIVERS_H_

#include "inc/hw_memmap.h"
#include "inc/hw_ints.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "driverlib/timer.h" 
#include "driverlib/interrupt.h"
#include "utils/uartstdio.h"

#define GPIO_PA0_U0RX    0x00000001
#define GPIO_PA1_U0TX    0x00000401

void Config_UART0(void);

void Config_UART0 (void){  
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
  SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
  GPIOPinConfigure(GPIO_PA0_U0RX);                                                   
  GPIOPinConfigure(GPIO_PA1_U0TX);
  UARTClockSourceSet(UART0_BASE, UART_CLOCK_PIOSC);
  GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
  UARTStdioConfig(0, 115200, 16000000); 
}

void delayMs(uint32_t ui32Ms) {

   // 1 clock cycle = 1 / SysCtlClockGet() second
   // 1 SysCtlDelay = 3 clock cycle = 3 / SysCtlClockGet() second
   // 1 second = SysCtlClockGet() / 3
   // 0.001 second = 1 ms = SysCtlClockGet() / 3 / 1000
   
   SysCtlDelay(ui32Ms * (SysCtlClockGet() / 3 / 1000));
}

void delayUs(uint32_t ui32Us) {
   SysCtlDelay(ui32Us * (SysCtlClockGet() / 3 / 1000000));
}


#endif // DRIVERS_H_INCLUDED

