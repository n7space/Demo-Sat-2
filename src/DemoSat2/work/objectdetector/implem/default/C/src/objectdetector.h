/* Header file for function ObjectDetector
 * Generated by TASTE (kazoo/templates/skeletons/c-header/function.tmplt)
 * DO NOT EDIT THIS FILE, IT WILL BE OVERWRITTEN DURING THE BUILD
 */

#pragma once

#include "dataview-uniq.h"

#ifdef __cplusplus
extern "C" {
#endif


void objectdetector_startup(void);

/* Provided interfaces */
void objectdetector_PI_LidarTrigger_ReturnDataCmd_Ri( const asn1SccLidarTriggerInterfaceType_ReturnDataCmd_Type * );


void objectdetector_PI_LidarTrigger_ReturnErrorCmd_Ri( const asn1SccLidarTriggerInterfaceType_ReturnErrorCmd_Type * );


void objectdetector_PI_ObjectDetection_SetEnabled( const asn1SccTEnabled * );

/* Required interfaces */
extern void objectdetector_RI_Lidar_DisableCmd_Pi( void );


extern void objectdetector_RI_Lidar_EnableCmd_Pi( void );


extern void objectdetector_RI_Lidar_InitLidarCmd_Pi( asn1SccLidar *, const asn1SccLidarConfig * );


extern void objectdetector_RI_ObjectDetection_Report( const asn1SccTObjectDetectionReport * );


#ifdef __cplusplus
}
#endif
