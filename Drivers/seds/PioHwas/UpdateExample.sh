#!/bin/bash

mv hwasBckp.c example/work/hwas/implem/default/C/src/hwas.c
mv managerBckp.c example/work/manager/C/src/manager.c
cp ~/Documents/sedsDrivers/pio/output/piohwasdriver.pr example/work/piohwasdriver/SDL/src/piohwasdriver.pr

rm example/skeletons.pro

spacecreator.AppImage example/example.pro
