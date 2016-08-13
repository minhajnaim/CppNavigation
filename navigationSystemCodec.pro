TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    CCodec.cpp \
    CCSVCodec.cpp \
    CGPSSensor.cpp \
    CIndentCodec.cpp \
    CNavigationSystem.cpp \
    CPOI.cpp \
    CPOIDataBase.cpp \
    CRoute.cpp \
    CWaypoint.cpp

HEADERS += \
    CCodec.h \
    CCSVCodec.h \
    CGPSSensor.h \
    CIndentCodec.h \
    CNavigationSystem.h \
    CPOI.h \
    CPOIDataBase.h \
    CRoute.h \
    CWaypoint.h
