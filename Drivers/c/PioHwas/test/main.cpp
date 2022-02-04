
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

#ifdef __cplusplus
extern "C" {
#endif
#include <Pio/Pio.h>
#include <PioHwas/PioHwas.h>
#include <Pmc/Pmc.h>

#ifdef __cplusplus
}
#endif

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

  configPio.control = Pio_Control_PeripheralA;
  configPio.irq = Pio_Irq_None;
  configPio.isMultiDriveEnabled = false;
  configPio.isSchmittTriggerDisabled = false;
  return configPio;
}

bool operator==(Pio_Pin_Config &lhs, Pio_Pin_Config &rhs) {
  if (lhs.control != rhs.control)
    return false;
  else if (lhs.direction != rhs.direction)
    return false;
  else if (lhs.filter != rhs.filter)
    return false;
  else if (lhs.irq != rhs.irq)
    return false;
  else if (lhs.isMultiDriveEnabled != rhs.isMultiDriveEnabled)
    return false;
  else if (lhs.isSchmittTriggerDisabled != rhs.isSchmittTriggerDisabled)
    return false;
  else if (lhs.pull != rhs.pull)
    return false;
  else
    return true;
}

static void VerifyConfig(const PioHwas &pioHwas,
                         PioHwas_Pin_Config &configPioHwas) {
  Pio_Pin_Config configPioExpected =
      ConvertConfigPioHwasToConfigPio(configPioHwas);
  Pio_Pin_Config configPioActual;
  Pio pio;
  Pio_init(GetPioPort(configPioHwas.port), &pio);

  int errorCode;
  Pio_getPinsConfig(&pio, static_cast<const uint32_t>(pioHwas.pin),
                    &configPioActual, &errorCode);

  LONGS_EQUAL(0, errorCode);
  CHECK_TRUE(configPioActual == configPioExpected);
}

static inline void Verify_PioHwas_init_pin(const PioHwas &testPio,
                                           PioHwas_Pin_Config &config) {

  VerifyPmc(config.port);
  VerifyPioPsr(testPio);
  VerifyConfig(testPio, config);
}

TEST_GROUP(PioHwas) {
  PioHwas testPio;
  void setup() override {}

  void teardown() override {
    Pio_Registers *pio = (Pio_Registers *)testPio.port;
    pio->pdr = testPio.pin;
  }
};

TEST(PioHwas, outputPullupDebounce) {
  PioHwas_Pin_Config config = {.port = PioHwas_Port_C,
                               .pin = PIO_HWAS_PIN_9,
                               .direction = PioHwas_Direction_Output,
                               .pull = PioHwas_Pull_Up,
                               .filter = PioHwas_Filter_Debounce};
  PioHwas_init_pin(&testPio, &config);
}