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
    Store.cpp \
    dialog.cpp \
    deletewindow.cpp \
    mempurchlist.cpp \
    additem.cpp \
    deleteitem.cpp \
    itemname.cpp \
    report.cpp \
    expire.cpp
    report.cpp

HEADERS  += mainwindow.h \
    date.h \
    executive.h \
    header.h \
    Item.h \
    itemnames.h \
    member.h \
    Store.h \
    dialog.h \
    deletewindow.h \
    mempurchlist.h \
    additem.h \
    deleteitem.h \
    itemname.h \
    report.h \
    expire.h
    report.h

FORMS    += mainwindow.ui \
    dialog.ui \
    deletewindow.ui \
    mempurchlist.ui \
    additem.ui \
    deleteitem.ui \
    itemname.ui \
    report.ui \
    expire.ui
    report.ui

DISTFILES += \
    day1.txt \
    day2.txt \
    day3.txt \
    day4.txt \
    day5.txt \
    members.txt \
    Extras
