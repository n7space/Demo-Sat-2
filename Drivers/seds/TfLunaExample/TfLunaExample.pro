TEMPLATE = lib
CONFIG -= qt
CONFIG += generateC

DISTFILES +=  $(HOME)/tool-inst/share/taste-types/taste-types.asn \
    COM-N7SPACE-HWAS.acn \
    COM-N7SPACE-TFLUNAHWAS.acn \
    COM-N7SPACE-UARTHWAS.acn \
    COM-N7SPACE-TFLUNAHWASCOMPONENT.acn \
    COM-N7SPACE-HWAS.asn \
    COM-N7SPACE-TFLUNAHWAS.asn \
    COM-N7SPACE-UARTHWAS.asn \
    COM-N7SPACE-TFLUNAHWASCOMPONENT.asn \
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
    COM-N7SPACE-HWAS.acn \
    COM-N7SPACE-PIOHWAS.acn \
    COM-N7SPACE-PIOHWASCOMPONENT.acn \
    COM-N7SPACE-HWAS.asn \
    COM-N7SPACE-PIOHWAS.asn \
    COM-N7SPACE-PIOHWASCOMPONENT.asn \
    samv71.dv.xml \
    COM-N7SPACE-HWAS.acn \
    COM-N7SPACE-TFLUNAHWAS.acn \
    COM-N7SPACE-UARTHWAS.acn \
    COM-N7SPACE-TFLUNAHWASCOMPONENT.acn \
    COM-N7SPACE-HWAS.asn \
    COM-N7SPACE-TFLUNAHWAS.asn \
    COM-N7SPACE-UARTHWAS.asn \
    COM-N7SPACE-TFLUNAHWASCOMPONENT.asn \
    COM-N7SPACE-HWAS.acn \
    COM-N7SPACE-TFLUNAHWAS.acn \
    COM-N7SPACE-UARTHWAS.acn \
    COM-N7SPACE-TFLUNAHWASCOMPONENT.acn \
    COM-N7SPACE-HWAS.asn \
    COM-N7SPACE-TFLUNAHWAS.asn \
    COM-N7SPACE-UARTHWAS.asn \
    COM-N7SPACE-TFLUNAHWASCOMPONENT.asn
DISTFILES += TfLunaExample.asn
DISTFILES += TfLunaExample.acn
DISTFILES += TfLunaExample.msc
DISTFILES += interfaceview.xml
DISTFILES += work/binaries/*.msc
DISTFILES += work/binaries/coverage/index.html
DISTFILES += work/binaries/filters
#include(handleAsn1AcnBuild.pri)
include(work/taste.pro)
message($$DISTFILES)

