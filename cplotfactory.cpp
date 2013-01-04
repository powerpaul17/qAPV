#include "cplotfactory.h"

#include "c2dplot.h"
#include "c3dplot.h"
#include "cpolarplot.h"

CPlotFactory::CPlotFactory() {
    plotMap.clear();

    registerPlot("2D",&C2DPlot::CreatePlot);
    registerPlot("3D",&C3DPlot::CreatePlot);
    registerPlot("Polar",&CPolarPlot::CreatePlot);
}

CPlotFactory::~CPlotFactory() {
    plotMap.clear();
}

void CPlotFactory::registerPlot(const QString &name_, CreatePlotFunc createfunc_) {
    plotMap[name_] = createfunc_;
}

CPlot* CPlotFactory::createPlot(const QString &name_) {
    QMap<QString,CreatePlotFunc>::iterator it = plotMap.find(name_);
    if(it != plotMap.end()) {
        return (it.value())();
    } else {
        return 0;
    }
}

QMapIterator<QString,CreatePlotFunc> CPlotFactory::getPlots() {
    return QMapIterator<QString,CreatePlotFunc>(plotMap);
}
