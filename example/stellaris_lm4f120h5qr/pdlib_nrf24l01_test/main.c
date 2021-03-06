/*
 * main.c
 */


#include "pdlib_nrf24l01.h"
#include "pdlib_spi.h"
#include <stdio.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/ssi.h"
#include "driverlib/rom.h"

int main(void) {
	
	unsigned char ucStatus;
	unsigned char address[5] = {0xDE, 0xAD, 0xBE, 0xEF, 0x01};

	unsigned char buf[5];

	/* PS: Set the clock frequency of the processor */
	SysCtlClockSet(SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ | SYSCTL_SYSDIV_5);

	/* PS: Initialize the module, need to provide CE pin, CSN pin and SSI module information */
	NRF24L01_Init(GPIO_PORTE_BASE,GPIO_PIN_1, SYSCTL_PERIPH_GPIOE, GPIO_PORTE_BASE, GPIO_PIN_2, SYSCTL_PERIPH_GPIOE, 0x03);

	NRF24L01_RegisterRead_Multi(0x10,buf,5);

	NRF24L01_SetTXAddress(address);

	NRF24L01_RegisterRead_Multi(0x10,buf,5);

	while(1)
	{

	}

	return 0;
}
