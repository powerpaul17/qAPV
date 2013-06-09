#include "cplot.h"

CPlot::CPlot(QString plotType_):CObject(0,"Plot") {
    m_type = "Plot";
    // setName("Plot");
    m_plotType = plotType_;

    m_dataSeries.clear();
}

QString CPlot::getPlotType() {
    return m_plotType;
}

void CPlot::addDataSeries(CData *dataSeries_) {
    m_dataSeries.append(dataSeries_);
}

void CPlot::removeDataSeries(int id_) {
    if((id_>=0) && (id_<m_dataSeries.size())) {
        m_dataSeries.removeAt(id_);
    }
}
