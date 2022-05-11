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
UartHwas_init_get_uart_register(UartHwas_Id id)
{
  switch (id)
  {
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

static inline void UartHwas_init_pmc_init(UartHwas_Id id)
{
  switch (id)
  {
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

static inline void UartHwas_init_cr_init(const UartHwas *const uart)
{
  Register_set_value(uart->uartAddress + UART_HWAS_CR_OFFSET,
                     UART_HWAS_CR_TXEN_MASK | UART_HWAS_CR_RXEN_MASK,
                     UART_HWAS_CR_MASK, 0);
}

static inline void UartHwas_init_mr_init(const UartHwas *const uart)
{
  Register_reset_bits(uart->uartAddress + UART_HWAS_MR_OFFSET,
                      UART_HWAS_MR_CHMODE_MASK);
  Register_set_bits(uart->uartAddress + UART_HWAS_MR_OFFSET,
                    UART_HWAS_MR_NO_PARITY_MASK);
}
static inline void
UartHwas_init_brgr_init(const UartHwas *const uart,
                        const UartHwas_Config *const config)
{
  Register_reset_bits(uart->uartAddress + UART_HWAS_BRGR_OFFSET,
                      UART_HWAS_BRGR_CD_MASK);
  switch (config->baudrate)
  {
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

inline static void
UartHwas_init_uart0_pio(PioHwas_Pin_Config *const pioConfigTx,
                        PioHwas_Pin_Config *const pioConfigRx)
{
  pioConfigRx->pin = PIO_HWAS_PIN_9;
  pioConfigRx->control = PioHwas_Control_PeripheralA;

  pioConfigTx->pin = PIO_HWAS_PIN_10;
  pioConfigTx->control = PioHwas_Control_PeripheralA;
}

inline static void
UartHwas_init_uart1_pio(PioHwas_Pin_Config *const pioConfigTx,
                        PioHwas_Pin_Config *const pioConfigRx)
{
  pioConfigRx->pin = PIO_HWAS_PIN_5;
  pioConfigRx->control = PioHwas_Control_PeripheralC;
  pioConfigRx->port = PioHwas_Port_A;

  pioConfigTx->pin = PIO_HWAS_PIN_6;
  pioConfigTx->control = PioHwas_Control_PeripheralC;
  pioConfigTx->port = PioHwas_Port_A;
}

inline static void
UartHwas_init_uart2_pio(PioHwas_Pin_Config *const pioConfigTx,
                        PioHwas_Pin_Config *const pioConfigRx)
{
  pioConfigRx->pin = PIO_HWAS_PIN_25;
  pioConfigRx->control = PioHwas_Control_PeripheralC;
  pioConfigRx->port = PioHwas_Port_D;

  pioConfigTx->pin = PIO_HWAS_PIN_26;
  pioConfigTx->control = PioHwas_Control_PeripheralC;
  pioConfigTx->port = PioHwas_Port_D;
}

inline static void
UartHwas_init_uart3_pio(PioHwas_Pin_Config *const pioConfigTx,
                        PioHwas_Pin_Config *const pioConfigRx)
{
  pioConfigRx->pin = PIO_HWAS_PIN_28;
  pioConfigRx->control = PioHwas_Control_PeripheralA;
  pioConfigRx->port = PioHwas_Port_D;

  pioConfigTx->pin = PIO_HWAS_PIN_30;
  pioConfigTx->control = PioHwas_Control_PeripheralA;
  pioConfigTx->port = PioHwas_Port_D;
}

inline static void
UartHwas_init_uart4_pio(PioHwas_Pin_Config *const pioConfigTx,
                        PioHwas_Pin_Config *const pioConfigRx)
{
  pioConfigRx->pin = PIO_HWAS_PIN_18;
  pioConfigRx->control = PioHwas_Control_PeripheralC;
  pioConfigRx->port = PioHwas_Port_D;

  pioConfigTx->pin = PIO_HWAS_PIN_19;
  pioConfigTx->control = PioHwas_Control_PeripheralC;
  pioConfigTx->port = PioHwas_Port_D;
}

static inline void UartHwas_init_pio_init(UartHwas_Id id)
{
  PioHwas_Pin_Config pioConfigTx = {
      .pull = PioHwas_Pull_Up,
      .filter = PioHwas_Filter_None,
      .direction = PioHwas_Direction_Output,
  };

  PioHwas_Pin_Config pioConfigRx = pioConfigTx;
  pioConfigRx.direction = PioHwas_Direction_Input;

  switch (id)
  {
  case UartHwas_Id_0:
    UartHwas_init_uart0_pio(&pioConfigTx, &pioConfigRx);
    break;
  case UartHwas_Id_1:
    UartHwas_init_uart1_pio(&pioConfigTx, &pioConfigRx);
    break;
  case UartHwas_Id_2:
    UartHwas_init_uart2_pio(&pioConfigTx, &pioConfigRx);
    break;
  case UartHwas_Id_3:
    UartHwas_init_uart3_pio(&pioConfigTx, &pioConfigRx);
    break;
  case UartHwas_Id_4:
    UartHwas_init_uart4_pio(&pioConfigTx, &pioConfigRx);
    break;
  }
  PioHwas pio;
  PioHwas_init_pin(&pio, &pioConfigTx);
  PioHwas_init_pin(&pio, &pioConfigRx);
}

void UartHwas_init_irq(UartHwas *const uart, UartHwas_Id id)
{
  switch (id)
  {
  case UartHwas_Id_0:
    uart->irqNumber = NvicHwas_Irq_Uart0;
    break;
  case UartHwas_Id_1:
    uart->irqNumber = NvicHwas_Irq_Uart1;
    break;
  case UartHwas_Id_2:
    uart->irqNumber = NvicHwas_Irq_Uart2;
    break;
  case UartHwas_Id_3:
    uart->irqNumber = NvicHwas_Irq_Uart3;
    break;
  case UartHwas_Id_4:
    uart->irqNumber = NvicHwas_Irq_Uart4;
    break;
  }
}

void UartHwas_init(UartHwas *const uart, const UartHwas_Config *const config)
{
  uart->uartAddress = UartHwas_init_get_uart_register(config->id);
  UartHwas_init_pmc_init(config->id);
  UartHwas_init_cr_init(uart);
  UartHwas_init_mr_init(uart);
  UartHwas_init_brgr_init(uart, config);
  UartHwas_init_irq(uart, config->id);
}

void UartHwas_readByteAsync(UartHwas *const uart,
                            UartHwasRxReadyCallback rxHandler)
{
  uart->rxCallback = rxHandler;
  Register_set_bits(uart->uartAddress + UART_HWAS_IER_OFFSET,
                    UART_HWAS_IxR_RXRDY_MASK);

  hwas_PI_InterruptSubscriptionManagement_SubscribeToInterrupt_Pi(
      (asn1SccInterruptNumber *)&uart->irqNumber);
  hwas_PI_InterruptManagement_EnableInterrupt_Pi(
      (asn1SccInterruptNumber *)&uart->irqNumber);
}

void UartHwas_sendByteAsync(UartHwas *const uart,
                            UartHwasTxEmptyCallback txHandler,
                            uint8_t byteToSend)
{
  uart->txCallback = txHandler;

  hwas_PI_InterruptSubscriptionManagement_SubscribeToInterrupt_Pi(
      (asn1SccInterruptNumber *)&uart->irqNumber);
  hwas_PI_InterruptManagement_EnableInterrupt_Pi(
      (asn1SccInterruptNumber *)&uart->irqNumber);

  Register_set_bits(uart->uartAddress + UART_HWAS_THR_OFFSET,
                    (asn1SccWord)byteToSend & UART_HWAS_THR_TXCHR_MASK);
  Register_set_bits(uart->uartAddress + UART_HWAS_IER_OFFSET,
                    UART_HWAS_IxR_TXEMPTY_MASK);
}

void UartHwas_handleInterrupt(UartHwas *const uart)
{
  uint32_t imr = Register_get_bits(uart->uartAddress + UART_HWAS_IMR_OFFSET,
                                   WHOLE_REGISTER_MASK);
  uint32_t maskedSr =
      Register_get_bits(uart->uartAddress + UART_HWAS_SR_OFFSET, imr);

  //< Have rx ready interrupt occured
  if (maskedSr & UART_HWAS_IxR_RXRDY_MASK)
  {
    uint8_t readByte;
    readByte = (uint8_t)Register_get_bits(
        uart->uartAddress + UART_HWAS_RHR_OFFSET, UART_HWAS_RHR_RXCHR_MASK);
    if (uart->rxCallback != NULL)
      uart->rxCallback(readByte);
  }

  //< Have tx empty interrupt occured
  if (maskedSr & UART_HWAS_IxR_TXEMPTY_MASK)
  {
    if (uart->txCallback != NULL)
      uart->txCallback();
  }
}
