TEMPLATE = lib
CONFIG -= qt
CONFIG += generateC

DISTFILES +=  $(HOME)/tool-inst/share/taste-types/taste-types.asn \
    COM-N7SPACE-HWAS.acn \
    COM-N7SPACE-UARTHWAS.acn \
    COM-N7SPACE-PIOHWAS.acn \
    COM-N7SPACE-UARTHWASCOMPONENT.acn \
    COM-N7SPACE-HWAS.asn \
    COM-N7SPACE-UARTHWAS.asn \
    COM-N7SPACE-PIOHWAS.asn \
    COM-N7SPACE-UARTHWASCOMPONENT.asn \
    COM-N7SPACE-HWAS.acn \
    COM-N7SPACE-PIOHWAS.acn \
    COM-N7SPACE-PIOHWASCOMPONENT.acn \
    COM-N7SPACE-HWAS.asn \
    COM-N7SPACE-PIOHWAS.asn \
    COM-N7SPACE-PIOHWASCOMPONENT.asn \
    COM-N7SPACE-HWAS.acn \
    COM-N7SPACE-HWASCOMPONENT.acn \
    COM-N7SPACE-HWAS.asn \
    COM-N7SPACE-HWASCOMPONENT.asn \
    samv71.dv.xml
DISTFILES += example.asn
DISTFILES += example.acn
DISTFILES += example.msc
DISTFILES += interfaceview.xml
DISTFILES += work/binaries/*.msc
DISTFILES += work/binaries/coverage/index.html
DISTFILES += work/binaries/filters
#include(handleAsn1AcnBuild.pri)
include(work/taste.pro)
message($$DISTFILES)

