#!/bin/bash

rm PioHwasComponent.xml
rm PioHwas.xml
rm Hwas.xml
rm HwasComponent.xml

cp ~/Documents/sedsDrivers/pio/Hwas.xml .
cp ~/Documents/sedsDrivers/pio/HwasComponent.xml .
cp ~/Documents/sedsDrivers/pio/Pio.xml PioHwas.xml
cp ~/Documents/sedsDrivers/pio/PioComponent.xml PioHwasComponent.xml

cp example/work/hwas/implem/default/C/src/hwas.c hwasBckp.c
cp example/work/manager/C/src/manager.c managerBckp.c

rm -rf example

taste
