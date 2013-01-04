#-------------------------------------------------
#
# Project created by QtCreator 2012-12-26T11:13:54
#
#-------------------------------------------------

QT       += core gui xml uitools

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
    cdata.cpp \
    qadddatasourcedialog.cpp \
    cdatasourcefactory.cpp \
    qplotwindow.cpp \
    cplot.cpp \
    caxis.cpp \
    c2dplot.cpp \
    qaddplotdialog.cpp \
    cplotfactory.cpp \
    c3dplot.cpp \
    cpolarplot.cpp

HEADERS  += wmainwindow.h \
    cproject.h \
    cobject.h \
    cdatasource.h \
    qprojecttreemodel.h \
    qprojecttreeview.h \
    cfiledatasource.h \
    cdata.h \
    caudiodata.h \
    qadddatasourcedialog.h \
    cdatasourcefactory.h \
    qplotwindow.h \
    cplot.h \
    caxis.h \
    c2dplot.h \
    c3dplot.h \
    cpolarplot.h \
    qaddplotdialog.h \
    cplotfactory.h

FORMS    += wmainwindow.ui \
    qadddatasourcedialog.ui \
    qplotwindow.ui \
    cfiledatasource_settings.ui \
    qaddplotdialog.ui \
    c2dplot_settings.ui
