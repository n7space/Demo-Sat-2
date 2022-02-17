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

#include "TestUtils/main.h"

#include <cstring>

#ifdef __cplusplus
extern "C" {
#endif
#include <Pmc/Pmc.h>
#include <Uart/Uart.h>
#include <UartHwas/UartHwas.h>
#include <UartHwas/UartHwasRegisters.h>

#ifdef __cplusplus
}
#endif

TEST_GROUP(UartHwas_init) {

  static inline void VerifyPmc(UartHwas_Id id) {
    switch (id) {
    case UartHwas_Id_0:
      CHECK_TRUE(Pmc_isPeripheralClkEnabled(Pmc_PeripheralId_Uart0));
      break;
    case UartHwas_Id_1:
      CHECK_TRUE(Pmc_isPeripheralClkEnabled(Pmc_PeripheralId_Uart1));
      break;
    case UartHwas_Id_2:
      CHECK_TRUE(Pmc_isPeripheralClkEnabled(Pmc_PeripheralId_Uart2));
      break;
    case UartHwas_Id_3:
      CHECK_TRUE(Pmc_isPeripheralClkEnabled(Pmc_PeripheralId_Uart3));
      break;
    case UartHwas_Id_4:
      CHECK_TRUE(Pmc_isPeripheralClkEnabled(Pmc_PeripheralId_Uart4));
      break;
    }
  }

  static inline void Verify_Cr(const Uart_Registers *const uartReg) {
    constexpr uint32_t EXPECTED_VALUE =
        UART_HWAS_CR_TXEN_MASK | UART_HWAS_CR_RXEN_MASK;
    LONGS_EQUAL(EXPECTED_VALUE, uartReg->cr);
  }

  static inline void Verify_Mr(const Uart_Registers *const uartReg) {
    constexpr uint32_t EXPECTED_VALUE = UART_HWAS_MR_NO_PARITY_MASK;
    LONGS_EQUAL(EXPECTED_VALUE, uartReg->mr);
  }

  static inline void Verify_Imr(const Uart_Registers *const uartReg) {
    constexpr uint32_t EXPECTED_VALUE = 0x00;
    LONGS_EQUAL(EXPECTED_VALUE, uartReg->imr);
  }

  static inline void Verify_Sr(const Uart_Registers *const uartReg) {
    constexpr uint32_t EXPECTED_VALUE = UART_HWAS_IxR_RXRDY_MASK |
                                        UART_HWAS_IxR_TXEMPTY_MASK |
                                        UART_HWAS_IxR_TXRDY_MASK;
    LONGS_EQUAL(EXPECTED_VALUE, uartReg->sr);
  }

  static inline void Verify_Brgr(const Uart_Registers *const uartReg,
                                 const UartHwas_Config &config) {
    uint32_t EXPECTED_VALUE;
    switch (config.baudrate) {
    case UartHwas_Baudrate_9600:
      EXPECTED_VALUE = UART_HWAS_BRGR_9600_VALUE;
      break;
    case UartHwas_Baudrate_115200:
      EXPECTED_VALUE = UART_HWAS_BRGR_115200_VALUE;
      break;
    }

    LONGS_EQUAL(EXPECTED_VALUE, uartReg->brgr);
  }

  static inline void Verify(const UartHwas &uart,
                            const UartHwas_Config &config) {
    const Uart_Registers *uartReg = (Uart_Registers *)uart.uartAddress;
    Verify_Cr(uartReg);
    Verify_Mr(uartReg);
    Verify_Imr(uartReg);
    Verify_Sr(uartReg);
    Verify_Brgr(uartReg, config);
  }

  UartHwas uart;
  UartHwas_Config config;

  void teardown() override { memset(&config, 0, sizeof(config)); }
};

TEST(UartHwas_init, uart0Baud9600) {
  config.baudrate = UartHwas_Baudrate_9600;
  config.id = UartHwas_Id_0;

  UartHwas_init(&uart, &config);
  Verify(uart, config);
}

TEST(UartHwas_init, uart1Baud9600) {
  config.baudrate = UartHwas_Baudrate_9600;
  config.id = UartHwas_Id_1;

  UartHwas_init(&uart, &config);
  Verify(uart, config);
}

TEST(UartHwas_init, uart2Baud9600) {
  config.baudrate = UartHwas_Baudrate_9600;
  config.id = UartHwas_Id_2;

  UartHwas_init(&uart, &config);
  Verify(uart, config);
}

TEST(UartHwas_init, uart3Baud9600) {
  config.baudrate = UartHwas_Baudrate_9600;
  config.id = UartHwas_Id_3;

  UartHwas_init(&uart, &config);
  Verify(uart, config);
}

TEST(UartHwas_init, uart4Baud9600) {
  config.baudrate = UartHwas_Baudrate_9600;
  config.id = UartHwas_Id_4;

  UartHwas_init(&uart, &config);
  Verify(uart, config);
}

TEST(UartHwas_init, uart4Baud115200) {
  config.baudrate = UartHwas_Baudrate_115200;
  config.id = UartHwas_Id_4;

  UartHwas_init(&uart, &config);
  Verify(uart, config);
}
