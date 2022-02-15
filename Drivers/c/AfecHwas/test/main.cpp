
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

#include "TestUtils/main.h"

#include <cstring>

#ifdef __cplusplus
extern "C" {
#endif

#include "AfecHwas/AfecHwas.h"
#include "AfecHwas/AfecHwasRegisters.h"
#include "RegisterHwas/RegisterHwas.h"

#ifdef __cplusplus
}
#endif

static constexpr uint32_t AFEC_HWAS_MR_DEFAULT_VALUE = 0x30800000;
static constexpr uint32_t AFEC_HWAS_EMR_DEFAULT_VALUE = AFEC_HWAS_EMR_TAG_MASK;
static constexpr uint32_t AFEC_HWAS_CHSR_DEFAULT_VALUE = 0x00000000;

TEST_GROUP(AfecHwas_init) {
  AfecHwas afec;
  AfecHwas_Instance_Config config;

  static inline void TeardownResetAfecInstance(AfecHwas *const afec) {
    Register_set_bits(afec->afecAddress, AFEC_HWAS_CR_SWRST_MASK);
  }

  static inline void VerifyConfig_MR(
      AfecHwas *const afec, const AfecHwas_Instance_Config *const config) {
    const uint32_t actualValue = Register_get_bits(
        afec->afecAddress + AFEC_HWAS_MR_OFFSET, WHOLE_REGISTER_MASK);

    const uint32_t expectedValue =
        AFEC_HWAS_MR_DEFAULT_VALUE |
        (config->prescalerValue << AFEC_HWAS_MR_PRESCAL_POS) |
        (config->startupTime << AFEC_HWAS_MR_STARTUP_POS);

    LONGS_EQUAL(expectedValue, actualValue);
  }

  static inline void VerifyConfig_EMR(
      AfecHwas *const afec, const AfecHwas_Instance_Config *const config) {
    const uint32_t actualValue = Register_get_bits(
        afec->afecAddress + AFEC_HWAS_EMR_OFFSET, WHOLE_REGISTER_MASK);

    LONGS_EQUAL(AFEC_HWAS_EMR_DEFAULT_VALUE, actualValue);
  }

  static inline void VerifyConfig_CHSR(AfecHwas *const afec) {
    const uint32_t actualValue = Register_get_bits(
        afec->afecAddress + AFEC_HWAS_CHSR_OFFSET, WHOLE_REGISTER_MASK);

    LONGS_EQUAL(AFEC_HWAS_CHSR_DEFAULT_VALUE, actualValue);
  }

  static inline void VerifyConfig(
      AfecHwas *const afec, const AfecHwas_Instance_Config *const config) {
    VerifyConfig_MR(afec, config);
    VerifyConfig_EMR(afec, config);
    VerifyConfig_CHSR(afec);
  }

  void setup() override {}

  void teardown() override {
    TeardownResetAfecInstance(&afec);
    memset(&config, 0, sizeof(config));
  }
};

TEST(AfecHwas_init, instance1Sut0Prescal1) {
  config.instance = AfecHwas_Instance_Afec1;
  config.startupTime = AfecHwas_StartupTime_Sut0;
  config.prescalerValue = 1;

  AfecHwas_init_instance(&afec, &config);
  VerifyConfig(&afec, &config);
}

TEST(AfecHwas_init, instance1Sut96Prescal1) {
  config.instance = AfecHwas_Instance_Afec1;
  config.startupTime = AfecHwas_StartupTime_Sut96;
  config.prescalerValue = 1;

  AfecHwas_init_instance(&afec, &config);
  VerifyConfig(&afec, &config);
}

TEST(AfecHwas_init, instance1Sut960Prescal1) {
  config.instance = AfecHwas_Instance_Afec1;
  config.startupTime = AfecHwas_StartupTime_Sut960;
  config.prescalerValue = 1;

  AfecHwas_init_instance(&afec, &config);
  VerifyConfig(&afec, &config);
}

TEST(AfecHwas_init, instance0Sut0Prescal1) {
  config.instance = AfecHwas_Instance_Afec1;
  config.startupTime = AfecHwas_StartupTime_Sut0;
  config.prescalerValue = 1;

  AfecHwas_init_instance(&afec, &config);
  VerifyConfig(&afec, &config);
}
