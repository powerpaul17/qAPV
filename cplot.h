#ifndef CPLOT_H
#define CPLOT_H

#include <QtWidgets>

#include "cobject.h"
#include "cdata.h"

/* typedef enum {
    Plot2D,
    Plot3D,
    PlotPolar
} PlotType; */

class CPlot:public CObject {

    // int plotType;
    QString plotType;

protected:

    QList<CData*> dataSeries;

public:

    //CPlot(PlotType plotType_);
    CPlot(QString plotType_);

    virtual QWidget* getSettingsWidget(QWidget* parent) = 0;
    virtual QGraphicsScene* getGraphicsScene() = 0;

    //int getPlotType();
    QString getPlotType();

    void addDataSeries(CData* dataSeries_);
    void removeDataSeries(int id_);

};

typedef CPlot* (*CreatePlotFunc)(void);

#endif // CPLOT_H
