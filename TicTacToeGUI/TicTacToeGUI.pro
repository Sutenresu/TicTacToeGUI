#-------------------------------------------------
#
# Project created by QtCreator 2018-05-07T16:44:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TicTacToeGUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    node.cpp \
    state.cpp \
    game.cpp

HEADERS  += mainwindow.h \
    node.h \
    state.h

FORMS    += mainwindow.ui
