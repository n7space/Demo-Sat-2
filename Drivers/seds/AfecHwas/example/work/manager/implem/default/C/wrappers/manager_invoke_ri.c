// Implementation of the glue code in C handling required interfaces

#include <stdlib.h>
#ifdef __unix__
   #include <stdio.h>
   #include "PrintTypesAsASN1.h"
   #include "timeInMS.h"
#endif
#include "C_ASN1_Types.h"
#include "dataview-uniq.h"

extern unsigned manager_initialized;

void manager_RI_AfecHwasInterface_GetValue_Pi
      (const asn1SccAfecHwas        *IN_afec,
       const asn1SccAfecHwasChannel *IN_analogchannel,
       asn1SccWord                  *OUT_channeloutput);
void manager_RI_AfecHwasInterface_GetValue_Pi
      (const asn1SccAfecHwas        *IN_afec,
       const asn1SccAfecHwasChannel *IN_analogchannel,
       asn1SccWord                  *OUT_channeloutput)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         // Log message to AfecHwasDriver (corresponding PI: AfecHwasInterface_GetValue_Pi)
         printf ("INNER_RI: manager,afechwasdriver,afechwasinterface_getvalue_pi,afechwasinterface_getvalue_pi,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif
   // Encode parameter afec using ASN.1 ACN
   __attribute__((section(".sdramMemorySection")))
   static char IN_buf_afec[asn1SccAfecHwas_REQUIRED_BYTES_FOR_ACN_ENCODING] = {0};
   int size_IN_buf_afec =
      Encode_ACN_AfecHwas
        ((void *)&IN_buf_afec,
          asn1SccAfecHwas_REQUIRED_BYTES_FOR_ACN_ENCODING,
          (asn1SccAfecHwas *)IN_afec);
   if (-1 == size_IN_buf_afec) {
      #ifdef __unix__
         puts ("[ERROR] ASN.1 Encoding failed in manager_RI_AfecHwasInterface_GetValue_Pi, parameter afec");
      #endif
        /* Crash the application due to message loss */
        abort();
   }
   // Encode parameter analogChannel using ASN.1 ACN
   __attribute__((section(".sdramMemorySection")))
   static char IN_buf_analogchannel[asn1SccAfecHwasChannel_REQUIRED_BYTES_FOR_ACN_ENCODING] = {0};
   int size_IN_buf_analogchannel =
      Encode_ACN_AfecHwasChannel
        ((void *)&IN_buf_analogchannel,
          asn1SccAfecHwasChannel_REQUIRED_BYTES_FOR_ACN_ENCODING,
          (asn1SccAfecHwasChannel *)IN_analogchannel);
   if (-1 == size_IN_buf_analogchannel) {
      #ifdef __unix__
         puts ("[ERROR] ASN.1 Encoding failed in manager_RI_AfecHwasInterface_GetValue_Pi, parameter analogChannel");
      #endif
        /* Crash the application due to message loss */
        abort();
   }

   // Buffer for decoding parameter channelOutput from ACN
   __attribute__((section(".sdramMemorySection")))
   static char OUT_buf_channeloutput[asn1SccWord_REQUIRED_BYTES_FOR_ACN_ENCODING];
   size_t      size_OUT_buf_channeloutput = 0;

   // Send the message via the middleware API
   extern void vm_manager_afechwasinterface_getvalue_pi
     (void *, size_t,
      void *, size_t,
      void *, size_t *);

   vm_manager_afechwasinterface_getvalue_pi
     ((void *)&IN_buf_afec, (size_t)size_IN_buf_afec,
      (void *)&IN_buf_analogchannel, (size_t)size_IN_buf_analogchannel,
      (void *)&OUT_buf_channeloutput, &size_OUT_buf_channeloutput);


   // Decode parameter channelOutput
   if (0 != Decode_ACN_Word
              (OUT_channeloutput, (void *)&OUT_buf_channeloutput, size_OUT_buf_channeloutput)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in manager_RI_AfecHwasInterface_GetValue_Pi, parameter channelOutput");
#endif
      return;
  }
}


void manager_RI_AfecHwasInterface_InitInstance_Pi
      (asn1SccAfecHwas             *OUT_afec,
       const asn1SccAfecHwasConfig *IN_config);
void manager_RI_AfecHwasInterface_InitInstance_Pi
      (asn1SccAfecHwas             *OUT_afec,
       const asn1SccAfecHwasConfig *IN_config)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         // Log message to AfecHwasDriver (corresponding PI: AfecHwasInterface_InitInstance_Pi)
         printf ("INNER_RI: manager,afechwasdriver,afechwasinterface_initinstance_pi,afechwasinterface_initinstance_pi,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif
   // Encode parameter config using ASN.1 ACN
   __attribute__((section(".sdramMemorySection")))
   static char IN_buf_config[asn1SccAfecHwasConfig_REQUIRED_BYTES_FOR_ACN_ENCODING] = {0};
   int size_IN_buf_config =
      Encode_ACN_AfecHwasConfig
        ((void *)&IN_buf_config,
          asn1SccAfecHwasConfig_REQUIRED_BYTES_FOR_ACN_ENCODING,
          (asn1SccAfecHwasConfig *)IN_config);
   if (-1 == size_IN_buf_config) {
      #ifdef __unix__
         puts ("[ERROR] ASN.1 Encoding failed in manager_RI_AfecHwasInterface_InitInstance_Pi, parameter config");
      #endif
        /* Crash the application due to message loss */
        abort();
   }

   // Buffer for decoding parameter afec from ACN
   __attribute__((section(".sdramMemorySection")))
   static char OUT_buf_afec[asn1SccAfecHwas_REQUIRED_BYTES_FOR_ACN_ENCODING];
   size_t      size_OUT_buf_afec = 0;

   // Send the message via the middleware API
   extern void vm_manager_afechwasinterface_initinstance_pi
     (void *, size_t *,
      void *, size_t);

   vm_manager_afechwasinterface_initinstance_pi
     ((void *)&OUT_buf_afec, &size_OUT_buf_afec,
      (void *)&IN_buf_config, (size_t)size_IN_buf_config);


   // Decode parameter afec
   if (0 != Decode_ACN_AfecHwas
              (OUT_afec, (void *)&OUT_buf_afec, size_OUT_buf_afec)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in manager_RI_AfecHwasInterface_InitInstance_Pi, parameter afec");
#endif
      return;
  }
}

