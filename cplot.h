#ifndef CPLOT_H
#define CPLOT_H

#include "cobject.h"
#include "cdata.h"
#include "caxis.h"

typedef enum {
    Plot2D,
    Plot3D,
    PlotPolar
} PlotType;

class CPlot:public CObject {

    int plotType;

protected:

    QList<CData*> dataSeries;

    QList<CAxis> axes;

public:

    CPlot(PlotType plotType_);

    virtual QWidget* getSettingsWidget() = 0;

};

typedef CPlot* (*CreatePlotFunc)(void);

#endif // CPLOT_H
