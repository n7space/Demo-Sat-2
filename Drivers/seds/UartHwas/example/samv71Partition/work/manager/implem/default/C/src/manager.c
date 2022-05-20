/* Body file for function Manager
 * Generated by TASTE on 2022-04-15 17:49:28
 * You can edit this file, it will not be overwritten
 * Provided interfaces : UartHwas_ReadByteAsyncCmd_Ri, UartHwas_SendByteAsyncCmd_Ri
 * Required interfaces : UartHwas_InitUartCmd_Pi, UartHwas_ReadByteAsyncCmd_Pi, UartHwas_SendByteAsyncCmd_Pi
 * User-defined properties for this function:
 * Timers              : 
 */
#include "manager.h"
#include <string.h>

#include <FreeRTOS.h>
#include <task.h>

#include <Escaper.h>
#include <Packetizer.h>
#include <Broker.h>

#include <Hal.h>

static bool wasInitialized = false;

static asn1SccUartHwas uart;
static asn1SccUartHwasConfig config = {.mInstance = asn1SccuartHwas_Instance_4, .mBaudrate = asn1SccuartHwas_Baudrate9600};

static asn1SccReadByteAsyncCmd_Type readByte;

static const char const * RX_MSG = {"Hello\n\r"};
static const char const * TX_MSG = {"Msg Received\n\r"};

#define RX_MSG_LENGTH strlen(RX_MSG)
#define TX_MSG_LENGTH strlen(TX_MSG)

#define TX_PACKET_LENGTH    SPACE_PACKET_PRIMARY_HEADER_SIZE +\
                            14 +\
                            SPACE_PACKET_ERROR_CONTROL_SIZE

static char txBuffer[TX_PACKET_LENGTH] = {""};

const uint8_t * ERR_MSG = {"SAM: FAILED\n\r"};
const uint8_t * SUCCESS_MSG = {"SAM: PASSED\n\r"};

static int sentBytes = 0;
static size_t bytesToSend;

Escaper escaper;
Packetizer packetizer;

#define SOURCE_DEVICE_ID 0
#define DESTINATION_DEVICE_ID 0

#define ENCODED_PACKET_BUFFER_SIZE 100
uint8_t encodedPacketBuffer[ENCODED_PACKET_BUFFER_SIZE] = {""};

#define DECODED_PACKET_BUFFER_SIZE 100
uint8_t decodedPacketBuffer[DECODED_PACKET_BUFFER_SIZE] = {""};

extern deliver_function interface_to_deliver_function[INTERFACE_MAX_ID];

void managerMsgCallback(uint8_t* const msg, const size_t msgLength);

inline static manager_initPacketizer()
{
    Packetizer_init(&packetizer);
    memcpy(&txBuffer[SPACE_PACKET_PRIMARY_HEADER_SIZE], TX_MSG, TX_MSG_LENGTH);
    Packetizer_packetize(&packetizer, 
                            Packetizer_PacketType_Telemetry,
                            SOURCE_DEVICE_ID,
                            DESTINATION_DEVICE_ID,
                            txBuffer,
                            SPACE_PACKET_PRIMARY_HEADER_SIZE,
                            TX_MSG_LENGTH);

    interface_to_deliver_function[SOURCE_DEVICE_ID] =  managerMsgCallback;
}

inline static manager_initEscaper(){
        Escaper_init(&escaper, 
                        encodedPacketBuffer,
                        ENCODED_PACKET_BUFFER_SIZE,
                        decodedPacketBuffer,
                        DECODED_PACKET_BUFFER_SIZE);
        Escaper_start_decoder(&escaper);
        size_t index = 0;
        bytesToSend = Escaper_encode_packet(&escaper, txBuffer, TX_PACKET_LENGTH, &index);
}

void manager_startup(void)
{
    manager_initPacketizer();
    manager_initEscaper();
    Hal_console_usart_init();
}

void manager_PI_SendData( void )
{
    if(!wasInitialized)
    {
        manager_RI_UartHwas_InitUartCmd_Pi(&uart, &config);
        readByte.uart = uart;
        manager_RI_UartHwas_ReadByteAsyncCmd_Pi(&readByte);

        wasInitialized = true;
    }
}

void managerMsgCallback(uint8_t* const msg, const size_t msgLength)
{
       if(strcmp(RX_MSG, msg))
       {
            Hal_console_usart_write(ERR_MSG, strlen(ERR_MSG));
           while(true)
           {
           }
       }else {
           Hal_console_usart_write(SUCCESS_MSG, strlen(SUCCESS_MSG));
           sentBytes = 0;
           asn1SccSendByteAsyncCmd_Type sendByteStructure = {
                .uart = uart, 
                .byteToSend = escaper.m_encoded_packet_buffer[sentBytes]
            };
           manager_RI_UartHwas_SendByteAsyncCmd_Pi(&sendByteStructure);
       }
}

void manager_PI_UartHwas_ReadByteAsyncCmd_Ri
      (const asn1SccReadByteAsyncCmd_Type1 *IN_inputparam)

{
        Escaper_decode_packet(&escaper, &IN_inputparam->byteToRead, 1, Broker_receive_packet);
}

void manager_PI_UartHwas_SendByteAsyncCmd_Ri
      (const asn1SccSendByteAsyncCmd_Type1 *IN_inputparam)
{
    sentBytes++;
    if(sentBytes <= bytesToSend)
    {
        asn1SccSendByteAsyncCmd_Type sendByteStructure = {
            .uart = uart, 
            .byteToSend = escaper.m_encoded_packet_buffer[sentBytes]
        };
        manager_RI_UartHwas_SendByteAsyncCmd_Pi(&sendByteStructure);
    }else {
        sentBytes = 0;
    }
}