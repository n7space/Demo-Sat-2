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

#pragma once

/// \brief PMC register offsets
#define PMC_OFFSET (asn1SccSourceAddress)0x400E0600
#define PMC_PCER0_OFFSET (asn1SccSourceAddress)0x0010
#define PMC_PCDR0_OFFSET (asn1SccSourceAddress)0x0014
#define PMC_PCSR0_OFFSET (asn1SccSourceAddress)0x0018

#define PMC_PCER1_OFFSET (asn1SccSourceAddress)0x0100
#define PMC_PCDR1_OFFSET (asn1SccSourceAddress)0x0104
#define PMC_PCSR1_OFFSET (asn1SccSourceAddress)0x0108

#define PMC_PCxR0_PID10_PIOA_POSITION 10u
#define PMC_PCxR0_PID11_PIOB_POSITION 11u
#define PMC_PCxR0_PID12_PIOC_POSITION 12u
#define PMC_PCxR0_PID16_PIOD_POSITION 16u
#define PMC_PCxR0_PID17_PIOE_POSITION 17u
#define PMC_PCxR0_PID29_AFEC0_POSITION 29u

#define PMC_PCxR1_PID40_AFEC1_POSITION 8u

#define PMC_PCxR0_PID10_PIOA_MASK                                              \
  (asn1SccWordMask)(0x1 << PMC_PCxR0_PID10_PIOA_POSITION)
#define PMC_PCxR0_PID11_PIOB_MASK                                              \
  (asn1SccWordMask)(0x1 << PMC_PCxR0_PID11_PIOB_POSITION)
#define PMC_PCxR0_PID12_PIOC_MASK                                              \
  (asn1SccWordMask)(0x1 << PMC_PCxR0_PID12_PIOC_POSITION)
#define PMC_PCxR0_PID16_PIOD_MASK                                              \
  (asn1SccWordMask)(0x1 << PMC_PCxR0_PID16_PIOD_POSITION)
#define PMC_PCxR0_PID17_PIOE_MASK                                              \
  (asn1SccWordMask)(0x1 << PMC_PCxR0_PID17_PIOE_POSITION)
#define PMC_PCxR0_PID29_AFEC0_MASK                                             \
  (asn1SccWordMask)(0x1 << PMC_PCxR0_PID29_AFEC0_POSITION)
#define PMC_PCxR1_PID40_AFEC1_MASK                                             \
  (asn1SccWordMask)(0x1 << PMC_PCxR1_PID40_AFEC1_POSITION)

#define PMC_PCER0 (asn1SccSourceAddress)(PMC_OFFSET + PMC_PCER0_OFFSET)
#define PMC_PCDR0 (asn1SccSourceAddress)(PMC_OFFSET + PMC_PCDR0_OFFSET)
#define PMC_PCSR0 (asn1SccSourceAddress)(PMC_OFFSET + PMC_PCSR0_OFFSET)
#define PMC_PCER1 (asn1SccSourceAddress)(PMC_OFFSET + PMC_PCER1_OFFSET)
#define PMC_PCDR1 (asn1SccSourceAddress)(PMC_OFFSET + PMC_PCDR1_OFFSET)
#define PMC_PCSR1 (asn1SccSourceAddress)(PMC_OFFSET + PMC_PCSR1_OFFSET)
