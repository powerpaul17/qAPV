#include <QtUiTools>

#include "c3dplot.h"

C3DPlot::C3DPlot():CPlot(Plot3D) {
    constructSettingsWidget();
}

C3DPlot::~C3DPlot() {

}

void C3DPlot::constructSettingsWidget() {
    QUiLoader loader;
    QFile file("c3dplot_settings.ui");
    file.open(QFile::ReadOnly);
    settingsWidget = loader.load(&file);
    file.close();
}

bool C3DPlot::hasChildren() {
    return false;
}

int C3DPlot::getNChildren() {
    return 0;
}

CObject* C3DPlot::getChild(long id_) {
    return 0;
}

void C3DPlot::exportToXML(QDomNode* node_) {
    //TODO
}

QWidget* C3DPlot::getSettingsWidget() {
    return settingsWidget;
}

CPlot* C3DPlot::CreatePlot() {
    return new C3DPlot();
}
