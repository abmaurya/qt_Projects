#-------------------------------------------------
#
# Project created by QtCreator 2015-09-29T21:25:34
#
#-------------------------------------------------

QT       += core gui

QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qqtteesstt
TEMPLATE = app


SOURCES += main.cpp \
    serving.cpp \
    Clients.cpp \
    ui.cpp

HEADERS += \
    serving.h \
    Clients.h \
    ui.h
