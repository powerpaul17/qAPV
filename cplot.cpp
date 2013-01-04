#include "cplot.h"

CPlot::CPlot() {
    this->type = Plot;
    this->name = "Plot";

    dataSeries.clear();
}

CPlot::~CPlot() {

}

bool CPlot::hasChildren() {
    return false;
}

int CPlot::getNChildren() {
    return 0;
}

CObject* CPlot::getChild(long id_) {
    return 0;
}

void CPlot::exportToXML(QDomNode* node_) {
    //TODO
}
