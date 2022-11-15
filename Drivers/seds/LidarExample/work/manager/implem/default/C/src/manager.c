/* Body file for function Manager
 * Generated by TASTE on 2022-06-08 17:19:15
 * You can edit this file, it will not be overwritten
 * Provided interfaces : Init, LidarTrigger_ReturnDataCmd_Ri, LidarTrigger_ReturnErrorCmd_Ri
 * Required interfaces : Lidar_DisableCmd_Pi, Lidar_EnableCmd_Pi, Lidar_InitLidarCmd_Pi
 * User-defined properties for this function:
 * Timers              : 
 */

#include "manager.h"

#include <stdio.h>
#include <string.h>

#include <Hal.h>

static bool initialized = false;
static bool stopped = false;

static asn1SccLidar lidar;
static asn1SccLidarConfig lidarConfig = {
    .mMP6500Config = {
        .mStepPioConfig = {.mPortConfig = PioHwas_Port_pioHwas_Port_D,
                           .mPinConfig = 27,
                           .mDirectionConfig = PioHwas_Direction_pioHwas_Direction_Output,
                           .mControlConfig = PioHwas_Control_pioHwas_Control_Pio},
        .mDirPioConfig = {.mPortConfig = PioHwas_Port_pioHwas_Port_C,
                          .mPinConfig = 19,
                          .mDirectionConfig = PioHwas_Direction_pioHwas_Direction_Output,
                          .mControlConfig = PioHwas_Control_pioHwas_Control_Pio},
    },
            .mLeftEndSwitchConfig = {.mPortConfig = PioHwas_Port_pioHwas_Port_D,
                                     .mPinConfig = 28,
                                     .mDirectionConfig = PioHwas_Direction_pioHwas_Direction_Input,
                                     .mControlConfig = PioHwas_Control_pioHwas_Control_Pio},
            .mRightEndSwitchConfig = {.mPortConfig = PioHwas_Port_pioHwas_Port_A,
                                      .mPinConfig = 6,
                                      .mDirectionConfig = PioHwas_Direction_pioHwas_Direction_Input,
                                      .mControlConfig = PioHwas_Control_pioHwas_Control_Pio}};
void manager_startup(void)
{
    Hal_console_usart_init();
}

void manager_PI_Init(void)
{
    if (!initialized)
    {
        manager_RI_Lidar_InitLidarCmd_Pi(&lidar, &lidarConfig);
        initialized = true;
    }
    else
    {
    }
}


void manager_PI_LidarTrigger_ReturnDataCmd_Ri
      (const asn1SccLidarTriggerInterfaceType_ReturnDataCmd_Type *IN_inputparam)

{
    asn1SccTfLuna_Data mTfLunaData;
    asn1SccLidarData_mStep mStep;
    static uint8_t buffer[40];
    sprintf(buffer, "Step %lld D %lld S %lld T %lld\n", IN_inputparam->data.mStep, IN_inputparam->data.mTfLunaData.mDistance, IN_inputparam->data.mTfLunaData.mStrength, IN_inputparam->data.mTfLunaData.mTemp);
    Hal_console_usart_write(buffer, strlen(buffer));
}


void manager_PI_LidarTrigger_ReturnErrorCmd_Ri
      (const asn1SccLidarTriggerInterfaceType_ReturnErrorCmd_Type *IN_inputparam)

{
    static uint8_t buffer[20];
    sprintf(buffer, "Error %i\n", IN_inputparam->err.mTfLunaError);
    Hal_console_usart_write(buffer, strlen(buffer));
}


void manager_PI_StartStop(  )
{
    if(stopped)
    {
        stopped = false;
        manager_RI_Lidar_EnableCmd_Pi();

    }else {
        stopped = true;
        manager_RI_Lidar_DisableCmd_Pi();
    }
}

