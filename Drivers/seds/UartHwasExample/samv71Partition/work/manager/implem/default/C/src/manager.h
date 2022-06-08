
/* Header file for function Manager in C language
 * Generated by TASTE on 2022-06-08 13:50:58
 * Context Parameters present : NO
 * Provided interfaces : SendData, UartHwas_ReadByteAsyncCmd_Ri, UartHwas_SendByteAsyncCmd_Ri
 * Required interfaces : UartHwas_InitUartCmd_Pi, UartHwas_ReadByteAsyncCmd_Pi, UartHwas_SendByteAsyncCmd_Pi
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
void manager_PI_SendData( void );


void manager_PI_UartHwas_ReadByteAsyncCmd_Ri( const asn1SccReadByteAsyncCmd_Type1 * );


void manager_PI_UartHwas_SendByteAsyncCmd_Ri( const asn1SccSendByteAsyncCmd_Type1 * );

/* Required interfaces */
extern void manager_RI_UartHwas_InitUartCmd_Pi( asn1SccUartHwas *, const asn1SccUartHwasConfig * );


extern void manager_RI_UartHwas_ReadByteAsyncCmd_Pi( const asn1SccReadByteAsyncCmd_Type * );


extern void manager_RI_UartHwas_SendByteAsyncCmd_Pi( const asn1SccSendByteAsyncCmd_Type * );


#ifdef __cplusplus
}
#endif
