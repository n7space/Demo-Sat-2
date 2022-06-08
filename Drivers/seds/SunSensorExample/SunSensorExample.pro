TEMPLATE = lib
CONFIG -= qt
CONFIG += generateC

DISTFILES +=  $(HOME)/tool-inst/share/taste-types/taste-types.asn \
    COM-N7SPACE-HWAS.acn \
    COM-N7SPACE-HWASCOMPONENT.acn \
    COM-N7SPACE-HWASCOMPONENT-HWAS.acn \
    COM-N7SPACE-HWAS.asn \
    COM-N7SPACE-HWASCOMPONENT.asn \
    COM-N7SPACE-HWASCOMPONENT-HWAS.asn \
    COM-N7SPACE-HWAS.acn \
    COM-N7SPACE-AFECHWAS.acn \
    COM-N7SPACE-AFECHWASCOMPONENT.acn \
    COM-N7SPACE-AFECHWASCOMPONENT-AFECHWASDRIVER.acn \
    COM-N7SPACE-HWAS.asn \
    COM-N7SPACE-AFECHWAS.asn \
    COM-N7SPACE-AFECHWASCOMPONENT.asn \
    COM-N7SPACE-AFECHWASCOMPONENT-AFECHWASDRIVER.asn \
    COM-N7SPACE-HWAS.acn \
    COM-N7SPACE-AFECHWAS.acn \
    COM-N7SPACE-SUNSENSOR.acn \
    COM-N7SPACE-SUNSENSORCOMPONENT.acn \
    COM-N7SPACE-SUNSENSORCOMPONENT-SUNSENSORDRIVER.acn \
    COM-N7SPACE-HWAS.asn \
    COM-N7SPACE-AFECHWAS.asn \
    COM-N7SPACE-SUNSENSOR.asn \
    COM-N7SPACE-SUNSENSORCOMPONENT.asn \
    COM-N7SPACE-SUNSENSORCOMPONENT-SUNSENSORDRIVER.asn \
    samv71.dv.xml \
    COM-N7SPACE-HWAS.acn \
    COM-N7SPACE-AFECHWAS.acn \
    COM-N7SPACE-SUNSENSOR.acn \
    COM-N7SPACE-SUNSENSORCOMPONENT.acn \
    COM-N7SPACE-SUNSENSORCOMPONENT-SUNSENSORDRIVER.acn \
    COM-N7SPACE-HWAS.asn \
    COM-N7SPACE-AFECHWAS.asn \
    COM-N7SPACE-SUNSENSOR.asn \
    COM-N7SPACE-SUNSENSORCOMPONENT.asn \
    COM-N7SPACE-SUNSENSORCOMPONENT-SUNSENSORDRIVER.asn
DISTFILES += SunSensorExample.asn
DISTFILES += SunSensorExample.acn
DISTFILES += SunSensorExample.msc
DISTFILES += interfaceview.xml
DISTFILES += work/binaries/*.msc
DISTFILES += work/binaries/coverage/index.html
DISTFILES += work/binaries/filters
#include(handleAsn1AcnBuild.pri)
include(work/taste.pro)
message($$DISTFILES)
