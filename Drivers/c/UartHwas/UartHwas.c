/**@file
 * This file is a part of the DemoSat2 validation use case for the EDS TASTE
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

#include <UartHwas/UartHwas.h>
#include <UartHwas/UartHwasRegisters.h>

#include <PmcHwas/PmcHwasRegisters.h>
#include <RegisterHwas/RegisterHwas.h>

static inline asn1SccSourceAddress
UartHwas_init_get_uart_register(UartHwas_Id id) {
  switch (id) {
  case UartHwas_Id_0:
    return UART_HWAS_0_OFFSET;
  case UartHwas_Id_1:
    return UART_HWAS_1_OFFSET;
  case UartHwas_Id_2:
    return UART_HWAS_2_OFFSET;
  case UartHwas_Id_3:
    return UART_HWAS_3_OFFSET;
  case UartHwas_Id_4:
    return UART_HWAS_4_OFFSET;
  }
}

static inline void UartHwas_init_pmc_init(UartHwas_Id id) {
  switch (id) {
  case UartHwas_Id_0:
    if (!(Register_get_bits(PMC_PCSR0, PMC_PCxR0_PID7_UART0_MASK)))
      Register_set_bits(PMC_PCER0, (asn1SccWord)PMC_PCxR0_PID7_UART0_MASK);
    break;
  case UartHwas_Id_1:
    if (!(Register_get_bits(PMC_PCSR0, PMC_PCxR0_PID8_UART1_MASK)))
      Register_set_bits(PMC_PCER0, (asn1SccWord)PMC_PCxR0_PID8_UART1_MASK);
    break;
  case UartHwas_Id_2:
    if (!(Register_get_bits(PMC_PCSR1, PMC_PCxR1_PID44_UART2_MASK)))
      Register_set_bits(PMC_PCER1, (asn1SccWord)PMC_PCxR1_PID44_UART2_MASK);
    break;
  case UartHwas_Id_3:
    if (!(Register_get_bits(PMC_PCSR1, PMC_PCxR1_PID45_UART3_MASK)))
      Register_set_bits(PMC_PCER1, (asn1SccWord)PMC_PCxR1_PID45_UART3_MASK);
    break;
  case UartHwas_Id_4:
    if (!(Register_get_bits(PMC_PCSR1, PMC_PCxR1_PID46_UART4_MASK)))
      Register_set_bits(PMC_PCER1, (asn1SccWord)PMC_PCxR1_PID46_UART4_MASK);
    break;
  }
}

static inline void UartHwas_init_cr_init(const UartHwas *const uart) {
  Register_set_bits(uart->uartAddress + UART_HWAS_CR_OFFSET,
                    UART_HWAS_CR_TXEN_MASK | UART_HWAS_CR_RXEN_MASK);
}

static inline void UartHwas_init_mr_init(const UartHwas *const uart) {
  Register_reset_bits(uart->uartAddress + UART_HWAS_MR_OFFSET,
                      UART_HWAS_MR_CHMODE_MASK);
  Register_set_bits(uart->uartAddress + UART_HWAS_MR_OFFSET,
                    UART_HWAS_MR_NO_PARITY_MASK);
}
static inline void
UartHwas_init_brgr_init(const UartHwas *const uart,
                        const UartHwas_Config *const config) {
  Register_reset_bits(uart->uartAddress + UART_HWAS_BRGR_OFFSET,
                      UART_HWAS_BRGR_CD_MASK);
  switch (config->baudrate) {
  case UartHwas_Baudrate_9600:
    Register_set_bits(uart->uartAddress + UART_HWAS_BRGR_OFFSET,
                      UART_HWAS_BRGR_CD_9600_VALUE);
    break;
  case UartHwas_Baudrate_115200:
    Register_set_bits(uart->uartAddress + UART_HWAS_BRGR_OFFSET,
                      UART_HWAS_BRGR_CD_115200_VALUE);
    break;
  }
}

void UartHwas_init(UartHwas *const uart, const UartHwas_Config *const config) {
  uart->uartAddress = UartHwas_init_get_uart_register(config->id);
  UartHwas_init_pmc_init(config->id);
  UartHwas_init_cr_init(uart);
  UartHwas_init_mr_init(uart);
  UartHwas_init_brgr_init(uart, config);
}

void UartHwas_rx(UartHwas *const uart) {}

void UartHwas_tx(UartHwas *const uart) {}
