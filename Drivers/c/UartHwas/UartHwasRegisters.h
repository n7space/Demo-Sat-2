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

/// \brief Uart register definitions
#pragma once

#include "hwas/hwas.h"

#define UART_HWAS_0_OFFSET (asn1SccSourceAddress)0x400E0800
#define UART_HWAS_1_OFFSET (asn1SccSourceAddress)0x400E0A00
#define UART_HWAS_2_OFFSET (asn1SccSourceAddress)0x400E1A00
#define UART_HWAS_3_OFFSET (asn1SccSourceAddress)0x400E1C00
#define UART_HWAS_4_OFFSET (asn1SccSourceAddress)0x400E1E00

#define UART_HWAS_CR_OFFSET (asn1SccSourceAddress)0x00
#define UART_HWAS_MR_OFFSET (asn1SccSourceAddress)0x04
#define UART_HWAS_IER_OFFSET (asn1SccSourceAddress)0x08
#define UART_HWAS_IDR_OFFSET (asn1SccSourceAddress)0x0C
#define UART_HWAS_IMR_OFFSET (asn1SccSourceAddress)0x10
#define UART_HWAS_SR_OFFSET (asn1SccSourceAddress)0x14
#define UART_HWAS_RHR_OFFSET (asn1SccSourceAddress)0x18
#define UART_HWAS_THR_OFFSET (asn1SccSourceAddress)0x1C
#define UART_HWAS_BRGR_OFFSET (asn1SccSourceAddress)0x20

#define UART_HWAS_CR_RXEN_MASK (asn1SccWordMask)0x00000010
#define UART_HWAS_CR_TXEN_MASK (asn1SccWordMask)0x00000040

#define UART_HWAS_MR_MASK (asn1SccWordMask)0x0000DE10
#define UART_HWAS_MR_NO_PARITY_MASK (asn1SccWordMask)0x00000800
#define UART_HWAS_MR_CHMODE_MASK (asn1SccWordMask)0x0000C000

#define UART_HWAS_MR_CHMODE_LOCAL_LOOPBACK_VALUE (asn1SccWordMask)0x00008000

#define UART_HWAS_IxR_MASK (asn1SccWordMask)0x000082E3
#define UART_HWAS_IxR_RXRDY_MASK (asn1SccWordMask)0x00000001
#define UART_HWAS_IxR_TXRDY_MASK (asn1SccWordMask)0x00000002
#define UART_HWAS_IxR_OVRE_MASK (asn1SccWordMask)0x00000020
#define UART_HWAS_IxR_FRAME_MASK (asn1SccWordMask)0x00000040
#define UART_HWAS_IxR_PARE_MASK (asn1SccWordMask)0x00000080
#define UART_HWAS_IxR_TXEMPTY_MASK (asn1SccWordMask)0x00000200

#define UART_HWAS_BRGR_CD_MASK (asn1SccWordMask)0x0000FFFF
#define UART_HWAS_BRGR_CD_115200_VALUE (asn1SccWordMask)0x00000028 //< Assuming peripheral clock is 75 MHz
#define UART_HWAS_BRGR_CD_9600_VALUE (asn1SccWordMask)0x000001E8 //< Assuming peripheral clock is 75 MHz


