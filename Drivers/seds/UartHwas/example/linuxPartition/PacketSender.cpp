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

#include <PacketSender.h>

#include "linux_serial_ccsds/linux_serial_ccsds.h"

#include <cstring>
#include <unistd.h>

uint8_t PacketSender::packetData[PACKET_SIZE]{};

void PacketSender::Init() {
  memcpy(&packetData[SPACE_PACKET_PRIMARY_HEADER_SIZE], TEXT, DATA_SIZE);

  Packetizer_init(&packetizer);
  Packetizer_packetize(&packetizer, Packetizer_PacketType_Telemetry, DEVICE_ID,
                       0, packetData, SPACE_PACKET_PRIMARY_HEADER_SIZE,
                       DATA_SIZE);
}

void PacketSender::SendThreadMethod(void *args) {
  linux_serial_ccsds_private_data *serial;

  static constexpr int numOfExe{10};
  while (true) {
    serial->driver_send(PacketSender::packetData, PACKET_SIZE);
    usleep(250000);
  }
}
