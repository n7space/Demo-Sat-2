TEMPLATE = lib
CONFIG -= qt
CONFIG += generateC

DISTFILES +=  $(HOME)/tool-inst/share/taste-types/taste-types.asn \
    COM-N7SPACE-AFECHWAS.acn \
    COM-N7SPACE-AFECHWAS.asn \
    COM-N7SPACE-AFECHWAS.acn \
    COM-N7SPACE-AFECHWAS.asn \
    COM-N7SPACE-AFECHWAS.acn \
    COM-N7SPACE-AFECHWAS.asn \
    COM-N7SPACE-HWAS.acn \
    COM-N7SPACE-HWAS.asn \
    COM-N7SPACE-AFECHWAS.acn \
    COM-N7SPACE-AFECHWAS.asn \
    samv71.dv.xml
DISTFILES += samv71Afec.asn
DISTFILES += samv71Afec.acn
DISTFILES += samv71Afec.msc
DISTFILES += interfaceview.xml
DISTFILES += work/binaries/*.msc
DISTFILES += work/binaries/coverage/index.html
DISTFILES += work/binaries/filters
#include(handleAsn1AcnBuild.pri)
include(work/taste.pro)
message($$DISTFILES)

