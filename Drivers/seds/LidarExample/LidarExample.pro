TEMPLATE = lib
CONFIG -= qt
CONFIG += generateC

DISTFILES +=  $(HOME)/tool-inst/share/taste-types/taste-types.asn \
    COM-N7SPACE-HWAS.acn \
    COM-N7SPACE-PIOHWAS.acn \
    COM-N7SPACE-MP6500.acn \
    COM-N7SPACE-TFLUNA.acn \
    COM-N7SPACE-LIDAR.acn \
    COM-N7SPACE-LIDARCOMPONENT.acn \
    COM-N7SPACE-UARTHWAS.acn \
    COM-N7SPACE-HWAS.asn \
    COM-N7SPACE-PIOHWAS.asn \
    COM-N7SPACE-MP6500.asn \
    COM-N7SPACE-TFLUNA.asn \
    COM-N7SPACE-LIDAR.asn \
    COM-N7SPACE-LIDARCOMPONENT.asn \
    COM-N7SPACE-UARTHWAS.asn \
    COM-N7SPACE-HWAS.acn \
    COM-N7SPACE-PIOHWAS.acn \
    COM-N7SPACE-MP6500.acn \
    COM-N7SPACE-MP6500COMPONENT.acn \
    COM-N7SPACE-HWAS.asn \
    COM-N7SPACE-PIOHWAS.asn \
    COM-N7SPACE-MP6500.asn \
    COM-N7SPACE-MP6500COMPONENT.asn \
    COM-N7SPACE-HWAS.acn \
    COM-N7SPACE-TFLUNA.acn \
    COM-N7SPACE-UARTHWAS.acn \
    COM-N7SPACE-TFLUNACOMPONENT.acn \
    COM-N7SPACE-HWAS.asn \
    COM-N7SPACE-TFLUNA.asn \
    COM-N7SPACE-UARTHWAS.asn \
    COM-N7SPACE-TFLUNACOMPONENT.asn \
    COM-N7SPACE-HWAS.acn \
    COM-N7SPACE-PIOHWAS.acn \
    COM-N7SPACE-PIOHWASCOMPONENT.acn \
    COM-N7SPACE-HWAS.asn \
    COM-N7SPACE-PIOHWAS.asn \
    COM-N7SPACE-PIOHWASCOMPONENT.asn \
    COM-N7SPACE-HWAS.acn \
    COM-N7SPACE-UARTHWAS.acn \
    COM-N7SPACE-PIOHWAS.acn \
    COM-N7SPACE-UARTHWASCOMPONENT.acn \
    COM-N7SPACE-HWAS.asn \
    COM-N7SPACE-UARTHWAS.asn \
    COM-N7SPACE-PIOHWAS.asn \
    COM-N7SPACE-UARTHWASCOMPONENT.asn \
    COM-N7SPACE-HWAS.acn \
    COM-N7SPACE-HWASCOMPONENT.acn \
    COM-N7SPACE-HWAS.asn \
    COM-N7SPACE-HWASCOMPONENT.asn \
    samv71.dv.xml \
    COM-N7SPACE-HWAS.acn \
    COM-N7SPACE-PIOHWAS.acn \
    COM-N7SPACE-MP6500.acn \
    COM-N7SPACE-TFLUNA.acn \
    COM-N7SPACE-LIDAR.acn \
    COM-N7SPACE-LIDARCOMPONENT.acn \
    COM-N7SPACE-UARTHWAS.acn \
    COM-N7SPACE-HWAS.asn \
    COM-N7SPACE-PIOHWAS.asn \
    COM-N7SPACE-MP6500.asn \
    COM-N7SPACE-TFLUNA.asn \
    COM-N7SPACE-LIDAR.asn \
    COM-N7SPACE-LIDARCOMPONENT.asn \
    COM-N7SPACE-UARTHWAS.asn \
    COM-N7SPACE-HWAS.acn \
    COM-N7SPACE-PIOHWAS.acn \
    COM-N7SPACE-MP6500.acn \
    COM-N7SPACE-TFLUNA.acn \
    COM-N7SPACE-LIDAR.acn \
    COM-N7SPACE-LIDARCOMPONENT.acn \
    COM-N7SPACE-UARTHWAS.acn \
    COM-N7SPACE-HWAS.asn \
    COM-N7SPACE-PIOHWAS.asn \
    COM-N7SPACE-MP6500.asn \
    COM-N7SPACE-TFLUNA.asn \
    COM-N7SPACE-LIDAR.asn \
    COM-N7SPACE-LIDARCOMPONENT.asn \
    COM-N7SPACE-UARTHWAS.asn
DISTFILES += LidarExample.asn
DISTFILES += LidarExample.acn
DISTFILES += LidarExample.msc
DISTFILES += interfaceview.xml
DISTFILES += work/binaries/*.msc
DISTFILES += work/binaries/coverage/index.html
DISTFILES += work/binaries/filters
#include(handleAsn1AcnBuild.pri)
include(work/taste.pro)
message($$DISTFILES)

