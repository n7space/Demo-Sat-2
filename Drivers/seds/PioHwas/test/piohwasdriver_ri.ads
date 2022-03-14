--  This file is a stub for the implementation of the required interfaces
--  It is normally overwritten by TASTE with the actual connection to the
--  middleware. If you use Opengeode independently from TASTE you must
--  edit the .adb (body) with your own implementation of these functions.
--  The body stub will be generated only once.

with SYSTEM_DATAVIEW;
use SYSTEM_DATAVIEW;
with adaasn1rtl;
use adaasn1rtl;

package PioHwasDriver_RI is
   procedure RawMemoryAccess_ReadBuffer_Ri (Address : in out asn1SccSourceAddress; Buffer : out asn1SccByteBuffer);
   procedure RawMemoryAccess_ReadWord_Ri (Address : in out asn1SccSourceAddress; Mask : in out asn1SccWordMask; Value : out asn1SccWord);
   procedure RawMemoryAccess_WriteBuffer_Ri (Address : in out asn1SccDestinationAddress; Buffer : in out asn1SccByteBuffer);
   procedure RawMemoryAccess_WriteWord_Ri (Address : in out asn1SccDestinationAddress; Mask : in out asn1SccWordMask; Value : in out asn1SccWord);
end PioHwasDriver_RI;