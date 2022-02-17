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

#include "hwas/hwas.h"

/// \brief Enumeration listing AFEC instances.
typedef enum {
  AfecHwas_Instance_Afec0 = 0, ///< Instance 0.
  AfecHwas_Instance_Afec1 = 1, ///< Instance 1.
} AfecHwas_Instance;

/// \brief Enumeration listing possible Startup Times.
typedef enum {
  AfecHwas_StartupTime_Sut0 = 0,    ///< 0 periods of AFE clock.
  AfecHwas_StartupTime_Sut8 = 1,    ///< 8 periods of AFE clock.
  AfecHwas_StartupTime_Sut16 = 2,   ///< 16 periods of AFE clock.
  AfecHwas_StartupTime_Sut24 = 3,   ///< 24 periods of AFE clock.
  AfecHwas_StartupTime_Sut64 = 4,   ///< 64 periods of AFE clock.
  AfecHwas_StartupTime_Sut80 = 5,   ///< 80 periods of AFE clock.
  AfecHwas_StartupTime_Sut96 = 6,   ///< 96 periods of AFE clock.
  AfecHwas_StartupTime_Sut112 = 7,  ///< 112 periods of AFE clock.
  AfecHwas_StartupTime_Sut512 = 8,  ///< 512 periods of AFE clock.
  AfecHwas_StartupTime_Sut576 = 9,  ///< 576 periods of AFE clock.
  AfecHwas_StartupTime_Sut640 = 10, ///< 640 periods of AFE clock.
  AfecHwas_StartupTime_Sut704 = 11, ///< 704 periods of AFE clock.
  AfecHwas_StartupTime_Sut768 = 12, ///< 768 periods of AFE clock.
  AfecHwas_StartupTime_Sut832 = 13, ///< 832 periods of AFE clock.
  AfecHwas_StartupTime_Sut896 = 14, ///< 896 periods of AFE clock.
  AfecHwas_StartupTime_Sut960 = 15, ///< 960 periods of AFE clock.
} AfecHwas_StartupTime;

/// \brief Enumeration listing possible channel numbers.
typedef enum {
  AfecHwas_Channel_0 = 0,
  AfecHwas_Channel_1,
  AfecHwas_Channel_2,
  AfecHwas_Channel_3,
  AfecHwas_Channel_4,
  AfecHwas_Channel_5,
  AfecHwas_Channel_6,
  AfecHwas_Channel_7,
  AfecHwas_Channel_8,
  AfecHwas_Channel_9,
  AfecHwas_Channel_10,
  AfecHwas_Channel_11,
  AfecHwas_Channel_Number
} AfecHwas_Channel;

/// \brief Structure representing AFEC configuration.
typedef struct {
  AfecHwas_Instance instance;
  AfecHwas_StartupTime startupTime;
  uint8_t prescalerValue;
} AfecHwas_Instance_Config;

/// \brief Afec descriptor
typedef struct {
  asn1SccSourceAddress afecAddress; //< AFEC instance address
} AfecHwas;

#define AFEC_HWAS_RESOLUTION 12u
#define AFEC_HWAS_MAX_VALUE 0x1 << AFEC_HWAS_RESOLUTION

/// \brief Sets the AFEC configuration.
/// \param [in,out] afec Afec descriptor.
/// \param [in] config AFEC configuration.
void AfecHwas_init_instance(AfecHwas *const afec,
                            const AfecHwas_Instance_Config *const config);

/// \brief Gets the result of the conversion from the given channel in a polling
///        mode
/// \param [in] afec Afec descriptor.
/// \param[in] channel Source channel number
/// \returns Conversion result.
uint32_t AfecHwas_get_value(AfecHwas *const afec,
                            const AfecHwas_Channel channel);
