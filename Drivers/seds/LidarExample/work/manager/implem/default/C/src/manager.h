
/* Header file for function Manager in C language
 * Generated by TASTE on 2022-06-08 18:04:19
 * Context Parameters present : NO
 * Provided interfaces : Init, LidarTrigger_ReturnDataCmd_Ri, LidarTrigger_ReturnErrorCmd_Ri, StartStop
 * Required interfaces : Lidar_DisableCmd_Pi, Lidar_EnableCmd_Pi, Lidar_InitLidarCmd_Pi
 * User-defined properties for this function:
 * DO NOT EDIT THIS FILE, IT WILL BE OVERWRITTEN DURING THE BUILD
 */

#pragma once

#include "dataview-uniq.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __unix__
   #include <stdlib.h>
   #include <stdio.h>
#endif

void manager_startup(void);

/* Provided interfaces */
void manager_PI_Init( void );


void manager_PI_LidarTrigger_ReturnDataCmd_Ri( const asn1SccLidarTriggerInterfaceType_ReturnDataCmd_Type * );


void manager_PI_LidarTrigger_ReturnErrorCmd_Ri( const asn1SccLidarTriggerInterfaceType_ReturnErrorCmd_Type * );


void manager_PI_StartStop( void );

/* Required interfaces */
extern void manager_RI_Lidar_DisableCmd_Pi( void );


extern void manager_RI_Lidar_EnableCmd_Pi( void );


extern void manager_RI_Lidar_InitLidarCmd_Pi( asn1SccLidar *, const asn1SccLidarConfig * );


#ifdef __cplusplus
}
#endif
