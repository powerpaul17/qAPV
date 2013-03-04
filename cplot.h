#ifndef CPLOT_H
#define CPLOT_H

#include <QtWidgets>

#include "cobject.h"
#include "cdata.h"

typedef enum {
    Plot2D,
    Plot3D,
    PlotPolar
} PlotType;

class CPlot:public CObject {

    int plotType;

protected:

    QList<CData*> dataSeries;

public:

    CPlot(PlotType plotType_);

    virtual QWidget* getSettingsWidget() = 0;
    virtual void drawPlot(QGraphicsScene* scene_) = 0;

    int getPlotType();

    void addDataSeries(CData* dataSeries_);
    void removeDataSeries(int id_);

};

typedef CPlot* (*CreatePlotFunc)(void);

#endif // CPLOT_H
