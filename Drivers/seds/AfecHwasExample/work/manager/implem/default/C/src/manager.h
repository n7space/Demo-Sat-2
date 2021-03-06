
/* Header file for function Manager in C language
 * Generated by TASTE on 2022-06-14 13:35:32
 * Context Parameters present : NO
 * Provided interfaces : AfecHwas_GetValueCmd_Ri, GetValue
 * Required interfaces : AfecHwas_GetValueCmd_Pi, AfecHwas_InitInstance_Pi
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
void manager_PI_AfecHwas_GetValueCmd_Ri( const asn1SccAfecHwasInterfaceType_GetValueCmd_TypeNotify * );


void manager_PI_GetValue( void );

/* Required interfaces */
extern void manager_RI_AfecHwas_GetValueCmd_Pi( const asn1SccAfecHwasInterfaceType_GetValueCmd_Type * );


extern void manager_RI_AfecHwas_InitInstance_Pi( asn1SccAfecHwas *, const asn1SccAfecHwasConfig * );


#ifdef __cplusplus
}
#endif
