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

#include <cstdio>
#include <cstring>

#include "PacketSender.h"

static constexpr size_t NUMBER_OF_DEVICES = 1;
static constexpr char const *RX_MSG = {"Msg Received\n\r"};

PacketSender tester;

void msgCallback(const uint8_t *const data, const size_t data_size) {
  if (memcmp(data, RX_MSG, strlen(RX_MSG))) {
    printf("Linux: FAILED\n\r");
    while (true) {
    }
  } else {
    printf("Linux: PASSED\n\r");
    tester.SendPacket();
  }
}

void *bus_to_driver_private_data[NUMBER_OF_DEVICES];
void *bus_to_driver_send_function[NUMBER_OF_DEVICES];
void *interface_to_deliver_function[NUMBER_OF_DEVICES]{
    reinterpret_cast<void *>(msgCallback)};

int main() {
  printf("\n\rDemo app started\n\r");

  // Setup test
  tester.Init();
  // Exercise test
  tester.SendPacket();
  while (true) {
  }
  return 0;
}
