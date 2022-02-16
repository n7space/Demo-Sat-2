/**@file
 * This file is part of the TASTE Runtime SAMV71.
 *
 * @copyright 2022 N7 Space Sp. z o.o.
 *
 * TASTE Runtime SAMV71 was developed under a programme of,
 * and funded by, the European Space Agency (the "ESA").
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

/// \brief Register data manipulation function prototypes and datatypes.

#pragma once

#include <hwas/hwas.h>

#define WHOLE_REGISTER_MASK (asn1SccWordMask)0xFFFFFFFF

/// \brief Sets the chosen bits in the given register.
/// \param [in] reg Pointer to the value that holds the register address value.
/// \param [in] bitsToSet Bits to set in the register.
void Register_set_bits(const asn1SccSourceAddress reg,
                       const asn1SccWord bitsToSet);

/// \brief Set the masked value at the given position in the reg.
/// \param [in] reg Pointer to the value that holds the register address value.
/// \param [in] valueToSet Value to be set after moving to the given position
///             and masking.
/// \param [in] mask Bitmask to mask the chosen value at the given
///             position.
/// \param [in] position The number by which the chosen value is
///             shifted left.
void Register_set_value(const asn1SccSourceAddress reg,
                        const asn1SccWord valueToSet,
                        const asn1SccWordMask mask, const uint8_t position);

/// \brief Resets the chosen bits in the given register.
/// \param [in] reg Pointer to the value that holds the register address value.
/// \param [in] bitsToReset Bits to reset in the register.
void Register_reset_bits(const asn1SccSourceAddress reg,
                         const asn1SccWord bitsToReset);

/// \brief Gets the bit values from the register using given mask
/// \param [in] reg Pointer to the value that holds the register address value.
/// \param [in] mask Bitmask to mask the register value at the given position.
/// \returns The value stored at the given register masked using the given mask
asn1SccWord Register_get_bits(const asn1SccSourceAddress reg,
                              const asn1SccWordMask mask);

/// \brief Gets the value from the register
/// \param [in] reg Pointer to the value that holds the register address value.
/// \returns The value stored at the given register.
asn1SccWord Register_get_value(const asn1SccSourceAddress reg);
