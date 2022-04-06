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
with Hwas_Datamodel; use Hwas_Datamodel;

with Hwas_RI;
package Hwas with Elaborate_Body is
   ctxt : aliased asn1SccHwas_Context :=
      (Init_Done => False,
       others => <>);
   function Get_State return chars_ptr is (New_String (asn1SccHwas_States'Image (ctxt.State))) with Export, Convention => C, Link_Name => "hwas_state";
   procedure Startup with Export, Convention => C, Link_Name => "Hwas_startup";
   --  Provided interface "RawMemoryAccess_ReadWord_Pi"
   procedure RawMemoryAccess_ReadWord_Pi_Transition;
   --  Provided interface "RawMemoryAccess_WriteWord_Pi"
   procedure RawMemoryAccess_WriteWord_Pi_Transition;
   procedure Execute_Transition (Id : Integer);
   CS_Only : constant := 1;
end Hwas;