#-------------------------------------------------
#
# Project created by QtCreator 2015-07-17T15:35:09
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt_login_register
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    showinfowindow.cpp \
    registerwindow.cpp \
    reguserdb.cpp

HEADERS  += mainwindow.h \
    showinfowindow.h \
    registerwindow.h \
    reguserdb.h \
    userStruct.h \
    dbDefine.h

FORMS    += mainwindow.ui \
    showinfowindow.ui \
    registerwindow.ui
