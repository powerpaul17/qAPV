#include "cplot.h"

CPlot::CPlot(PlotType plotType_) {
    this->type = Plot;
    this->name = "Plot";
    this->plotType = plotType_;

    dataSeries.clear();
    axes.clear();
}
