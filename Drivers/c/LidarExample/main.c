#include "FreeRTOS.h"
#include "task.h"

#include <Hal/Hal.h>
#include <Init/Init.h>

#include <RegisterHwas/RegisterHwas.h>
#include <UartHwas/UartHwas.h>
#include <UartHwas/UartHwasRegisters.h>

#include <stdio.h>
#include <string.h>

#define LIDAR_RX_BUFFER_LEN 100
uint8_t lidarRxBuffer[LIDAR_RX_BUFFER_LEN] = {""};

ByteFifo rxFifo;
UartHwas uart;

#define PRV_INTERRUPT_STACK_SIZE 400
__attribute__((section(".sdramMemorySection"))) static StackType_t
    prvTaskStackBuffer[PRV_INTERRUPT_STACK_SIZE];
__attribute__((
    section(".sdramMemorySection"))) static StaticTask_t prvTaskBuffer;

#define TF_LUNA_DATA_FRAME_HEADER1 0x59
#define TF_LUNA_DATA_FRAME_HEADER2 0x59
#define TF_LUNA_DATA_FRAME_LENGTHT 9

size_t txIndex = 0;
size_t txLength = 0;
uint8_t txBuffer[20];

static void prvTask(void *pvParameters);

void lidarRxCallback(uint8_t readByte) {
  if (!ByteFifo_push(&rxFifo, readByte)) {
    Hal_console_usart_write("Fifo Full\n", 10);
  }
}

void lidarTxCallback(void) {
  ++txIndex;
  if (txIndex < txLength) {
    UartHwas_sendByteAsync(&uart, lidarTxCallback, txBuffer[txIndex]);
  } else {
    Register_set_bits(uart.uartAddress + UART_HWAS_IDR_OFFSET,
                      UART_HWAS_IxR_TXRDY_MASK | UART_HWAS_IxR_TXEMPTY_MASK);
  }
}

extern void
hwas_RI_InterruptSubscription_Interrupt_Ri(const asn1SccInterrupt_Type *irq);
void hwas_RI_InterruptSubscription_Interrupt_Ri(
    const asn1SccInterrupt_Type *irq) {

  switch (irq->interrupt) {
  case Nvic_Irq_Uart0:
  case Nvic_Irq_Uart1:
  case Nvic_Irq_Uart2:
  case Nvic_Irq_Uart3:
  case Nvic_Irq_Uart4:
    UartHwas_handleInterrupt(&uart);
    hwas_PI_InterruptManagement_EnableInterrupt_Pi(&irq->interrupt);
  }
}

int main() {
  Init_setup_hardware();
  Hal_console_usart_init();

  hwas_startup();
  xTaskCreateStatic(prvTask, "Task1", 400, NULL, 1, prvTaskStackBuffer,
                    &prvTaskBuffer);

  vTaskStartScheduler();
  for (;;) {
  }
}

static void parseTfLunaData() {
  uint8_t rxByte;
  uint8_t checksum;
  uint16_t distance;
  uint16_t strength;
  int16_t temp;
  if (ByteFifo_getCount(&rxFifo) >= TF_LUNA_DATA_FRAME_LENGTHT) {
    ByteFifo_pull(&rxFifo, &rxByte);
    if (rxByte == TF_LUNA_DATA_FRAME_HEADER1) {
      checksum = TF_LUNA_DATA_FRAME_HEADER1;
      ByteFifo_pull(&rxFifo, &rxByte);
      if (rxByte == TF_LUNA_DATA_FRAME_HEADER2) {
        checksum += TF_LUNA_DATA_FRAME_HEADER2;
        // Read low 8 bits of distance
        ByteFifo_pull(&rxFifo, &rxByte);
        distance = rxByte;
        checksum += rxByte;
        // Read high 8 bits of distance
        ByteFifo_pull(&rxFifo, &rxByte);
        distance += (rxByte << 8);
        checksum += rxByte;

        // Read low 8 bits of strength
        ByteFifo_pull(&rxFifo, &rxByte);
        checksum += rxByte;
        strength = rxByte;

        // Read high 8 bits of strength
        ByteFifo_pull(&rxFifo, &rxByte);
        checksum += rxByte;
        strength += (rxByte << 8);

        // Read low 8 bits of temperature
        ByteFifo_pull(&rxFifo, &rxByte);
        checksum += rxByte;
        temp = rxByte;

        // Read high 8 bits of temperature
        ByteFifo_pull(&rxFifo, &rxByte);
        checksum += rxByte;
        temp += (rxByte << 8);

        // Read and check crc
        ByteFifo_pull(&rxFifo, &rxByte);
        if (checksum != rxByte) {
          Hal_console_usart_write("Wrong CRC\n", 10);
        } else {
          char buffer[30];
          sprintf(buffer, "D: %i S: %i T: %.2f\n", distance, strength,
                  ((float)temp / 8.0f - 256.0f));
          Hal_console_usart_write(buffer, strlen(buffer));
        }
      } else {
        return;
      }
    } else {
      return;
    }
  }
}

static void prvTask(void *pvParameters) {
  UartHwas_Config config = {.baudrate = UartHwas_Baudrate_9600,
                            .id = UartHwas_Id_2,
                            .irqNumber = Nvic_Irq_Uart2};
  (void)pvParameters;

  /* Block for 500ms. */
  const TickType_t xDelay = 500 / portTICK_PERIOD_MS;

  ByteFifo_init(&rxFifo, lidarRxBuffer, LIDAR_RX_BUFFER_LEN);
  UartHwas_init(&uart, &config);
  UartHwas_readByteAsync(&uart, lidarRxCallback);

  for (;;) {
    parseTfLunaData();
    taskYIELD();
  }
}

void vApplicationMallocFailedHook() { configASSERT(0); }

void vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName) {
  (void)pxTask;
  (void)pcTaskName;

  configASSERT(0);
}

void vApplicationIdleHook() {
  volatile size_t xFreeHeapSpace = xPortGetFreeHeapSize();
  (void)xFreeHeapSpace;
}

void vApplicationTickHook() {}
