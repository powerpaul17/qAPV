#ifndef CPLOT_H
#define CPLOT_H

#include <QtWidgets>

#include "cobject.h"
#include "cdata.h"

class CPlot:public CObject {

    QString plotType;

protected:

    QList<CData*> dataSeries;

public:

    CPlot(QString plotType_);

    virtual QWidget* getSettingsWidget(QWidget* parent) = 0;
    virtual QGraphicsScene* getGraphicsScene() = 0;

    QString getPlotType();

    void addDataSeries(CData* dataSeries_);
    void removeDataSeries(int id_);

};

typedef CPlot* (*CreatePlotFunc)(void);

#endif // CPLOT_H
