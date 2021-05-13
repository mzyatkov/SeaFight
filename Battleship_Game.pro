#-------------------------------------------------
#
# Project created by QtCreator 2014-12-04T21:11:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Battleship_Game
TEMPLATE = app


SOURCES += Sources/main.cpp\
    Sources/enemy.cpp \
        Sources/mainwindow.cpp \
    Sources/cpu.cpp \
    Sources/battleshipgame.cpp \
    Sources/displayships.cpp \
    Sources/selectship.cpp \
    Sources/boardsquare.cpp \
    Sources/player.cpp \
    Sources/human.cpp \
    Sources/gameships.cpp \
    Sources/cpuships.cpp \
    Sources/blast.cpp

HEADERS  += Headers/mainwindow.h \
    Headers/cpu.h \
    Headers/enemy.h \
    Headers/vars.h \
    Headers/battleshipgame.h \
    Headers/displayships.h \
    Headers/selectship.h \
    Headers/boardsquare.h \
    Headers/player.h \
    Headers/human.h \
    Headers/gameships.h \
    Headers/cpuships.h \
    Headers/blast.h

FORMS    += mainwindow.ui


