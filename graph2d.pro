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
    calculation.cpp

HEADERS += \
    window.h \
    renderer.h \
    widget.h \
    camera.h \
    calculation.h
