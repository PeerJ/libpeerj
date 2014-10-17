#-------------------------------------------------
#
# Project created by QtCreator 2014-07-20T13:47:12
#
#-------------------------------------------------

QT       += core
QT       += network
QT       -= gui

TARGET    = peerjtest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app
SOURCES += main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../release/ -lpeerj
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../debug/ -lpeerj
else:unix: LIBS += -L$$OUT_PWD/../ -lpeerj

LIBS+= -L$$PWD/../../../qjson/ -lqjson

INCLUDEPATH += $$PWD/../ $$PWD/../../../qjson/
DEPENDPATH += $$PWD/../
