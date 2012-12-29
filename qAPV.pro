#-------------------------------------------------
#
# Project created by QtCreator 2012-12-26T11:13:54
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qAPV
TEMPLATE = app


SOURCES += main.cpp\
        wmainwindow.cpp \
    cproject.cpp \
    cobject.cpp \
    cdatasource.cpp \
    qprojecttreemodel.cpp \
    qprojecttreeview.cpp \
    cfiledatasource.cpp \
    cdata.cpp

HEADERS  += wmainwindow.h \
    cproject.h \
    cobject.h \
    cdatasource.h \
    qprojecttreemodel.h \
    qprojecttreeview.h \
    cfiledatasource.h \
    cdata.h \
    caudiodata.h

FORMS    += wmainwindow.ui
