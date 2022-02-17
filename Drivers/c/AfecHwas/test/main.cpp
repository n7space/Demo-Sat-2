
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

static inline void TeardownResetAfecInstance(AfecHwas *const afec) {
  Register_set_bits(afec->afecAddress, AFEC_HWAS_CR_SWRST_MASK);
}

TEST_GROUP(AfecHwas_init) {
  AfecHwas afec;
  AfecHwas_Instance_Config config;

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

/// \Given an uninitialized Afec1
/// \When the afec is initialized and the configis set with the Prescaler value
///       1 and startup time 0
/// \Then the proper value is written to the MR and EMR
///       register, and no channel is yet enabled.
TEST(AfecHwas_init, instance1Sut0Prescal1) {
  config.instance = AfecHwas_Instance_Afec1;
  config.startupTime = AfecHwas_StartupTime_Sut0;
  config.prescalerValue = 1;

  AfecHwas_init_instance(&afec, &config);
  VerifyConfig(&afec, &config);
}

/// \Given an uninitialized Afec1
/// \When the afec is initialized and the configis set with the Prescaler value
///       1 and startup time 96
/// \Then the proper value is written to the MR and EMR
///       register, and no channel is yet enabled.
TEST(AfecHwas_init, instance1Sut96Prescal1) {
  config.instance = AfecHwas_Instance_Afec1;
  config.startupTime = AfecHwas_StartupTime_Sut96;
  config.prescalerValue = 1;

  AfecHwas_init_instance(&afec, &config);
  VerifyConfig(&afec, &config);
}

/// \Given an uninitialized Afec1
/// \When the afec is initialized and the configis set with the Prescaler value
///       1 and startup time 960
/// \Then the proper value is written to the MR and EMR
///       register, and no channel is yet enabled.
TEST(AfecHwas_init, instance1Sut960Prescal1) {
  config.instance = AfecHwas_Instance_Afec1;
  config.startupTime = AfecHwas_StartupTime_Sut960;
  config.prescalerValue = 1;

  AfecHwas_init_instance(&afec, &config);
  VerifyConfig(&afec, &config);
}

/// \Given an uninitialized Afec0
/// \When the afec is initialized and the configis set with the Prescaler value
///       1 and startup time 0
/// \Then the proper value is written to the MR and EMR
///       register, and no channel is yet enabled.
TEST(AfecHwas_init, instance0Sut0Prescal1) {
  config.instance = AfecHwas_Instance_Afec1;
  config.startupTime = AfecHwas_StartupTime_Sut0;
  config.prescalerValue = 1;

  AfecHwas_init_instance(&afec, &config);
  VerifyConfig(&afec, &config);
}

/// \Given an uninitialized Afec0
/// \When the afec is initialized and the configis set with the Prescaler value
///       7 and startup time 0
/// \Then the proper value is written to the MR and EMR
///       register, and no channel is yet enabled.
TEST(AfecHwas_init, instance0Sut0Prescal7) {
  config.instance = AfecHwas_Instance_Afec1;
  config.startupTime = AfecHwas_StartupTime_Sut0;
  config.prescalerValue = 7;

  AfecHwas_init_instance(&afec, &config);
  VerifyConfig(&afec, &config);
}

TEST_GROUP(AfecHwas_get_value) {
  AfecHwas afec;
  AfecHwas_Instance_Config config;
  AfecHwas_Channel channel;

  static inline void Verify_ChannelDisabled(AfecHwas *const afec) {
    uint32_t actualValue =
        Register_get_bits(afec->afecAddress, WHOLE_REGISTER_MASK);
    LONGS_EQUAL(AFEC_HWAS_CHSR_DEFAULT_VALUE, actualValue);
  }

  static inline void Verify_NoOngoingCoversion(AfecHwas *const afec) {
    CHECK_FALSE(Register_get_bits(afec->afecAddress, AFEC_HWAS_CR_START_MASK));
  }

  static inline void Verify_ProperChannelRead(AfecHwas *const afec,
                                              const AfecHwas_Channel channel) {
    uint32_t actualValue =
        Register_get_bits(afec->afecAddress + AFEC_HWAS_LCDR_OFFSET,
                          AFEC_HWAS_LCDR_CHNB_MASK) >>
        AFEC_HWAS_LCDR_CHNB_POS;
    LONGS_EQUAL(channel, actualValue);
  }
  static inline void Verify(AfecHwas *const afec,
                            const AfecHwas_Channel channel,
                            uint32_t readValue) {
    Verify_ChannelDisabled(afec);
    Verify_NoOngoingCoversion(afec);
    Verify_ProperChannelRead(afec, channel);
    CHECK_TRUE(readValue > 0);
    CHECK_TRUE(readValue < AFEC_HWAS_MAX_VALUE);
  }

  void setup() override {
    config.startupTime = AfecHwas_StartupTime_Sut96;
    config.prescalerValue = 1;
  }

  void teardown() override {
    TeardownResetAfecInstance(&afec);
    memset(&config, 0, sizeof(config));
  }
};

/// \Given an initialized and configured Afec0
/// \When value is read in polling mode from channel 0
/// \Then the proper channel is enable only while conversion is performed and
///       proper data value is read and return
TEST(AfecHwas_get_value, instance0channel0) {
  config.instance = AfecHwas_Instance_Afec0;
  channel = AfecHwas_Channel_0;
  AfecHwas_init_instance(&afec, &config);
  uint32_t readValue = AfecHwas_get_value(&afec, channel);
  Verify(&afec, channel, readValue);
}

/// \Given an initialized and configured Afec0
/// \When value is read in polling mode from channel 11
/// \Then the proper channel is enable only while conversion is performed and
///       proper data value is read and return
TEST(AfecHwas_get_value, instance0channel11) {
  config.instance = AfecHwas_Instance_Afec0;
  channel = AfecHwas_Channel_11;
  AfecHwas_init_instance(&afec, &config);
  uint32_t readValue = AfecHwas_get_value(&afec, channel);
  Verify(&afec, channel, readValue);
}

/// \Given an initialized and configured Afec0
/// \When value is read in polling mode from channel 4
/// \Then the proper channel is enable only while conversion is performed and
///       proper data value is read and return
TEST(AfecHwas_get_value, instance0channel4) {
  config.instance = AfecHwas_Instance_Afec0;
  channel = AfecHwas_Channel_4;
  AfecHwas_init_instance(&afec, &config);
  uint32_t readValue = AfecHwas_get_value(&afec, channel);
  Verify(&afec, channel, readValue);
}

/// \Given an initialized and configured Afec1
/// \When value is read in polling mode from channel 0
/// \Then the proper channel is enable only while conversion is performed and
///       proper data value is read and return
TEST(AfecHwas_get_value, instance1channel0) {
  config.instance = AfecHwas_Instance_Afec1;
  channel = AfecHwas_Channel_0;
  AfecHwas_init_instance(&afec, &config);
  uint32_t readValue = AfecHwas_get_value(&afec, channel);
  Verify(&afec, channel, readValue);
}

/// \Given an initialized and configured Afec1
/// \When value is read in polling mode from channel 11
/// \Then the proper channel is enable only while conversion is performed and
///       proper data value is read and return
TEST(AfecHwas_get_value, instance1channel11) {
  config.instance = AfecHwas_Instance_Afec1;
  channel = AfecHwas_Channel_11;
  AfecHwas_init_instance(&afec, &config);
  uint32_t readValue = AfecHwas_get_value(&afec, channel);
  Verify(&afec, channel, readValue);
}
