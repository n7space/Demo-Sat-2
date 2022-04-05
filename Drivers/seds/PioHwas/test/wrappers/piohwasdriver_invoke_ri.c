// Implementation of the glue code in C handling required interfaces

#include <stdlib.h>
#ifdef __unix__
   #include <stdio.h>
   #include "PrintTypesAsASN1.h"
   #include "timeInMS.h"
#endif
#include "C_ASN1_Types.h"
#include "dataview-uniq.h"

extern unsigned piohwasdriver_initialized;

void piohwasdriver_RI_RawMemoryAccess_ReadBuffer_Ri
      (const asn1SccSourceAddress *IN_address,
       asn1SccByteBuffer          *OUT_buffer);
void piohwasdriver_RI_RawMemoryAccess_ReadBuffer_Ri
      (const asn1SccSourceAddress *IN_address,
       asn1SccByteBuffer          *OUT_buffer)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         fflush(stdout);
      }
   #endif
   // Encode parameter address using ASN.1 ACN
   static char IN_buf_address[asn1SccSourceAddress_REQUIRED_BYTES_FOR_ACN_ENCODING] = {0};
   int size_IN_buf_address =
      Encode_ACN_SourceAddress
        ((void *)&IN_buf_address,
          asn1SccSourceAddress_REQUIRED_BYTES_FOR_ACN_ENCODING,
          (asn1SccSourceAddress *)IN_address);
   if (-1 == size_IN_buf_address) {
      #ifdef __unix__
         puts ("[ERROR] ASN.1 Encoding failed in piohwasdriver_RI_RawMemoryAccess_ReadBuffer_Ri, parameter address");
      #endif
        /* Crash the application due to message loss */
        abort();
   }

   // Buffer for decoding parameter buffer from ACN
   static char OUT_buf_buffer[asn1SccByteBuffer_REQUIRED_BYTES_FOR_ACN_ENCODING];
   size_t      size_OUT_buf_buffer = 0;

   // Send the message via the middleware API
   extern void vm_piohwasdriver_rawmemoryaccess_readbuffer_ri
     (void *, size_t,
      void *, size_t *);

   vm_piohwasdriver_rawmemoryaccess_readbuffer_ri
     ((void *)&IN_buf_address, (size_t)size_IN_buf_address,
      (void *)&OUT_buf_buffer, &size_OUT_buf_buffer);


   // Decode parameter buffer
   if (0 != Decode_ACN_ByteBuffer
              (OUT_buffer, (void *)&OUT_buf_buffer, size_OUT_buf_buffer)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in piohwasdriver_RI_RawMemoryAccess_ReadBuffer_Ri, parameter buffer");
#endif
      return;
  }
}


void piohwasdriver_RI_RawMemoryAccess_ReadWord_Ri
      (const asn1SccSourceAddress *IN_address,
       const asn1SccWordMask      *IN_mask,
       asn1SccWord                *OUT_inputvalue);
void piohwasdriver_RI_RawMemoryAccess_ReadWord_Ri
      (const asn1SccSourceAddress *IN_address,
       const asn1SccWordMask      *IN_mask,
       asn1SccWord                *OUT_inputvalue)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         fflush(stdout);
      }
   #endif
   // Encode parameter address using ASN.1 ACN
   static char IN_buf_address[asn1SccSourceAddress_REQUIRED_BYTES_FOR_ACN_ENCODING] = {0};
   int size_IN_buf_address =
      Encode_ACN_SourceAddress
        ((void *)&IN_buf_address,
          asn1SccSourceAddress_REQUIRED_BYTES_FOR_ACN_ENCODING,
          (asn1SccSourceAddress *)IN_address);
   if (-1 == size_IN_buf_address) {
      #ifdef __unix__
         puts ("[ERROR] ASN.1 Encoding failed in piohwasdriver_RI_RawMemoryAccess_ReadWord_Ri, parameter address");
      #endif
        /* Crash the application due to message loss */
        abort();
   }
   // Encode parameter mask using ASN.1 ACN
   static char IN_buf_mask[asn1SccWordMask_REQUIRED_BYTES_FOR_ACN_ENCODING] = {0};
   int size_IN_buf_mask =
      Encode_ACN_WordMask
        ((void *)&IN_buf_mask,
          asn1SccWordMask_REQUIRED_BYTES_FOR_ACN_ENCODING,
          (asn1SccWordMask *)IN_mask);
   if (-1 == size_IN_buf_mask) {
      #ifdef __unix__
         puts ("[ERROR] ASN.1 Encoding failed in piohwasdriver_RI_RawMemoryAccess_ReadWord_Ri, parameter mask");
      #endif
        /* Crash the application due to message loss */
        abort();
   }

   // Buffer for decoding parameter inputValue from ACN
   static char OUT_buf_inputvalue[asn1SccWord_REQUIRED_BYTES_FOR_ACN_ENCODING];
   size_t      size_OUT_buf_inputvalue = 0;

   // Send the message via the middleware API
   extern void vm_piohwasdriver_rawmemoryaccess_readword_ri
     (void *, size_t,
      void *, size_t,
      void *, size_t *);

   vm_piohwasdriver_rawmemoryaccess_readword_ri
     ((void *)&IN_buf_address, (size_t)size_IN_buf_address,
      (void *)&IN_buf_mask, (size_t)size_IN_buf_mask,
      (void *)&OUT_buf_inputvalue, &size_OUT_buf_inputvalue);


   // Decode parameter inputValue
   if (0 != Decode_ACN_Word
              (OUT_inputvalue, (void *)&OUT_buf_inputvalue, size_OUT_buf_inputvalue)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in piohwasdriver_RI_RawMemoryAccess_ReadWord_Ri, parameter inputValue");
#endif
      return;
  }
}


void piohwasdriver_RI_RawMemoryAccess_WriteBuffer_Ri
      (const asn1SccDestinationAddress *IN_address,
       const asn1SccByteBuffer         *IN_buffer);
void piohwasdriver_RI_RawMemoryAccess_WriteBuffer_Ri
      (const asn1SccDestinationAddress *IN_address,
       const asn1SccByteBuffer         *IN_buffer)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         fflush(stdout);
      }
   #endif
   // Encode parameter address using ASN.1 ACN
   static char IN_buf_address[asn1SccDestinationAddress_REQUIRED_BYTES_FOR_ACN_ENCODING] = {0};
   int size_IN_buf_address =
      Encode_ACN_DestinationAddress
        ((void *)&IN_buf_address,
          asn1SccDestinationAddress_REQUIRED_BYTES_FOR_ACN_ENCODING,
          (asn1SccDestinationAddress *)IN_address);
   if (-1 == size_IN_buf_address) {
      #ifdef __unix__
         puts ("[ERROR] ASN.1 Encoding failed in piohwasdriver_RI_RawMemoryAccess_WriteBuffer_Ri, parameter address");
      #endif
        /* Crash the application due to message loss */
        abort();
   }
   // Encode parameter buffer using ASN.1 ACN
   static char IN_buf_buffer[asn1SccByteBuffer_REQUIRED_BYTES_FOR_ACN_ENCODING] = {0};
   int size_IN_buf_buffer =
      Encode_ACN_ByteBuffer
        ((void *)&IN_buf_buffer,
          asn1SccByteBuffer_REQUIRED_BYTES_FOR_ACN_ENCODING,
          (asn1SccByteBuffer *)IN_buffer);
   if (-1 == size_IN_buf_buffer) {
      #ifdef __unix__
         puts ("[ERROR] ASN.1 Encoding failed in piohwasdriver_RI_RawMemoryAccess_WriteBuffer_Ri, parameter buffer");
      #endif
        /* Crash the application due to message loss */
        abort();
   }


   // Send the message via the middleware API
   extern void vm_piohwasdriver_rawmemoryaccess_writebuffer_ri
     (void *, size_t,
      void *, size_t);

   vm_piohwasdriver_rawmemoryaccess_writebuffer_ri
     ((void *)&IN_buf_address, (size_t)size_IN_buf_address,
      (void *)&IN_buf_buffer, (size_t)size_IN_buf_buffer);


}


void piohwasdriver_RI_RawMemoryAccess_WriteWord_Ri
      (const asn1SccDestinationAddress *IN_address,
       const asn1SccWordMask           *IN_mask,
       const asn1SccWord               *IN_inputvalue);
void piohwasdriver_RI_RawMemoryAccess_WriteWord_Ri
      (const asn1SccDestinationAddress *IN_address,
       const asn1SccWordMask           *IN_mask,
       const asn1SccWord               *IN_inputvalue)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         fflush(stdout);
      }
   #endif
   // Encode parameter address using ASN.1 ACN
   static char IN_buf_address[asn1SccDestinationAddress_REQUIRED_BYTES_FOR_ACN_ENCODING] = {0};
   int size_IN_buf_address =
      Encode_ACN_DestinationAddress
        ((void *)&IN_buf_address,
          asn1SccDestinationAddress_REQUIRED_BYTES_FOR_ACN_ENCODING,
          (asn1SccDestinationAddress *)IN_address);
   if (-1 == size_IN_buf_address) {
      #ifdef __unix__
         puts ("[ERROR] ASN.1 Encoding failed in piohwasdriver_RI_RawMemoryAccess_WriteWord_Ri, parameter address");
      #endif
        /* Crash the application due to message loss */
        abort();
   }
   // Encode parameter mask using ASN.1 ACN
   static char IN_buf_mask[asn1SccWordMask_REQUIRED_BYTES_FOR_ACN_ENCODING] = {0};
   int size_IN_buf_mask =
      Encode_ACN_WordMask
        ((void *)&IN_buf_mask,
          asn1SccWordMask_REQUIRED_BYTES_FOR_ACN_ENCODING,
          (asn1SccWordMask *)IN_mask);
   if (-1 == size_IN_buf_mask) {
      #ifdef __unix__
         puts ("[ERROR] ASN.1 Encoding failed in piohwasdriver_RI_RawMemoryAccess_WriteWord_Ri, parameter mask");
      #endif
        /* Crash the application due to message loss */
        abort();
   }
   // Encode parameter inputValue using ASN.1 ACN
   static char IN_buf_inputvalue[asn1SccWord_REQUIRED_BYTES_FOR_ACN_ENCODING] = {0};
   int size_IN_buf_inputvalue =
      Encode_ACN_Word
        ((void *)&IN_buf_inputvalue,
          asn1SccWord_REQUIRED_BYTES_FOR_ACN_ENCODING,
          (asn1SccWord *)IN_inputvalue);
   if (-1 == size_IN_buf_inputvalue) {
      #ifdef __unix__
         puts ("[ERROR] ASN.1 Encoding failed in piohwasdriver_RI_RawMemoryAccess_WriteWord_Ri, parameter inputValue");
      #endif
        /* Crash the application due to message loss */
        abort();
   }


   // Send the message via the middleware API
   extern void vm_piohwasdriver_rawmemoryaccess_writeword_ri
     (void *, size_t,
      void *, size_t,
      void *, size_t);

   vm_piohwasdriver_rawmemoryaccess_writeword_ri
     ((void *)&IN_buf_address, (size_t)size_IN_buf_address,
      (void *)&IN_buf_mask, (size_t)size_IN_buf_mask,
      (void *)&IN_buf_inputvalue, (size_t)size_IN_buf_inputvalue);


}

