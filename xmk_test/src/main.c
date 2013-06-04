/*
 * Copyright (c) 2009 Xilinx, Inc.  All rights reserved.
 *
 * Xilinx, Inc.
 * XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS" AS A
 * COURTESY TO YOU.  BY PROVIDING THIS DESIGN, CODE, OR INFORMATION AS
 * ONE POSSIBLE   IMPLEMENTATION OF THIS FEATURE, APPLICATION OR
 * STANDARD, XILINX IS MAKING NO REPRESENTATION THAT THIS IMPLEMENTATION
 * IS FREE FROM ANY CLAIMS OF INFRINGEMENT, AND YOU ARE RESPONSIBLE
 * FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE FOR YOUR IMPLEMENTATION.
 * XILINX EXPRESSLY DISCLAIMS ANY WARRANTY WHATSOEVER WITH RESPECT TO
 * THE ADEQUACY OF THE IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO
 * ANY WARRANTIES OR REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE
 * FROM CLAIMS OF INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 */

/* Includes */
#include "xmk.h"
#include "os_config.h"
#include "sys/ksched.h"
#include "sys/init.h"
#include "config/config_param.h"
#include "stdio.h"
#include "xparameters.h"
#include "platform.h"
#include "platform_config.h"
#include <pthread.h>
#include <sys/types.h>

#include "xgpio.h"

#define GPIO_EXAMPLE_DEVICE_ID  XPAR_LEDS_8BIT_DEVICE_ID
#define LED_CHANNEL 1

XGpio Gpio; /* The Instance of the GPIO Driver */

/* The master thread */
void* master_thread(void *arg)
{
	int i = 0;

	while (1) {
		xil_printf("in master: %d\r\n", i++);
		sys_sleep(1000);
	};
    return (void*)0;
}

/* The master thread */
void* leds_thread(void *arg)
{
	int i = 0;
	while (1) {
		XGpio_DiscreteWrite(&Gpio, LED_CHANNEL, i++);
		sys_sleep(1000);
	};
    return (void*)0;
}


/* Functions */
int main()
{
	int Status;

    init_platform();
    
    xil_printf("before init\r\n");

	Status = XGpio_Initialize(&Gpio, GPIO_EXAMPLE_DEVICE_ID);
	if (Status != XST_SUCCESS) {
		xil_printf("LEDS init error\r\n");
		return XST_FAILURE;
	}

	XGpio_DiscreteWrite(&Gpio, LED_CHANNEL, 0x55);

    /* Initialize xilkernel */
    xilkernel_init();

    /* Create the master thread */
    xmk_add_static_thread(master_thread, 0);
    xmk_add_static_thread(leds_thread, 0);
    
    /* Start the kernel */
    xilkernel_start();
    
    /* Never reached */
    cleanup_platform();
    
    return 0;
}
