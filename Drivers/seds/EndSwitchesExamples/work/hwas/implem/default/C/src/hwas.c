#include "hwas.h"

#include <Nvic/Nvic.h>

#include <string.h>
#include <assert.h>

#include <FreeRTOS.h>
#include <queue.h>
#include <task.h>

static volatile bool interruptSubscribe[Nvic_InterruptCount] = { 0 };

#define HWAS_INTERRUPT_QUEUE_SIZE 100
#define HWAS_INTERRUPT_QUEUE_ITEM_SIZE (sizeof(asn1SccInterrupt_Type))
#define HWAS_INTERRUPT_STACK_SIZE 100
#define HWAS_INTERRUPT_PRIORITY 1

#define PERIPH_INTERRUPT_PRIORITY 1

__attribute__((section(".sdramMemorySection"))) static volatile QueueHandle_t hwasInterruptQueueHandle;
__attribute__((section(".sdramMemorySection"))) static uint8_t
        hwasInterruptQueueStorageBuffer[HWAS_INTERRUPT_QUEUE_SIZE * HWAS_INTERRUPT_QUEUE_ITEM_SIZE];
__attribute__((section(".sdramMemorySection"))) static StaticQueue_t hwasInterruptQueueBuffer;

__attribute__((section(".sdramMemorySection"))) static StackType_t hwasTaskStackBuffer[HWAS_INTERRUPT_STACK_SIZE];
__attribute__((section(".sdramMemorySection"))) static StaticTask_t hwasTaskBuffer;

void
HwasHandleInterrupt(asn1SccInterrupt_Type* irq)
{
    xQueueSendFromISR(hwasInterruptQueueHandle, irq, NULL);
    hwas_PI_InterruptManagement_DisableInterrupt_Pi(&irq->interrupt);
}

void
PIOA_Handler(void)
{
    if(interruptSubscribe[Nvic_Irq_PioA]) {
        asn1SccInterrupt_Type irq = { .interrupt = Nvic_Irq_PioA };
        HwasHandleInterrupt(&irq);
    }
}

void
PIOB_Handler(void)
{
    if(interruptSubscribe[Nvic_Irq_PioB]) {
        asn1SccInterrupt_Type irq = { .interrupt = Nvic_Irq_PioB };
        HwasHandleInterrupt(&irq);
    }
}

void
PIOC_Handler(void)
{
    if(interruptSubscribe[Nvic_Irq_PioC]) {
        asn1SccInterrupt_Type irq = { .interrupt = Nvic_Irq_PioC };
        HwasHandleInterrupt(&irq);
    }
}

void
PIOD_Handler(void)
{
    if(interruptSubscribe[Nvic_Irq_PioD]) {
        asn1SccInterrupt_Type irq = { .interrupt = Nvic_Irq_PioD };
        HwasHandleInterrupt(&irq);
    }
}

void
PIOE_Handler(void)
{
    if(interruptSubscribe[Nvic_Irq_PioE]) {
        asn1SccInterrupt_Type irq = { .interrupt = Nvic_Irq_PioE };
        HwasHandleInterrupt(&irq);
    }
}

void
ISI_Handler(void)
{
    if(interruptSubscribe[Nvic_Irq_Isi]) {
        asn1SccInterrupt_Type irq = { .interrupt = Nvic_Irq_Isi };
        HwasHandleInterrupt(&irq);
    }
}

void
GMAC_Handler(void)
{
    if(interruptSubscribe[Nvic_Irq_Gmac]) {
        asn1SccInterrupt_Type irq = { .interrupt = Nvic_Irq_Gmac };
        HwasHandleInterrupt(&irq);
    }
}

void
SPI0_Handler(void)
{
    if(interruptSubscribe[Nvic_Irq_Spi0]) {
        asn1SccInterrupt_Type irq = { .interrupt = Nvic_Irq_Spi0 };
        HwasHandleInterrupt(&irq);
    }
}

void
SPI1_Handler(void)
{
    if(interruptSubscribe[Nvic_Irq_Spi1]) {
        asn1SccInterrupt_Type irq = { .interrupt = Nvic_Irq_Spi1 };
        HwasHandleInterrupt(&irq);
    }
}

void
TWIHS0_Handler(void)
{
    if(interruptSubscribe[Nvic_Irq_Twihs0]) {
        asn1SccInterrupt_Type irq = { .interrupt = Nvic_Irq_Twihs0 };
        HwasHandleInterrupt(&irq);
    }
}

void
TWIHS1_Handler(void)
{
    if(interruptSubscribe[Nvic_Irq_Twihs1]) {
        asn1SccInterrupt_Type irq = { .interrupt = Nvic_Irq_Twihs1 };
        HwasHandleInterrupt(&irq);
    }
}

void
TWIHS2_Handler(void)
{
    if(interruptSubscribe[Nvic_Irq_Twihs2]) {
        asn1SccInterrupt_Type irq = { .interrupt = Nvic_Irq_Twihs2 };
        HwasHandleInterrupt(&irq);
    }
}

void
MCAN0_Handler(void)
{
    if(interruptSubscribe[Nvic_Irq_Mcan0_Irq0]) {
        asn1SccInterrupt_Type irq = { .interrupt = Nvic_Irq_Mcan0_Irq0 };
        HwasHandleInterrupt(&irq);
    }
    if(interruptSubscribe[Nvic_Irq_Mcan0_Irq1]) {
        asn1SccInterrupt_Type irq = { .interrupt = Nvic_Irq_Mcan0_Irq1 };
        HwasHandleInterrupt(&irq);
    }
}

void
MCAN1_Handler(void)
{
    if(interruptSubscribe[Nvic_Irq_Mcan1_Irq0]) {
        asn1SccInterrupt_Type irq = { .interrupt = Nvic_Irq_Mcan1_Irq0 };
        HwasHandleInterrupt(&irq);
    }
    if(interruptSubscribe[Nvic_Irq_Mcan1_Irq1]) {
        asn1SccInterrupt_Type irq = { .interrupt = Nvic_Irq_Mcan1_Irq1 };
        HwasHandleInterrupt(&irq);
    }
}

void hwas_RI_InterruptSubscription_Interrupt_Ri(asn1SccInterrupt_Type *value)
{

}

void
HwasInterruptHandlerTask(void* args)
{
    (void)args;
    while(true) {
        asn1SccInterrupt_Type value;
        if(xQueueReceive(hwasInterruptQueueHandle, &value, portMAX_DELAY) == pdTRUE) {
            hwas_RI_InterruptSubscription_Interrupt_Ri(&value);
        } else {
            assert(false && "Error while reading the queue");
            break;
        }
    }
}

void
hwas_startup(void)
{
    memset((void*)interruptSubscribe, 0, Nvic_InterruptCount);
    hwasInterruptQueueHandle = xQueueCreateStatic(HWAS_INTERRUPT_QUEUE_SIZE,
                                                  HWAS_INTERRUPT_QUEUE_ITEM_SIZE,
                                                  hwasInterruptQueueStorageBuffer,
                                                  &hwasInterruptQueueBuffer);
    assert(hwasInterruptQueueHandle != NULL);
    assert(xTaskCreateStatic(HwasInterruptHandlerTask,
                             "HwasInterruptHandlerTask",
                             HWAS_INTERRUPT_STACK_SIZE,
                             NULL,
                             HWAS_INTERRUPT_PRIORITY,
                             hwasTaskStackBuffer,
                             &hwasTaskBuffer)
           != NULL);
}

void
hwas_PI_InterruptManagement_DisableInterrupt_Pi(const asn1SccInterruptNumber* IN_interrupt)
{
    Nvic_Irq irqNumber = (Nvic_Irq)*IN_interrupt;
    switch(irqNumber) {
        case Nvic_Irq_Usart1:
        case Nvic_Irq_Xdmac:
            break;
        default:
            Nvic_disableInterrupt(irqNumber);
    }
}

void
hwas_PI_InterruptManagement_EnableInterrupt_Pi(const asn1SccInterruptNumber* IN_interrupt)
{
    Nvic_Irq irqNumber = (Nvic_Irq)*IN_interrupt;
    switch(irqNumber) {
        case Nvic_Irq_Usart1:
        case Nvic_Irq_Xdmac:
            break;
        default:
            Nvic_setInterruptPriority(irqNumber, PERIPH_INTERRUPT_PRIORITY);
            Nvic_enableInterrupt(irqNumber);
    }
}

void
hwas_PI_InterruptSubscriptionManagement_SubscribeToInterrupt_Pi(const asn1SccInterruptNumber* IN_interrupt)
{
    interruptSubscribe[*IN_interrupt] = true;
}

void
hwas_PI_RawMemoryAccess_ReadWord_Pi(const asn1SccSourceAddress* IN_address,
                                    const asn1SccWordMask* IN_mask,
                                    asn1SccWord* OUT_value)
{
    uint32_t* address = (uint32_t*)((uint32_t)*IN_address);
    uint32_t maskValue = (uint32_t)*IN_mask;
    uint32_t* addressOut = (uint32_t*)OUT_value;
    *addressOut = maskValue & *address;
}


void
hwas_PI_RawMemoryAccess_WriteWord_Pi(const asn1SccDestinationAddress* IN_address,
                                     const asn1SccWordMask* IN_mask,
                                     const asn1SccWord* IN_value)
{
    uint32_t* address = (uint32_t*)((uint32_t)*IN_address);
    uint32_t regValue = (uint32_t)*address;
    uint32_t mask = (uint32_t)*IN_mask;
    uint32_t valueToSet = (uint32_t)*IN_value;
    regValue &= ~(mask);
    regValue |= (mask & valueToSet);

    *address = regValue;
}

void
hwas_PI_RawMemoryAccess_ExclusiveReadWord_Pi(const asn1SccSourceAddress* IN_address,
                                             const asn1SccWordMask* IN_mask,
                                             asn1SccWord* OUT_value)
{
    volatile uint32_t memVal;
    uint32_t maskValue = (uint32_t)*IN_mask;
    volatile uint32_t* address = (uint32_t*)((uint32_t)*IN_address);

    /// Read
    __asm volatile("   ldrex  %[memVal],   [%[address]]  \n\r"
                   : [memVal] "=&r"(memVal)
                   : [address] "r"(address)
                   : "memory");

    uint32_t* addressOut = (uint32_t*)OUT_value;
    *addressOut = maskValue & memVal;
}

void
hwas_PI_RawMemoryAccess_ExclusiveWriteWord_Pi(const asn1SccDestinationAddress* IN_address,
                                              const asn1SccWordMask* IN_mask,
                                              const asn1SccWord* IN_value,
                                              asn1SccByte* OUT_status)
{
    volatile uint32_t* address = (uint32_t*)((uint32_t)*IN_address);
    volatile uint32_t newValue = ((uint32_t)*IN_value) & ((uint32_t)*IN_mask);
    volatile uint32_t result = 1;
    /// Write
    __asm volatile("    strex   %[result],  %[newValue], [%[address]] \n\r"
                   "    dmb"
                   : [result] "=&r"(result)
                   : [newValue] "r"(newValue), [address] "r"(address)
                   : "memory");
    *OUT_status = (asn1SccByte)result;
}
