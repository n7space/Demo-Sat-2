/* Body file for function Manager
 * Generated by TASTE on 2022-04-06 11:12:12
 * You can edit this file, it will not be overwritten
 * Provided interfaces : GetTemperature
 * Required interfaces : AfecHwasInterface_GetValue_Pi, AfecHwasInterface_InitInstance_Pi
 * User-defined properties for this function:
 * Timers              :
 */

#include "manager.h"

static bool initialized = false;
static asn1SccAfecHwas afec = {};
static asn1SccAfecHwasConfig config = {.mAfecInstance = asn1SccafecHwas_Instance_Afec0, .mStartupTime = 10,.mPrescalerValue = 2};
static asn1SccWord tempRawValue = 0;
static asn1SccWord channelNumber = 11;

void manager_startup(void)
{
   // Write your initialisation code, but DO NOT CALL REQUIRED INTERFACES
   // puts ("[Manager] Startup");
}

void manager_PI_GetTemperature(void)
{
   // Write your code here
    if(!initialized)
    {
        manager_RI_AfecHwasInterface_InitInstance_Pi(&afec, &config);
        initialized = true;
    }else {
        manager_RI_AfecHwasInterface_GetValue_Pi(&afec, &channelNumber, &tempRawValue);
    }
}