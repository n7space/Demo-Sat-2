-- This file was generated automatically by OpenGEODE: DO NOT MODIFY IT !

with Interfaces,
     Interfaces.C.Strings,
     Ada.Characters.Handling;

use Interfaces,
    Interfaces.C.Strings,
    Ada.Characters.Handling;

with COM_N7SPACE_PIOHWAS;
use COM_N7SPACE_PIOHWAS;
with PROJECT3_DATAVIEW;
use PROJECT3_DATAVIEW;
with TASTE_BasicTypes;
use TASTE_BasicTypes;
with adaasn1rtl;
use adaasn1rtl;
with PioHwasDriver_Datamodel; use PioHwasDriver_Datamodel;

with PioHwasDriver_RI;
package PioHwasDriver with Elaborate_Body is
   ctxt : aliased asn1SccPiohwasdriver_Context :=
      (Init_Done => False,
       others => <>);
   function Get_State return chars_ptr is (New_String (asn1SccPioHwasDriver_States'Image (ctxt.State))) with Export, Convention => C, Link_Name => "piohwasdriver_state";
   procedure Startup with Export, Convention => C, Link_Name => "PioHwasDriver_startup";
   procedure PioHwas_InitPin_Pi(Pio: in out asn1SccPioHwas;Config: in out asn1SccPioHwasPinConfig);
   pragma Export (C, PioHwas_InitPin_Pi, "piohwasdriver_PI_PioHwas_InitPin_Pi");
   procedure PioHwas_ResetPin_Pi(Pio: in out asn1SccPioHwas);
   pragma Export (C, PioHwas_ResetPin_Pi, "piohwasdriver_PI_PioHwas_ResetPin_Pi");
   procedure PioHwas_SetPin_Pi(Pio: in out asn1SccPioHwas);
   pragma Export (C, PioHwas_SetPin_Pi, "piohwasdriver_PI_PioHwas_SetPin_Pi");
   --  Provided interface "PioHwas_InitPin_Pi"
   procedure PioHwas_InitPin_Pi_Transition;
   --  Provided interface "PioHwas_ResetPin_Pi"
   procedure PioHwas_ResetPin_Pi_Transition;
   --  Provided interface "PioHwas_SetPin_Pi"
   procedure PioHwas_SetPin_Pi_Transition;
   --  Synchronous Required Interface "RawMemoryAccess_ReadBuffer_Ri"
   procedure RI_0_RawMemoryAccess_ReadBuffer_Ri (Address : in out asn1SccSourceAddress; Buffer : out asn1SccByteBuffer) renames PioHwasDriver_RI.RawMemoryAccess_ReadBuffer_Ri;
   --  Synchronous Required Interface "RawMemoryAccess_ReadWord_Ri"
   procedure RI_0_RawMemoryAccess_ReadWord_Ri (Address : in out asn1SccSourceAddress; Mask : in out asn1SccWordMask; Inputvalue : out asn1SccWord) renames PioHwasDriver_RI.RawMemoryAccess_ReadWord_Ri;
   --  Synchronous Required Interface "RawMemoryAccess_WriteBuffer_Ri"
   procedure RI_0_RawMemoryAccess_WriteBuffer_Ri (Address : in out asn1SccDestinationAddress; Buffer : in out asn1SccByteBuffer) renames PioHwasDriver_RI.RawMemoryAccess_WriteBuffer_Ri;
   --  Synchronous Required Interface "RawMemoryAccess_WriteWord_Ri"
   procedure RI_0_RawMemoryAccess_WriteWord_Ri (Address : in out asn1SccDestinationAddress; Mask : in out asn1SccWordMask; Inputvalue : in out asn1SccWord) renames PioHwasDriver_RI.RawMemoryAccess_WriteWord_Ri;
   procedure Execute_Transition (Id : Integer);
   CS_Only : constant := 4;
end PioHwasDriver;