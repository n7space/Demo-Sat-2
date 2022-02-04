/**@file
 * This file is part of the TASTE Runtime SAMV71.
 *
 * @copyright 2022 N7 Space Sp. z o.o.
 *
 * TASTE Runtime SAMV71 was developed under a programme of,
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

#include "FreeRTOS.h"
#include "task.h"

// #include <sys/stat.h>
#include <sys/wait.h>

// int _gettimeofday(struct timeval* tv, void* tzvp);

// int
// _gettimeofday(struct timeval* tv, void* tzvp)
// {
//     // to suppress compiler errors
//     (void)tzvp;
//     uint64_t t = xTaskGetTickCount() * portTICK_PERIOD_MS; // get uptime in
//     miliseconds tv->tv_sec = t / 1000;                                 //
//     convert to seconds tv->tv_usec = (t % 1000) / 1000; // get remaining
//     microseconds return 0;                                              //
//     return non-zero for error
// } // end _gettimeofday()

// pid_t
// waitpid(pid_t a, int* b, int c)
// {
//     return 0;
// }

// pid_t
// _fork(void)
// {
//     return 0;
// }
clock_t _times(struct tms *buf) {}