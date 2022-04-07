-- This file was generated automatically by OpenGEODE: DO NOT MODIFY IT !

with Interfaces,
     Interfaces.C.Strings,
     Ada.Characters.Handling;

use Interfaces,
    Interfaces.C.Strings,
    Ada.Characters.Handling;

with COM_N7SPACE_AFECHWAS;
use COM_N7SPACE_AFECHWAS;
with COM_N7SPACE_HWAS;
use COM_N7SPACE_HWAS;
with TASTE_BasicTypes;
use TASTE_BasicTypes;
with adaasn1rtl;
use adaasn1rtl;
with AfecHwasDriver_Datamodel; use AfecHwasDriver_Datamodel;

with AfecHwasDriver_RI;
package AfecHwasDriver with Elaborate_Body is
   ctxt : aliased asn1SccAfechwasdriver_Context :=
      (Init_Done => False,
       others => <>);
   function Get_State return chars_ptr is (New_String (asn1SccAfecHwasDriver_States'Image (ctxt.State))) with Export, Convention => C, Link_Name => "afechwasdriver_state";
   procedure Startup with Export, Convention => C, Link_Name => "AfecHwasDriver_startup";
   procedure AfecHwasInterface_GetValue_Pi(Afec: in out asn1SccAfecHwas;Analogchannel: in out asn1SccAfecHwasChannel;Channeloutput: in out asn1SccWord);
   pragma Export (C, AfecHwasInterface_GetValue_Pi, "afechwasdriver_PI_AfecHwasInterface_GetValue_Pi");
   procedure AfecHwasInterface_InitInstance_Pi(Afec: in out asn1SccAfecHwas;Config: in out asn1SccAfecHwasConfig);
   pragma Export (C, AfecHwasInterface_InitInstance_Pi, "afechwasdriver_PI_AfecHwasInterface_InitInstance_Pi");
   --  Provided interface "AfecHwasInterface_GetValue_Pi"
   procedure AfecHwasInterface_GetValue_Pi_Transition;
   --  Provided interface "AfecHwasInterface_InitInstance_Pi"
   procedure AfecHwasInterface_InitInstance_Pi_Transition;
   --  Synchronous Required Interface "RawMemoryAccess_ReadWord_Ri"
   procedure RI_0_RawMemoryAccess_ReadWord_Ri (Address : in out asn1SccSourceAddress; Mask : in out asn1SccWordMask; Outputvalue : out asn1SccWord) renames AfecHwasDriver_RI.RawMemoryAccess_ReadWord_Ri;
   --  Synchronous Required Interface "RawMemoryAccess_WriteWord_Ri"
   procedure RI_0_RawMemoryAccess_WriteWord_Ri (Address : in out asn1SccDestinationAddress; Mask : in out asn1SccWordMask; Inputvalue : in out asn1SccWord) renames AfecHwasDriver_RI.RawMemoryAccess_WriteWord_Ri;
   procedure Execute_Transition (Id : Integer);
   CS_Only : constant := 3;
end AfecHwasDriver;