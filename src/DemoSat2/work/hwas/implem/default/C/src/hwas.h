/* Header file for function HWAS
 * Generated by TASTE (kazoo/templates/skeletons/c-header/function.tmplt)
 * DO NOT EDIT THIS FILE, IT WILL BE OVERWRITTEN DURING THE BUILD
 */

#pragma once

#include "dataview-uniq.h"

#ifdef __cplusplus
extern "C" {
#endif


void hwas_startup(void);

/* Provided interfaces */
void hwas_PI_InterruptManagement_DisableInterrupt_Pi( const asn1SccInterruptNumber * );


void hwas_PI_InterruptManagement_EnableInterrupt_Pi( const asn1SccInterruptNumber * );


void hwas_PI_InterruptSubscriptionManagement_SubscribeToInterrupt_Pi( const asn1SccInterruptNumber * );


void hwas_PI_RawMemoryAccess_ReadWord_Pi( const asn1SccSourceAddress *, const asn1SccWordMask *, asn1SccWord * );


void hwas_PI_RawMemoryAccess_WriteWord_Pi( const asn1SccDestinationAddress *, const asn1SccWordMask *, const asn1SccWord * );

/* Required interfaces */
extern void hwas_RI_InterruptSubscription_Interrupt_Ri( const asn1SccInterruptNumber * );


#ifdef __cplusplus
}
#endif
