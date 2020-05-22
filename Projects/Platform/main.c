/*---------------------------------------------------------------------------
 * Copyright (c) 2020 Arm Limited. All rights reserved.
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
#include "RTE_Device.h"

#include "peripherals.h"
#include "pin_mux.h"
#include "board.h"
#include "fsl_debug_console.h"

#include "cmsis_os2.h"
#include "cmsis_vio.h"

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

  osKernelInitialize();                 // Initialize CMSIS-RTOS2
  osThreadNew(app_main, NULL, NULL);    // Create application main thread
  osKernelStart();                      // Start thread execution

  for (;;);
}

/*---------------------------------------------------------------------------
 * NXP FSL driver callback implementations
 *---------------------------------------------------------------------------*/

#if (defined(RTE_SPI8) && (RTE_SPI8 != 0))
uint32_t SPI8_GetFreq(void) {
  return CLOCK_GetHsLspiClkFreq();
}
void SPI8_InitPins(void) {
  // Pins are initialized in main function in BOARD_InitBootPins function
}
void SPI8_DeinitPins(void) {
  // Pins deinitialization is not implemented
}
#endif

#if (defined(RTE_USART2) && (RTE_USART2 != 0))
uint32_t USART2_GetFreq(void) {
  return CLOCK_GetFlexCommClkFreq(2U);
}
void USART2_InitPins(void) {
  // Pins are initialized in main function in BOARD_InitBootPins function
}
void USART2_DeinitPins(void) {
  // Pins deinitialization is not implemented
}
#endif
