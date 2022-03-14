-- This file was generated automatically by OpenGEODE: DO NOT MODIFY IT !

with System.IO;
use System.IO;

with Ada.Unchecked_Conversion;
with Ada.Numerics.Generic_Elementary_Functions;

package body PioHwasDriver is
   procedure p_0_InitPmc(Pmc: in asn1SccPmcHwas);
   procedure p_0_InitPioContainer(Pio: in asn1SccPioHwas);
   procedure p_0_InitSync(Pio: in asn1SccPioHwas;Config: in asn1SccPioHwasPinConfig;Pmc: in asn1SccPmcHwas);
   procedure p_0_SetPin(Pio: in asn1SccPioHwas);
   procedure p_0_ResetPin(Pio: in asn1SccPioHwas);
   procedure p_0_InitPmc(Pmc: in asn1SccPmcHwas) is
      begin
         --  Pmc.Pmc_pcsr0_offset := 1074660880 (17,17)
         Pmc.pmc_pcsr0_offset := 1074660880;
         --  Pmc.Pmc_pcxr0_pid10_pioa_mask := 1024 (19,17)
         Pmc.pmc_pcxr0_pid10_pioa_mask := 1024;
         --  Pmc.Pmc_pcxr0_pid11_piob_mask := 2048 (21,17)
         Pmc.pmc_pcxr0_pid11_piob_mask := 2048;
         --  Pmc.Pmc_pcxr0_pid12_pioc_mask := 4096 (23,17)
         Pmc.pmc_pcxr0_pid12_pioc_mask := 4096;
         --  Pmc.Pmc_pcxr0_pid16_piod_mask := 65536 (25,17)
         Pmc.pmc_pcxr0_pid16_piod_mask := 65536;
         --  Pmc.Pmc_pcxr0_pid17_pioe_mask := 131072 (27,17)
         Pmc.pmc_pcxr0_pid17_pioe_mask := 131072;
         --  RETURN  (None,None) at None, None
         return;
      end p_0_InitPmc;
      

   procedure p_0_InitPioContainer(Pio: in asn1SccPioHwas) is
      begin
         --  Pio.Mportperaddress := 0 (39,17)
         Pio.mportperaddress := 0;
         --  Pio.Mportperaddress := Pio.Mportaddress + 0 (41,17)
         Pio.mportperaddress := (Pio.mportaddress + 0);
         --  Pio.Mportoeraddress := 16 (43,17)
         Pio.mportoeraddress := 16;
         --  Pio.Mportoeraddress := Pio.Mportaddress + Pio.Mportoeraddress (45,17)
         Pio.mportoeraddress := (Pio.mportaddress + Pio.mportoeraddress);
         --  Pio.Mportodraddress := 20 (47,17)
         Pio.mportodraddress := 20;
         --  Pio.Mportodraddress := Pio.Mportaddress + Pio.Mportodraddress (49,17)
         Pio.mportodraddress := (Pio.mportaddress + Pio.mportodraddress);
         --  Pio.Mportifdraddress := 36 (51,17)
         Pio.mportifdraddress := 36;
         --  Pio.Mportifdraddress := Pio.Mportaddress + Pio.Mportifdraddress (53,17)
         Pio.mportifdraddress := (Pio.mportaddress + Pio.mportifdraddress);
         --  Pio.Mportsodraddress := 48 (55,17)
         Pio.mportsodraddress := 48;
         --  Pio.Mportsodraddress := Pio.Mportaddress + Pio.Mportsodraddress (57,17)
         Pio.mportsodraddress := (Pio.mportaddress + Pio.mportsodraddress);
         --  Pio.Mportcodraddress := 52 (59,17)
         Pio.mportcodraddress := 52;
         --  Pio.Mportcodraddress := Pio.Mportaddress + Pio.Mportcodraddress (61,17)
         Pio.mportcodraddress := (Pio.mportaddress + Pio.mportcodraddress);
         --  Pio.Mportmddraddress := 84 (63,17)
         Pio.mportmddraddress := 84;
         --  Pio.Mportmddraddress := Pio.Mportaddress + Pio.Mportmddraddress (65,17)
         Pio.mportmddraddress := (Pio.mportaddress + Pio.mportmddraddress);
         --  Pio.Mportpudraddress := 96 (67,17)
         Pio.mportpudraddress := 96;
         --  Pio.Mportpudraddress := Pio.Mportaddress + Pio.Mportpudraddress (69,17)
         Pio.mportpudraddress := (Pio.mportaddress + Pio.mportpudraddress);
         --  Pio.Mportifscdraddress := 128 (71,17)
         Pio.mportifscdraddress := 128;
         --  Pio.Mportifscdraddress := Pio.Mportaddress + Pio.Mportifscdraddress (73,17)
         Pio.mportifscdraddress := (Pio.mportaddress + Pio.mportifscdraddress);
         --  Pio.Mportppddraddress := 144 (75,17)
         Pio.mportppddraddress := 144;
         --  Pio.Mportppddraddress := Pio.Mportaddress + Pio.Mportppddraddress (77,17)
         Pio.mportppddraddress := (Pio.mportaddress + Pio.mportppddraddress);
         --  Pio.Mportoweraddress := 160 (79,17)
         Pio.mportoweraddress := 160;
         --  Pio.Mportoweraddress := Pio.Mportaddress + Pio.Mportoweraddress (81,17)
         Pio.mportoweraddress := (Pio.mportaddress + Pio.mportoweraddress);
         --  Pio.Mportowdraddress := 164 (83,17)
         Pio.mportowdraddress := 164;
         --  Pio.Mportowdraddress := Pio.Mportaddress + Pio.Mportowdraddress (85,17)
         Pio.mportowdraddress := (Pio.mportaddress + Pio.mportowdraddress);
         --  Pio.Mportschmittaddress := 256 (87,17)
         Pio.mportschmittaddress := 256;
         --  Pio.Mportschmittaddress := Pio.Mportaddress + Pio.Mportschmittaddress (89,17)
         Pio.mportschmittaddress := (Pio.mportaddress + Pio.mportschmittaddress);
         --  RETURN  (None,None) at None, None
         return;
      end p_0_InitPioContainer;
      

   procedure p_0_InitSync(Pio: in asn1SccPioHwas;Config: in asn1SccPioHwasPinConfig;Pmc: in asn1SccPmcHwas) is
      tmp379 : asn1SccWord;
      tmp249 : asn1SccDestinationAddress;
      tmp361 : asn1SccWord;
      tmp283 : asn1SccWord;
      tmp291 : asn1SccDestinationAddress;
      tmp306 : asn1SccDestinationAddress;
      tmp331 : asn1SccDestinationAddress;
      tmp360 : asn1SccWordMask;
      tmp292 : asn1SccWordMask;
      tmp387 : asn1SccWordMask;
      tmp233 : asn1SccDestinationAddress;
      tmp267 : asn1SccWord;
      tmp370 : asn1SccWord;
      tmp378 : asn1SccWordMask;
      tmp316 : asn1SccWordMask;
      tmp251 : asn1SccWord;
      tmp369 : asn1SccWordMask;
      tmp293 : asn1SccWord;
      tmp234 : asn1SccWordMask;
      tmp377 : asn1SccDestinationAddress;
      tmp342 : asn1SccWord;
      tmp217 : asn1SccDestinationAddress;
      tmp281 : asn1SccDestinationAddress;
      tmp307 : asn1SccWordMask;
      tmp315 : asn1SccDestinationAddress;
      tmp332 : asn1SccWordMask;
      tmp265 : asn1SccDestinationAddress;
      tmp218 : asn1SccWordMask;
      tmp282 : asn1SccWordMask;
      tmp397 : asn1SccWord;
      tmp340 : asn1SccDestinationAddress;
      tmp250 : asn1SccWordMask;
      tmp317 : asn1SccWord;
      tmp368 : asn1SccDestinationAddress;
      tmp359 : asn1SccDestinationAddress;
      tmp308 : asn1SccWord;
      tmp350 : asn1SccDestinationAddress;
      tmp388 : asn1SccWord;
      tmp395 : asn1SccDestinationAddress;
      --  !! stack: _call_external_function line 1656
      tmp341 : asn1SccWordMask;
      tmp235 : asn1SccWord;
      tmp351 : asn1SccWordMask;
      tmp333 : asn1SccWord;
      tmp352 : asn1SccWord;
      tmp219 : asn1SccWord;
      tmp266 : asn1SccWordMask;
      tmp396 : asn1SccWordMask;
      tmp386 : asn1SccDestinationAddress;
      begin
         --  InitPmc(Pmcvar) (103,17)
         p_0_InitPmc(ctxt.Pmcvar);
         --  DECISION Config.Mportconfig = PioHwas_Port_A (105,40)
         --  ANSWER True (107,17)
         if ((Config.mportconfig = asn1SccpioHwas_Port_A)) then
            --  Pio.Mportaddress := 1074662912 (109,25)
            Pio.mportaddress := 1074662912;
            --  JOIN condition_1 (111,25) at 0, 1162
            goto condition_1;
            --  ANSWER False (113,17)
         else
            --  DECISION Config.Mportconfig = PioHwas_Port_B (115,48)
            --  ANSWER True (117,25)
            if ((Config.mportconfig = asn1SccpioHwas_Port_B)) then
               --  Pio.Mportaddress := 1074663424 (119,33)
               Pio.mportaddress := 1074663424;
               --  JOIN condition_2 (121,33) at 600, 1237
               goto condition_2;
               --  ANSWER False (123,25)
            else
               --  DECISION Config.Mportconfig = PioHwas_Port_C (125,56)
               --  ANSWER True (127,33)
               if ((Config.mportconfig = asn1SccpioHwas_Port_C)) then
                  --  Pio.Mportaddress := 1074663936 (129,41)
                  Pio.mportaddress := 1074663936;
                  --  JOIN condition_3 (131,41) at 1200, 1312
                  goto condition_3;
                  --  ANSWER False (133,33)
               else
                  --  DECISION Config.Mportconfig = PioHwas_Port_D (135,64)
                  --  ANSWER True (137,41)
                  if ((Config.mportconfig = asn1SccpioHwas_Port_D)) then
                     --  Pio.Mportaddress := 1074664448 (139,49)
                     Pio.mportaddress := 1074664448;
                     --  JOIN condition_4 (141,49) at 1800, 1387
                     goto condition_4;
                     --  ANSWER False (143,41)
                  else
                     --  DECISION Config.Mportconfig = PioHwas_Port_E (145,72)
                     --  ANSWER True (147,49)
                     if ((Config.mportconfig = asn1SccpioHwas_Port_E)) then
                        --  Pio.Mportaddress := 1074664960 (149,57)
                        Pio.mportaddress := 1074664960;
                        --  JOIN condition_5 (151,57) at 2400, 1462
                        goto condition_5;
                        --  ANSWER False (153,49)
                     else
                        --  JOIN condition_5 (155,57) at 3000, 1387
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
         --  CONNECTION condition_5 (158,44)
         <<condition_5>>
         --  JOIN condition_4 (160,49) at 3600, 1462
         goto condition_4;
         --  CONNECTION condition_4 (163,36)
         <<condition_4>>
         --  JOIN condition_3 (165,41) at 4200, 1387
         goto condition_3;
         --  CONNECTION condition_3 (168,28)
         <<condition_3>>
         --  JOIN condition_2 (170,33) at 4800, 1312
         goto condition_2;
         --  CONNECTION condition_2 (173,20)
         <<condition_2>>
         --  JOIN condition_1 (175,25) at 5400, 1237
         goto condition_1;
         --  CONNECTION condition_10 (237,44)
         <<condition_10>>
         --  JOIN condition_9 (239,49) at 9600, 1762
         goto condition_9;
         --  CONNECTION condition_9 (242,36)
         <<condition_9>>
         --  JOIN condition_8 (244,41) at 10200, 1687
         goto condition_8;
         --  CONNECTION condition_8 (247,28)
         <<condition_8>>
         --  JOIN condition_7 (249,33) at 10800, 1612
         goto condition_7;
         --  CONNECTION condition_7 (252,20)
         <<condition_7>>
         --  JOIN condition_6 (254,25) at 11400, 1537
         goto condition_6;
         --  CONNECTION condition_12 (288,20)
         <<condition_12>>
         --  JOIN condition_11 (290,25) at 13800, 1762
         goto condition_11;
         --  CONNECTION condition_11 (293,12)
         <<condition_11>>
         --  RawMemoryAccess_WriteWord_Ri(pio.mPortPudrAddress, pio.mPin, pio.mPin) (295,17)
         tmp350 := asn1SccDestinationAddress (pio.mportpudraddress);
         tmp351 := asn1SccWordMask (pio.mpin);
         tmp352 := asn1SccWord (pio.mpin);
         RI_0_RawMemoryAccess_WriteWord_Ri(tmp350, tmp351, tmp352);
         --  RawMemoryAccess_WriteWord_Ri(pio.mPortPpddrAddress, pio.mPin, pio.mPin) (297,17)
         tmp359 := asn1SccDestinationAddress (pio.mportppddraddress);
         tmp360 := asn1SccWordMask (pio.mpin);
         tmp361 := asn1SccWord (pio.mpin);
         RI_0_RawMemoryAccess_WriteWord_Ri(tmp359, tmp360, tmp361);
         --  RawMemoryAccess_WriteWord_Ri(pio.mPortIfdrAddress, pio.mPin, pio.mPin) (299,17)
         tmp368 := asn1SccDestinationAddress (pio.mportifdraddress);
         tmp369 := asn1SccWordMask (pio.mpin);
         tmp370 := asn1SccWord (pio.mpin);
         RI_0_RawMemoryAccess_WriteWord_Ri(tmp368, tmp369, tmp370);
         --  RawMemoryAccess_WriteWord_Ri(pio.mPortIfscdrAddress, pio.mPin, pio.mPin) (301,17)
         tmp377 := asn1SccDestinationAddress (pio.mportifscdraddress);
         tmp378 := asn1SccWordMask (pio.mpin);
         tmp379 := asn1SccWord (pio.mpin);
         RI_0_RawMemoryAccess_WriteWord_Ri(tmp377, tmp378, tmp379);
         --  RawMemoryAccess_WriteWord_Ri(pio.mPortSchmittAddress, pio.mPin, pio.mPin) (303,17)
         tmp386 := asn1SccDestinationAddress (pio.mportschmittaddress);
         tmp387 := asn1SccWordMask (pio.mpin);
         tmp388 := asn1SccWord (pio.mpin);
         RI_0_RawMemoryAccess_WriteWord_Ri(tmp386, tmp387, tmp388);
         --  RawMemoryAccess_WriteWord_Ri(pio.mPortMddrAddress, pio.mPin, pio.mPin) (305,17)
         tmp395 := asn1SccDestinationAddress (pio.mportmddraddress);
         tmp396 := asn1SccWordMask (pio.mpin);
         tmp397 := asn1SccWord (pio.mpin);
         RI_0_RawMemoryAccess_WriteWord_Ri(tmp395, tmp396, tmp397);
         --  RETURN  (None,None) at None, None
         return;
         --  CONNECTION condition_6 (257,12)
         <<condition_6>>
         --  RawMemoryAccess_WriteWord_Ri(pio.mPortPerAddress, pio.mPin, pio.mPin) (259,17)
         tmp291 := asn1SccDestinationAddress (pio.mportperaddress);
         tmp292 := asn1SccWordMask (pio.mpin);
         tmp293 := asn1SccWord (pio.mpin);
         RI_0_RawMemoryAccess_WriteWord_Ri(tmp291, tmp292, tmp293);
         --  DECISION Config.Mdirectionconfig = PioHwas_Direction_Input (261,45)
         --  ANSWER True (263,17)
         if ((Config.mdirectionconfig = asn1SccpioHwas_Direction_Input)) then
            --  RawMemoryAccess_WriteWord_Ri(pio.mPortOdrAddress, pio.mPin, pio.mPin) (265,25)
            tmp306 := asn1SccDestinationAddress (pio.mportodraddress);
            tmp307 := asn1SccWordMask (pio.mpin);
            tmp308 := asn1SccWord (pio.mpin);
            RI_0_RawMemoryAccess_WriteWord_Ri(tmp306, tmp307, tmp308);
            --  RawMemoryAccess_WriteWord_Ri(pio.mPortOwdrAddress, pio.mPin, pio.mPin) (267,25)
            tmp315 := asn1SccDestinationAddress (pio.mportowdraddress);
            tmp316 := asn1SccWordMask (pio.mpin);
            tmp317 := asn1SccWord (pio.mpin);
            RI_0_RawMemoryAccess_WriteWord_Ri(tmp315, tmp316, tmp317);
            --  JOIN condition_11 (269,25) at 12000, 1762
            goto condition_11;
            --  ANSWER False (271,17)
         else
            --  DECISION Config.Mdirectionconfig = PioHwas_Direction_Output (273,53)
            --  ANSWER True (275,25)
            if ((Config.mdirectionconfig = asn1SccpioHwas_Direction_Output)) then
               --  RawMemoryAccess_WriteWord_Ri(pio.mPortOerAddress, pio.mPin, pio.mPin) (277,33)
               tmp331 := asn1SccDestinationAddress (pio.mportoeraddress);
               tmp332 := asn1SccWordMask (pio.mpin);
               tmp333 := asn1SccWord (pio.mpin);
               RI_0_RawMemoryAccess_WriteWord_Ri(tmp331, tmp332, tmp333);
               --  RawMemoryAccess_WriteWord_Ri(pio.mPortOwdrAddress, pio.mPin, pio.mPin) (279,33)
               tmp340 := asn1SccDestinationAddress (pio.mportowdraddress);
               tmp341 := asn1SccWordMask (pio.mpin);
               tmp342 := asn1SccWord (pio.mpin);
               RI_0_RawMemoryAccess_WriteWord_Ri(tmp340, tmp341, tmp342);
               --  JOIN condition_12 (281,33) at 12600, 1837
               goto condition_12;
               --  ANSWER False (283,25)
            else
               --  JOIN condition_12 (285,33) at 13200, 1687
               goto condition_12;
            end if;
            --  JOIN condition_12 (None,None) at None, None
            goto condition_12;
         end if;
         --  JOIN condition_11 (None,None) at None, None
         goto condition_11;
         --  CONNECTION condition_1 (178,12)
         <<condition_1>>
         --  InitPioContainer(Piovar) (180,17)
         p_0_InitPioContainer(ctxt.Piovar);
         --  Pio.Mpin := config.mPinConfig (182,17)
         Pio.mpin := config.mpinconfig;
         --  DECISION Config.Mportconfig = PioHwas_Port_A (184,40)
         --  ANSWER True (186,17)
         if ((Config.mportconfig = asn1SccpioHwas_Port_A)) then
            --  RawMemoryAccess_WriteWord_Ri(pmc.PMC_PCSR0_OFFSET, pmc.PMC_PCxR0_PID10_PIOA_Mask, pmc.PMC_PCxR0_PID10_PIOA_Mask) (188,25)
            tmp217 := asn1SccDestinationAddress (pmc.pmc_pcsr0_offset);
            tmp218 := asn1SccWordMask (pmc.pmc_pcxr0_pid10_pioa_mask);
            tmp219 := asn1SccWord (pmc.pmc_pcxr0_pid10_pioa_mask);
            RI_0_RawMemoryAccess_WriteWord_Ri(tmp217, tmp218, tmp219);
            --  JOIN condition_6 (190,25) at 6000, 1462
            goto condition_6;
            --  ANSWER False (192,17)
         else
            --  DECISION Config.Mportconfig = PioHwas_Port_B (194,48)
            --  ANSWER True (196,25)
            if ((Config.mportconfig = asn1SccpioHwas_Port_B)) then
               --  RawMemoryAccess_WriteWord_Ri(pmc.PMC_PCSR0_OFFSET, pmc.PMC_PCxR0_PID11_PIOB_Mask, pmc.PMC_PCxR0_PID11_PIOB_Mask) (198,33)
               tmp233 := asn1SccDestinationAddress (pmc.pmc_pcsr0_offset);
               tmp234 := asn1SccWordMask (pmc.pmc_pcxr0_pid11_piob_mask);
               tmp235 := asn1SccWord (pmc.pmc_pcxr0_pid11_piob_mask);
               RI_0_RawMemoryAccess_WriteWord_Ri(tmp233, tmp234, tmp235);
               --  JOIN condition_7 (200,33) at 6600, 1537
               goto condition_7;
               --  ANSWER False (202,25)
            else
               --  DECISION Config.Mportconfig = PioHwas_Port_C (204,56)
               --  ANSWER True (206,33)
               if ((Config.mportconfig = asn1SccpioHwas_Port_C)) then
                  --  RawMemoryAccess_WriteWord_Ri(pmc.PMC_PCSR0_OFFSET, pmc.PMC_PCxR0_PID12_PIOC_Mask, pmc.PMC_PCxR0_PID12_PIOC_Mask) (208,41)
                  tmp249 := asn1SccDestinationAddress (pmc.pmc_pcsr0_offset);
                  tmp250 := asn1SccWordMask (pmc.pmc_pcxr0_pid12_pioc_mask);
                  tmp251 := asn1SccWord (pmc.pmc_pcxr0_pid12_pioc_mask);
                  RI_0_RawMemoryAccess_WriteWord_Ri(tmp249, tmp250, tmp251);
                  --  JOIN condition_8 (210,41) at 7200, 1612
                  goto condition_8;
                  --  ANSWER False (212,33)
               else
                  --  DECISION Config.Mportconfig = PioHwas_Port_D (214,64)
                  --  ANSWER True (216,41)
                  if ((Config.mportconfig = asn1SccpioHwas_Port_D)) then
                     --  RawMemoryAccess_WriteWord_Ri(pmc.PMC_PCSR0_OFFSET, pmc.PMC_PCxR0_PID16_PIOD_Mask, pmc.PMC_PCxR0_PID16_PIOD_Mask) (218,49)
                     tmp265 := asn1SccDestinationAddress (pmc.pmc_pcsr0_offset);
                     tmp266 := asn1SccWordMask (pmc.pmc_pcxr0_pid16_piod_mask);
                     tmp267 := asn1SccWord (pmc.pmc_pcxr0_pid16_piod_mask);
                     RI_0_RawMemoryAccess_WriteWord_Ri(tmp265, tmp266, tmp267);
                     --  JOIN condition_9 (220,49) at 7800, 1687
                     goto condition_9;
                     --  ANSWER False (222,41)
                  else
                     --  DECISION Config.Mportconfig = PioHwas_Port_E (224,72)
                     --  ANSWER True (226,49)
                     if ((Config.mportconfig = asn1SccpioHwas_Port_E)) then
                        --  RawMemoryAccess_WriteWord_Ri(pmc.PMC_PCSR0_OFFSET, pmc.PMC_PCxR0_PID17_PIOE_Mask, pmc.PMC_PCxR0_PID17_PIOE_Mask) (228,57)
                        tmp281 := asn1SccDestinationAddress (pmc.pmc_pcsr0_offset);
                        tmp282 := asn1SccWordMask (pmc.pmc_pcxr0_pid17_pioe_mask);
                        tmp283 := asn1SccWord (pmc.pmc_pcxr0_pid17_pioe_mask);
                        RI_0_RawMemoryAccess_WriteWord_Ri(tmp281, tmp282, tmp283);
                        --  JOIN condition_10 (230,57) at 8400, 1762
                        goto condition_10;
                        --  ANSWER False (232,49)
                     else
                        --  JOIN condition_10 (234,57) at 9000, 1687
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
      end p_0_InitSync;
      

   procedure p_0_SetPin(Pio: in asn1SccPioHwas) is
      --  !! stack: _call_external_function line 1656
      tmp404 : asn1SccDestinationAddress;
      tmp406 : asn1SccWord;
      tmp405 : asn1SccWordMask;
      begin
         --  RawMemoryAccess_WriteWord_Ri(pio.mPortSodrAddress, pio.mPin, pio.mPin) (317,17)
         tmp404 := asn1SccDestinationAddress (pio.mportsodraddress);
         tmp405 := asn1SccWordMask (pio.mpin);
         tmp406 := asn1SccWord (pio.mpin);
         RI_0_RawMemoryAccess_WriteWord_Ri(tmp404, tmp405, tmp406);
         --  RETURN  (None,None) at None, None
         return;
      end p_0_SetPin;
      

   procedure p_0_ResetPin(Pio: in asn1SccPioHwas) is
      --  !! stack: _call_external_function line 1656
      tmp413 : asn1SccDestinationAddress;
      tmp414 : asn1SccWordMask;
      tmp415 : asn1SccWord;
      begin
         --  RawMemoryAccess_WriteWord_Ri(pio.mPortCodrAddress, pio.mPin, pio.mPin) (329,17)
         tmp413 := asn1SccDestinationAddress (pio.mportcodraddress);
         tmp414 := asn1SccWordMask (pio.mpin);
         tmp415 := asn1SccWord (pio.mpin);
         RI_0_RawMemoryAccess_WriteWord_Ri(tmp413, tmp414, tmp415);
         --  RETURN  (None,None) at None, None
         return;
      end p_0_ResetPin;
      

   procedure PioHwas_InitPin_Pi(Pio: in out asn1SccPioHwas;Config: in out asn1SccPioHwasPinConfig) is
      begin
         --  Piovar := Pio (342,17)
         ctxt.Piovar := Pio;
         --  Configvar := Config (344,17)
         ctxt.Configvar := Config;
         --  InitSync(Piovar, Configvar, Pmcvar) (346,17)
         p_0_InitSync(ctxt.Piovar, ctxt.Configvar, ctxt.Pmcvar);
         --  PioHwas_InitPin_Pi_Transition (None,None)
         PioHwas_InitPin_Pi_Transition;
         --  RETURN  (None,None) at None, None
         return;
      end PioHwas_InitPin_Pi;
      

   procedure PioHwas_ResetPin_Pi(Pio: in out asn1SccPioHwas) is
      begin
         --  Piovar := Pio (358,17)
         ctxt.Piovar := Pio;
         --  ResetPin(Piovar) (360,17)
         p_0_ResetPin(ctxt.Piovar);
         --  PioHwas_ResetPin_Pi_Transition (None,None)
         PioHwas_ResetPin_Pi_Transition;
         --  RETURN  (None,None) at None, None
         return;
      end PioHwas_ResetPin_Pi;
      

   procedure PioHwas_SetPin_Pi(Pio: in out asn1SccPioHwas) is
      begin
         --  Piovar := Pio (372,17)
         ctxt.Piovar := Pio;
         --  SetPin(Piovar) (374,17)
         p_0_SetPin(ctxt.Piovar);
         --  PioHwas_SetPin_Pi_Transition (None,None)
         PioHwas_SetPin_Pi_Transition;
         --  RETURN  (None,None) at None, None
         return;
      end PioHwas_SetPin_Pi;
      

   procedure PioHwas_InitPin_Pi_Transition is
      begin
         case ctxt.state is
            when asn1Sccoff =>
               Execute_Transition (3);
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
                  --  NEXT_STATE Off (380,18) at 0, 1687
                  trId := -1;
                  ctxt.State := asn1SccOff;
                  goto Continuous_Signals;
               when 1 =>
                  --  NEXT_STATE Idle (386,22) at 0, 1837
                  trId := -1;
                  ctxt.State := asn1SccIdle;
                  goto Continuous_Signals;
               when 2 =>
                  --  NEXT_STATE Idle (390,22) at 300, 1837
                  trId := -1;
                  ctxt.State := asn1SccIdle;
                  goto Continuous_Signals;
               when 3 =>
                  --  NEXT_STATE Idle (397,22) at 900, 1837
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