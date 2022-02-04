
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

static void VerifyPmc(PioHwas_Port port) {
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

static void VerifyPioPsr(const PioHwas &pio) {
  const Pio_Registers *pioReg = (Pio_Registers *)pio.port;
  CHECK_TRUE(pioReg->psr & pio.pin);
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
  VerifyPmc(config.port);
  VerifyPioPsr(testPio);
}