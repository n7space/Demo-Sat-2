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

#include "AfecHwas/AfecHwas.h"
#include "AfecHwas/AfecHwasRegisters.h"

#include "PmcHwas/PmcHwasRegisters.h"
#include "RegisterHwas/RegisterHwas.h"

#include <assert.h>

static inline asn1SccSourceAddress
Afec_init_get_afec_register(const AfecHwas_Instance instance) {
  switch (instance) {
  case AfecHwas_Instance_Afec0:
    return AFEC0_HWAS_OFFSET;
  case AfecHwas_Instance_Afec1:
    return AFEC1_HWAS_OFFSET;
  }
}

static inline void Afec_init_pmc_init(AfecHwas_Instance instance) {
  switch (instance) {
  case AfecHwas_Instance_Afec0:
    if (!(Register_get_bits(PMC_PCSR0, PMC_PCxR0_PID29_AFEC0_MASK)))
      Register_set_bits(PMC_PCER0, (asn1SccWord)PMC_PCxR0_PID29_AFEC0_MASK);
    break;
  case AfecHwas_Instance_Afec1:
    if (!(Register_get_bits(PMC_PCSR1, PMC_PCxR1_PID40_AFEC1_MASK)))
      Register_set_bits(PMC_PCER1, (asn1SccWord)PMC_PCxR1_PID40_AFEC1_MASK);
    break;
  }
}

static inline void
Afec_init_set_mode(AfecHwas *const afec,
                   const AfecHwas_Instance_Config *const config) {

  assert(config->startupTime <= AfecHwas_StartupTime_Sut960);
  asn1SccWord bitsToSet = AFEC_HWAS_MR_ONE_MASK |
                          (config->prescalerValue << AFEC_HWAS_MR_PRESCAL_POS) |
                          (config->startupTime << AFEC_HWAS_MR_STARTUP_POS);

  Register_set_bits(afec->afecAddress + AFEC_HWAS_MR_OFFSET, bitsToSet);
}

static inline void Afec_init_set_extended_mode(AfecHwas *const afec) {
  Register_set_bits(afec->afecAddress + AFEC_HWAS_EMR_OFFSET,
                    AFEC_HWAS_EMR_TAG_MASK);
}

void AfecHwas_init_instance(AfecHwas *const afec,
                            const AfecHwas_Instance_Config *const config) {

  afec->afecAddress = Afec_init_get_afec_register(config->instance);
  Afec_init_pmc_init(config->instance);
  Afec_init_set_mode(afec, config);
  Afec_init_set_extended_mode(afec);
}

uint32_t AfecHwas_get_value(AfecHwas *const afec,
                            const AfecHwas_Channel channel) {
  asn1SccWord channelToEnable = 0x01 << channel;

  Register_set_bits(afec->afecAddress + AFEC_HWAS_CHDR_OFFSET,
                    ~channelToEnable);
  Register_set_bits(afec->afecAddress + AFEC_HWAS_CHER_OFFSET, channelToEnable);

  while (!(Register_get_bits(afec->afecAddress + AFEC_HWAS_CHSR_OFFSET,
                             channelToEnable))) {
  }

  Register_set_bits(afec->afecAddress + AFEC_HWAS_CR_OFFSET,
                    AFEC_HWAS_CR_START_MASK);
  while (!(Register_get_bits(afec->afecAddress + AFEC_HWAS_ISR_OFFSET,
                             AFEC_HWAS_ISR_DRDY_MASK))) {
  }

  return Register_get_bits(afec->afecAddress + AFEC_HWAS_LCDR_OFFSET,
                           AFEC_HWAS_LCDR_LDATA_MASK);
}
