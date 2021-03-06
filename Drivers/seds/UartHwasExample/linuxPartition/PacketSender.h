/**@file
 * This file is part of the TASTE DemoSat2
 *
 * @copyright 2022 N7 Space Sp. z o.o.
 *
 * TASTE Linux Runtime was developed under a programme of,
 * and funded by, the European Space Agency (the "ESA").
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

#ifndef PACKET_SENDER_H
#define PACKET_SENDER_H

#include "linux_serial_ccsds/linux_serial_ccsds.h"

extern "C" {
#include <Packetizer.h>
}

class PacketSender {
public:
  void Init();
  void SendPacket();

private:
  static constexpr uint16_t DEVICE_ID = 0;

  static constexpr char const *TEXT{"Hello\n\r"};

  static constexpr size_t DATA_SIZE = sizeof(TEXT);
  static constexpr size_t PACKET_SIZE = SPACE_PACKET_PRIMARY_HEADER_SIZE +
                                        DATA_SIZE +
                                        SPACE_PACKET_ERROR_CONTROL_SIZE;

private:
  Packetizer packetizer{};
  static uint8_t packetData[PACKET_SIZE];
  linux_serial_ccsds_private_data serial;
};

#endif
