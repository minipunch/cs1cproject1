#-------------------------------------------------
#
# Project created by QtCreator 2016-03-08T17:50:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    date.cpp \
    executive.cpp \
    Item.cpp \
    member.cpp \
    Store.cpp

HEADERS  += mainwindow.h \
    date.h \
    executive.h \
    header.h \
    Item.h \
    itemnames.h \
    member.h \
    Store.h

FORMS    += mainwindow.ui

DISTFILES += \
    day1.txt \
    day2.txt \
    day3.txt \
    day4.txt \
    day5.txt \
    members.txt