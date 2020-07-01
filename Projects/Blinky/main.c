/*---------------------------------------------------------------------------
 * Copyright (c) 2020 Arm Limited (or its affiliates). All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *      Name:    main.c
 *      Purpose: Main file for NXP LPC55S69 device
 *
 *---------------------------------------------------------------------------*/

#include "main.h"

#include "RTE_Components.h"
#include  CMSIS_device_header
#include "cmsis_os2.h"

#include "RTE_Device.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "board.h"
#include "fsl_debug_console.h"

#ifdef    RTE_VIO_BOARD
#include "cmsis_vio.h"
#endif
#ifdef    RTE_Compiler_EventRecorder
#include "EventRecorder.h"
#endif

/*---------------------------------------------------------------------------
 * Main function
 *---------------------------------------------------------------------------*/
int main (void) {

  // System initialization
  BOARD_InitBootPeripherals();
  BOARD_InitBootPins();
  BOARD_InitBootClocks();
  BOARD_InitDebugConsole();

  SystemCoreClockUpdate();              // Update System Core Clock info

#ifdef RTE_VIO_BOARD
  vioInit();                            // Initialize Virtual I/O
#endif

#ifdef RTE_Compiler_EventRecorder
  EventRecorderInitialize (EventRecordAll, 1U); // Initialize and start Event Recorder
#endif

  osKernelInitialize();                 // Initialize CMSIS-RTOS2
  app_initialize();                     // Initialize application
  osKernelStart();                      // Start thread execution

  for (;;) {}
}
