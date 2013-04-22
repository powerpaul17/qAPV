#include "cplot.h"

CPlot::CPlot(QString plotType_) {
    this->type = "Plot";
    this->name = "Plot";
    this->plotType = plotType_;

    dataSeries.clear();
}

QString CPlot::getPlotType() {
    return plotType;
}

void CPlot::addDataSeries(CData *dataSeries_) {
    dataSeries.append(dataSeries_);
}

void CPlot::removeDataSeries(int id_) {
    if((id_>=0) && (id_<dataSeries.size())) {
        dataSeries.removeAt(id_);
    }
}
