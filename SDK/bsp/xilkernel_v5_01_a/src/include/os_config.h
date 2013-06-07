/******************************************************************************
*
* (c) Copyright 2010 Xilinx, Inc. All rights reserved.
*
* This file contains confidential and proprietary information of Xilinx, Inc.
* and is protected under U.S. and international copyright and other
* intellectual property laws.
*
* DISCLAIMER
* This disclaimer is not a license and does not grant any rights to the
* materials distributed herewith. Except as otherwise provided in a valid
* license issued to you by Xilinx, and to the maximum extent permitted by
* applicable law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND WITH ALL
* FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES AND CONDITIONS, EXPRESS,
* IMPLIED, OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF
* MERCHANTABILITY, NON-INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE;
* and (2) Xilinx shall not be liable (whether in contract or tort, including
* negligence, or under any other theory of liability) for any loss or damage
* of any kind or nature related to, arising under or in connection with these
* materials, including for any direct, or any indirect, special, incidental,
* or consequential loss or damage (including loss of data, profits, goodwill,
* or any type of loss or damage suffered as a result of any action brought by
* a third party) even if such damage or loss was reasonably foreseeable or
* Xilinx had been advised of the possibility of the same.
*
* CRITICAL APPLICATIONS
* Xilinx products are not designed or intended to be fail-safe, or for use in
* any application requiring fail-safe performance, such as life-support or
* safety devices or systems, Class III medical devices, nuclear facilities,
* applications related to the deployment of airbags, or any other applications
* that could lead to death, personal injury, or severe property or
* environmental damage (individually and collectively, "Critical
* Applications"). Customer assumes the sole risk and liability of any use of
* Xilinx products in Critical Applications, subject only to applicable laws
* and regulations governing limitations on product liability.
*
* THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS PART OF THIS FILE
* AT ALL TIMES.
*
******************************************************************************/
//----------------------------------------------------------------------------------------------------//
//! @file os_config.h 
//! This file caontains all the configuration #define's for the system. The
//! different modules of the kernel can be configured by changing this file
//! and recompiling the kernel. Some of the modules that are configurable are:
//!  - Process Management
//!  - Thread Management
//!  - Scheduling type
//!  - Semaphore
//!  - Message Queue
//!  - Shared Memory
//!  - Dynamic Buffer Management
//!
//!  By recompiling, the kernel gets compiled with the defaults for each 
//!  modules. To further configure the kernel changes may have to be made in the
//!  following files:
//!  - config_param.h
//!  - config_cparam.h
//!  - config_init.h
//----------------------------------------------------------------------------------------------------//

#ifndef _OS_CONFIG_H
#define _OS_CONFIG_H

//! Timer ticks value used for scheduling.
#define TIMER_TICKS 2	

//! Process Management.
//! Further configuration of this module can be done by modifying 
//! config_param.h. The initial system processes are specified in sys/init.c file.
#define MAX_PROCS 10	// Max. number of Processesing contexts in the system 

//! Max. number of Processes in each Priority ready queue. This determines the size
//! of the Ready Queue. This is determined by the type of application.
#define MAX_READYQ 10	

#define CONFIG_KILL     1           //! Include kill() function 
#define CONFIG_YIELD    1           //! Include yield() function 

//! Type of process scheduling. There two types of scheduling supported and 
//! can be configured during system build.
#define SCHED_TYPE 3	//! SCHED_PRIO 


//! ELF Process Management
//! Further configuration of this module can be done by modifying 
//! config_param.h. 
#define CONFIG_ELF_PROCESS      1	// Support ELF process functionality

//! Thread Management
//! Further configuration of this module can be done by modifying 
//! config_param.h. 
#define CONFIG_PTHREAD_SUPPORT  1	//! Support thread functionality

//! Semaphore
//! Further configuration of this module can be done by modifying 
//! config_param.h. 

//! Include the Semapore module 
#define CONFIG_SEMA 	1

//! pthread mutex
//! Further configuration of this module can be done by modifying 
//! config_param.h. 

//! Include the Mutex module 
#define CONFIG_PTHREAD_MUTEX 	1

//! Message Queue
//! Further configuration of this module can be done by modifying 
//! config_cparam.h and sys/init.c.

//! Include the Message Queue functionality. 
#define CONFIG_MSGQ 	1

//! Shared Memory
//! Further configuration of this module can be done by modifying 
//! config_cparam.h and sys/init.c.
//! Include the Shared Memory Functionality 
#define CONFIG_SHM 	1

//! Dynamic Buffer Management
//! Further configuration of this module can be done by modifying 
//! config_cparam.h and sys/init.c.
//! Include the Dynamic buffer management functionality.
#define CONFIG_MALLOC 	1

//! Cache Enable
//! For PPC only
//! Further configuration can be done by modifying sys/main.c
//! Enable caches 
#define CONFIG_CACHE 1

//! Configure timer functionality
#define CONFIG_TIMERS 1

#endif /* _OS_CONFIG_H */
