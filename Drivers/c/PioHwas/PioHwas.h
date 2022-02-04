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

#include "hwas/hwas.h"

/// \brief Mask indicating pin 0.
#define PIO_HWAS_PIN_0 (asn1SccWordMask)0x00000001u
/// \brief Mask indicating pin 1.
#define PIO_HWAS_PIN_1 (asn1SccWordMask)0x00000002u
/// \brief Mask indicating pin 2.
#define PIO_HWAS_PIN_2 (asn1SccWordMask)0x00000004u
/// \brief Mask indicating pin 3.
#define PIO_HWAS_PIN_3 (asn1SccWordMask)0x00000008u
/// \brief Mask indicating pin 4.
#define PIO_HWAS_PIN_4 (asn1SccWordMask)0x00000010u
/// \brief Mask indicating pin 5.
#define PIO_HWAS_PIN_5 (asn1SccWordMask)0x00000020u
/// \brief Mask indicating pin 6.
#define PIO_HWAS_PIN_6 (asn1SccWordMask)0x00000040u
/// \brief Mask indicating pin 7.
#define PIO_HWAS_PIN_7 (asn1SccWordMask)0x00000080u
/// \brief Mask indicating pin 8.
#define PIO_HWAS_PIN_8 (asn1SccWordMask)0x00000100u
/// \brief Mask indicating pin 9.
#define PIO_HWAS_PIN_9 (asn1SccWordMask)0x00000200u
/// \brief Mask indicating pin 10.
#define PIO_HWAS_PIN_10 (asn1SccWordMask)0x00000400u
/// \brief Mask indicating pin 11.
#define PIO_HWAS_PIN_11 (asn1SccWordMask)0x00000800u
/// \brief Mask indicating pin 12.
#define PIO_HWAS_PIN_12 (asn1SccWordMask)0x00001000u
/// \brief Mask indicating pin 13.
#define PIO_HWAS_PIN_13 (asn1SccWordMask)0x00002000u
/// \brief Mask indicating pin 14.
#define PIO_HWAS_PIN_14 (asn1SccWordMask)0x00004000u
/// \brief Mask indicating pin 15.
#define PIO_HWAS_PIN_15 (asn1SccWordMask)0x00008000u
/// \brief Mask indicating pin 16.
#define PIO_HWAS_PIN_16 (asn1SccWordMask)0x00010000u
/// \brief Mask indicating pin 17.
#define PIO_HWAS_PIN_17 (asn1SccWordMask)0x00020000u
/// \brief Mask indicating pin 18.
#define PIO_HWAS_PIN_18 (asn1SccWordMask)0x00040000u
/// \brief Mask indicating pin 19.
#define PIO_HWAS_PIN_19 (asn1SccWordMask)0x00080000u
/// \brief Mask indicating pin 20.
#define PIO_HWAS_PIN_20 (asn1SccWordMask)0x00100000u
/// \brief Mask indicating pin 21.
#define PIO_HWAS_PIN_21 (asn1SccWordMask)0x00200000u
/// \brief Mask indicating pin 22.
#define PIO_HWAS_PIN_22 (asn1SccWordMask)0x00400000u
/// \brief Mask indicating pin 23.
#define PIO_HWAS_PIN_23 (asn1SccWordMask)0x00800000u
/// \brief Mask indicating pin 24.
#define PIO_HWAS_PIN_24 (asn1SccWordMask)0x01000000u
/// \brief Mask indicating pin 25.
#define PIO_HWAS_PIN_25 (asn1SccWordMask)0x02000000u
/// \brief Mask indicating pin 26.
#define PIO_HWAS_PIN_26 (asn1SccWordMask)0x04000000u
/// \brief Mask indicating pin 27.
#define PIO_HWAS_PIN_27 (asn1SccWordMask)0x08000000u
/// \brief Mask indicating pin 28.
#define PIO_HWAS_PIN_28 (asn1SccWordMask)0x10000000u
/// \brief Mask indicating pin 29.
#define PIO_HWAS_PIN_29 (asn1SccWordMask)0x20000000u
/// \brief Mask indicating pin 30.
#define PIO_HWAS_PIN_30 (asn1SccWordMask)0x40000000u
/// \brief Mask indicating pin 31.
#define PIO_HWAS_PIN_31 (asn1SccWordMask)0x80000000u

/// \brief Enumeration listing I/O ports.
typedef enum {
  PioHwas_Port_A = 0,     ///< I/O line port A.
  PioHwas_Port_B = 1,     ///< I/O line port B.
  PioHwas_Port_C = 2,     ///< I/O line port C.
  PioHwas_Port_D = 3,     ///< I/O line port D.
  PioHwas_Port_E = 4,     ///< I/O line port E.
  PioHwas_Port_Count = 5, ///< I/O line port count.
} PioHwas_Port;

/// \brief Possible I/O line flow direction.
typedef enum {
  PioHwas_Direction_Input,             ///< Input mode.
  PioHwas_Direction_Output,            ///< Output mode.
  PioHwas_Direction_SynchronousOutput, ///< Synchronous output.
} PioHwas_Direction;

/// \brief I/O line pull resistors.
typedef enum {
  PioHwas_Pull_None, ///< Pull disabled.
  PioHwas_Pull_Up,   ///< Pull up enabled.
  PioHwas_Pull_Down, ///< Pull down enabled.
} PioHwas_Pull;

/// \brief I/O line filtering options.
typedef enum {
  PioHwas_Filter_None,     ///< Filtering disabled.
  PioHwas_Filter_Glitch,   ///< Clock glitch filter.
  PioHwas_Filter_Debounce, ///< Debounce filter.
} PioHwas_Filter;

/// \brief I/O line configuration structure.
typedef struct {
  PioHwas_Port port;           ///< I/O line port
  asn1SccWordMask pin;         ///< I/O port registers.
  PioHwas_Direction direction; ///< I/O line flow direction.
  PioHwas_Pull pull;           ///< I/O line pull mode.
  PioHwas_Filter filter;       ///< I/O line filtering mode.
} PioHwas_Pin_Config;

/// \brief Pio descriptor.
typedef struct {
  asn1SccSourceAddress port; ///< I/O port.
  asn1SccWordMask pin;       ///< I/O port registers.
} PioHwas;

/// \brief Sets configuration for specified I/O line set.
/// \param [in] pio Pio descriptor.
/// \param [in] config I/O line set configuration structure.
void PioHwas_init_pin(PioHwas *const pio,
                      const PioHwas_Pin_Config *const config);

/// \brief Sets the output pin state.
/// \param [in] pio Pio descriptor.
void PioHwas_set_pin(PioHwas *const pin);

/// \brief Reets the output pin state.
/// \param [in] pio Pio descriptor.
void PioHwas_reset_pin(PioHwas *const pin);

/// \brief Toggles the output pin state.
/// \param [in] pio Pio descriptor.
void PioHwas_toggle_pin(PioHwas *const pin);

/// \brief Gets the output pin state.
/// \param [in] pio Pio descriptor.
/// \returns I/O port's lines status
bool PioHwas_get_pin(PioHwas *const pin);