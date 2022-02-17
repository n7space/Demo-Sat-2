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

/// \brief AFEC register deffinitions

#define AFEC0_HWAS_OFFSET (asn1SccSourceAddress)0x4003C000
#define AFEC1_HWAS_OFFSET (asn1SccSourceAddress)0x40064000

#define AFEC_HWAS_CR_OFFSET (asn1SccSourceAddress)0x00
#define AFEC_HWAS_MR_OFFSET (asn1SccSourceAddress)0x04
#define AFEC_HWAS_EMR_OFFSET (asn1SccSourceAddress)0x08
#define AFEC_HWAS_CHER_OFFSET (asn1SccSourceAddress)0x14
#define AFEC_HWAS_CHDR_OFFSET (asn1SccSourceAddress)0x18
#define AFEC_HWAS_CHSR_OFFSET (asn1SccSourceAddress)0x1C
#define AFEC_HWAS_LCDR_OFFSET (asn1SccSourceAddress)0x20
#define AFEC_HWAS_ISR_OFFSET (asn1SccSourceAddress)0x30

#define AFEC_HWAS_CR_SWRST_MASK (asn1SccWordMask)0x00000001
#define AFEC_HWAS_CR_START_MASK (asn1SccWordMask)0x00000002

#define AFEC_HWAS_MR_ONE_MASK (asn1SccWordMask)0x00800000

#define AFEC_HWAS_MR_PRESCAL_POS (asn1SccWord)8u
#define AFEC_HWAS_MR_STARTUP_POS (asn1SccWord)16u

#define AFEC_HWAS_EMR_TAG_MASK (asn1SccWordMask)0x01000000

#define AFEC_HWAS_LCDR_CHNB_MASK (asn1SccWordMask)0x0F000000
#define AFEC_HWAS_LCDR_LDATA_MASK (asn1SccWordMask)0x0000FFFF

#define AFEC_HWAS_LCDR_CHNB_POS (asn1SccWord)24u

#define AFEC_HWAS_ISR_DRDY_MASK (asn1SccWordMask)0x01000000
