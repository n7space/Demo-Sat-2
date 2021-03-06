
/* Header file for function Manager in C language
 * Generated by TASTE on 2022-05-26 13:21:54
 * Context Parameters present : NO
 * Provided interfaces : ChangeDir, MakeStep
 * Required interfaces : MP6500_InitMP6500Cmd_Pi, MP6500_SetDirectionLeftCmd_Pi, MP6500_SetDirectionRightCmd_Pi, MP6500_StepCmd_Pi
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
void manager_PI_ChangeDir( void );


void manager_PI_MakeStep( void );

/* Required interfaces */
extern void manager_RI_MP6500_InitMP6500Cmd_Pi( asn1SccMP6500 *, const asn1SccMP6500Config * );


extern void manager_RI_MP6500_SetDirectionLeftCmd_Pi( const asn1SccMP6500 * );


extern void manager_RI_MP6500_SetDirectionRightCmd_Pi( const asn1SccMP6500 * );


extern void manager_RI_MP6500_StepCmd_Pi( const asn1SccMP6500 * );


#ifdef __cplusplus
}
#endif
