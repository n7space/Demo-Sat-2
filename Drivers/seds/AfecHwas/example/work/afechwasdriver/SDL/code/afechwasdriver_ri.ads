--  DO NOT EDIT THIS FILE, IT WILL BE OVERWRITTEN DURING THE BUILD
--  Generated by TASTE (Kazoo template templates/skeletons/ada-ri-source/function.tmplt)
--  2022-04-07 10:47:13
with Com_N7space_Afechwas; use Com_N7space_Afechwas;
with Com_N7space_Hwas;     use Com_N7space_Hwas;
with Taste_Basictypes;     use Taste_Basictypes;
with adaasn1rtl;

package Afechwasdriver_RI is

   procedure Rawmemoryaccess_Readword_Ri (Address : in out asn1SccSourceaddress; Mask : in out asn1SccWordmask; Outputvalue : out asn1SccWord);
   
   
   procedure Rawmemoryaccess_Writeword_Ri (Address : in out asn1SccDestinationaddress; Mask : in out asn1SccWordmask; Inputvalue : in out asn1SccWord);

   procedure Check_Queue (Res : out adaasn1rtl.Asn1Boolean)
      with Import, Convention => C, Link_Name => "afechwasdriver_check_queue";
end Afechwasdriver_RI;
