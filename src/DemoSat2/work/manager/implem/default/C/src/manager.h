/* Header file for function Manager
 * Generated by TASTE (kazoo/templates/skeletons/c-header/function.tmplt)
 * DO NOT EDIT THIS FILE, IT WILL BE OVERWRITTEN DURING THE BUILD
 */

#pragma once

#include "dataview-uniq.h"

#ifdef __cplusplus
extern "C" {
#endif


void manager_startup(void);

/* Provided interfaces */
void manager_PI_ObjectDetection_Report( const asn1SccTObjectDetectionReport * );


void manager_PI_SunSensorReturn_ReturnDataCmd_Ri( const asn1SccConversionData * );


void manager_PI_pps_hk( void );


void manager_PI_pps_ss( void );


void manager_PI_tc( const asn1SccTTC * );

/* Required interfaces */
extern void manager_RI_Debug_SetEnabled( const asn1SccTEnabled * );


extern void manager_RI_ObjectDetection_SetEnabled( const asn1SccTEnabled * );


extern void manager_RI_Propulsion_ChangeStateCmd_Pi( const asn1SccPropulsionThrusterIndex *, const asn1SccPropulsion_ThrusterState * );


extern void manager_RI_Propulsion_InitPropulsionCmd_Pi( asn1SccPropulsion *, const asn1SccPropulsionConfig * );


extern void manager_RI_SunSensor_InitSunSensorCmd_Pi( const asn1SccSunSensorConfig *, asn1SccSunSensor * );


extern void manager_RI_SunSensor_RequestDataCmd_Pi( const asn1SccSunSensor * );


extern void manager_RI_hk( const asn1SccTHouseKeepingReport * );


extern void manager_RI_tm( const asn1SccTTM * );


#ifdef __cplusplus
}
#endif
