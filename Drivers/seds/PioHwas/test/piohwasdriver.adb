-- This file was generated automatically by OpenGEODE: DO NOT MODIFY IT !

with System.IO;
use System.IO;

with Ada.Unchecked_Conversion;
with Ada.Numerics.Generic_Elementary_Functions;

package body PioHwasDriver is
   procedure p_0_InitPmc;
   procedure p_0_InitPioContainer;
   procedure p_0_InitSync(Config: in asn1SccPioHwasPinConfig);
   procedure p_0_SetPin(Pio: in asn1SccPioHwas);
   procedure p_0_ResetPin(Pio: in asn1SccPioHwas);
   procedure p_0_InitPmc is
      begin
         --  Pmcvar.Pmc_pcsr0_offset := 1074660880 (13,17)
         ctxt.Pmcvar.pmc_pcsr0_offset := 1074660880;
         --  Pmcvar.Pmc_pcxr0_pid10_pioa_mask := 1024 (15,17)
         ctxt.Pmcvar.pmc_pcxr0_pid10_pioa_mask := 1024;
         --  Pmcvar.Pmc_pcxr0_pid11_piob_mask := 2048 (17,17)
         ctxt.Pmcvar.pmc_pcxr0_pid11_piob_mask := 2048;
         --  Pmcvar.Pmc_pcxr0_pid12_pioc_mask := 4096 (19,17)
         ctxt.Pmcvar.pmc_pcxr0_pid12_pioc_mask := 4096;
         --  Pmcvar.Pmc_pcxr0_pid16_piod_mask := 65536 (21,17)
         ctxt.Pmcvar.pmc_pcxr0_pid16_piod_mask := 65536;
         --  Pmcvar.Pmc_pcxr0_pid17_pioe_mask := 131072 (23,17)
         ctxt.Pmcvar.pmc_pcxr0_pid17_pioe_mask := 131072;
         --  RETURN  (None,None) at None, None
         return;
      end p_0_InitPmc;
      

   procedure p_0_InitPioContainer is
      begin
         --  Piovar.Mportperaddress := 0 (31,17)
         ctxt.Piovar.mportperaddress := 0;
         --  Piovar.Mportperaddress := Piovar.Mportaddress + 0 (33,17)
         ctxt.Piovar.mportperaddress := (ctxt.Piovar.mportaddress + 0);
         --  Piovar.Mportoeraddress := 16 (35,17)
         ctxt.Piovar.mportoeraddress := 16;
         --  Piovar.Mportoeraddress := Piovar.Mportaddress + Piovar.Mportoeraddress (37,17)
         ctxt.Piovar.mportoeraddress := (ctxt.Piovar.mportaddress + ctxt.Piovar.mportoeraddress);
         --  Piovar.Mportodraddress := 20 (39,17)
         ctxt.Piovar.mportodraddress := 20;
         --  Piovar.Mportodraddress := Piovar.Mportaddress + Piovar.Mportodraddress (41,17)
         ctxt.Piovar.mportodraddress := (ctxt.Piovar.mportaddress + ctxt.Piovar.mportodraddress);
         --  Piovar.Mportifdraddress := 36 (43,17)
         ctxt.Piovar.mportifdraddress := 36;
         --  Piovar.Mportifdraddress := Piovar.Mportaddress + Piovar.Mportifdraddress (45,17)
         ctxt.Piovar.mportifdraddress := (ctxt.Piovar.mportaddress + ctxt.Piovar.mportifdraddress);
         --  Piovar.Mportsodraddress := 48 (47,17)
         ctxt.Piovar.mportsodraddress := 48;
         --  Piovar.Mportsodraddress := Piovar.Mportaddress + Piovar.Mportsodraddress (49,17)
         ctxt.Piovar.mportsodraddress := (ctxt.Piovar.mportaddress + ctxt.Piovar.mportsodraddress);
         --  Piovar.Mportcodraddress := 52 (51,17)
         ctxt.Piovar.mportcodraddress := 52;
         --  Piovar.Mportcodraddress := Piovar.Mportaddress + Piovar.Mportcodraddress (53,17)
         ctxt.Piovar.mportcodraddress := (ctxt.Piovar.mportaddress + ctxt.Piovar.mportcodraddress);
         --  Piovar.Mportmddraddress := 84 (55,17)
         ctxt.Piovar.mportmddraddress := 84;
         --  Piovar.Mportmddraddress := Piovar.Mportaddress + Piovar.Mportmddraddress (57,17)
         ctxt.Piovar.mportmddraddress := (ctxt.Piovar.mportaddress + ctxt.Piovar.mportmddraddress);
         --  Piovar.Mportpudraddress := 96 (59,17)
         ctxt.Piovar.mportpudraddress := 96;
         --  Piovar.Mportpudraddress := Piovar.Mportaddress + Piovar.Mportpudraddress (61,17)
         ctxt.Piovar.mportpudraddress := (ctxt.Piovar.mportaddress + ctxt.Piovar.mportpudraddress);
         --  Piovar.Mportifscdraddress := 128 (63,17)
         ctxt.Piovar.mportifscdraddress := 128;
         --  Piovar.Mportifscdraddress := Piovar.Mportaddress + Piovar.Mportifscdraddress (65,17)
         ctxt.Piovar.mportifscdraddress := (ctxt.Piovar.mportaddress + ctxt.Piovar.mportifscdraddress);
         --  Piovar.Mportppddraddress := 144 (67,17)
         ctxt.Piovar.mportppddraddress := 144;
         --  Piovar.Mportppddraddress := Piovar.Mportaddress + Piovar.Mportppddraddress (69,17)
         ctxt.Piovar.mportppddraddress := (ctxt.Piovar.mportaddress + ctxt.Piovar.mportppddraddress);
         --  Piovar.Mportoweraddress := 160 (71,17)
         ctxt.Piovar.mportoweraddress := 160;
         --  Piovar.Mportoweraddress := Piovar.Mportaddress + Piovar.Mportoweraddress (73,17)
         ctxt.Piovar.mportoweraddress := (ctxt.Piovar.mportaddress + ctxt.Piovar.mportoweraddress);
         --  Piovar.Mportowdraddress := 164 (75,17)
         ctxt.Piovar.mportowdraddress := 164;
         --  Piovar.Mportowdraddress := Piovar.Mportaddress + Piovar.Mportowdraddress (77,17)
         ctxt.Piovar.mportowdraddress := (ctxt.Piovar.mportaddress + ctxt.Piovar.mportowdraddress);
         --  Piovar.Mportschmittaddress := 256 (79,17)
         ctxt.Piovar.mportschmittaddress := 256;
         --  Piovar.Mportschmittaddress := Piovar.Mportaddress + Piovar.Mportschmittaddress (81,17)
         ctxt.Piovar.mportschmittaddress := (ctxt.Piovar.mportaddress + ctxt.Piovar.mportschmittaddress);
         --  RETURN  (None,None) at None, None
         return;
      end p_0_InitPioContainer;
      

   procedure p_0_InitSync(Config: in asn1SccPioHwasPinConfig) is
      tmp328 : asn1SccWordMask;
      tmp346 : asn1SccDestinationAddress;
      tmp373 : asn1SccDestinationAddress;
      tmp375 : asn1SccWord;
      tmp384 : asn1SccWord;
      tmp304 : asn1SccWord;
      tmp366 : asn1SccWord;
      tmp356 : asn1SccWordMask;
      tmp393 : asn1SccWord;
      tmp374 : asn1SccWordMask;
      tmp230 : asn1SccWordMask;
      tmp289 : asn1SccWord;
      tmp277 : asn1SccDestinationAddress;
      tmp391 : asn1SccDestinationAddress;
      tmp348 : asn1SccWord;
      tmp279 : asn1SccWord;
      tmp229 : asn1SccDestinationAddress;
      tmp245 : asn1SccDestinationAddress;
      tmp262 : asn1SccWordMask;
      tmp313 : asn1SccWord;
      tmp215 : asn1SccWord;
      tmp383 : asn1SccWordMask;
      tmp392 : asn1SccWordMask;
      tmp311 : asn1SccDestinationAddress;
      tmp303 : asn1SccWordMask;
      tmp214 : asn1SccWordMask;
      tmp278 : asn1SccWordMask;
      tmp263 : asn1SccWord;
      tmp338 : asn1SccWord;
      tmp329 : asn1SccWord;
      tmp337 : asn1SccWordMask;
      tmp364 : asn1SccDestinationAddress;
      tmp365 : asn1SccWordMask;
      --  !! stack: _call_external_function line 1656
      tmp287 : asn1SccDestinationAddress;
      tmp213 : asn1SccDestinationAddress;
      tmp231 : asn1SccWord;
      tmp246 : asn1SccWordMask;
      tmp247 : asn1SccWord;
      tmp327 : asn1SccDestinationAddress;
      tmp288 : asn1SccWordMask;
      tmp357 : asn1SccWord;
      tmp347 : asn1SccWordMask;
      tmp336 : asn1SccDestinationAddress;
      tmp312 : asn1SccWordMask;
      tmp382 : asn1SccDestinationAddress;
      tmp302 : asn1SccDestinationAddress;
      tmp261 : asn1SccDestinationAddress;
      tmp355 : asn1SccDestinationAddress;
      begin
         --  InitPmc (93,17)
         p_0_InitPmc;
         --  DECISION Config.Mportconfig = PioHwas_Port_A (95,40)
         --  ANSWER True (97,17)
         if ((Config.mportconfig = asn1SccpioHwas_Port_A)) then
            --  Piovar.Mportaddress := 1074662912 (99,25)
            ctxt.Piovar.mportaddress := 1074662912;
            --  JOIN condition_1 (101,25) at 0, 1162
            goto condition_1;
            --  ANSWER False (103,17)
         else
            --  DECISION Config.Mportconfig = PioHwas_Port_B (105,48)
            --  ANSWER True (107,25)
            if ((Config.mportconfig = asn1SccpioHwas_Port_B)) then
               --  Piovar.Mportaddress := 1074663424 (109,33)
               ctxt.Piovar.mportaddress := 1074663424;
               --  JOIN condition_2 (111,33) at 600, 1237
               goto condition_2;
               --  ANSWER False (113,25)
            else
               --  DECISION Config.Mportconfig = PioHwas_Port_C (115,56)
               --  ANSWER True (117,33)
               if ((Config.mportconfig = asn1SccpioHwas_Port_C)) then
                  --  Piovar.Mportaddress := 1074663936 (119,41)
                  ctxt.Piovar.mportaddress := 1074663936;
                  --  JOIN condition_3 (121,41) at 1200, 1312
                  goto condition_3;
                  --  ANSWER False (123,33)
               else
                  --  DECISION Config.Mportconfig = PioHwas_Port_D (125,64)
                  --  ANSWER True (127,41)
                  if ((Config.mportconfig = asn1SccpioHwas_Port_D)) then
                     --  Piovar.Mportaddress := 1074664448 (129,49)
                     ctxt.Piovar.mportaddress := 1074664448;
                     --  JOIN condition_4 (131,49) at 1800, 1387
                     goto condition_4;
                     --  ANSWER False (133,41)
                  else
                     --  DECISION Config.Mportconfig = PioHwas_Port_E (135,72)
                     --  ANSWER True (137,49)
                     if ((Config.mportconfig = asn1SccpioHwas_Port_E)) then
                        --  Piovar.Mportaddress := 1074664960 (139,57)
                        ctxt.Piovar.mportaddress := 1074664960;
                        --  JOIN condition_5 (141,57) at 2400, 1462
                        goto condition_5;
                        --  ANSWER False (143,49)
                     else
                        --  JOIN condition_5 (145,57) at 3000, 1387
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
         --  CONNECTION condition_5 (148,44)
         <<condition_5>>
         --  JOIN condition_4 (150,49) at 3600, 1462
         goto condition_4;
         --  CONNECTION condition_4 (153,36)
         <<condition_4>>
         --  JOIN condition_3 (155,41) at 4200, 1387
         goto condition_3;
         --  CONNECTION condition_3 (158,28)
         <<condition_3>>
         --  JOIN condition_2 (160,33) at 4800, 1312
         goto condition_2;
         --  CONNECTION condition_2 (163,20)
         <<condition_2>>
         --  JOIN condition_1 (165,25) at 5400, 1237
         goto condition_1;
         --  CONNECTION condition_10 (227,44)
         <<condition_10>>
         --  JOIN condition_9 (229,49) at 9600, 1762
         goto condition_9;
         --  CONNECTION condition_9 (232,36)
         <<condition_9>>
         --  JOIN condition_8 (234,41) at 10200, 1687
         goto condition_8;
         --  CONNECTION condition_8 (237,28)
         <<condition_8>>
         --  JOIN condition_7 (239,33) at 10800, 1612
         goto condition_7;
         --  CONNECTION condition_7 (242,20)
         <<condition_7>>
         --  JOIN condition_6 (244,25) at 11400, 1537
         goto condition_6;
         --  CONNECTION condition_12 (278,20)
         <<condition_12>>
         --  JOIN condition_11 (280,25) at 13800, 1762
         goto condition_11;
         --  CONNECTION condition_11 (283,12)
         <<condition_11>>
         --  RawMemoryAccess_WriteWord_Ri(pioVar.mPortPudrAddress, pioVar.mPin, pioVar.mPin) (285,17)
         tmp346 := asn1SccDestinationAddress (ctxt.pioVar.mportpudraddress);
         tmp347 := asn1SccWordMask (ctxt.pioVar.mpin);
         tmp348 := asn1SccWord (ctxt.pioVar.mpin);
         RI_0_RawMemoryAccess_WriteWord_Ri(tmp346, tmp347, tmp348);
         --  RawMemoryAccess_WriteWord_Ri(pioVar.mPortPpddrAddress, pioVar.mPin, pioVar.mPin) (287,17)
         tmp355 := asn1SccDestinationAddress (ctxt.pioVar.mportppddraddress);
         tmp356 := asn1SccWordMask (ctxt.pioVar.mpin);
         tmp357 := asn1SccWord (ctxt.pioVar.mpin);
         RI_0_RawMemoryAccess_WriteWord_Ri(tmp355, tmp356, tmp357);
         --  RawMemoryAccess_WriteWord_Ri(pioVar.mPortIfdrAddress, pioVar.mPin, pioVar.mPin) (289,17)
         tmp364 := asn1SccDestinationAddress (ctxt.pioVar.mportifdraddress);
         tmp365 := asn1SccWordMask (ctxt.pioVar.mpin);
         tmp366 := asn1SccWord (ctxt.pioVar.mpin);
         RI_0_RawMemoryAccess_WriteWord_Ri(tmp364, tmp365, tmp366);
         --  RawMemoryAccess_WriteWord_Ri(pioVar.mPortIfscdrAddress, pioVar.mPin, pioVar.mPin) (291,17)
         tmp373 := asn1SccDestinationAddress (ctxt.pioVar.mportifscdraddress);
         tmp374 := asn1SccWordMask (ctxt.pioVar.mpin);
         tmp375 := asn1SccWord (ctxt.pioVar.mpin);
         RI_0_RawMemoryAccess_WriteWord_Ri(tmp373, tmp374, tmp375);
         --  RawMemoryAccess_WriteWord_Ri(pioVar.mPortSchmittAddress, pioVar.mPin, pioVar.mPin) (293,17)
         tmp382 := asn1SccDestinationAddress (ctxt.pioVar.mportschmittaddress);
         tmp383 := asn1SccWordMask (ctxt.pioVar.mpin);
         tmp384 := asn1SccWord (ctxt.pioVar.mpin);
         RI_0_RawMemoryAccess_WriteWord_Ri(tmp382, tmp383, tmp384);
         --  RawMemoryAccess_WriteWord_Ri(pioVar.mPortMddrAddress, pioVar.mPin, pioVar.mPin) (295,17)
         tmp391 := asn1SccDestinationAddress (ctxt.pioVar.mportmddraddress);
         tmp392 := asn1SccWordMask (ctxt.pioVar.mpin);
         tmp393 := asn1SccWord (ctxt.pioVar.mpin);
         RI_0_RawMemoryAccess_WriteWord_Ri(tmp391, tmp392, tmp393);
         --  RETURN  (None,None) at None, None
         return;
         --  CONNECTION condition_6 (247,12)
         <<condition_6>>
         --  RawMemoryAccess_WriteWord_Ri(pioVar.mPortPerAddress, pioVar.mPin, pioVar.mPin) (249,17)
         tmp287 := asn1SccDestinationAddress (ctxt.pioVar.mportperaddress);
         tmp288 := asn1SccWordMask (ctxt.pioVar.mpin);
         tmp289 := asn1SccWord (ctxt.pioVar.mpin);
         RI_0_RawMemoryAccess_WriteWord_Ri(tmp287, tmp288, tmp289);
         --  DECISION Config.Mdirectionconfig = PioHwas_Direction_Input (251,45)
         --  ANSWER True (253,17)
         if ((Config.mdirectionconfig = asn1SccpioHwas_Direction_Input)) then
            --  RawMemoryAccess_WriteWord_Ri(pioVar.mPortOdrAddress, pioVar.mPin, pioVar.mPin) (255,25)
            tmp302 := asn1SccDestinationAddress (ctxt.pioVar.mportodraddress);
            tmp303 := asn1SccWordMask (ctxt.pioVar.mpin);
            tmp304 := asn1SccWord (ctxt.pioVar.mpin);
            RI_0_RawMemoryAccess_WriteWord_Ri(tmp302, tmp303, tmp304);
            --  RawMemoryAccess_WriteWord_Ri(pioVar.mPortOwdrAddress, pioVar.mPin, pioVar.mPin) (257,25)
            tmp311 := asn1SccDestinationAddress (ctxt.pioVar.mportowdraddress);
            tmp312 := asn1SccWordMask (ctxt.pioVar.mpin);
            tmp313 := asn1SccWord (ctxt.pioVar.mpin);
            RI_0_RawMemoryAccess_WriteWord_Ri(tmp311, tmp312, tmp313);
            --  JOIN condition_11 (259,25) at 12000, 1762
            goto condition_11;
            --  ANSWER False (261,17)
         else
            --  DECISION Config.Mdirectionconfig = PioHwas_Direction_Output (263,53)
            --  ANSWER True (265,25)
            if ((Config.mdirectionconfig = asn1SccpioHwas_Direction_Output)) then
               --  RawMemoryAccess_WriteWord_Ri(pioVar.mPortOerAddress, pioVar.mPin, pioVar.mPin) (267,33)
               tmp327 := asn1SccDestinationAddress (ctxt.pioVar.mportoeraddress);
               tmp328 := asn1SccWordMask (ctxt.pioVar.mpin);
               tmp329 := asn1SccWord (ctxt.pioVar.mpin);
               RI_0_RawMemoryAccess_WriteWord_Ri(tmp327, tmp328, tmp329);
               --  RawMemoryAccess_WriteWord_Ri(pioVar.mPortOwdrAddress, pioVar.mPin, pioVar.mPin) (269,33)
               tmp336 := asn1SccDestinationAddress (ctxt.pioVar.mportowdraddress);
               tmp337 := asn1SccWordMask (ctxt.pioVar.mpin);
               tmp338 := asn1SccWord (ctxt.pioVar.mpin);
               RI_0_RawMemoryAccess_WriteWord_Ri(tmp336, tmp337, tmp338);
               --  JOIN condition_12 (271,33) at 12600, 1837
               goto condition_12;
               --  ANSWER False (273,25)
            else
               --  JOIN condition_12 (275,33) at 13200, 1687
               goto condition_12;
            end if;
            --  JOIN condition_12 (None,None) at None, None
            goto condition_12;
         end if;
         --  JOIN condition_11 (None,None) at None, None
         goto condition_11;
         --  CONNECTION condition_1 (168,12)
         <<condition_1>>
         --  InitPioContainer (170,17)
         p_0_InitPioContainer;
         --  Piovar.Mpin := config.mPinConfig (172,17)
         ctxt.Piovar.mpin := config.mpinconfig;
         --  DECISION Config.Mportconfig = PioHwas_Port_A (174,40)
         --  ANSWER True (176,17)
         if ((Config.mportconfig = asn1SccpioHwas_Port_A)) then
            --  RawMemoryAccess_WriteWord_Ri(pmcVar.PMC_PCSR0_OFFSET, pmcVar.PMC_PCxR0_PID10_PIOA_Mask, pmcVar.PMC_PCxR0_PID10_PIOA_Mask) (178,25)
            tmp213 := asn1SccDestinationAddress (ctxt.pmcVar.pmc_pcsr0_offset);
            tmp214 := asn1SccWordMask (ctxt.pmcVar.pmc_pcxr0_pid10_pioa_mask);
            tmp215 := asn1SccWord (ctxt.pmcVar.pmc_pcxr0_pid10_pioa_mask);
            RI_0_RawMemoryAccess_WriteWord_Ri(tmp213, tmp214, tmp215);
            --  JOIN condition_6 (180,25) at 6000, 1462
            goto condition_6;
            --  ANSWER False (182,17)
         else
            --  DECISION Config.Mportconfig = PioHwas_Port_B (184,48)
            --  ANSWER True (186,25)
            if ((Config.mportconfig = asn1SccpioHwas_Port_B)) then
               --  RawMemoryAccess_WriteWord_Ri(pmcVar.PMC_PCSR0_OFFSET, pmcVar.PMC_PCxR0_PID11_PIOB_Mask, pmcVar.PMC_PCxR0_PID11_PIOB_Mask) (188,33)
               tmp229 := asn1SccDestinationAddress (ctxt.pmcVar.pmc_pcsr0_offset);
               tmp230 := asn1SccWordMask (ctxt.pmcVar.pmc_pcxr0_pid11_piob_mask);
               tmp231 := asn1SccWord (ctxt.pmcVar.pmc_pcxr0_pid11_piob_mask);
               RI_0_RawMemoryAccess_WriteWord_Ri(tmp229, tmp230, tmp231);
               --  JOIN condition_7 (190,33) at 6600, 1537
               goto condition_7;
               --  ANSWER False (192,25)
            else
               --  DECISION Config.Mportconfig = PioHwas_Port_C (194,56)
               --  ANSWER True (196,33)
               if ((Config.mportconfig = asn1SccpioHwas_Port_C)) then
                  --  RawMemoryAccess_WriteWord_Ri(pmcVar.PMC_PCSR0_OFFSET, pmcVar.PMC_PCxR0_PID12_PIOC_Mask, pmcVar.PMC_PCxR0_PID12_PIOC_Mask) (198,41)
                  tmp245 := asn1SccDestinationAddress (ctxt.pmcVar.pmc_pcsr0_offset);
                  tmp246 := asn1SccWordMask (ctxt.pmcVar.pmc_pcxr0_pid12_pioc_mask);
                  tmp247 := asn1SccWord (ctxt.pmcVar.pmc_pcxr0_pid12_pioc_mask);
                  RI_0_RawMemoryAccess_WriteWord_Ri(tmp245, tmp246, tmp247);
                  --  JOIN condition_8 (200,41) at 7200, 1612
                  goto condition_8;
                  --  ANSWER False (202,33)
               else
                  --  DECISION Config.Mportconfig = PioHwas_Port_D (204,64)
                  --  ANSWER True (206,41)
                  if ((Config.mportconfig = asn1SccpioHwas_Port_D)) then
                     --  RawMemoryAccess_WriteWord_Ri(pmcVar.PMC_PCSR0_OFFSET, pmcVar.PMC_PCxR0_PID16_PIOD_Mask, pmcVar.PMC_PCxR0_PID16_PIOD_Mask) (208,49)
                     tmp261 := asn1SccDestinationAddress (ctxt.pmcVar.pmc_pcsr0_offset);
                     tmp262 := asn1SccWordMask (ctxt.pmcVar.pmc_pcxr0_pid16_piod_mask);
                     tmp263 := asn1SccWord (ctxt.pmcVar.pmc_pcxr0_pid16_piod_mask);
                     RI_0_RawMemoryAccess_WriteWord_Ri(tmp261, tmp262, tmp263);
                     --  JOIN condition_9 (210,49) at 7800, 1687
                     goto condition_9;
                     --  ANSWER False (212,41)
                  else
                     --  DECISION Config.Mportconfig = PioHwas_Port_E (214,72)
                     --  ANSWER True (216,49)
                     if ((Config.mportconfig = asn1SccpioHwas_Port_E)) then
                        --  RawMemoryAccess_WriteWord_Ri(pmcVar.PMC_PCSR0_OFFSET, pmcVar.PMC_PCxR0_PID17_PIOE_Mask, pmcVar.PMC_PCxR0_PID17_PIOE_Mask) (218,57)
                        tmp277 := asn1SccDestinationAddress (ctxt.pmcVar.pmc_pcsr0_offset);
                        tmp278 := asn1SccWordMask (ctxt.pmcVar.pmc_pcxr0_pid17_pioe_mask);
                        tmp279 := asn1SccWord (ctxt.pmcVar.pmc_pcxr0_pid17_pioe_mask);
                        RI_0_RawMemoryAccess_WriteWord_Ri(tmp277, tmp278, tmp279);
                        --  JOIN condition_10 (220,57) at 8400, 1762
                        goto condition_10;
                        --  ANSWER False (222,49)
                     else
                        --  JOIN condition_10 (224,57) at 9000, 1687
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
      tmp401 : asn1SccWordMask;
      tmp402 : asn1SccWord;
      tmp400 : asn1SccDestinationAddress;
      begin
         --  RawMemoryAccess_WriteWord_Ri(pio.mPortSodrAddress, pio.mPin, pio.mPin) (307,17)
         tmp400 := asn1SccDestinationAddress (pio.mportsodraddress);
         tmp401 := asn1SccWordMask (pio.mpin);
         tmp402 := asn1SccWord (pio.mpin);
         RI_0_RawMemoryAccess_WriteWord_Ri(tmp400, tmp401, tmp402);
         --  RETURN  (None,None) at None, None
         return;
      end p_0_SetPin;
      

   procedure p_0_ResetPin(Pio: in asn1SccPioHwas) is
      --  !! stack: _call_external_function line 1656
      tmp411 : asn1SccWord;
      tmp409 : asn1SccDestinationAddress;
      tmp410 : asn1SccWordMask;
      begin
         --  RawMemoryAccess_WriteWord_Ri(pio.mPortCodrAddress, pio.mPin, pio.mPin) (319,17)
         tmp409 := asn1SccDestinationAddress (pio.mportcodraddress);
         tmp410 := asn1SccWordMask (pio.mpin);
         tmp411 := asn1SccWord (pio.mpin);
         RI_0_RawMemoryAccess_WriteWord_Ri(tmp409, tmp410, tmp411);
         --  RETURN  (None,None) at None, None
         return;
      end p_0_ResetPin;
      

   procedure PioHwas_InitPin_Pi(Pio: in out asn1SccPioHwas;Config: in out asn1SccPioHwasPinConfig) is
      begin
         --  Configvar := Config (332,17)
         ctxt.Configvar := Config;
         --  InitSync(Configvar) (334,17)
         p_0_InitSync(ctxt.Configvar);
         --  Pio := Piovar (336,17)
         Pio := ctxt.Piovar;
         --  PioHwas_InitPin_Pi_Transition (None,None)
         PioHwas_InitPin_Pi_Transition;
         --  RETURN  (None,None) at None, None
         return;
      end PioHwas_InitPin_Pi;
      

   procedure PioHwas_ResetPin_Pi(Pio: in out asn1SccPioHwas) is
      begin
         --  Piovar := Pio (348,17)
         ctxt.Piovar := Pio;
         --  ResetPin(Piovar) (350,17)
         p_0_ResetPin(ctxt.Piovar);
         --  PioHwas_ResetPin_Pi_Transition (None,None)
         PioHwas_ResetPin_Pi_Transition;
         --  RETURN  (None,None) at None, None
         return;
      end PioHwas_ResetPin_Pi;
      

   procedure PioHwas_SetPin_Pi(Pio: in out asn1SccPioHwas) is
      begin
         --  Piovar := Pio (362,17)
         ctxt.Piovar := Pio;
         --  SetPin(Piovar) (364,17)
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
                  --  NEXT_STATE Off (370,18) at 0, 1687
                  trId := -1;
                  ctxt.State := asn1SccOff;
                  goto Continuous_Signals;
               when 1 =>
                  --  NEXT_STATE Idle (376,22) at 0, 1837
                  trId := -1;
                  ctxt.State := asn1SccIdle;
                  goto Continuous_Signals;
               when 2 =>
                  --  NEXT_STATE Idle (380,22) at 300, 1837
                  trId := -1;
                  ctxt.State := asn1SccIdle;
                  goto Continuous_Signals;
               when 3 =>
                  --  NEXT_STATE Idle (387,22) at 900, 1837
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