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

#include "PioHwas/PioHwas.h"
#include "PioHwas/PioHwasRegisters.h"
#include "PmcHwas/PmcHwasRegisters.h"
#include "RegisterHwas/RegisterHwas.h"

static inline asn1SccSourceAddress
PioHwas_get_port_register(PioHwas_Port port) {
  switch (port) {
  case PioHwas_Port_A:
    return PIO_HWAS_A_OFFSET;
  case PioHwas_Port_B:
    return PIO_HWAS_B_OFFSET;
  case PioHwas_Port_C:
    return PIO_HWAS_C_OFFSET;
  case PioHwas_Port_D:
    return PIO_HWAS_D_OFFSET;
  case PioHwas_Port_E:
    return PIO_HWAS_E_OFFSET;
  }
}

static inline void PioHwas_init_pin_init_pmc(PioHwas_Port port) {
  switch (port) {
  case PioHwas_Port_A:
    if (!(Register_get_bits(PMC_PCSR0, PMC_PCxR0_PID10_PIOA_MASK)))
      Register_set_bits(PMC_PCER0, (asn1SccWord)PMC_PCxR0_PID10_PIOA_MASK);
    break;
  case PioHwas_Port_B:
    if (!(Register_get_bits(PMC_PCSR0, PMC_PCxR0_PID11_PIOB_MASK)))
      Register_set_bits(PMC_PCER0, (asn1SccWord)PMC_PCxR0_PID11_PIOB_MASK);
    break;
  case PioHwas_Port_C:
    if (!(Register_get_bits(PMC_PCSR0, PMC_PCxR0_PID12_PIOC_MASK)))
      Register_set_bits(PMC_PCER0, (asn1SccWord)PMC_PCxR0_PID12_PIOC_MASK);
    break;
  case PioHwas_Port_D:
    if (!(Register_get_bits(PMC_PCSR0, PMC_PCxR0_PID16_PIOD_MASK)))
      Register_set_bits(PMC_PCER0, (asn1SccWord)PMC_PCxR0_PID16_PIOD_MASK);
    break;
  case PioHwas_Port_E:
    if (!(Register_get_bits(PMC_PCSR0, PMC_PCxR0_PID17_PIOE_MASK)))
      Register_set_bits(PMC_PCER0, (asn1SccWord)PMC_PCxR0_PID17_PIOE_MASK);
    break;
  }
}

static inline void PioHwas_init_pin_set_control(PioHwas *const pio,
                                                PioHwas_Control control) {
  switch (control) {
  case Pio_Control_Pio:
    Register_set_bits(pio->port + PIO_HWAS_PER_OFFSET, pio->pin);
    break;
  case Pio_Control_PeripheralA:
    Register_reset_bits(pio->port + PIO_HWAS_ABCDSR0_OFFSET, pio->pin);
    Register_reset_bits(pio->port + PIO_HWAS_ABCDSR1_OFFSET, pio->pin);
    break;
  case Pio_Control_PeripheralB:
    Register_set_bits(pio->port + PIO_HWAS_ABCDSR0_OFFSET, pio->pin);
    Register_reset_bits(pio->port + PIO_HWAS_ABCDSR1_OFFSET, pio->pin);
    break;
  case Pio_Control_PeripheralC:
    Register_reset_bits(pio->port + PIO_HWAS_ABCDSR0_OFFSET, pio->pin);
    Register_set_bits(pio->port + PIO_HWAS_ABCDSR1_OFFSET, pio->pin);
    break;
  case Pio_Control_PeripheralD:
    Register_set_bits(pio->port + PIO_HWAS_ABCDSR0_OFFSET, pio->pin);
    Register_set_bits(pio->port + PIO_HWAS_ABCDSR1_OFFSET, pio->pin);
    break;
  }
}
static inline void PioHwas_init_pin_set_direction(PioHwas *const pio,
                                                  PioHwas_Direction direction) {
  switch (direction) {
  case PioHwas_Direction_Input:
    Register_set_bits(pio->port + PIO_HWAS_ODR_OFFSET, pio->pin);
    Register_set_bits(pio->port + PIO_HWAS_OWDR_OFFSET, pio->pin);
    break;
  case PioHwas_Direction_Output:
    Register_set_bits(pio->port + PIO_HWAS_OER_OFFSET, pio->pin);
    Register_set_bits(pio->port + PIO_HWAS_OWDR_OFFSET, pio->pin);
    break;
  case PioHwas_Direction_SynchronousOutput:
    Register_set_bits(pio->port + PIO_HWAS_OER_OFFSET, pio->pin);
    Register_set_bits(pio->port + PIO_HWAS_OWER_OFFSET, pio->pin);
    break;
  }
}

static inline void PioHwas_init_pin_set_pull(PioHwas *const pio,
                                             PioHwas_Pull pull) {
  switch (pull) {
  case PioHwas_Pull_None:
    Register_set_bits(pio->port + PIO_HWAS_PUDR_OFFSET, pio->pin);
    Register_set_bits(pio->port + PIO_HWAS_PPDDR_OFFSET, pio->pin);
    break;
  case PioHwas_Pull_Up:
    Register_set_bits(pio->port + PIO_HWAS_PPDDR_OFFSET, pio->pin);
    Register_set_bits(pio->port + PIO_HWAS_PUER_OFFSET, pio->pin);
    break;
  case PioHwas_Pull_Down:
    Register_set_bits(pio->port + PIO_HWAS_PUDR_OFFSET, pio->pin);
    Register_set_bits(pio->port + PIO_HWAS_PPDER_OFFSET, pio->pin);
    break;
  }
}

static inline void PioHwas_init_pin_set_filter(PioHwas *const pio,
                                               PioHwas_Filter filter) {
  switch (filter) {
  case PioHwas_Filter_None:
    Register_set_bits(pio->port + PIO_HWAS_IFDR_OFFSET, pio->pin);
    Register_set_bits(pio->port + PIO_HWAS_IFSCDR_OFFSET, pio->pin);
    break;
  case PioHwas_Filter_Glitch:
    Register_set_bits(pio->port + PIO_HWAS_IFSCDR_OFFSET, pio->pin);
    Register_set_bits(pio->port + PIO_HWAS_IFER_OFFSET, pio->pin);
    break;
  case PioHwas_Filter_Debounce:
    Register_set_bits(pio->port + PIO_HWAS_IFSCER_OFFSET, pio->pin);
    Register_set_bits(pio->port + PIO_HWAS_IFER_OFFSET, pio->pin);
    break;
  }
}

static inline void PioHwas_init_pin_set_schmitt(PioHwas *const pio) {
  Register_set_bits(pio->port + PIO_HWAS_SCHMITT_OFFSET, pio->pin);
}

static inline void PioHwas_init_pin_set_opendrain(PioHwas *const pio) {
  Register_set_bits(pio->port + PIO_HWAS_MDDR_OFFSET, pio->pin);
}

void PioHwas_init_pin(PioHwas *const pio,
                      const PioHwas_Pin_Config *const config) {
  pio->port = PioHwas_get_port_register(config->port);
  pio->pin = config->pin;

  PioHwas_init_pin_init_pmc(config->port);

  PioHwas_init_pin_set_control(pio, config->control);
  PioHwas_init_pin_set_direction(pio, config->direction);
  PioHwas_init_pin_set_pull(pio, config->pull);
  PioHwas_init_pin_set_filter(pio, config->filter);
  PioHwas_init_pin_set_schmitt(pio);
  PioHwas_init_pin_set_opendrain(pio);
}

void PioHwas_set_pin(PioHwas *const pio) {
  Register_set_bits(pio->port + PIO_HWAS_SODR_OFFSET, pio->pin);
}

void PioHwas_reset_pin(PioHwas *const pio) {
  Register_set_bits(pio->port + PIO_HWAS_CODR_OFFSET, pio->pin);
}

void PioHwas_toggle_pin(PioHwas *const pio) {
  PioHwas_get_pin(pio) ? PioHwas_reset_pin(pio) : PioHwas_set_pin(pio);
}

bool PioHwas_get_pin(PioHwas *const pio) {
  return (Register_get_bits(pio->port + PIO_HWAS_PDSR_OFFSET, pio->pin));
}
