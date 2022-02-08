
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
#include <Pio/Pio.h>
#include <PioHwas/PioHwas.h>
#include <Pmc/Pmc.h>

#ifdef __cplusplus
}
#endif

#define PIO_HWAS_CYCLES 5000

static inline void VerifyPmc(PioHwas_Port port) {
  switch (port) {
  case PioHwas_Port_A:
    CHECK_TRUE(Pmc_isPeripheralClkEnabled(Pmc_PeripheralId_PioA));
    break;
  case PioHwas_Port_B:
    CHECK_TRUE(Pmc_isPeripheralClkEnabled(Pmc_PeripheralId_PioB));
    break;
  case PioHwas_Port_C:
    CHECK_TRUE(Pmc_isPeripheralClkEnabled(Pmc_PeripheralId_PioC));
    break;
  case PioHwas_Port_D:
    CHECK_TRUE(Pmc_isPeripheralClkEnabled(Pmc_PeripheralId_PioD));
    break;
  case PioHwas_Port_E:
    CHECK_TRUE(Pmc_isPeripheralClkEnabled(Pmc_PeripheralId_PioE));
    break;
  }
}

static inline void VerifyPioPsr(const PioHwas &pio) {
  const Pio_Registers *pioReg = (Pio_Registers *)pio.port;
  CHECK_TRUE(pioReg->psr & pio.pin);
}

static inline void
ConvertPioDirrection(Pio_Pin_Config &configPio,
                     const PioHwas_Pin_Config &configHwasPio) {
  switch (configHwasPio.direction) {
  case PioHwas_Direction_Input:
    configPio.direction = Pio_Direction_Input;
    break;
  case PioHwas_Direction_Output:
    configPio.direction = Pio_Direction_Output;
    break;
  }
}

static inline void ConvertPioFilter(Pio_Pin_Config &configPio,
                                    const PioHwas_Pin_Config &configPioHwas) {

  switch (configPioHwas.filter) {
  case PioHwas_Filter_Debounce:
    configPio.filter = Pio_Filter_Debounce;
    break;
  case PioHwas_Filter_Glitch:
    configPio.filter = Pio_Filter_Glitch;
    break;
  case PioHwas_Filter_None:
    configPio.filter = Pio_Filter_None;
    break;
  }
}

static inline void ConvertPioPull(Pio_Pin_Config &configPio,
                                  const PioHwas_Pin_Config &configPioHwas) {

  switch (configPioHwas.pull) {
  case PioHwas_Pull_Down:
    configPio.pull = Pio_Pull_Down;
    break;
  case PioHwas_Pull_Up:
    configPio.pull = Pio_Pull_Up;
    break;
  case PioHwas_Pull_None:
    configPio.pull = Pio_Pull_None;
    break;
  }
}

static inline Pio_Port GetPioPort(PioHwas_Port port) {
  switch (port) {
  case PioHwas_Port_A:
    return Pio_Port_A;
  case PioHwas_Port_B:
    return Pio_Port_B;
  case PioHwas_Port_C:
    return Pio_Port_C;
  case PioHwas_Port_D:
    return Pio_Port_D;
  case PioHwas_Port_E:
    break;
  }
  return Pio_Port_E;
}

static inline Pio_Pin_Config
ConvertConfigPioHwasToConfigPio(PioHwas_Pin_Config &configPioHwas) {
  Pio_Pin_Config configPio;

  ConvertPioDirrection(configPio, configPioHwas);
  ConvertPioFilter(configPio, configPioHwas);
  ConvertPioPull(configPio, configPioHwas);

  configPio.control = Pio_Control_Pio;
  configPio.irq = Pio_Irq_None;
  configPio.isMultiDriveEnabled = false;
  configPio.isSchmittTriggerDisabled = true;
  return configPio;
}

bool operator==(Pio_Pin_Config &lhs, Pio_Pin_Config &rhs) {
  LONGS_EQUAL(lhs.control, rhs.control);
  LONGS_EQUAL(lhs.direction, rhs.direction);
  LONGS_EQUAL(lhs.filter, rhs.filter);
  LONGS_EQUAL(lhs.irq, rhs.irq);
  LONGS_EQUAL(lhs.isMultiDriveEnabled, rhs.isMultiDriveEnabled);
  LONGS_EQUAL(lhs.isSchmittTriggerDisabled, rhs.isSchmittTriggerDisabled);
  LONGS_EQUAL(lhs.pull, rhs.pull);
  return true;
}

static void VerifyConfig(const PioHwas &pioHwas,
                         PioHwas_Pin_Config &configPioHwas) {
  Pio_Pin_Config configPioExpected =
      ConvertConfigPioHwasToConfigPio(configPioHwas);
  Pio_Pin_Config configPioActual;
  Pio pio;
  Pio_init(GetPioPort(configPioHwas.port), &pio);

  int errorCode{0};
  Pio_getPinsConfig(&pio, static_cast<const uint32_t>(pioHwas.pin),
                    &configPioActual, &errorCode);

  LONGS_EQUAL(0, errorCode);
  CHECK_TRUE(configPioExpected == configPioActual);
}

static inline void Verify_PioHwas_init_pin(const PioHwas &testPio,
                                           PioHwas_Pin_Config &config) {
  VerifyPmc(config.port);
  VerifyPioPsr(testPio);
  VerifyConfig(testPio, config);
}

TEST_GROUP(PioHwas_init_pin) {
  PioHwas testPio;
  PioHwas_Pin_Config config;

  void teardown() override {
    Verify_PioHwas_init_pin(testPio, config);

    Pio_Registers *pio = (Pio_Registers *)testPio.port;
    pio->pdr = testPio.pin;
    memset(&config, 0, sizeof(config));
  }
};

/// \Given initialized Pio
/// \When a pin is configured as output, with debounce filter and pull up
/// \Then proper pin configuration can be read
TEST(PioHwas_init_pin, outputPullupDebounce) {
  config = {.port = PioHwas_Port_C,
            .pin = PIO_HWAS_PIN_9,
            .direction = PioHwas_Direction_Output,
            .pull = PioHwas_Pull_Up,
            .filter = PioHwas_Filter_Debounce};
  PioHwas_init_pin(&testPio, &config);
}

/// \Given initialized Pio
/// \When a pin is configured as output, with debounce filter and pull down
/// \Then proper pin configuration can be read
TEST(PioHwas_init_pin, outputPullDownDebounce) {
  config = {.port = PioHwas_Port_C,
            .pin = PIO_HWAS_PIN_9,
            .direction = PioHwas_Direction_Output,
            .pull = PioHwas_Pull_Down,
            .filter = PioHwas_Filter_Debounce};
  PioHwas_init_pin(&testPio, &config);
}

/// \Given initialized Pio
/// \When a pin is configured as output, with glitch filter and pull up
/// \Then proper pin configuration can be read
TEST(PioHwas_init_pin, outputPullupGlitch) {
  config = {.port = PioHwas_Port_C,
            .pin = PIO_HWAS_PIN_9,
            .direction = PioHwas_Direction_Output,
            .pull = PioHwas_Pull_Up,
            .filter = PioHwas_Filter_Glitch};
  PioHwas_init_pin(&testPio, &config);
}

/// \Given initialized Pio
/// \When a pin is configured as output, with glitch filter and no pull
/// \Then proper pin configuration can be read
TEST(PioHwas_init_pin, outputNoPullGlitch) {
  config = {.port = PioHwas_Port_C,
            .pin = PIO_HWAS_PIN_9,
            .direction = PioHwas_Direction_Output,
            .pull = PioHwas_Pull_None,
            .filter = PioHwas_Filter_Glitch};
  PioHwas_init_pin(&testPio, &config);
}

/// \Given initialized Pio
/// \When a pin is configured as output, with no filter and pull up
/// \Then proper pin configuration can be read
TEST(PioHwas_init_pin, outputPullUpNoFilter) {
  config = {.port = PioHwas_Port_C,
            .pin = PIO_HWAS_PIN_9,
            .direction = PioHwas_Direction_Output,
            .pull = PioHwas_Pull_Up,
            .filter = PioHwas_Filter_None};
  PioHwas_init_pin(&testPio, &config);
}

/// \Given initialized Pio
/// \When a pin is configured as input, with debounce filter and pull up
/// \Then proper pin configuration can be read
TEST(PioHwas_init_pin, inputPullUpDebounce) {
  config = {.port = PioHwas_Port_D,
            .pin = PIO_HWAS_PIN_11,
            .direction = PioHwas_Direction_Input,
            .pull = PioHwas_Pull_Up,
            .filter = PioHwas_Filter_Debounce};
  PioHwas_init_pin(&testPio, &config);
}

/// \Given initialized Pio
/// \When a pin is configured as input, with debounce filter and pull down
/// \Then proper pin configuration can be read
TEST(PioHwas_init_pin, inputPullDownDebounce) {
  config = {.port = PioHwas_Port_D,
            .pin = PIO_HWAS_PIN_11,
            .direction = PioHwas_Direction_Input,
            .pull = PioHwas_Pull_Down,
            .filter = PioHwas_Filter_Debounce};
  PioHwas_init_pin(&testPio, &config);
}

/// \Given initialized Pio
/// \When a pin is configured as input, with debounce filter and no pull
/// \Then proper pin configuration can be read
TEST(PioHwas_init_pin, inputNoPullDebounce) {
  config = {.port = PioHwas_Port_D,
            .pin = PIO_HWAS_PIN_11,
            .direction = PioHwas_Direction_Input,
            .pull = PioHwas_Pull_None,
            .filter = PioHwas_Filter_Debounce};
  PioHwas_init_pin(&testPio, &config);
}

/// \Given initialized Pio
/// \When a pin is configured as input, with glitch filter and pull up
/// \Then proper pin configuration can be read
TEST(PioHwas_init_pin, inputPullUpGlitch) {
  config = {.port = PioHwas_Port_D,
            .pin = PIO_HWAS_PIN_11,
            .direction = PioHwas_Direction_Input,
            .pull = PioHwas_Pull_Up,
            .filter = PioHwas_Filter_Glitch};
  PioHwas_init_pin(&testPio, &config);
}

/// \Given initialized Pio
/// \When a pin is configured as input, with no filter and pull up
/// \Then proper pin configuration can be read
TEST(PioHwas_init_pin, inputPullUpNoFilter) {
  config = {.port = PioHwas_Port_D,
            .pin = PIO_HWAS_PIN_11,
            .direction = PioHwas_Direction_Input,
            .pull = PioHwas_Pull_Up,
            .filter = PioHwas_Filter_None};
  PioHwas_init_pin(&testPio, &config);
}

TEST_GROUP(PioHwas_output) {
  PioHwas testPio;
  PioHwas_Pin_Config config = {.port = PioHwas_Port_C,
                               .pin = PIO_HWAS_PIN_9,
                               .direction = PioHwas_Direction_Output,
                               .pull = PioHwas_Pull_Up,
                               .filter = PioHwas_Filter_Debounce};
  void setup() override { PioHwas_init_pin(&testPio, &config); }
  void teardown() override {

    Pio_Registers *pio = (Pio_Registers *)testPio.port;
    pio->pdr = testPio.pin;
  }
};

/**
 * @brief Wait for for the register value to be updated.
 */
inline static void WaitForRegValueToUpdate() {
  for (int i = 0; i < PIO_HWAS_CYCLES; i++)
    asm volatile("nop");
}

/// \Given initalized Pio, with pin in output mode
/// \When pin is set
/// \Then the pin value is set
TEST(PioHwas_output, set) {
  PioHwas_set_pin(&testPio);
  WaitForRegValueToUpdate();
  CHECK_TRUE(PioHwas_get_pin(&testPio));
}

/// \Given initalized Pio, with pin in output mode
/// \When pin is reset
/// \Then the pin value is reset
TEST(PioHwas_output, reset) {
  PioHwas_reset_pin(&testPio);
  WaitForRegValueToUpdate();
  CHECK_FALSE(PioHwas_get_pin(&testPio));
}

/// \Given initalized Pio, with pin in output mode
/// \When pin is toggled
/// \Then the pin value is set when it was previously reset
///   and it is reset if it was prevoisuly set.
TEST(PioHwas_output, toggle) {
  PioHwas_reset_pin(&testPio);
  WaitForRegValueToUpdate();
  CHECK_FALSE(PioHwas_get_pin(&testPio));
  PioHwas_toggle_pin(&testPio);
  WaitForRegValueToUpdate();
  CHECK_TRUE(PioHwas_get_pin(&testPio));
  PioHwas_toggle_pin(&testPio);
  WaitForRegValueToUpdate();
  CHECK_FALSE(PioHwas_get_pin(&testPio));
}

TEST_GROUP(PioHwas_Pull) {
  PioHwas testPio;
  PioHwas_Pin_Config config = {.port = PioHwas_Port_C,
                               .pin = PIO_HWAS_PIN_28,
                               .direction = PioHwas_Direction_Input,
                               .pull = PioHwas_Pull_None,
                               .filter = PioHwas_Filter_None};
  void teardown() override {
    Pio_Registers *pio = (Pio_Registers *)testPio.port;
    pio->pdr = testPio.pin;
  }
};

/// \Given initialized Pio, with pin in input mode
/// \When pin pull down configuration is set
/// \Then pin value changes to "reset".
TEST(PioHwas_Pull, pullDown) {
  config.pull = PioHwas_Pull_Down;
  PioHwas_init_pin(&testPio, &config);
  WaitForRegValueToUpdate();
  CHECK_FALSE(PioHwas_get_pin(&testPio));
}

/// \Given initialized Pio, with pin in input mode
/// \When pin pull up configuration is set
/// \Then pin value changes to "set".
TEST(PioHwas_Pull, pullUp) {
  config.pull = PioHwas_Pull_Up;
  PioHwas_init_pin(&testPio, &config);
  WaitForRegValueToUpdate();
  CHECK_TRUE(PioHwas_get_pin(&testPio));
}
