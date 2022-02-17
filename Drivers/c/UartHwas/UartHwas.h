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

/// \brief Uart device identifiers.
typedef enum {
  UartHwas_Baudrate_9600 = 0,   ///< Uart baudrate 9600 bps
  UartHwas_Baudrate_115200 = 1, ///< Uart baudrate 115200 bps
} UartHwas_Baudrate;

/// \brief Uart configuration descriptor.
typedef struct {
  UartHwas_Id id;
  UartHwas_Baudrate baudrate;
} UartHwas_Config;

/// \brief Uart descriptor
typedef struct {
  asn1SccSourceAddress uartAddress; //< Uart instance address
} UartHwas;

void UartHwas_init(UartHwas *const uart, const UartHwas_Config *const config);

void UartHwas_rx(UartHwas *const uart);

void UartHwas_tx(UartHwas *const uart);
