#include <QtUiTools>
#include <QtWidgets>

#include "c2dplot.h"

C2DPlot::C2DPlot():CPlot(Plot2D) {
    axes.append(CAxis());
    axes.append(CAxis());
    constructSettingsWidget();
}

C2DPlot::~C2DPlot() {

}

void C2DPlot::constructSettingsWidget() {
    QUiLoader loader;
    QFile file("c2dplot_settings.ui");
    file.open(QFile::ReadOnly);
    settingsWidget = loader.load(&file);
    file.close();
}

bool C2DPlot::hasChildren() {
    return false;
}

int C2DPlot::getNChildren() {
    return 0;
}

CObject* C2DPlot::getChild(long id_) {
    return 0;
}

void C2DPlot::exportToXML(QDomNode* node_) {
    //TODO
}

QWidget* C2DPlot::getSettingsWidget() {
    return settingsWidget;
}

CPlot* C2DPlot::CreatePlot() {
    return new C2DPlot();
}
