-- This file was generated automatically by OpenGEODE: DO NOT MODIFY IT !

with System.IO;
use System.IO;

with Ada.Unchecked_Conversion;
with Ada.Numerics.Generic_Elementary_Functions;

package body AfecHwasDriver is
   procedure p_0_InitPmc;
   procedure p_0_InitAfecContainer;
   procedure p_0_InitSync(Config: in asn1SccAfecHwasConfig);
   procedure p_0_GetValue(Afec: in asn1SccAfecHwas;Analogchannel: in asn1SccAfecHwasChannel);
   procedure p_0_InitPmc is
      begin
         --  Pmcvar.Pmc_pcer0_offset := 1074660880 (20,17)
         ctxt.Pmcvar.pmc_pcer0_offset := 1074660880;
         --  Pmcvar.Pmc_pcer1_offset := 1074661120 (22,17)
         ctxt.Pmcvar.pmc_pcer1_offset := 1074661120;
         --  Pmcvar.Pmc_pcxr0_pid29_afec0_mask := 536870912 (24,17)
         ctxt.Pmcvar.pmc_pcxr0_pid29_afec0_mask := 536870912;
         --  Pmcvar.Pmc_pcxr1_pid40_afec1_mask := 256 (26,17)
         ctxt.Pmcvar.pmc_pcxr1_pid40_afec1_mask := 256;
         --  RETURN  (None,None) at None, None
         return;
      end p_0_InitPmc;
      

   procedure p_0_InitAfecContainer is
      begin
         --  Afecvar.Minstancemraddress := 4 (34,17)
         ctxt.Afecvar.minstancemraddress := 4;
         --  Afecvar.Minstancemraddress := Afecvar.Minstanceaddress + Afecvar.Minstancemraddress (36,17)
         ctxt.Afecvar.minstancemraddress := (ctxt.Afecvar.minstanceaddress + ctxt.Afecvar.minstancemraddress);
         --  Afecvar.Minstanceemraddress := 8 (38,17)
         ctxt.Afecvar.minstanceemraddress := 8;
         --  Afecvar.Minstanceemraddress := Afecvar.Minstanceaddress + Afecvar.Minstanceemraddress (40,17)
         ctxt.Afecvar.minstanceemraddress := (ctxt.Afecvar.minstanceaddress + ctxt.Afecvar.minstanceemraddress);
         --  Afecvar.Minstancecheraddress := 20 (42,17)
         ctxt.Afecvar.minstancecheraddress := 20;
         --  Afecvar.Minstancecheraddress := Afecvar.Minstanceaddress + Afecvar.Minstancecheraddress (44,17)
         ctxt.Afecvar.minstancecheraddress := (ctxt.Afecvar.minstanceaddress + ctxt.Afecvar.minstancecheraddress);
         --  Afecvar.Minstancechdraddress := 24 (46,17)
         ctxt.Afecvar.minstancechdraddress := 24;
         --  Afecvar.Minstancechdraddress := Afecvar.Minstanceaddress + Afecvar.Minstancechdraddress (48,17)
         ctxt.Afecvar.minstancechdraddress := (ctxt.Afecvar.minstanceaddress + ctxt.Afecvar.minstancechdraddress);
         --  Afecvar.Minstancechsraddress := 28 (50,17)
         ctxt.Afecvar.minstancechsraddress := 28;
         --  Afecvar.Minstancechsraddress := Afecvar.Minstanceaddress + Afecvar.Minstancechsraddress (52,17)
         ctxt.Afecvar.minstancechsraddress := (ctxt.Afecvar.minstanceaddress + ctxt.Afecvar.minstancechsraddress);
         --  Afecvar.Minstancecraddress := 0 (54,17)
         ctxt.Afecvar.minstancecraddress := 0;
         --  Afecvar.Minstancecraddress := Afecvar.Minstanceaddress + Afecvar.Minstancecraddress (56,17)
         ctxt.Afecvar.minstancecraddress := (ctxt.Afecvar.minstanceaddress + ctxt.Afecvar.minstancecraddress);
         --  Afecvar.Minstanceisraddress := 48 (58,17)
         ctxt.Afecvar.minstanceisraddress := 48;
         --  Afecvar.Minstanceisraddress := Afecvar.Minstanceaddress + Afecvar.Minstanceisraddress (60,17)
         ctxt.Afecvar.minstanceisraddress := (ctxt.Afecvar.minstanceaddress + ctxt.Afecvar.minstanceisraddress);
         --  Afecvar.Minstancelcdraddress := 32 (62,17)
         ctxt.Afecvar.minstancelcdraddress := 32;
         --  Afecvar.Minstancelcdraddress := Afecvar.Minstanceaddress + Afecvar.Minstancelcdraddress (64,17)
         ctxt.Afecvar.minstancelcdraddress := (ctxt.Afecvar.minstanceaddress + ctxt.Afecvar.minstancelcdraddress);
         --  RETURN  (None,None) at None, None
         return;
      end p_0_InitAfecContainer;
      

   procedure p_0_InitSync(Config: in asn1SccAfecHwasConfig) is
      tmp179 : asn1SccWord;
      tmp178 : asn1SccWordMask;
      --  !! stack: _call_external_function line 1656
      begin
         --  InitPmc (76,17)
         p_0_InitPmc;
         --  DECISION Config.Mafecinstance = AfecHwas_Instance_Afec0 (78,42)
         --  ANSWER True (80,17)
         if ((Config.mafecinstance = asn1SccafecHwas_Instance_Afec0)) then
            --  Afecvar.Minstanceaddress := 1073987584 (82,25)
            ctxt.Afecvar.minstanceaddress := 1073987584;
            --  JOIN condition_1 (84,25) at 0, 1162
            goto condition_1;
            --  ANSWER False (86,17)
         else
            --  DECISION Config.Mafecinstance = AfecHwas_Instance_Afec1 (88,50)
            --  ANSWER True (90,25)
            if ((Config.mafecinstance = asn1SccafecHwas_Instance_Afec1)) then
               --  Afecvar.Minstanceaddress := 1074151424 (92,33)
               ctxt.Afecvar.minstanceaddress := 1074151424;
               --  JOIN condition_2 (94,33) at 600, 1237
               goto condition_2;
               --  ANSWER False (96,25)
            else
               --  JOIN condition_2 (98,33) at 1200, 1162
               goto condition_2;
            end if;
            --  JOIN condition_2 (None,None) at None, None
            goto condition_2;
         end if;
         --  JOIN condition_1 (None,None) at None, None
         goto condition_1;
         --  CONNECTION condition_2 (101,20)
         <<condition_2>>
         --  JOIN condition_1 (103,25) at 1800, 1237
         goto condition_1;
         --  CONNECTION condition_4 (141,20)
         <<condition_4>>
         --  JOIN condition_3 (143,25) at 4200, 1462
         goto condition_3;
         --  CONNECTION condition_3 (146,12)
         <<condition_3>>
         --  RawMemoryAccess_WriteWord_Ri(Destinationaddressvar, Pinmaskvar, Bitstosetvar) (148,17)
         RI_0_RawMemoryAccess_WriteWord_Ri(ctxt.Destinationaddressvar, ctxt.Pinmaskvar, ctxt.Bitstosetvar);
         --  Bitstosetvar := (8388608 + (Config.Mstartuptime * 65536)) + (Config.Mprescalervalue * 256) (150,17)
         ctxt.Bitstosetvar := ((8388608 + (Config.mstartuptime * 65536)) + (Config.mprescalervalue * 256));
         --  Destinationaddressvar := Afecvar.Minstancemraddress (152,17)
         ctxt.Destinationaddressvar := ctxt.Afecvar.minstancemraddress;
         --  RawMemoryAccess_WriteWord_Ri(Destinationaddressvar, Bitstosetvar, Bitstosetvar) (154,17)
         RI_0_RawMemoryAccess_WriteWord_Ri(ctxt.Destinationaddressvar, ctxt.Bitstosetvar, ctxt.Bitstosetvar);
         --  Destinationaddressvar := Afecvar.Minstanceemraddress (156,17)
         ctxt.Destinationaddressvar := ctxt.Afecvar.minstanceemraddress;
         --  RawMemoryAccess_WriteWord_Ri(Destinationaddressvar, 16777216, 16777216) (158,17)
         tmp178 := asn1SccWordMask (16777216);
         tmp179 := asn1SccWord (16777216);
         RI_0_RawMemoryAccess_WriteWord_Ri(ctxt.Destinationaddressvar, tmp178, tmp179);
         --  RETURN  (None,None) at None, None
         return;
         --  CONNECTION condition_1 (106,12)
         <<condition_1>>
         --  InitAfecContainer (108,17)
         p_0_InitAfecContainer;
         --  DECISION Config.Mafecinstance = AfecHwas_Instance_Afec0 (110,42)
         --  ANSWER True (112,17)
         if ((Config.mafecinstance = asn1SccafecHwas_Instance_Afec0)) then
            --  Destinationaddressvar := Pmcvar.Pmc_pcer0_offset (114,25)
            ctxt.Destinationaddressvar := ctxt.Pmcvar.pmc_pcer0_offset;
            --  Pinmaskvar := Pmcvar.Pmc_pcxr0_pid29_afec0_mask (116,25)
            ctxt.Pinmaskvar := ctxt.Pmcvar.pmc_pcxr0_pid29_afec0_mask;
            --  Bitstosetvar := Pmcvar.Pmc_pcxr0_pid29_afec0_mask (118,25)
            ctxt.Bitstosetvar := ctxt.Pmcvar.pmc_pcxr0_pid29_afec0_mask;
            --  JOIN condition_3 (120,25) at 2400, 1537
            goto condition_3;
            --  ANSWER False (122,17)
         else
            --  DECISION Config.Mafecinstance = AfecHwas_Instance_Afec1 (124,50)
            --  ANSWER True (126,25)
            if ((Config.mafecinstance = asn1SccafecHwas_Instance_Afec1)) then
               --  Destinationaddressvar := Pmcvar.Pmc_pcer1_offset (128,33)
               ctxt.Destinationaddressvar := ctxt.Pmcvar.pmc_pcer1_offset;
               --  Pinmaskvar := Pmcvar.Pmc_pcxr1_pid40_afec1_mask (130,33)
               ctxt.Pinmaskvar := ctxt.Pmcvar.pmc_pcxr1_pid40_afec1_mask;
               --  Bitstosetvar := Pmcvar.Pmc_pcxr1_pid40_afec1_mask (132,33)
               ctxt.Bitstosetvar := ctxt.Pmcvar.pmc_pcxr1_pid40_afec1_mask;
               --  JOIN condition_4 (134,33) at 3000, 1612
               goto condition_4;
               --  ANSWER False (136,25)
            else
               --  JOIN condition_4 (138,33) at 3600, 1387
               goto condition_4;
            end if;
            --  JOIN condition_4 (None,None) at None, None
            goto condition_4;
         end if;
         --  JOIN condition_3 (None,None) at None, None
         goto condition_3;
      end p_0_InitSync;
      

   procedure p_0_GetValue(Afec: in asn1SccAfecHwas;Analogchannel: in asn1SccAfecHwasChannel) is
      tmp204 : asn1SccWordMask;
      tmp235 : asn1SccWord;
      --  !! stack: _call_external_function line 1656
      tmp234 : asn1SccWordMask;
      tmp274 : asn1SccWord;
      tmp251 : asn1SccWordMask;
      tmp264 : asn1SccWordMask;
      tmp273 : asn1SccWordMask;
      begin
         --  Channelmaskvar := power(2, Analogchannel) (171,17)
         ctxt.Channelmaskvar := 2 ** Natural(Analogchannel);
         --  Destinationaddressvar := Afecvar.Minstancecheraddress (173,17)
         ctxt.Destinationaddressvar := ctxt.Afecvar.minstancecheraddress;
         --  RawMemoryAccess_WriteWord_Ri(Destinationaddressvar, Channelmaskvar, Channelmaskvar) (175,17)
         RI_0_RawMemoryAccess_WriteWord_Ri(ctxt.Destinationaddressvar, ctxt.Channelmaskvar, ctxt.Channelmaskvar);
         --  Bitstosetvar := 4294967295 - Channelmaskvar (177,17)
         ctxt.Bitstosetvar := (4294967295 - ctxt.Channelmaskvar);
         --  Destinationaddressvar := Afecvar.Minstancechdraddress (179,17)
         ctxt.Destinationaddressvar := ctxt.Afecvar.minstancechdraddress;
         --  RawMemoryAccess_WriteWord_Ri(Destinationaddressvar, 4095, Bitstosetvar) (181,17)
         tmp204 := asn1SccWordMask (4095);
         RI_0_RawMemoryAccess_WriteWord_Ri(ctxt.Destinationaddressvar, tmp204, ctxt.Bitstosetvar);
         --  Sourceaddressvar := Afecvar.Minstancechsraddress (183,17)
         ctxt.Sourceaddressvar := ctxt.Afecvar.minstancechsraddress;
         --  Readbitsvar := 0 (185,17)
         ctxt.Readbitsvar := 0;
         --  JOIN loop_start_1 (None,None) at None, None
         goto loop_start_1;
         --  CONNECTION loop_end_4 (231,12)
         <<loop_end_4>>
         --  Sourceaddressvar := Afecvar.Minstancelcdraddress (233,17)
         ctxt.Sourceaddressvar := ctxt.Afecvar.minstancelcdraddress;
         --  RawMemoryAccess_ReadWord_Ri(Sourceaddressvar, 65535, Readbitsvar) (235,17)
         tmp264 := asn1SccWordMask (65535);
         RI_0_RawMemoryAccess_ReadWord_Ri(ctxt.Sourceaddressvar, tmp264, ctxt.Readbitsvar);
         --  Destinationaddressvar := Afecvar.Minstancechdraddress (237,17)
         ctxt.Destinationaddressvar := ctxt.Afecvar.minstancechdraddress;
         --  RawMemoryAccess_WriteWord_Ri(Destinationaddressvar, 4095, 4095) (239,17)
         tmp273 := asn1SccWordMask (4095);
         tmp274 := asn1SccWord (4095);
         RI_0_RawMemoryAccess_WriteWord_Ri(ctxt.Destinationaddressvar, tmp273, tmp274);
         --  RETURN  (None,None) at None, None
         return;
         --  CONNECTION loop_start_3 (214,12)
         <<loop_start_3>>
         --  DECISION Readbitsvar <= 16777216 (216,33)
         --  ANSWER False (218,17)
         if not ((ctxt.Readbitsvar <= 16777216)) then
            --  JOIN loop_end_4 (220,25) at 1200, 2212
            goto loop_end_4;
            --  ANSWER True (222,17)
         else
            --  RawMemoryAccess_ReadWord_Ri(Sourceaddressvar, 16777216, Readbitsvar) (224,25)
            tmp251 := asn1SccWordMask (16777216);
            RI_0_RawMemoryAccess_ReadWord_Ri(ctxt.Sourceaddressvar, tmp251, ctxt.Readbitsvar);
            --  Readbitsvar := Readbitsvar + 1 (226,25)
            ctxt.Readbitsvar := (ctxt.Readbitsvar + 1);
            --  JOIN loop_start_3 (228,25) at 1800, 2362
            goto loop_start_3;
         end if;
         --  JOIN loop_end_4 (None,None) at None, None
         goto loop_end_4;
         --  CONNECTION loop_end_2 (204,12)
         <<loop_end_2>>
         --  Destinationaddressvar := Afecvar.Minstancecraddress (206,17)
         ctxt.Destinationaddressvar := ctxt.Afecvar.minstancecraddress;
         --  RawMemoryAccess_WriteWord_Ri(Destinationaddressvar, 2, 2) (208,17)
         tmp234 := asn1SccWordMask (2);
         tmp235 := asn1SccWord (2);
         RI_0_RawMemoryAccess_WriteWord_Ri(ctxt.Destinationaddressvar, tmp234, tmp235);
         --  Sourceaddressvar := Afecvar.Minstanceisraddress (210,17)
         ctxt.Sourceaddressvar := ctxt.Afecvar.minstanceisraddress;
         --  Readbitsvar := 0 (212,17)
         ctxt.Readbitsvar := 0;
         --  JOIN loop_start_3 (None,None) at None, None
         goto loop_start_3;
         --  CONNECTION loop_start_1 (187,12)
         <<loop_start_1>>
         --  DECISION Readbitsvar <= Channelmaskvar (189,33)
         --  ANSWER False (191,17)
         if not ((ctxt.Readbitsvar <= ctxt.Channelmaskvar)) then
            --  JOIN loop_end_2 (193,25) at 0, 1687
            goto loop_end_2;
            --  ANSWER True (195,17)
         else
            --  RawMemoryAccess_ReadWord_Ri(Sourceaddressvar, Channelmaskvar, Readbitsvar) (197,25)
            RI_0_RawMemoryAccess_ReadWord_Ri(ctxt.Sourceaddressvar, ctxt.Channelmaskvar, ctxt.Readbitsvar);
            --  Readbitsvar := Readbitsvar + 1 (199,25)
            ctxt.Readbitsvar := (ctxt.Readbitsvar + 1);
            --  JOIN loop_start_1 (201,25) at 600, 1837
            goto loop_start_1;
         end if;
         --  JOIN loop_end_2 (None,None) at None, None
         goto loop_end_2;
      end p_0_GetValue;
      

   procedure AfecHwasInterface_GetValue_Pi(Afec: in out asn1SccAfecHwas;Analogchannel: in out asn1SccAfecHwasChannel;Channeloutput: in out asn1SccWord) is
      begin
         --  Afecvar := Afec (253,17)
         ctxt.Afecvar := Afec;
         --  Channelvar := Analogchannel (255,17)
         ctxt.Channelvar := Analogchannel;
         --  GetValue(Afecvar, Channelvar) (257,17)
         p_0_GetValue(ctxt.Afecvar, ctxt.Channelvar);
         --  Channeloutput := Readbitsvar (259,17)
         Channeloutput := ctxt.Readbitsvar;
         --  AfecHwasInterface_GetValue_Pi_Transition (None,None)
         AfecHwasInterface_GetValue_Pi_Transition;
         --  RETURN  (None,None) at None, None
         return;
      end AfecHwasInterface_GetValue_Pi;
      

   procedure AfecHwasInterface_InitInstance_Pi(Afec: in out asn1SccAfecHwas;Config: in out asn1SccAfecHwasConfig) is
      begin
         --  Configvar := Config (272,17)
         ctxt.Configvar := Config;
         --  InitSync(Configvar) (274,17)
         p_0_InitSync(ctxt.Configvar);
         --  Afec := Afecvar (276,17)
         Afec := ctxt.Afecvar;
         --  AfecHwasInterface_InitInstance_Pi_Transition (None,None)
         AfecHwasInterface_InitInstance_Pi_Transition;
         --  RETURN  (None,None) at None, None
         return;
      end AfecHwasInterface_InitInstance_Pi;
      

   procedure AfecHwasInterface_GetValue_Pi_Transition is
      begin
         case ctxt.state is
            when asn1Sccidle =>
               Execute_Transition (1);
            when others =>
               Execute_Transition (CS_Only);
         end case;
      end AfecHwasInterface_GetValue_Pi_Transition;
      

   procedure AfecHwasInterface_InitInstance_Pi_Transition is
      begin
         case ctxt.state is
            when asn1Sccoff =>
               Execute_Transition (2);
            when others =>
               Execute_Transition (CS_Only);
         end case;
      end AfecHwasInterface_InitInstance_Pi_Transition;
      

   procedure Execute_Transition (Id : Integer) is
      trId : Integer := Id;
      begin
         while (trId /= -1) loop
            case trId is
               when 0 =>
                  --  NEXT_STATE Off (282,18) at 0, 1537
                  trId := -1;
                  ctxt.State := asn1SccOff;
                  goto Continuous_Signals;
               when 1 =>
                  --  NEXT_STATE Idle (288,22) at 0, 1687
                  trId := -1;
                  ctxt.State := asn1SccIdle;
                  goto Continuous_Signals;
               when 2 =>
                  --  NEXT_STATE Idle (295,22) at 600, 1687
                  trId := -1;
                  ctxt.State := asn1SccIdle;
                  goto Continuous_Signals;
               when CS_Only =>
                  trId := -1;
                  goto Continuous_Signals;
               when others =>
                  null;
            end case;
            <<Continuous_Signals>>
            <<Next_Transition>>
         end loop;
      end Execute_Transition;
      

   procedure Startup is
      begin
         Execute_Transition (0);
         ctxt.Init_Done := True;
      end Startup;
   begin
      Startup;
end AfecHwasDriver;