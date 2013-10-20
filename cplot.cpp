#include "cplot.h"

CPlot::CPlot(QString plotType_):CObject(0,"Plot") {
    addProperty("plottype","Plot Type","Plot Type",plotType_,true,false);

    m_dataSeries.clear();
}

QString CPlot::getPlotType() {
    return getStringPropertyValue("plottype");
}

void CPlot::addDataSeries(CData *dataSeries_) {
    m_dataSeries.append(dataSeries_);
}

void CPlot::removeDataSeries(int id_) {
    if((id_>=0) && (id_<m_dataSeries.size())) {
        m_dataSeries.removeAt(id_);
    }
}
