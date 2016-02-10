QT += core
QT += network
QT -= gui

TARGET = tdlm
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    utils/filelister.cpp \
    utils/filereader.cpp \
    todo_core/todoparser.cpp \
    todo_core/textformatter.cpp \
    todo_core/outputmanager.cpp \
    utils/filewriter.cpp \
    github/githubclient.cpp \
    github/gist.cpp \
    todo_core/templateparser.cpp

HEADERS += \
    utils/filelister.h \
    utils/filereader.h \
    todo_core/task.h \
    todo_core/todoparser.h \
    todo_core/textformatter.h \
    todo_core/outputmanager.h \
    utils/filewriter.h \
    github/githubclient.h \
    github/gist.h \
    todo_core/templateparser.h

