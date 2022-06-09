
/* Header file for function HWAS in C language
 * Generated by TASTE on 2022-06-09 06:32:40
 * Context Parameters present : NO
 * Provided interfaces : RawMemoryAccess_ReadWord_Pi, RawMemoryAccess_WriteWord_Pi
 * Required interfaces : 
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

void hwas_startup(void);

/* Provided interfaces */
void hwas_PI_RawMemoryAccess_ReadWord_Pi( const asn1SccSourceAddress *, const asn1SccWordMask *, asn1SccWord * );


void hwas_PI_RawMemoryAccess_WriteWord_Pi( const asn1SccDestinationAddress *, const asn1SccWordMask *, const asn1SccWord * );

/* Required interfaces */



#ifdef __cplusplus
}
#endif
