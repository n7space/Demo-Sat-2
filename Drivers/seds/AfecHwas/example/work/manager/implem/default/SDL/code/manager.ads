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
with SAMV71AFEC_DATAVIEW;
use SAMV71AFEC_DATAVIEW;
with TASTE_BasicTypes;
use TASTE_BasicTypes;
with adaasn1rtl;
use adaasn1rtl;
with Manager_Datamodel; use Manager_Datamodel;

with Manager_RI;
package Manager with Elaborate_Body is
   ctxt : aliased asn1SccManager_Context :=
      (Init_Done => False,
       others => <>);
   function Get_State return chars_ptr is (New_String (asn1SccManager_States'Image (ctxt.State))) with Export, Convention => C, Link_Name => "manager_state";
   procedure Startup with Export, Convention => C, Link_Name => "Manager_startup";
   --  Provided interface "GetTemperature"
   procedure GetTemperature;
   pragma Export(C, GetTemperature, "manager_PI_GetTemperature");
   --  Synchronous Required Interface "AfecHwasInterface_GetValue_Pi"
   procedure RI_0_AfecHwasInterface_GetValue_Pi (Afec : in out asn1SccAfecHwas; Analogchannel : in out asn1SccAfecHwasChannel; Channeloutput : out asn1SccWord) renames Manager_RI.AfecHwasInterface_GetValue_Pi;
   --  Synchronous Required Interface "AfecHwasInterface_InitInstance_Pi"
   procedure RI_0_AfecHwasInterface_InitInstance_Pi (Afec : out asn1SccAfecHwas; Config : in out asn1SccAfecHwasConfig) renames Manager_RI.AfecHwasInterface_InitInstance_Pi;
   procedure Execute_Transition (Id : Integer);
   CS_Only : constant := 1;
end Manager;