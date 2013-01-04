#ifndef CPLOTFACTORY_H
#define CPLOTFACTORY_H

#include <QMap>

#include "cplot.h"

class CPlotFactory {

    QMap<QString,CreatePlotFunc> plotMap;

public:

    CPlotFactory();
    ~CPlotFactory();

    void registerPlot(const QString& name_, CreatePlotFunc createfunc_);

    CPlot* createPlot(const QString& name_);

    QMapIterator<QString,CreatePlotFunc> getPlots();

};

#endif // CPLOTFACTORY_H
