#-------------------------------------------------
#
# Project created by QtCreator 2021-03-12T21:11:47
#
#-------------------------------------------------

QT       += core gui
QT       += widgets

TARGET = Battleship_Game
TEMPLATE = app


SOURCES += main.cpp\
    enemy.cpp \
    mainwindow.cpp \
    cpu.cpp \
    battleshipgame.cpp \
    displayships.cpp \
    selectship.cpp \
    boardsquare.cpp \
    player.cpp \
    human.cpp \
    gameships.cpp \
    cpuships.cpp \
    blast.cpp

HEADERS  += mainwindow.h \
    cpu.h \
    enemy.h \
    vars.h \
    battleshipgame.h \
    displayships.h \
    selectship.h \
    boardsquare.h \
    player.h \
    human.h \
    gameships.h \
    cpuships.h \
    blast.h

FORMS    += mainwindow.ui


