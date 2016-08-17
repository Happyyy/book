#-------------------------------------------------
#
# Project created by QtCreator 2016-08-03T12:31:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = udpq
TEMPLATE = app


SOURCES += main.cpp\
        udpserver.cpp

HEADERS  += udpserver.h

QT +=network
