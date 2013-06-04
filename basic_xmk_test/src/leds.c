/* Includes */
#include "xmk.h"
#include "os_config.h"
#include "sys/ksched.h"
#include "sys/init.h"
#include "sys/timer.h"
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
int leds_init(void)
{
	int Status;

	Status = XGpio_Initialize(&Gpio, GPIO_EXAMPLE_DEVICE_ID);
	if (Status != XST_SUCCESS) {
		xil_printf("LEDS init error\r\n");
		return XST_FAILURE;
	}

	XGpio_DiscreteWrite(&Gpio, LED_CHANNEL, 0x55);
    return 0;
}
