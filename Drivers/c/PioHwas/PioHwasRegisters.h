/**@file
 * This file is part of the ARM BSP for the Test Environment.
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

/// \brief PMC register offsets

#define PIO_HWAS_A_OFFSET (asn1SccSourceAddress)0x400E0E00
#define PIO_HWAS_B_OFFSET (asn1SccSourceAddress)0x400E1000
#define PIO_HWAS_C_OFFSET (asn1SccSourceAddress)0x400E1200
#define PIO_HWAS_D_OFFSET (asn1SccSourceAddress)0x400E1400
#define PIO_HWAS_E_OFFSET (asn1SccSourceAddress)0x400E1600

#define PIO_HWAS_PER_OFFSET (asn1SccSourceAddress)0x00
#define PIO_HWAS_PDR_OFFSET (asn1SccSourceAddress)0x04
#define PIO_HWAS_PSR_OFFSET (asn1SccSourceAddress)0x08
#define PIO_HWAS_OER_OFFSET (asn1SccSourceAddress)0x10
#define PIO_HWAS_ODR_OFFSET (asn1SccSourceAddress)0x14
#define PIO_HWAS_OSR_OFFSET (asn1SccSourceAddress)0x18
#define PIO_HWAS_IFER_OFFSET (asn1SccSourceAddress)0x20
#define PIO_HWAS_IFDR_OFFSET (asn1SccSourceAddress)0x24
#define PIO_HWAS_IFSR_OFFSET (asn1SccSourceAddress)0x28
#define PIO_HWAS_SODR_OFFSET (asn1SccSourceAddress)0x30
#define PIO_HWAS_CODR_OFFSET (asn1SccSourceAddress)0x34
#define PIO_HWAS_ODSR_OFFSET (asn1SccSourceAddress)0x38
#define PIO_HWAS_PDSR_OFFSET (asn1SccSourceAddress)0x3C
#define PIO_HWAS_PUDR_OFFSET (asn1SccSourceAddress)0x60
#define PIO_HWAS_PUER_OFFSET (asn1SccSourceAddress)0x64
#define PIO_HWAS_PUSR_OFFSET (asn1SccSourceAddress)0x68
#define PIO_HWAS_ABCDSR1_OFFSET (asn1SccSourceAddress)0x70
#define PIO_HWAS_ABCDSR2_OFFSET (asn1SccSourceAddress)0x74
#define PIO_HWAS_IFSCDR_OFFSET (asn1SccSourceAddress)0x80
#define PIO_HWAS_IFSCER_OFFSET (asn1SccSourceAddress)0x84
#define PIO_HWAS_IFSCSR_OFFSET (asn1SccSourceAddress)0x88
#define PIO_HWAS_PPDDR_OFFSET (asn1SccSourceAddress)0x90
#define PIO_HWAS_PPDER_OFFSET (asn1SccSourceAddress)0x94
#define PIO_HWAS_PPDSR_OFFSET (asn1SccSourceAddress)0x98
#define PIO_HWAS_OWER_OFFSET (asn1SccSourceAddress)0xA0
#define PIO_HWAS_OWDR_OFFSET (asn1SccSourceAddress)0xA4
#define PIO_HWAS_OWSR_OFFSET (asn1SccSourceAddress)0xA8
