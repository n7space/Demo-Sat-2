#ifndef __C_DATAVIEW_UNIQ_H__
#define __C_DATAVIEW_UNIQ_H__

#if defined( __unix__ ) || defined( __MSP430__ )
#include <stdlib.h> /* for size_t */
#else
typedef unsigned size_t;
#endif

#ifndef STATIC
#define STATIC
#endif


#include "dataview-uniq.h" // Space certified compiler generated

#include "../../system_config.h" // Choose ASN.1 Types to use

#ifdef __NEED_DestinationAddress_UPER
int Encode_UPER_DestinationAddress(void *pBuffer, size_t iMaxBufferSize, const asn1SccDestinationAddress *pSrc);
#endif

#ifdef __NEED_DestinationAddress_ACN
int Encode_ACN_DestinationAddress(void *pBuffer, size_t iMaxBufferSize, asn1SccDestinationAddress *pSrc);
#endif

#ifdef __NEED_DestinationAddress_NATIVE
int Encode_NATIVE_DestinationAddress(void *pBuffer, size_t iMaxBufferSize, const asn1SccDestinationAddress *pSrc);
#endif

#ifdef __NEED_DestinationAddress_UPER
int Decode_UPER_DestinationAddress(asn1SccDestinationAddress *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_DestinationAddress_ACN
int Decode_ACN_DestinationAddress(asn1SccDestinationAddress *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_DestinationAddress_NATIVE
int Decode_NATIVE_DestinationAddress(asn1SccDestinationAddress *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_SourceAddress_UPER
int Encode_UPER_SourceAddress(void *pBuffer, size_t iMaxBufferSize, const asn1SccSourceAddress *pSrc);
#endif

#ifdef __NEED_SourceAddress_ACN
int Encode_ACN_SourceAddress(void *pBuffer, size_t iMaxBufferSize, asn1SccSourceAddress *pSrc);
#endif

#ifdef __NEED_SourceAddress_NATIVE
int Encode_NATIVE_SourceAddress(void *pBuffer, size_t iMaxBufferSize, const asn1SccSourceAddress *pSrc);
#endif

#ifdef __NEED_SourceAddress_UPER
int Decode_UPER_SourceAddress(asn1SccSourceAddress *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_SourceAddress_ACN
int Decode_ACN_SourceAddress(asn1SccSourceAddress *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_SourceAddress_NATIVE
int Decode_NATIVE_SourceAddress(asn1SccSourceAddress *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Word_UPER
int Encode_UPER_Word(void *pBuffer, size_t iMaxBufferSize, const asn1SccWord *pSrc);
#endif

#ifdef __NEED_Word_ACN
int Encode_ACN_Word(void *pBuffer, size_t iMaxBufferSize, asn1SccWord *pSrc);
#endif

#ifdef __NEED_Word_NATIVE
int Encode_NATIVE_Word(void *pBuffer, size_t iMaxBufferSize, const asn1SccWord *pSrc);
#endif

#ifdef __NEED_Word_UPER
int Decode_UPER_Word(asn1SccWord *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Word_ACN
int Decode_ACN_Word(asn1SccWord *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Word_NATIVE
int Decode_NATIVE_Word(asn1SccWord *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_WordMask_UPER
int Encode_UPER_WordMask(void *pBuffer, size_t iMaxBufferSize, const asn1SccWordMask *pSrc);
#endif

#ifdef __NEED_WordMask_ACN
int Encode_ACN_WordMask(void *pBuffer, size_t iMaxBufferSize, asn1SccWordMask *pSrc);
#endif

#ifdef __NEED_WordMask_NATIVE
int Encode_NATIVE_WordMask(void *pBuffer, size_t iMaxBufferSize, const asn1SccWordMask *pSrc);
#endif

#ifdef __NEED_WordMask_UPER
int Decode_UPER_WordMask(asn1SccWordMask *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_WordMask_ACN
int Decode_ACN_WordMask(asn1SccWordMask *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_WordMask_NATIVE
int Decode_NATIVE_WordMask(asn1SccWordMask *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_BufferSize_UPER
int Encode_UPER_BufferSize(void *pBuffer, size_t iMaxBufferSize, const asn1SccBufferSize *pSrc);
#endif

#ifdef __NEED_BufferSize_ACN
int Encode_ACN_BufferSize(void *pBuffer, size_t iMaxBufferSize, asn1SccBufferSize *pSrc);
#endif

#ifdef __NEED_BufferSize_NATIVE
int Encode_NATIVE_BufferSize(void *pBuffer, size_t iMaxBufferSize, const asn1SccBufferSize *pSrc);
#endif

#ifdef __NEED_BufferSize_UPER
int Decode_UPER_BufferSize(asn1SccBufferSize *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_BufferSize_ACN
int Decode_ACN_BufferSize(asn1SccBufferSize *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_BufferSize_NATIVE
int Decode_NATIVE_BufferSize(asn1SccBufferSize *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_InterruptNumber_UPER
int Encode_UPER_InterruptNumber(void *pBuffer, size_t iMaxBufferSize, const asn1SccInterruptNumber *pSrc);
#endif

#ifdef __NEED_InterruptNumber_ACN
int Encode_ACN_InterruptNumber(void *pBuffer, size_t iMaxBufferSize, asn1SccInterruptNumber *pSrc);
#endif

#ifdef __NEED_InterruptNumber_NATIVE
int Encode_NATIVE_InterruptNumber(void *pBuffer, size_t iMaxBufferSize, const asn1SccInterruptNumber *pSrc);
#endif

#ifdef __NEED_InterruptNumber_UPER
int Decode_UPER_InterruptNumber(asn1SccInterruptNumber *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_InterruptNumber_ACN
int Decode_ACN_InterruptNumber(asn1SccInterruptNumber *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_InterruptNumber_NATIVE
int Decode_NATIVE_InterruptNumber(asn1SccInterruptNumber *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Byte_UPER
int Encode_UPER_Byte(void *pBuffer, size_t iMaxBufferSize, const asn1SccByte *pSrc);
#endif

#ifdef __NEED_Byte_ACN
int Encode_ACN_Byte(void *pBuffer, size_t iMaxBufferSize, asn1SccByte *pSrc);
#endif

#ifdef __NEED_Byte_NATIVE
int Encode_NATIVE_Byte(void *pBuffer, size_t iMaxBufferSize, const asn1SccByte *pSrc);
#endif

#ifdef __NEED_Byte_UPER
int Decode_UPER_Byte(asn1SccByte *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Byte_ACN
int Decode_ACN_Byte(asn1SccByte *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Byte_NATIVE
int Decode_NATIVE_Byte(asn1SccByte *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_ByteBuffer_UPER
int Encode_UPER_ByteBuffer(void *pBuffer, size_t iMaxBufferSize, const asn1SccByteBuffer *pSrc);
#endif

#ifdef __NEED_ByteBuffer_ACN
int Encode_ACN_ByteBuffer(void *pBuffer, size_t iMaxBufferSize, asn1SccByteBuffer *pSrc);
#endif

#ifdef __NEED_ByteBuffer_NATIVE
int Encode_NATIVE_ByteBuffer(void *pBuffer, size_t iMaxBufferSize, const asn1SccByteBuffer *pSrc);
#endif

#ifdef __NEED_ByteBuffer_UPER
int Decode_UPER_ByteBuffer(asn1SccByteBuffer *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_ByteBuffer_ACN
int Decode_ACN_ByteBuffer(asn1SccByteBuffer *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_ByteBuffer_NATIVE
int Decode_NATIVE_ByteBuffer(asn1SccByteBuffer *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PinNumber_UPER
int Encode_UPER_PinNumber(void *pBuffer, size_t iMaxBufferSize, const asn1SccPinNumber *pSrc);
#endif

#ifdef __NEED_PinNumber_ACN
int Encode_ACN_PinNumber(void *pBuffer, size_t iMaxBufferSize, asn1SccPinNumber *pSrc);
#endif

#ifdef __NEED_PinNumber_NATIVE
int Encode_NATIVE_PinNumber(void *pBuffer, size_t iMaxBufferSize, const asn1SccPinNumber *pSrc);
#endif

#ifdef __NEED_PinNumber_UPER
int Decode_UPER_PinNumber(asn1SccPinNumber *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PinNumber_ACN
int Decode_ACN_PinNumber(asn1SccPinNumber *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PinNumber_NATIVE
int Decode_NATIVE_PinNumber(asn1SccPinNumber *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PioHwas_Port_UPER
int Encode_UPER_PioHwas_Port(void *pBuffer, size_t iMaxBufferSize, const asn1SccPioHwas_Port *pSrc);
#endif

#ifdef __NEED_PioHwas_Port_ACN
int Encode_ACN_PioHwas_Port(void *pBuffer, size_t iMaxBufferSize, asn1SccPioHwas_Port *pSrc);
#endif

#ifdef __NEED_PioHwas_Port_NATIVE
int Encode_NATIVE_PioHwas_Port(void *pBuffer, size_t iMaxBufferSize, const asn1SccPioHwas_Port *pSrc);
#endif

#ifdef __NEED_PioHwas_Port_UPER
int Decode_UPER_PioHwas_Port(asn1SccPioHwas_Port *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PioHwas_Port_ACN
int Decode_ACN_PioHwas_Port(asn1SccPioHwas_Port *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PioHwas_Port_NATIVE
int Decode_NATIVE_PioHwas_Port(asn1SccPioHwas_Port *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PioHwas_Direction_UPER
int Encode_UPER_PioHwas_Direction(void *pBuffer, size_t iMaxBufferSize, const asn1SccPioHwas_Direction *pSrc);
#endif

#ifdef __NEED_PioHwas_Direction_ACN
int Encode_ACN_PioHwas_Direction(void *pBuffer, size_t iMaxBufferSize, asn1SccPioHwas_Direction *pSrc);
#endif

#ifdef __NEED_PioHwas_Direction_NATIVE
int Encode_NATIVE_PioHwas_Direction(void *pBuffer, size_t iMaxBufferSize, const asn1SccPioHwas_Direction *pSrc);
#endif

#ifdef __NEED_PioHwas_Direction_UPER
int Decode_UPER_PioHwas_Direction(asn1SccPioHwas_Direction *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PioHwas_Direction_ACN
int Decode_ACN_PioHwas_Direction(asn1SccPioHwas_Direction *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PioHwas_Direction_NATIVE
int Decode_NATIVE_PioHwas_Direction(asn1SccPioHwas_Direction *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PioHwas_UPER
int Encode_UPER_PioHwas(void *pBuffer, size_t iMaxBufferSize, const asn1SccPioHwas *pSrc);
#endif

#ifdef __NEED_PioHwas_ACN
int Encode_ACN_PioHwas(void *pBuffer, size_t iMaxBufferSize, asn1SccPioHwas *pSrc);
#endif

#ifdef __NEED_PioHwas_NATIVE
int Encode_NATIVE_PioHwas(void *pBuffer, size_t iMaxBufferSize, const asn1SccPioHwas *pSrc);
#endif

#ifdef __NEED_PioHwas_UPER
int Decode_UPER_PioHwas(asn1SccPioHwas *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PioHwas_ACN
int Decode_ACN_PioHwas(asn1SccPioHwas *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PioHwas_NATIVE
int Decode_NATIVE_PioHwas(asn1SccPioHwas *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PioHwasPinConfig_UPER
int Encode_UPER_PioHwasPinConfig(void *pBuffer, size_t iMaxBufferSize, const asn1SccPioHwasPinConfig *pSrc);
#endif

#ifdef __NEED_PioHwasPinConfig_ACN
int Encode_ACN_PioHwasPinConfig(void *pBuffer, size_t iMaxBufferSize, asn1SccPioHwasPinConfig *pSrc);
#endif

#ifdef __NEED_PioHwasPinConfig_NATIVE
int Encode_NATIVE_PioHwasPinConfig(void *pBuffer, size_t iMaxBufferSize, const asn1SccPioHwasPinConfig *pSrc);
#endif

#ifdef __NEED_PioHwasPinConfig_UPER
int Decode_UPER_PioHwasPinConfig(asn1SccPioHwasPinConfig *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PioHwasPinConfig_ACN
int Decode_ACN_PioHwasPinConfig(asn1SccPioHwasPinConfig *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PioHwasPinConfig_NATIVE
int Decode_NATIVE_PioHwasPinConfig(asn1SccPioHwasPinConfig *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PmcHwas_UPER
int Encode_UPER_PmcHwas(void *pBuffer, size_t iMaxBufferSize, const asn1SccPmcHwas *pSrc);
#endif

#ifdef __NEED_PmcHwas_ACN
int Encode_ACN_PmcHwas(void *pBuffer, size_t iMaxBufferSize, asn1SccPmcHwas *pSrc);
#endif

#ifdef __NEED_PmcHwas_NATIVE
int Encode_NATIVE_PmcHwas(void *pBuffer, size_t iMaxBufferSize, const asn1SccPmcHwas *pSrc);
#endif

#ifdef __NEED_PmcHwas_UPER
int Decode_UPER_PmcHwas(asn1SccPmcHwas *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PmcHwas_ACN
int Decode_ACN_PmcHwas(asn1SccPmcHwas *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PmcHwas_NATIVE
int Decode_NATIVE_PmcHwas(asn1SccPmcHwas *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_MyInteger_UPER
int Encode_UPER_MyInteger(void *pBuffer, size_t iMaxBufferSize, const asn1SccMyInteger *pSrc);
#endif

#ifdef __NEED_MyInteger_ACN
int Encode_ACN_MyInteger(void *pBuffer, size_t iMaxBufferSize, asn1SccMyInteger *pSrc);
#endif

#ifdef __NEED_MyInteger_NATIVE
int Encode_NATIVE_MyInteger(void *pBuffer, size_t iMaxBufferSize, const asn1SccMyInteger *pSrc);
#endif

#ifdef __NEED_MyInteger_UPER
int Decode_UPER_MyInteger(asn1SccMyInteger *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_MyInteger_ACN
int Decode_ACN_MyInteger(asn1SccMyInteger *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_MyInteger_NATIVE
int Decode_NATIVE_MyInteger(asn1SccMyInteger *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int32_UPER
int Encode_UPER_T_Int32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int32 *pSrc);
#endif

#ifdef __NEED_T_Int32_ACN
int Encode_ACN_T_Int32(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Int32 *pSrc);
#endif

#ifdef __NEED_T_Int32_NATIVE
int Encode_NATIVE_T_Int32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int32 *pSrc);
#endif

#ifdef __NEED_T_Int32_UPER
int Decode_UPER_T_Int32(asn1SccT_Int32 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int32_ACN
int Decode_ACN_T_Int32(asn1SccT_Int32 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int32_NATIVE
int Decode_NATIVE_T_Int32(asn1SccT_Int32 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt32_UPER
int Encode_UPER_T_UInt32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt32 *pSrc);
#endif

#ifdef __NEED_T_UInt32_ACN
int Encode_ACN_T_UInt32(void *pBuffer, size_t iMaxBufferSize, asn1SccT_UInt32 *pSrc);
#endif

#ifdef __NEED_T_UInt32_NATIVE
int Encode_NATIVE_T_UInt32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt32 *pSrc);
#endif

#ifdef __NEED_T_UInt32_UPER
int Decode_UPER_T_UInt32(asn1SccT_UInt32 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt32_ACN
int Decode_ACN_T_UInt32(asn1SccT_UInt32 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt32_NATIVE
int Decode_NATIVE_T_UInt32(asn1SccT_UInt32 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int8_UPER
int Encode_UPER_T_Int8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int8 *pSrc);
#endif

#ifdef __NEED_T_Int8_ACN
int Encode_ACN_T_Int8(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Int8 *pSrc);
#endif

#ifdef __NEED_T_Int8_NATIVE
int Encode_NATIVE_T_Int8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int8 *pSrc);
#endif

#ifdef __NEED_T_Int8_UPER
int Decode_UPER_T_Int8(asn1SccT_Int8 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int8_ACN
int Decode_ACN_T_Int8(asn1SccT_Int8 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int8_NATIVE
int Decode_NATIVE_T_Int8(asn1SccT_Int8 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt8_UPER
int Encode_UPER_T_UInt8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt8 *pSrc);
#endif

#ifdef __NEED_T_UInt8_ACN
int Encode_ACN_T_UInt8(void *pBuffer, size_t iMaxBufferSize, asn1SccT_UInt8 *pSrc);
#endif

#ifdef __NEED_T_UInt8_NATIVE
int Encode_NATIVE_T_UInt8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt8 *pSrc);
#endif

#ifdef __NEED_T_UInt8_UPER
int Decode_UPER_T_UInt8(asn1SccT_UInt8 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt8_ACN
int Decode_ACN_T_UInt8(asn1SccT_UInt8 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt8_NATIVE
int Decode_NATIVE_T_UInt8(asn1SccT_UInt8 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Boolean_UPER
int Encode_UPER_T_Boolean(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Boolean *pSrc);
#endif

#ifdef __NEED_T_Boolean_ACN
int Encode_ACN_T_Boolean(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Boolean *pSrc);
#endif

#ifdef __NEED_T_Boolean_NATIVE
int Encode_NATIVE_T_Boolean(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Boolean *pSrc);
#endif

#ifdef __NEED_T_Boolean_UPER
int Decode_UPER_T_Boolean(asn1SccT_Boolean *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Boolean_ACN
int Decode_ACN_T_Boolean(asn1SccT_Boolean *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Boolean_NATIVE
int Decode_NATIVE_T_Boolean(asn1SccT_Boolean *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Null_Record_UPER
int Encode_UPER_T_Null_Record(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Null_Record *pSrc);
#endif

#ifdef __NEED_T_Null_Record_ACN
int Encode_ACN_T_Null_Record(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Null_Record *pSrc);
#endif

#ifdef __NEED_T_Null_Record_NATIVE
int Encode_NATIVE_T_Null_Record(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Null_Record *pSrc);
#endif

#ifdef __NEED_T_Null_Record_UPER
int Decode_UPER_T_Null_Record(asn1SccT_Null_Record *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Null_Record_ACN
int Decode_ACN_T_Null_Record(asn1SccT_Null_Record *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Null_Record_NATIVE
int Decode_NATIVE_T_Null_Record(asn1SccT_Null_Record *pDst, void *pBuffer, size_t iBufferSize);
#endif


#endif
