#-------------------------------------------------
#
# Project created by QtCreator 2014-07-24T12:43:17
#
#-------------------------------------------------

QT       += network

QT       -= gui

TARGET = peerj
TEMPLATE = lib

DEFINES += PEERJ_LIBRARY

SOURCES += peerj.cpp \
    entity/revision.cpp \
    entity/file.cpp \
    entity/article.cpp \
    entity/entity.cpp

HEADERS += peerj.h\
        peerj_global.h \
    entity/revision.h \
    entity/file.h \
    entity/article.h \
    entity/entity.h \
    entity/util.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

win32 {
    LIBS += -lqjson
}

INCLUDEPATH += $$PWD/../../qjson/
LIBS += $$PWD/../../qjson/
