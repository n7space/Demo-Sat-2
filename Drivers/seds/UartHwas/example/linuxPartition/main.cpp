/**@file
 * This file is part of the TASTE Linux Runtime.
 *
 * @copyright 2021 N7 Space Sp. z o.o.
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
#include "linux_serial_ccsds/linux_serial_ccsds.h"

#include <cstdio>

#include "Thread.h"

#include "PacketSender.h"

static constexpr int SEND_THREAD_PRIORITY1 = 1;
static constexpr int SEND_THREAD_STACK_SIZE1 = 65536;

static constexpr size_t NUMBER_OF_DEVICES = 1;

void device_interface_deliver_function(const uint8_t *const data,
                                       const size_t data_size) {
  (void)data_size;
  printf("Serial received: %s", data);
}

void *bus_to_driver_private_data[NUMBER_OF_DEVICES];
void *bus_to_driver_send_function[NUMBER_OF_DEVICES];
void *interface_to_deliver_function[NUMBER_OF_DEVICES]{
    reinterpret_cast<void *>(device_interface_deliver_function)};

int main() {
  printf("\n\rDemo app started\n\r");

  PacketSender packetSender;
  packetSender.Init();

  linux_serial_ccsds_private_data serial{};

  taste::Thread sendThread{SEND_THREAD_PRIORITY1, SEND_THREAD_STACK_SIZE1};

  Serial_CCSDS_Linux_Conf_T device{"/tmp/serialTest",
                                   Serial_CCSDS_Linux_Baudrate_T_b9600,
                                   Serial_CCSDS_Linux_Parity_T_odd,
                                   8,
                                   0,
                                   {}};

  serial.driver_init(BUS_INVALID_ID, DEVICE_INVALID_ID, &device, nullptr);

  sendThread.start(&PacketSender::SendThreadMethod, &serial);

  sendThread.join();

  printf("\n\rDemo app finished");
  return 0;
}
