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

#pragma once

#include "hwas/hwas.h"

/// \brief Uart device identifiers.
typedef enum {
  UartHwas_Id_0 = 0, ///< Uart instance 0.
  UartHwas_Id_1 = 1, ///< Uart instance 1.
  UartHwas_Id_2 = 2, ///< Uart instance 2.
  UartHwas_Id_3 = 3, ///< Uart instance 3.
  UartHwas_Id_4 = 4, ///< Uart instance 4.
} UartHwas_Id;

/// \brief Uart nvic numbers
typedef enum {
  NvicHwas_Irq_Uart0 = 7,
  NvicHwas_Irq_Uart1 = 8,
  NvicHwas_Irq_Uart2 = 44,
  NvicHwas_Irq_Uart3 = 45,
  NvicHwas_Irq_Uart4 = 46,
} NvicHwas_Irq;

/// \brief Uart device identifiers.
typedef enum {
  UartHwas_Baudrate_9600 = 0,   ///< Uart baudrate 9600 bps
  UartHwas_Baudrate_115200 = 1, ///< Uart baudrate 115200 bps
} UartHwas_Baudrate;

/// \brief Uart configuration descriptor.
typedef struct {
  UartHwas_Id id;
  UartHwas_Baudrate baudrate;
  asn1SccInterruptNumber irqNumber;
} UartHwas_Config;

/// \brief A function serving as a callback called at the end of single byte
/// transmission.
typedef void (*UartHwasTxEmptyCallback)();

/// \brief A descriptor of single byte end-of-transmission event handler
typedef struct {
  UartHwasTxEmptyCallback callback;
} UartHwasTxHandler;

/// \brief A function serving as a callback called upon a reception of a single
/// byte
typedef void (*UartHwasRxReadyCallback)(uint8_t readByte);

/// \brief A descriptor of a single byte reception event handler
typedef struct {
  UartHwasRxReadyCallback callback;
} UartHwasRxHandler;

/// \brief Uart descriptor
typedef struct {
  asn1SccSourceAddress uartAddress; //< Uart instance address
  UartHwasTxEmptyCallback txCallback;
  UartHwasRxReadyCallback rxCallback;
  NvicHwas_Irq irqNumber;
} UartHwas;

/**
 * @brief Initializes uart peripheral
 *
 * @param uart
 * @param config
 */
void UartHwas_init(UartHwas *const uart, const UartHwas_Config *const config);

/**
 * @brief
 *
 * @param uart
 * @param rxHandler
 */
void UartHwas_readByteAsync(UartHwas *const uart,
                            UartHwasRxReadyCallback rxHandler);

/**
 * @brief
 *
 * @param uart
 * @param txHandler
 */
void UartHwas_sendByteAsync(UartHwas *const uart,
                            UartHwasTxEmptyCallback txHandler,
                            uint8_t byteToSend);

/**
 * @brief
 *
 * @param uart
 */
void UartHwas_handleInterrupt(UartHwas *const uart);