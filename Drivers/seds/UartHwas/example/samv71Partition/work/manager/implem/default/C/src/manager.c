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

static bool wasInitialized = false;
static char * msg = {"MSG Received\n\r"};

static asn1SccUartHwas uart;
static asn1SccUartHwasConfig config = {.mInstance = asn1SccuartHwas_Instance_4, .mBaudrate = asn1SccuartHwas_Baudrate9600};

static const char const * RX_MSG {"Hello\n\r"};

#define MSG_LEN 14
#define RX_BUFFER_LENGTH 7

#define START_BYTE (uint8_t)0x00
#define STOP_BYTE (uint8_t)0xFF

static char rxBuffer[RX_BUFFER_LENGTH];
static int sentBytes = 0;
static int receivedBytes =0;

static bool msgDetected;

void manager_startup(void)
{
   // Write your initialisation code, but DO NOT CALL REQUIRED INTERFACES
   // puts ("[Manager] Startup");
}

void manager_PI_SendData( void )
{
    if(!wasInitialized)
    {
        manager_RI_UartHwas_InitUartCmd_Pi(&uart, &config);
        wasInitialized = true;
    }
}

void manager_PI_UartHwas_ReadByteAsyncCmd_Ri
      (const asn1SccReadByteAsyncCmd_Type1 *IN_inputparam)

{
    if(IN_inputparam->byteToRead == START_BYTE)
    {
        msgDetected = true;
    }else if(IN_inputparam->byteToRead == STOP_BYTE)
    {
        if(strcmp(RX_MSG, rxBuffer))
        {
            while(true)
            {
                //Received msg is corrupted
            }
        }else {
            sentBytes = 0;
            asn1SccSendByteAsyncCmd_Type sendByteStructure = {.uart = uart, .byteToSend = msg[sentBytes]};
            manager_RI_UartHwas_SendByteAsyncCmd_Pi(&sendByteStructure);
            msgDetected = false;
            receivedBytes = 0;
        }
    }else if(msgDetected == true)
    {
        if(receivedBytes < RX_BUFFER_LENGTH)
        {
            rxBuffer[receivedBytes] = IN_inputparam->byteToRead;
            receivedBytes++;
        }
        else {
            while(true)
            {
                //Error no STOP byte
            }
        }
    }



   // Write your code here
}


void manager_PI_UartHwas_SendByteAsyncCmd_Ri
      (const asn1SccSendByteAsyncCmd_Type1 *IN_inputparam)

{
   // Write your code here
    sentBytes++;
    if(sentBytes < MSG_LEN)
    {
        asn1SccSendByteAsyncCmd_Type sendByteStructure = {.uart = uart, .byteToSend = msg[sentBytes]};
        manager_RI_UartHwas_SendByteAsyncCmd_Pi(&sendByteStructure);
    }else {
        sentBytes = 0;
    }
}


