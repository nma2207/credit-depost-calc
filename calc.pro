#-------------------------------------------------
#
# Project created by QtCreator 2018-02-16T15:44:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = calc
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    creditcalcwidget.cpp \
    depositcalcwidget.cpp

HEADERS  += mainwindow.h \
    creditcalcwidget.h \
    depositcalcwidget.h

FORMS    += mainwindow.ui
