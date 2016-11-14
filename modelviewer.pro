QT += core gui widgets

CONFIG += c++11

TARGET = graph2d
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    window.cpp \
    renderer.cpp \
    widget.cpp \
    camera.cpp \
    models/basemodel.cpp \
    models/graphicmv.cpp \
    models/modelmv.cpp \
    matrix.cpp \
    affine2d.cpp \
    affine3d.cpp \
    affineparams.cpp \
    chosenpoint.cpp

HEADERS += \
    window.h \
    renderer.h \
    widget.h \
    camera.h \
    models/basemodel.h \
    models/graphicmv.h \
    models/modelmv.h \
    matrix.h \
    affine2d.h \
    affine3d.h \
    affineparams.h \
    typeEnums.h \
    chosenpoint.h
