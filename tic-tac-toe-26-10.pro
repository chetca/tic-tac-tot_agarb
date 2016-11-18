#-------------------------------------------------
#
# Project created by QtCreator 2016-10-26T14:51:22
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tic-tac-toe-26-10
TEMPLATE = app

CONFIG += c++11


SOURCES += main.cpp\
    abstractgame.cpp \
    gamefield.cpp \
    coords.cpp \
    abstractplayer.cpp \
    game.cpp \
    gameview.cpp \
    gameviewbutton.cpp \
    gameviewplayer.cpp \
    remoteplayer.cpp \
    protocolevent.cpp \
    mark.cpp

HEADERS  += \
    abstractgame.h \
    gamefield.h \
    mark.h \
    coords.h \
    abstractplayer.h \
    game.h \
    gameview.h \
    gameviewbutton.h \
    gameviewplayer.h \
    remoteplayer.h \
    protocolevent.h

FORMS    +=
