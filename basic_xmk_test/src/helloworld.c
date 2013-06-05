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

/* helloworld_xmk.c: launch a thread that prints out Hello World */

#include "xmk.h"
#include "sys/init.h"
#include "platform.h"

#include <stdio.h>

#include "leds.h"

void *hello_world(void *arg)
{
    print("Hello threaded World4\r\n");
}

int main()
{
    init_platform();
    leds_init();

    /* Initialize xilkernel */
    xilkernel_init();

    /* add a thread to be launched once xilkernel starts */
    xmk_add_static_thread(hello_world, 0);
    xmk_add_static_thread(leds_thread, 0);

    /* start xilkernel - does not return control */
    xilkernel_start();

    /* Never reached */
    cleanup_platform();

    return 0;
}
