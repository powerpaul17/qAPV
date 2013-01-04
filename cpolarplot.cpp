#include <QtUiTools>

#include "cpolarplot.h"

CPolarPlot::CPolarPlot():CPlot(PlotPolar) {
    constructSettingsWidget();
}

CPolarPlot::~CPolarPlot() {

}

void CPolarPlot::constructSettingsWidget() {
    QUiLoader loader;
    QFile file("cpolarplot_settings.ui");
    file.open(QFile::ReadOnly);
    settingsWidget = loader.load(&file);
    file.close();
}

bool CPolarPlot::hasChildren() {
    return false;
}

int CPolarPlot::getNChildren() {
    return 0;
}

CObject* CPolarPlot::getChild(long id_) {
    return 0;
}

void CPolarPlot::exportToXML(QDomNode *node_) {
    //TODO
}

QWidget* CPolarPlot::getSettingsWidget() {
    return settingsWidget;
}

CPlot* CPolarPlot::CreatePlot() {
    return new CPolarPlot();
}
