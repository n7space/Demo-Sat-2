/**@file
 * This file is a part of the DemoSat2 validation use case for the EDS TASTE
 * Bridge project.
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

#include <RegisterHwas/RegisterHwas.h>

void Register_set_bits(const asn1SccSourceAddress reg,
                       const asn1SccWord bitsToSet) {
  asn1SccWordMask tempMask = (asn1SccWordMask)bitsToSet;
  asn1SccWord tempValue = (asn1SccWord)bitsToSet;
  hwas_PI_RawMemoryAccess_WriteWord_Pi(&reg, &tempMask, &tempValue);
}

void Register_set_value(const asn1SccSourceAddress reg,
                        const asn1SccWord valueToSet,
                        const asn1SccWordMask mask, const uint8_t position) {
  asn1SccWord value = (valueToSet << position) & mask;
  hwas_PI_RawMemoryAccess_WriteWord_Pi(&reg, &mask, &value);
}

void Register_reset_bits(const asn1SccSourceAddress reg,
                         const asn1SccWord bitsToReset) {
  asn1SccWordMask tempMask = (asn1SccWordMask)bitsToReset;
  const asn1SccWord tempValue = ~(bitsToReset);
  hwas_PI_RawMemoryAccess_WriteWord_Pi(&reg, &tempMask, &tempValue);
}

asn1SccWord Register_get_bits(const asn1SccSourceAddress reg,
                              const asn1SccWordMask mask) {
  asn1SccWord retValue = 0;
  hwas_PI_RawMemoryAccess_ReadWord_Pi(&reg, &mask, &retValue);
  return retValue;
}

asn1SccWord Register_get_value(const asn1SccSourceAddress reg) {
  asn1SccWord retValue = 0;
  asn1SccWordMask mask = WHOLE_REGISTER_MASK;
  hwas_PI_RawMemoryAccess_ReadWord_Pi(&reg, &mask, &retValue);
  return retValue;
}
