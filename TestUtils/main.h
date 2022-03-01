
/**@file
 * This file is a part of the DemoSat2 validation use case for the EDS TASTE
 * Bridge project.
 *
 * @copyright 2020-2022 N7 Space Sp. z o.o.
 *
 * Test Environment was developed under a programme of,
 * and funded by, the European Space Agency (the "ESA").
 *
 *
 * Licensed under the ESA Public License (ESA-PL) Permissive,
 * Version 2.3 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     https://essr.esa.int/license/list
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifdef __cplusplus
extern "C"
{
#endif

#include "FreeRTOS.h"
#include "task.h"

#include <Hal/Hal.h>
#include <Init/Init.h>

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
}
#endif

#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>

void vApplicationMallocFailedHook();
void vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName);
void vApplicationIdleHook();
void vApplicationTickHook();

typedef struct __attribute__((packed)) ContextStateFrame
{
  uint32_t r0;
  uint32_t r1;
  uint32_t r2;
  uint32_t r3;
  uint32_t r12;
  uint32_t lr;
  uint32_t return_address;
  uint32_t xpsr;
} sContextStateFrame;

// NOTE: If you are using CMSIS, the registers can also be
// accessed through CoreDebug->DHCSR & CoreDebug_DHCSR_C_DEBUGEN_Msk
#define HALT_IF_DEBUGGING()                            \
  do                                                   \
  {                                                    \
    if ((*(volatile uint32_t *)0xE000EDF0) & (1 << 0)) \
    {                                                  \
      __asm("bkpt 1");                                 \
    }                                                  \
  } while (0)

// Disable optimizations for this function so "frame" argument
// does not get optimized away
__attribute__((optimize("O0"))) void
my_fault_handler_c(sContextStateFrame *frame)
{
  // If and only if a debugger is attached, execute a breakpoint
  // instruction so we can take a look at what triggered the fault
  HALT_IF_DEBUGGING();
}

#define HARDFAULT_HANDLING_ASM(_x)  \
  __asm volatile("tst lr, #4 \n"    \
                 "ite eq \n"        \
                 "mrseq r0, msp \n" \
                 "mrsne r0, psp \n" \
                 "b my_fault_handler_c \n")

void HardFault_Handler(void)
{
  HARDFAULT_HANDLING_ASM();
}

int main()
{
  Init_setup_hardware();

  char **av{};
  const int r = CommandLineTestRunner::RunAllTests(0, av);

  return EXIT_SUCCESS;
}

void vApplicationMallocFailedHook() { configASSERT(0); }

void vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName)
{
  (void)pxTask;
  (void)pcTaskName;

  configASSERT(0);
}

void vApplicationIdleHook()
{
  volatile size_t xFreeHeapSpace = xPortGetFreeHeapSize();
  (void)xFreeHeapSpace;
}

void vApplicationTickHook() {}
