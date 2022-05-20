
/* Header file for function manager in C language
 * Generated by TASTE on 2022-04-15 12:00:59
 * Context Parameters present : NO
 * Provided interfaces : Blink
 * Required interfaces : PioHwas_GetPin_Pi, PioHwas_InitPin_Pi, PioHwas_ResetPin_Pi, PioHwas_SetPin_Pi
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
void manager_PI_Blink( void );

/* Required interfaces */
extern void manager_RI_PioHwas_GetPin_Pi( const asn1SccPioHwas *, asn1SccWord * );


extern void manager_RI_PioHwas_InitPin_Pi( asn1SccPioHwas *, const asn1SccPioHwasPinConfig * );


extern void manager_RI_PioHwas_ResetPin_Pi( const asn1SccPioHwas * );


extern void manager_RI_PioHwas_SetPin_Pi( const asn1SccPioHwas * );


#ifdef __cplusplus
}
#endif
