-- This file was generated automatically by OpenGEODE: DO NOT MODIFY IT !

with System.IO;
use System.IO;

with Ada.Unchecked_Conversion;
with Ada.Numerics.Generic_Elementary_Functions;

package body PioHwasDriver is
   procedure p_0_InitPmc;
   procedure p_0_InitPioContainer;
   procedure p_0_InitializePin(Config: in asn1SccPioHwasPinConfig);
   procedure p_0_SetPin(Pio: in asn1SccPioHwas);
   procedure p_0_ResetPin(Pio: in asn1SccPioHwas);
   procedure p_0_GetPinValue(Pio: in asn1SccPioHwas);
   procedure p_0_InitPmc is
      begin
         --  Pmcvar.Pmc_pcer0_offset := 1074660880 (17,17)
         ctxt.Pmcvar.pmc_pcer0_offset := 1074660880;
         --  Pmcvar.Pmc_pcxr0_pid10_pioa_mask := 1024 (19,17)
         ctxt.Pmcvar.pmc_pcxr0_pid10_pioa_mask := 1024;
         --  Pmcvar.Pmc_pcxr0_pid11_piob_mask := 2048 (21,17)
         ctxt.Pmcvar.pmc_pcxr0_pid11_piob_mask := 2048;
         --  Pmcvar.Pmc_pcxr0_pid12_pioc_mask := 4096 (23,17)
         ctxt.Pmcvar.pmc_pcxr0_pid12_pioc_mask := 4096;
         --  Pmcvar.Pmc_pcxr0_pid16_piod_mask := 65536 (25,17)
         ctxt.Pmcvar.pmc_pcxr0_pid16_piod_mask := 65536;
         --  Pmcvar.Pmc_pcxr0_pid17_pioe_mask := 131072 (27,17)
         ctxt.Pmcvar.pmc_pcxr0_pid17_pioe_mask := 131072;
         --  RETURN  (None,None) at None, None
         return;
      end p_0_InitPmc;
      

   procedure p_0_InitPioContainer is
      begin
         --  Piovar.Mportperaddress := 0 (35,17)
         ctxt.Piovar.mportperaddress := 0;
         --  Piovar.Mportperaddress := Piovar.Mportaddress + 0 (37,17)
         ctxt.Piovar.mportperaddress := (ctxt.Piovar.mportaddress + 0);
         --  Piovar.Mportoeraddress := 16 (39,17)
         ctxt.Piovar.mportoeraddress := 16;
         --  Piovar.Mportoeraddress := Piovar.Mportaddress + Piovar.Mportoeraddress (41,17)
         ctxt.Piovar.mportoeraddress := (ctxt.Piovar.mportaddress + ctxt.Piovar.mportoeraddress);
         --  Piovar.Mportodraddress := 20 (43,17)
         ctxt.Piovar.mportodraddress := 20;
         --  Piovar.Mportodraddress := Piovar.Mportaddress + Piovar.Mportodraddress (45,17)
         ctxt.Piovar.mportodraddress := (ctxt.Piovar.mportaddress + ctxt.Piovar.mportodraddress);
         --  Piovar.Mportifdraddress := 36 (47,17)
         ctxt.Piovar.mportifdraddress := 36;
         --  Piovar.Mportifdraddress := Piovar.Mportaddress + Piovar.Mportifdraddress (49,17)
         ctxt.Piovar.mportifdraddress := (ctxt.Piovar.mportaddress + ctxt.Piovar.mportifdraddress);
         --  Piovar.Mportsodraddress := 48 (51,17)
         ctxt.Piovar.mportsodraddress := 48;
         --  Piovar.Mportsodraddress := Piovar.Mportaddress + Piovar.Mportsodraddress (53,17)
         ctxt.Piovar.mportsodraddress := (ctxt.Piovar.mportaddress + ctxt.Piovar.mportsodraddress);
         --  Piovar.Mportcodraddress := 52 (55,17)
         ctxt.Piovar.mportcodraddress := 52;
         --  Piovar.Mportcodraddress := Piovar.Mportaddress + Piovar.Mportcodraddress (57,17)
         ctxt.Piovar.mportcodraddress := (ctxt.Piovar.mportaddress + ctxt.Piovar.mportcodraddress);
         --  Piovar.Mportodsraddress := 56 (59,17)
         ctxt.Piovar.mportodsraddress := 56;
         --  Piovar.Mportodsraddress := Piovar.Mportaddress + Piovar.Mportodsraddress (61,17)
         ctxt.Piovar.mportodsraddress := (ctxt.Piovar.mportaddress + ctxt.Piovar.mportodsraddress);
         --  Piovar.Mportmddraddress := 84 (63,17)
         ctxt.Piovar.mportmddraddress := 84;
         --  Piovar.Mportmddraddress := Piovar.Mportaddress + Piovar.Mportmddraddress (65,17)
         ctxt.Piovar.mportmddraddress := (ctxt.Piovar.mportaddress + ctxt.Piovar.mportmddraddress);
         --  Piovar.Mportpudraddress := 96 (67,17)
         ctxt.Piovar.mportpudraddress := 96;
         --  Piovar.Mportpudraddress := Piovar.Mportaddress + Piovar.Mportpudraddress (69,17)
         ctxt.Piovar.mportpudraddress := (ctxt.Piovar.mportaddress + ctxt.Piovar.mportpudraddress);
         --  Piovar.Mportifscdraddress := 128 (71,17)
         ctxt.Piovar.mportifscdraddress := 128;
         --  Piovar.Mportifscdraddress := Piovar.Mportaddress + Piovar.Mportifscdraddress (73,17)
         ctxt.Piovar.mportifscdraddress := (ctxt.Piovar.mportaddress + ctxt.Piovar.mportifscdraddress);
         --  Piovar.Mportppddraddress := 144 (75,17)
         ctxt.Piovar.mportppddraddress := 144;
         --  Piovar.Mportppddraddress := Piovar.Mportaddress + Piovar.Mportppddraddress (77,17)
         ctxt.Piovar.mportppddraddress := (ctxt.Piovar.mportaddress + ctxt.Piovar.mportppddraddress);
         --  Piovar.Mportoweraddress := 160 (79,17)
         ctxt.Piovar.mportoweraddress := 160;
         --  Piovar.Mportoweraddress := Piovar.Mportaddress + Piovar.Mportoweraddress (81,17)
         ctxt.Piovar.mportoweraddress := (ctxt.Piovar.mportaddress + ctxt.Piovar.mportoweraddress);
         --  Piovar.Mportowdraddress := 164 (83,17)
         ctxt.Piovar.mportowdraddress := 164;
         --  Piovar.Mportowdraddress := Piovar.Mportaddress + Piovar.Mportowdraddress (85,17)
         ctxt.Piovar.mportowdraddress := (ctxt.Piovar.mportaddress + ctxt.Piovar.mportowdraddress);
         --  Piovar.Mportschmittaddress := 256 (87,17)
         ctxt.Piovar.mportschmittaddress := 256;
         --  Piovar.Mportschmittaddress := Piovar.Mportaddress + Piovar.Mportschmittaddress (89,17)
         ctxt.Piovar.mportschmittaddress := (ctxt.Piovar.mportaddress + ctxt.Piovar.mportschmittaddress);
         --  RETURN  (None,None) at None, None
         return;
      end p_0_InitPioContainer;
      

   procedure p_0_InitializePin(Config: in asn1SccPioHwasPinConfig) is
      begin
         --  InitPmc (101,17)
         p_0_InitPmc;
         --  DECISION Config.Mportconfig = PioHwas_Port_A (103,40)
         --  ANSWER True (105,17)
         if ((Config.mportconfig = asn1SccpioHwas_Port_A)) then
            --  Piovar.Mportaddress := 1074662912 (107,25)
            ctxt.Piovar.mportaddress := 1074662912;
            --  JOIN condition_1 (109,25) at 0, 1162
            goto condition_1;
            --  ANSWER False (111,17)
         else
            --  DECISION Config.Mportconfig = PioHwas_Port_B (113,48)
            --  ANSWER True (115,25)
            if ((Config.mportconfig = asn1SccpioHwas_Port_B)) then
               --  Piovar.Mportaddress := 1074663424 (117,33)
               ctxt.Piovar.mportaddress := 1074663424;
               --  JOIN condition_2 (119,33) at 600, 1237
               goto condition_2;
               --  ANSWER False (121,25)
            else
               --  DECISION Config.Mportconfig = PioHwas_Port_C (123,56)
               --  ANSWER True (125,33)
               if ((Config.mportconfig = asn1SccpioHwas_Port_C)) then
                  --  Piovar.Mportaddress := 1074663936 (127,41)
                  ctxt.Piovar.mportaddress := 1074663936;
                  --  JOIN condition_3 (129,41) at 1200, 1312
                  goto condition_3;
                  --  ANSWER False (131,33)
               else
                  --  DECISION Config.Mportconfig = PioHwas_Port_D (133,64)
                  --  ANSWER True (135,41)
                  if ((Config.mportconfig = asn1SccpioHwas_Port_D)) then
                     --  Piovar.Mportaddress := 1074664448 (137,49)
                     ctxt.Piovar.mportaddress := 1074664448;
                     --  JOIN condition_4 (139,49) at 1800, 1387
                     goto condition_4;
                     --  ANSWER False (141,41)
                  else
                     --  DECISION Config.Mportconfig = PioHwas_Port_E (143,72)
                     --  ANSWER True (145,49)
                     if ((Config.mportconfig = asn1SccpioHwas_Port_E)) then
                        --  Piovar.Mportaddress := 1074664960 (147,57)
                        ctxt.Piovar.mportaddress := 1074664960;
                        --  JOIN condition_5 (149,57) at 2400, 1462
                        goto condition_5;
                        --  ANSWER False (151,49)
                     else
                        --  JOIN condition_5 (153,57) at 3000, 1387
                        goto condition_5;
                     end if;
                     --  JOIN condition_5 (None,None) at None, None
                     goto condition_5;
                  end if;
                  --  JOIN condition_4 (None,None) at None, None
                  goto condition_4;
               end if;
               --  JOIN condition_3 (None,None) at None, None
               goto condition_3;
            end if;
            --  JOIN condition_2 (None,None) at None, None
            goto condition_2;
         end if;
         --  JOIN condition_1 (None,None) at None, None
         goto condition_1;
         --  CONNECTION condition_5 (156,44)
         <<condition_5>>
         --  JOIN condition_4 (158,49) at 3600, 1462
         goto condition_4;
         --  CONNECTION condition_4 (161,36)
         <<condition_4>>
         --  JOIN condition_3 (163,41) at 4200, 1387
         goto condition_3;
         --  CONNECTION condition_3 (166,28)
         <<condition_3>>
         --  JOIN condition_2 (168,33) at 4800, 1312
         goto condition_2;
         --  CONNECTION condition_2 (171,20)
         <<condition_2>>
         --  JOIN condition_1 (173,25) at 5400, 1237
         goto condition_1;
         --  CONNECTION condition_10 (245,44)
         <<condition_10>>
         --  JOIN condition_9 (247,49) at 9600, 1762
         goto condition_9;
         --  CONNECTION condition_9 (250,36)
         <<condition_9>>
         --  JOIN condition_8 (252,41) at 10200, 1687
         goto condition_8;
         --  CONNECTION condition_8 (255,28)
         <<condition_8>>
         --  JOIN condition_7 (257,33) at 10800, 1612
         goto condition_7;
         --  CONNECTION condition_7 (260,20)
         <<condition_7>>
         --  JOIN condition_6 (262,25) at 11400, 1537
         goto condition_6;
         --  CONNECTION condition_12 (306,20)
         <<condition_12>>
         --  JOIN condition_11 (308,25) at 13800, 2137
         goto condition_11;
         --  CONNECTION condition_11 (311,12)
         <<condition_11>>
         --  Destinationaddressvar := Piovar.Mportowdraddress (313,17)
         ctxt.Destinationaddressvar := ctxt.Piovar.mportowdraddress;
         --  RawMemoryAccess_WriteWord_Ri(Destinationaddressvar, Pinmaskvar, Pinvaluevar) (315,17)
         RI_0_RawMemoryAccess_WriteWord_Ri(ctxt.Destinationaddressvar, ctxt.Pinmaskvar, ctxt.Pinvaluevar);
         --  Destinationaddressvar := Piovar.Mportpudraddress (317,17)
         ctxt.Destinationaddressvar := ctxt.Piovar.mportpudraddress;
         --  RawMemoryAccess_WriteWord_Ri(Destinationaddressvar, Pinmaskvar, Pinvaluevar) (319,17)
         RI_0_RawMemoryAccess_WriteWord_Ri(ctxt.Destinationaddressvar, ctxt.Pinmaskvar, ctxt.Pinvaluevar);
         --  Destinationaddressvar := Piovar.Mportppddraddress (321,17)
         ctxt.Destinationaddressvar := ctxt.Piovar.mportppddraddress;
         --  RawMemoryAccess_WriteWord_Ri(Destinationaddressvar, Pinmaskvar, Pinvaluevar) (323,17)
         RI_0_RawMemoryAccess_WriteWord_Ri(ctxt.Destinationaddressvar, ctxt.Pinmaskvar, ctxt.Pinvaluevar);
         --  Destinationaddressvar := Piovar.Mportifdraddress (325,17)
         ctxt.Destinationaddressvar := ctxt.Piovar.mportifdraddress;
         --  RawMemoryAccess_WriteWord_Ri(Destinationaddressvar, Pinmaskvar, Pinvaluevar) (327,17)
         RI_0_RawMemoryAccess_WriteWord_Ri(ctxt.Destinationaddressvar, ctxt.Pinmaskvar, ctxt.Pinvaluevar);
         --  Destinationaddressvar := Piovar.Mportifscdraddress (329,17)
         ctxt.Destinationaddressvar := ctxt.Piovar.mportifscdraddress;
         --  RawMemoryAccess_WriteWord_Ri(Destinationaddressvar, Pinmaskvar, Pinvaluevar) (331,17)
         RI_0_RawMemoryAccess_WriteWord_Ri(ctxt.Destinationaddressvar, ctxt.Pinmaskvar, ctxt.Pinvaluevar);
         --  Destinationaddressvar := Piovar.Mportschmittaddress (333,17)
         ctxt.Destinationaddressvar := ctxt.Piovar.mportschmittaddress;
         --  RawMemoryAccess_WriteWord_Ri(Destinationaddressvar, Pinmaskvar, Pinvaluevar) (335,17)
         RI_0_RawMemoryAccess_WriteWord_Ri(ctxt.Destinationaddressvar, ctxt.Pinmaskvar, ctxt.Pinvaluevar);
         --  Destinationaddressvar := Piovar.Mportmddraddress (337,17)
         ctxt.Destinationaddressvar := ctxt.Piovar.mportmddraddress;
         --  RawMemoryAccess_WriteWord_Ri(Destinationaddressvar, Pinmaskvar, Pinvaluevar) (339,17)
         RI_0_RawMemoryAccess_WriteWord_Ri(ctxt.Destinationaddressvar, ctxt.Pinmaskvar, ctxt.Pinvaluevar);
         --  RETURN  (None,None) at None, None
         return;
         --  CONNECTION condition_6 (265,12)
         <<condition_6>>
         --  RawMemoryAccess_WriteWord_Ri(Destinationaddressvar, Pinmaskvar, Pinvaluevar) (267,17)
         RI_0_RawMemoryAccess_WriteWord_Ri(ctxt.Destinationaddressvar, ctxt.Pinmaskvar, ctxt.Pinvaluevar);
         --  Piovar.Mpin := power(2, Config.Mpinconfig) (269,17)
         ctxt.Piovar.mpin := 2 ** Natural(Config.mpinconfig);
         --  Pinvaluevar := Piovar.Mpin (271,17)
         ctxt.Pinvaluevar := ctxt.Piovar.mpin;
         --  Pinmaskvar := Piovar.Mpin (273,17)
         ctxt.Pinmaskvar := ctxt.Piovar.mpin;
         --  Destinationaddressvar := Piovar.Mportperaddress (275,17)
         ctxt.Destinationaddressvar := ctxt.Piovar.mportperaddress;
         --  RawMemoryAccess_WriteWord_Ri(Destinationaddressvar, Pinmaskvar, Pinvaluevar) (277,17)
         RI_0_RawMemoryAccess_WriteWord_Ri(ctxt.Destinationaddressvar, ctxt.Pinmaskvar, ctxt.Pinvaluevar);
         --  DECISION Config.Mdirectionconfig = PioHwas_Direction_Input (279,45)
         --  ANSWER True (281,17)
         if ((Config.mdirectionconfig = asn1SccpioHwas_Direction_Input)) then
            --  Destinationaddressvar := Piovar.Mportodraddress (283,25)
            ctxt.Destinationaddressvar := ctxt.Piovar.mportodraddress;
            --  RawMemoryAccess_WriteWord_Ri(Destinationaddressvar, Pinmaskvar, Pinvaluevar) (285,25)
            RI_0_RawMemoryAccess_WriteWord_Ri(ctxt.Destinationaddressvar, ctxt.Pinmaskvar, ctxt.Pinvaluevar);
            --  JOIN condition_11 (287,25) at 12000, 2137
            goto condition_11;
            --  ANSWER False (289,17)
         else
            --  DECISION Config.Mdirectionconfig = PioHwas_Direction_Output (291,53)
            --  ANSWER True (293,25)
            if ((Config.mdirectionconfig = asn1SccpioHwas_Direction_Output)) then
               --  Destinationaddressvar := Piovar.Mportoeraddress (295,33)
               ctxt.Destinationaddressvar := ctxt.Piovar.mportoeraddress;
               --  RawMemoryAccess_WriteWord_Ri(Destinationaddressvar, Pinmaskvar, Pinvaluevar) (297,33)
               RI_0_RawMemoryAccess_WriteWord_Ri(ctxt.Destinationaddressvar, ctxt.Pinmaskvar, ctxt.Pinvaluevar);
               --  JOIN condition_12 (299,33) at 12600, 2212
               goto condition_12;
               --  ANSWER False (301,25)
            else
               --  JOIN condition_12 (303,33) at 13200, 2062
               goto condition_12;
            end if;
            --  JOIN condition_12 (None,None) at None, None
            goto condition_12;
         end if;
         --  JOIN condition_11 (None,None) at None, None
         goto condition_11;
         --  CONNECTION condition_1 (176,12)
         <<condition_1>>
         --  InitPioContainer (178,17)
         p_0_InitPioContainer;
         --  Destinationaddressvar := Pmcvar.Pmc_pcer0_offset (180,17)
         ctxt.Destinationaddressvar := ctxt.Pmcvar.pmc_pcer0_offset;
         --  DECISION Config.Mportconfig = PioHwas_Port_A (182,40)
         --  ANSWER True (184,17)
         if ((Config.mportconfig = asn1SccpioHwas_Port_A)) then
            --  Pinmaskvar := Pmcvar.Pmc_pcxr0_pid10_pioa_mask (186,25)
            ctxt.Pinmaskvar := ctxt.Pmcvar.pmc_pcxr0_pid10_pioa_mask;
            --  Pinvaluevar := Pmcvar.Pmc_pcxr0_pid10_pioa_mask (188,25)
            ctxt.Pinvaluevar := ctxt.Pmcvar.pmc_pcxr0_pid10_pioa_mask;
            --  JOIN condition_6 (190,25) at 6000, 1537
            goto condition_6;
            --  ANSWER False (192,17)
         else
            --  DECISION Config.Mportconfig = PioHwas_Port_B (194,48)
            --  ANSWER True (196,25)
            if ((Config.mportconfig = asn1SccpioHwas_Port_B)) then
               --  Pinmaskvar := Pmcvar.Pmc_pcxr0_pid11_piob_mask (198,33)
               ctxt.Pinmaskvar := ctxt.Pmcvar.pmc_pcxr0_pid11_piob_mask;
               --  Pinvaluevar := Pmcvar.Pmc_pcxr0_pid11_piob_mask (200,33)
               ctxt.Pinvaluevar := ctxt.Pmcvar.pmc_pcxr0_pid11_piob_mask;
               --  JOIN condition_7 (202,33) at 6600, 1612
               goto condition_7;
               --  ANSWER False (204,25)
            else
               --  DECISION Config.Mportconfig = PioHwas_Port_C (206,56)
               --  ANSWER True (208,33)
               if ((Config.mportconfig = asn1SccpioHwas_Port_C)) then
                  --  Pinmaskvar := Pmcvar.Pmc_pcxr0_pid12_pioc_mask (210,41)
                  ctxt.Pinmaskvar := ctxt.Pmcvar.pmc_pcxr0_pid12_pioc_mask;
                  --  Pinvaluevar := Pmcvar.Pmc_pcxr0_pid12_pioc_mask (212,41)
                  ctxt.Pinvaluevar := ctxt.Pmcvar.pmc_pcxr0_pid12_pioc_mask;
                  --  JOIN condition_8 (214,41) at 7200, 1687
                  goto condition_8;
                  --  ANSWER False (216,33)
               else
                  --  DECISION Config.Mportconfig = PioHwas_Port_D (218,64)
                  --  ANSWER True (220,41)
                  if ((Config.mportconfig = asn1SccpioHwas_Port_D)) then
                     --  Pinmaskvar := Pmcvar.Pmc_pcxr0_pid16_piod_mask (222,49)
                     ctxt.Pinmaskvar := ctxt.Pmcvar.pmc_pcxr0_pid16_piod_mask;
                     --  Pinvaluevar := Pmcvar.Pmc_pcxr0_pid16_piod_mask (224,49)
                     ctxt.Pinvaluevar := ctxt.Pmcvar.pmc_pcxr0_pid16_piod_mask;
                     --  JOIN condition_9 (226,49) at 7800, 1762
                     goto condition_9;
                     --  ANSWER False (228,41)
                  else
                     --  DECISION Config.Mportconfig = PioHwas_Port_E (230,72)
                     --  ANSWER True (232,49)
                     if ((Config.mportconfig = asn1SccpioHwas_Port_E)) then
                        --  Pinmaskvar := Pmcvar.Pmc_pcxr0_pid17_pioe_mask (234,57)
                        ctxt.Pinmaskvar := ctxt.Pmcvar.pmc_pcxr0_pid17_pioe_mask;
                        --  Pinvaluevar := Pmcvar.Pmc_pcxr0_pid17_pioe_mask (236,57)
                        ctxt.Pinvaluevar := ctxt.Pmcvar.pmc_pcxr0_pid17_pioe_mask;
                        --  JOIN condition_10 (238,57) at 8400, 1837
                        goto condition_10;
                        --  ANSWER False (240,49)
                     else
                        --  JOIN condition_10 (242,57) at 9000, 1687
                        goto condition_10;
                     end if;
                     --  JOIN condition_10 (None,None) at None, None
                     goto condition_10;
                  end if;
                  --  JOIN condition_9 (None,None) at None, None
                  goto condition_9;
               end if;
               --  JOIN condition_8 (None,None) at None, None
               goto condition_8;
            end if;
            --  JOIN condition_7 (None,None) at None, None
            goto condition_7;
         end if;
         --  JOIN condition_6 (None,None) at None, None
         goto condition_6;
      end p_0_InitializePin;
      

   procedure p_0_SetPin(Pio: in asn1SccPioHwas) is
      begin
         --  Destinationaddressvar := Pio.Mportsodraddress (351,17)
         ctxt.Destinationaddressvar := Pio.mportsodraddress;
         --  Pinmaskvar := Pio.Mpin (353,17)
         ctxt.Pinmaskvar := Pio.mpin;
         --  Pinvaluevar := Pio.Mpin (355,17)
         ctxt.Pinvaluevar := Pio.mpin;
         --  RawMemoryAccess_WriteWord_Ri(Destinationaddressvar, Pinmaskvar, Pinvaluevar) (357,17)
         RI_0_RawMemoryAccess_WriteWord_Ri(ctxt.Destinationaddressvar, ctxt.Pinmaskvar, ctxt.Pinvaluevar);
         --  RETURN  (None,None) at None, None
         return;
      end p_0_SetPin;
      

   procedure p_0_ResetPin(Pio: in asn1SccPioHwas) is
      begin
         --  Destinationaddressvar := Pio.Mportcodraddress (369,17)
         ctxt.Destinationaddressvar := Pio.mportcodraddress;
         --  Pinmaskvar := Pio.Mpin (371,17)
         ctxt.Pinmaskvar := Pio.mpin;
         --  Pinvaluevar := Pio.Mpin (373,17)
         ctxt.Pinvaluevar := Pio.mpin;
         --  RawMemoryAccess_WriteWord_Ri(Destinationaddressvar, Pinmaskvar, Pinvaluevar) (375,17)
         RI_0_RawMemoryAccess_WriteWord_Ri(ctxt.Destinationaddressvar, ctxt.Pinmaskvar, ctxt.Pinvaluevar);
         --  RETURN  (None,None) at None, None
         return;
      end p_0_ResetPin;
      

   procedure p_0_GetPinValue(Pio: in asn1SccPioHwas) is
      begin
         --  Sourceaddressvar := Pio.Mportodsraddress (387,17)
         ctxt.Sourceaddressvar := Pio.mportodsraddress;
         --  Pinmaskvar := Pio.Mpin (389,17)
         ctxt.Pinmaskvar := Pio.mpin;
         --  RawMemoryAccess_ReadWord_Ri(Sourceaddressvar, Pinmaskvar, Pinvaluevar) (391,17)
         RI_0_RawMemoryAccess_ReadWord_Ri(ctxt.Sourceaddressvar, ctxt.Pinmaskvar, ctxt.Pinvaluevar);
         --  RETURN  (None,None) at None, None
         return;
      end p_0_GetPinValue;
      

   procedure PioHwas_GetPin_Pi(Pio: in out asn1SccPioHwas;Pinvalue: in out asn1SccWord) is
      begin
         --  Piovar := Pio (404,17)
         ctxt.Piovar := Pio;
         --  GetPinValue(Piovar) (406,17)
         p_0_GetPinValue(ctxt.Piovar);
         --  Pinvalue := Pinvaluevar (408,17)
         Pinvalue := ctxt.Pinvaluevar;
         --  PioHwas_GetPin_Pi_Transition (None,None)
         PioHwas_GetPin_Pi_Transition;
         --  RETURN  (None,None) at None, None
         return;
      end PioHwas_GetPin_Pi;
      

   procedure PioHwas_InitPin_Pi(Pio: in out asn1SccPioHwas;Config: in out asn1SccPioHwasPinConfig) is
      begin
         --  Configvar := Config (421,17)
         ctxt.Configvar := Config;
         --  InitializePin(Configvar) (423,17)
         p_0_InitializePin(ctxt.Configvar);
         --  Pio := Piovar (425,17)
         Pio := ctxt.Piovar;
         --  PioHwas_InitPin_Pi_Transition (None,None)
         PioHwas_InitPin_Pi_Transition;
         --  RETURN  (None,None) at None, None
         return;
      end PioHwas_InitPin_Pi;
      

   procedure PioHwas_ResetPin_Pi(Pio: in out asn1SccPioHwas) is
      begin
         --  Piovar := Pio (437,17)
         ctxt.Piovar := Pio;
         --  ResetPin(Piovar) (439,17)
         p_0_ResetPin(ctxt.Piovar);
         --  PioHwas_ResetPin_Pi_Transition (None,None)
         PioHwas_ResetPin_Pi_Transition;
         --  RETURN  (None,None) at None, None
         return;
      end PioHwas_ResetPin_Pi;
      

   procedure PioHwas_SetPin_Pi(Pio: in out asn1SccPioHwas) is
      begin
         --  Piovar := Pio (451,17)
         ctxt.Piovar := Pio;
         --  SetPin(Piovar) (453,17)
         p_0_SetPin(ctxt.Piovar);
         --  PioHwas_SetPin_Pi_Transition (None,None)
         PioHwas_SetPin_Pi_Transition;
         --  RETURN  (None,None) at None, None
         return;
      end PioHwas_SetPin_Pi;
      

   procedure PioHwas_GetPin_Pi_Transition is
      begin
         case ctxt.state is
            when asn1Sccidle =>
               Execute_Transition (3);
            when others =>
               Execute_Transition (CS_Only);
         end case;
      end PioHwas_GetPin_Pi_Transition;
      

   procedure PioHwas_InitPin_Pi_Transition is
      begin
         case ctxt.state is
            when asn1Sccoff =>
               Execute_Transition (4);
            when others =>
               Execute_Transition (CS_Only);
         end case;
      end PioHwas_InitPin_Pi_Transition;
      

   procedure PioHwas_ResetPin_Pi_Transition is
      begin
         case ctxt.state is
            when asn1Sccidle =>
               Execute_Transition (2);
            when others =>
               Execute_Transition (CS_Only);
         end case;
      end PioHwas_ResetPin_Pi_Transition;
      

   procedure PioHwas_SetPin_Pi_Transition is
      begin
         case ctxt.state is
            when asn1Sccidle =>
               Execute_Transition (1);
            when others =>
               Execute_Transition (CS_Only);
         end case;
      end PioHwas_SetPin_Pi_Transition;
      

   procedure Execute_Transition (Id : Integer) is
      trId : Integer := Id;
      begin
         while (trId /= -1) loop
            case trId is
               when 0 =>
                  --  NEXT_STATE Off (459,18) at 0, 1837
                  trId := -1;
                  ctxt.State := asn1SccOff;
                  goto Continuous_Signals;
               when 1 =>
                  --  NEXT_STATE Idle (465,22) at 0, 1987
                  trId := -1;
                  ctxt.State := asn1SccIdle;
                  goto Continuous_Signals;
               when 2 =>
                  --  NEXT_STATE Idle (469,22) at 300, 1987
                  trId := -1;
                  ctxt.State := asn1SccIdle;
                  goto Continuous_Signals;
               when 3 =>
                  --  NEXT_STATE Idle (473,22) at 600, 1987
                  trId := -1;
                  ctxt.State := asn1SccIdle;
                  goto Continuous_Signals;
               when 4 =>
                  --  NEXT_STATE Idle (480,22) at 1200, 1987
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
end PioHwasDriver;