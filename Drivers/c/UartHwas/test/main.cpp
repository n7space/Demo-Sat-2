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

#include "TestUtils/main_FreeRTOS.h"

#include <cstring>
#include <string>

#ifdef __cplusplus
extern "C" {
#endif
#include <Nvic/Nvic.h>
#include <Pmc/Pmc.h>
#include <Uart/Uart.h>

#include <RegisterHwas/RegisterHwas.h>
#include <UartHwas/UartHwas.h>
#include <UartHwas/UartHwasRegisters.h>

#ifdef __cplusplus
}
#endif

UartHwas uart;

void hwas_RI_InterruptSubscription_Interrupt_Ri(
    const asn1SccInterrupt_Type *irq) {
  switch (irq->interrupt) {
  case Nvic_Irq_Uart0:
  case Nvic_Irq_Uart1:
  case Nvic_Irq_Uart2:
  case Nvic_Irq_Uart3:
  case Nvic_Irq_Uart4:
    UartHwas_handleInterrupt(&uart);
    break;
  default:
    break;
  }
}

volatile uint8_t rxByte = 0;
void UartTxCallback() {
  const Uart_Registers *uartReg = (Uart_Registers *)uart.uartAddress;
  rxByte = static_cast<uint8_t>(uartReg->rhr & UART_HWAS_RHR_RXCHR_MASK);
}

void UartRxCallback(uint8_t readByte) { rxByte = readByte; }

TEST_GROUP(UartHwas) {

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

  static inline void Verify_Mr(const Uart_Registers *const uartReg) {
    constexpr uint32_t EXPECTED_VALUE = UART_HWAS_MR_NO_PARITY_MASK;
    LONGS_EQUAL(EXPECTED_VALUE, uartReg->mr & UART_HWAS_MR_MASK);
  }

  static inline void Verify_Imr(const Uart_Registers *const uartReg) {
    constexpr uint32_t EXPECTED_VALUE = 0x00;
    LONGS_EQUAL(EXPECTED_VALUE, uartReg->imr & UART_HWAS_IxR_MASK);
  }

  static inline void Verify_Sr(const Uart_Registers *const uartReg) {
    constexpr uint32_t EXPECTED_VALUE =
        UART_HWAS_IxR_TXEMPTY_MASK | UART_HWAS_IxR_TXRDY_MASK;
    LONGS_EQUAL(EXPECTED_VALUE, uartReg->sr & UART_HWAS_IxR_MASK);
  }

  static inline void Verify_Brgr(const Uart_Registers *const uartReg,
                                 const UartHwas_Config &config) {
    uint32_t EXPECTED_VALUE;
    switch (config.baudrate) {
    case UartHwas_Baudrate_9600:
      EXPECTED_VALUE = UART_HWAS_BRGR_CD_9600_VALUE;
      break;
    case UartHwas_Baudrate_115200:
      EXPECTED_VALUE = UART_HWAS_BRGR_CD_115200_VALUE;
      break;
    }

    LONGS_EQUAL(EXPECTED_VALUE, uartReg->brgr & UART_HWAS_BRGR_CD_MASK);
  }

  static inline void VerifyInit(const UartHwas &uart,
                                const UartHwas_Config &config) {
    const Uart_Registers *uartReg = (Uart_Registers *)uart.uartAddress;

    Verify_Mr(uartReg);
    Verify_Imr(uartReg);
    Verify_Sr(uartReg);
    Verify_Brgr(uartReg, config);
  }

  void SetupInterrupt(UartHwas_Id id, UartHwas_Baudrate baudrate) {
    config.baudrate = baudrate;
    config.id = id;

    UartHwas_init(&uart, &config);
    // put uart in self test - loop back mode
    Register_set_bits(uart.uartAddress + UART_HWAS_MR_OFFSET,
                      UART_HWAS_MR_CHMODE_LOCAL_LOOPBACK_VALUE);
  }

  static inline void Verify_Tx(const UartHwas &uart,
                               const uint8_t EXPECTED_RX_VALUE) {
    const Uart_Registers *uartReg = (Uart_Registers *)uart.uartAddress;

    /// wait for byte to be sent
    while (!(uartReg->sr & UART_HWAS_IxR_TXEMPTY_MASK)) {
    }

    /// wait for byte to be received
    while (uartReg->sr & UART_HWAS_IxR_RXRDY_MASK) {
    }

    constexpr uint32_t EXPECTED_TX_EMPTY_VALUE = UART_HWAS_IxR_TXEMPTY_MASK;
    const uint32_t ACTUAL_TX_EMPTY_VALUE =
        uartReg->sr & UART_HWAS_IxR_TXEMPTY_MASK;
    LONGS_EQUAL(EXPECTED_TX_EMPTY_VALUE, ACTUAL_TX_EMPTY_VALUE);

    LONGS_EQUAL(EXPECTED_RX_VALUE, rxByte);
  }

  static inline void Verify_Rx(const UartHwas &uart,
                               const uint8_t EXPECTED_RX_VALUE) {
    const Uart_Registers *uartReg = (Uart_Registers *)uart.uartAddress;

    //< wait for byte to be send
    while (!(uartReg->sr & UART_HWAS_IxR_TXEMPTY_MASK)) {
    }

    //< wait for byte to be read
    while (uartReg->sr & UART_HWAS_IxR_RXRDY_MASK) {
    }

    LONGS_EQUAL(EXPECTED_RX_VALUE, rxByte);
  }

  UartHwas_Config config;

  void teardown() override {
    Register_set_bits(uart.uartAddress + UART_HWAS_IDR_OFFSET,
                      UART_HWAS_IxR_TXEMPTY_MASK | UART_HWAS_IxR_RXRDY_MASK);
    Register_set_bits(uart.uartAddress + UART_HWAS_CR_OFFSET,
                      UART_HWAS_CR_RSTRX_MASK | UART_HWAS_CR_RSTTX_MASK);
    memset(&config, 0, sizeof(config));
  }
};

/// \Given uninitialized UART
/// \When UART0 is initialized with 9600 bps
/// \Then proper configuration shall be read.
TEST(UartHwas, uart0Baud9600) {
  //< Setup
  config.baudrate = UartHwas_Baudrate_9600;
  config.id = UartHwas_Id_0;

  //< Exercise
  UartHwas_init(&uart, &config);

  //< Verify
  VerifyInit(uart, config);
}

/// \Given uninitialized UART
/// \When UART1 is initialized with 9600 bps
/// \Then proper configuration shall be read.
TEST(UartHwas, uart1Baud9600) {
  //< Setup
  config.baudrate = UartHwas_Baudrate_9600;
  config.id = UartHwas_Id_1;

  //< Exercise
  UartHwas_init(&uart, &config);

  //< Verify
  VerifyInit(uart, config);
}

/// \Given uninitialized UART
/// \When UART2 is initialized with 9600 bps
/// \Then proper configuration shall be read.
TEST(UartHwas, uart2Baud9600) {
  //< Setup
  config.baudrate = UartHwas_Baudrate_9600;
  config.id = UartHwas_Id_2;

  //< Exercise
  UartHwas_init(&uart, &config);

  //< Verify
  VerifyInit(uart, config);
}

/// \Given uninitialized UART
/// \When UART3 is initialized with 9600 bps
/// \Then proper configuration shall be read.
TEST(UartHwas, uart3Baud9600) {
  //< Setup
  config.baudrate = UartHwas_Baudrate_9600;
  config.id = UartHwas_Id_3;

  //< Exercise
  UartHwas_init(&uart, &config);

  //< Verify
  VerifyInit(uart, config);
}

/// \Given uninitialized UART
/// \When UART4 is initialized with 9600 bps
/// \Then proper configuration shall be read.
TEST(UartHwas, uart4Baud9600) {
  //< Setup
  config.baudrate = UartHwas_Baudrate_9600;
  config.id = UartHwas_Id_4;

  //< Exercise
  UartHwas_init(&uart, &config);

  //< Verify
  VerifyInit(uart, config);
}

/// \Given uninitialized UART
/// \When UART0 is initialized with 115200 bps
/// \Then proper configuration shall be read.
TEST(UartHwas, uart4Baud115200) {
  //< Setup
  config.baudrate = UartHwas_Baudrate_115200;
  config.id = UartHwas_Id_4;

  //< Exercise
  UartHwas_init(&uart, &config);

  //< Verify
  VerifyInit(uart, config);
}

/// \Given initialized UART0 in loopback mode
/// \When byte is read asynchroniously and data byte is transfered to THR
/// \Then the same byte shall be read in the interrupt
TEST(UartHwas, uart0Rx) {
  //< Setup
  SetupInterrupt(UartHwas_Id_0, UartHwas_Baudrate_9600);

  //< Exercise
  uint8_t byteToSend = 0xC5;
  UartHwas_readByteAsync(&uart, UartRxCallback);
  Register_set_bits(uart.uartAddress + UART_HWAS_THR_OFFSET, byteToSend);

  //< Verify
  Verify_Rx(uart, byteToSend);
}

/// \Given initialized UART0 in loopback mode
/// \When byte is written asynchroniously
/// \Then the same byte shall be received
TEST(UartHwas, uart0Tx) {
  //< Setup
  SetupInterrupt(UartHwas_Id_0, UartHwas_Baudrate_9600);

  //< Exercise
  uint8_t byteToSend = 0x5C;
  UartHwas_sendByteAsync(&uart, UartTxCallback, byteToSend);

  //< Verify
  Verify_Tx(uart, byteToSend);
}

/// \Given initialized UART1 in loopback mode
/// \When byte is read asynchroniously and data byte is transfered to THR
/// \Then the same byte shall be read in the interrupt
TEST(UartHwas, uart1Rx) {
  //< Setup
  SetupInterrupt(UartHwas_Id_1, UartHwas_Baudrate_9600);

  //< Exercise
  uint8_t byteToSend = 0xC5;
  UartHwas_readByteAsync(&uart, UartRxCallback);
  Register_set_bits(uart.uartAddress + UART_HWAS_THR_OFFSET, byteToSend);

  //< Verify
  Verify_Rx(uart, byteToSend);
}

/// \Given initialized UART1 in loopback mode
/// \When byte is written asynchroniously
/// \Then the same byte shall be received
TEST(UartHwas, uart1Tx) {
  //< Setup
  SetupInterrupt(UartHwas_Id_1, UartHwas_Baudrate_9600);

  //< Exercise
  uint8_t byteToSend = 0x5C;
  UartHwas_sendByteAsync(&uart, UartTxCallback, byteToSend);

  //< Verify
  Verify_Tx(uart, byteToSend);
}

/// \Given initialized UART2 in loopback mode
/// \When byte is read asynchroniously and data byte is transfered to THR
/// \Then the same byte shall be read in the interrupt
TEST(UartHwas, uart2Rx) {
  //< Setup
  SetupInterrupt(UartHwas_Id_2, UartHwas_Baudrate_9600);

  //< Exercise
  uint8_t byteToSend = 0xC5;
  UartHwas_readByteAsync(&uart, UartRxCallback);
  Register_set_bits(uart.uartAddress + UART_HWAS_THR_OFFSET, byteToSend);

  //< Verify
  Verify_Rx(uart, byteToSend);
}

/// \Given initialized UART2 in loopback mode
/// \When byte is written asynchroniously
/// \Then the same byte shall be received
TEST(UartHwas, uart2Tx) {
  //< Setup
  SetupInterrupt(UartHwas_Id_2, UartHwas_Baudrate_9600);

  //< Exercise
  uint8_t byteToSend = 0x5C;
  UartHwas_sendByteAsync(&uart, UartTxCallback, byteToSend);

  //< Verify
  Verify_Tx(uart, byteToSend);
}

/// \Given initialized UART3 in loopback mode
/// \When byte is read asynchroniously and data byte is transfered to THR
/// \Then the same byte shall be read in the interrupt
TEST(UartHwas, uart3Rx) {
  //< Setup
  SetupInterrupt(UartHwas_Id_3, UartHwas_Baudrate_9600);

  //< Exercise
  uint8_t byteToSend = 0xC5;
  UartHwas_readByteAsync(&uart, UartRxCallback);
  Register_set_bits(uart.uartAddress + UART_HWAS_THR_OFFSET, byteToSend);

  //< Verify
  Verify_Rx(uart, byteToSend);
}

/// \Given initialized UART3 in loopback mode
/// \When byte is written asynchroniously
/// \Then the same byte shall be received
TEST(UartHwas, uart3Tx) {
  //< Setup
  SetupInterrupt(UartHwas_Id_3, UartHwas_Baudrate_9600);

  //< Exercise
  uint8_t byteToSend = 0x5C;
  UartHwas_sendByteAsync(&uart, UartTxCallback, byteToSend);

  //< Verify
  Verify_Tx(uart, byteToSend);
}

/// \Given initialized UART4 in loopback mode
/// \When byte is read asynchroniously and data byte is transfered to THR
/// \Then the same byte shall be read in the interrupt
TEST(UartHwas, uart4Rx) {
  //< Setup
  SetupInterrupt(UartHwas_Id_4, UartHwas_Baudrate_9600);

  //< Exercise
  uint8_t byteToSend = 0xC5;
  UartHwas_readByteAsync(&uart, UartRxCallback);
  Register_set_bits(uart.uartAddress + UART_HWAS_THR_OFFSET, byteToSend);

  //< Verify
  Verify_Rx(uart, byteToSend);
}

/// \Given initialized UART4 in loopback mode
/// \When byte is written asynchroniously
/// \Then the same byte shall be received
TEST(UartHwas, uart4Tx) {
  //< Setup
  SetupInterrupt(UartHwas_Id_4, UartHwas_Baudrate_9600);

  //< Exercise
  uint8_t byteToSend = 0x5C;
  UartHwas_sendByteAsync(&uart, UartTxCallback, byteToSend);

  //< Verify
  Verify_Tx(uart, byteToSend);
}