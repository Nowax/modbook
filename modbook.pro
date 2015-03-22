#-------------------------------------------------
#
# Project created by QtCreator 2015-03-20T19:26:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = modbook
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
        main_window.cpp \
    common_const.cpp \
    log/logger.cpp \
    log/time_controller.cpp \
    log/log_consts.cpp \

HEADERS  += main_window.h \
    common_consts.h \
    operations.h \
    log/logger.h \
    log/time_controller.h \
    log/log_consts.h \

FORMS    += main_window.ui

RESOURCES += resources/application.qrc

DEFINES += DEBUG_1 \
        DEBUG_2
