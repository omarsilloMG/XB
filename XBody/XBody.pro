#-------------------------------------------------
#
# Project created by QtCreator 2016-02-16T17:17:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = XBody
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    maintests.cpp \
    splash.cpp

HEADERS  += dialog.h \
    splash.h

FORMS    += dialog.ui \
    splash.ui

RESOURCES += \
    resources.qrc
