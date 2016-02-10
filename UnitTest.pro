#-------------------------------------------------
#
# Project created by QtCreator 2015-10-31T20:25:03
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_gasipromotest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_gasipromotest.cpp \
    utils/filelister.cpp \
    utils/filereader.cpp \
    todo_core/todoparser.cpp \
    todo_core/textformatter.cpp \
    todo_core/outputmanager.cpp \
    todo_core/templateparser.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    utils/filelister.h \
    utils/filereader.h \
    todo_core/task.h \
    todo_core/todoparser.h \
    todo_core/textformatter.h \
    todo_core/outputmanager.h \
    todo_core/templateparser.h
