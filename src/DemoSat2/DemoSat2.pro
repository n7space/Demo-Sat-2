TEMPLATE = lib
CONFIG -= qt
CONFIG += generateC

DISTFILES +=  $(HOME)/tool-inst/share/taste-types/taste-types.asn \
    COM-N7SPACE-AFECHWAS.acn \
    COM-N7SPACE-AFECHWAS.asn \
    COM-N7SPACE-AFECHWASCOMPONENT-AFECHWASDRIVER.acn \
    COM-N7SPACE-AFECHWASCOMPONENT-AFECHWASDRIVER.asn \
    COM-N7SPACE-AFECHWASCOMPONENT.acn \
    COM-N7SPACE-AFECHWASCOMPONENT.asn \
    COM-N7SPACE-HWAS.acn \
    COM-N7SPACE-HWAS.asn \
    COM-N7SPACE-HWASCOMPONENT-HWAS.acn \
    COM-N7SPACE-HWASCOMPONENT-HWAS.asn \
    COM-N7SPACE-HWASCOMPONENT.acn \
    COM-N7SPACE-HWASCOMPONENT.asn \
    COM-N7SPACE-LIDAR.acn \
    COM-N7SPACE-LIDAR.asn \
    COM-N7SPACE-LIDARCOMPONENT-LIDARDRIVER.acn \
    COM-N7SPACE-LIDARCOMPONENT-LIDARDRIVER.asn \
    COM-N7SPACE-LIDARCOMPONENT.acn \
    COM-N7SPACE-LIDARCOMPONENT.asn \
    COM-N7SPACE-MP6500.acn \
    COM-N7SPACE-MP6500.asn \
    COM-N7SPACE-MP6500COMPONENT-MP6500DRIVER.acn \
    COM-N7SPACE-MP6500COMPONENT-MP6500DRIVER.asn \
    COM-N7SPACE-MP6500COMPONENT.acn \
    COM-N7SPACE-MP6500COMPONENT.asn \
    COM-N7SPACE-PIOHWAS.acn \
    COM-N7SPACE-PIOHWAS.asn \
    COM-N7SPACE-PIOHWASCOMPONENT-PIOHWASDRIVER.acn \
    COM-N7SPACE-PIOHWASCOMPONENT-PIOHWASDRIVER.asn \
    COM-N7SPACE-PIOHWASCOMPONENT.acn \
    COM-N7SPACE-PIOHWASCOMPONENT.asn \
    COM-N7SPACE-PROPULSION.acn \
    COM-N7SPACE-PROPULSION.asn \
    COM-N7SPACE-PROPULSIONCOMPONENT-PROPULSIONDRIVER.acn \
    COM-N7SPACE-PROPULSIONCOMPONENT-PROPULSIONDRIVER.asn \
    COM-N7SPACE-PROPULSIONCOMPONENT.acn \
    COM-N7SPACE-PROPULSIONCOMPONENT.asn \
    COM-N7SPACE-SUNSENSOR.acn \
    COM-N7SPACE-SUNSENSOR.asn \
    COM-N7SPACE-SUNSENSORCOMPONENT-SUNSENSORDRIVER.acn \
    COM-N7SPACE-SUNSENSORCOMPONENT-SUNSENSORDRIVER.asn \
    COM-N7SPACE-SUNSENSORCOMPONENT.acn \
    COM-N7SPACE-SUNSENSORCOMPONENT.asn \
    COM-N7SPACE-TFLUNA.acn \
    COM-N7SPACE-TFLUNA.asn \
    COM-N7SPACE-TFLUNACOMPONENT-TFLUNADRIVER.acn \
    COM-N7SPACE-TFLUNACOMPONENT-TFLUNADRIVER.asn \
    COM-N7SPACE-TFLUNACOMPONENT.acn \
    COM-N7SPACE-TFLUNACOMPONENT.asn \
    COM-N7SPACE-UARTHWAS.acn \
    COM-N7SPACE-UARTHWAS.asn \
    COM-N7SPACE-UARTHWASCOMPONENT-UARTHWASDRIVER.acn \
    COM-N7SPACE-UARTHWASCOMPONENT-UARTHWASDRIVER.asn \
    COM-N7SPACE-UARTHWASCOMPONENT.acn \
    COM-N7SPACE-UARTHWASCOMPONENT.asn
DISTFILES += DemoSat2.msc
DISTFILES += interfaceview.xml
DISTFILES += work/binaries/*.msc
DISTFILES += work/binaries/coverage/index.html
DISTFILES += work/binaries/filters
DISTFILES += work/system.asn

DISTFILES += DemoSat2.asn
DISTFILES += DemoSat2.acn
include(work/taste.pro)
message($$DISTFILES)

