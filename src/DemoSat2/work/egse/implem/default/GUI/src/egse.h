/* Header file for function EGSE
 * Generated by TASTE (kazoo/templates/skeletons/c-header/function.tmplt)
 * DO NOT EDIT THIS FILE, IT WILL BE OVERWRITTEN DURING THE BUILD
 */

#pragma once

#include "dataview-uniq.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdio.h>

void egse_startup(void);

/* Provided interfaces */
void egse_PI_hk( const asn1SccTHouseKeepingReport * );


void egse_PI_tm( const asn1SccTTM * );

/* Required interfaces */
extern void egse_RI_tc( const asn1SccTTC * );


#ifdef __cplusplus
}
#endif

