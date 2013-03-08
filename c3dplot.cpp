#include <QtUiTools>

#include "c3dplot.h"

C3DPlot::C3DPlot():CPlot("3D") {
    this->name = "3D Plot";
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

CObject* C3DPlot::getChildById(long id_) {
    return 0;
}

CObject* C3DPlot::getChildByPosition(long pos_) {
    return 0;
}

int C3DPlot::getPositionOfChild(CObject* child_) {
    return -1;
}

void C3DPlot::exportToXML(QXmlStreamWriter *xml_) {
    //TODO
}

void C3DPlot::constructFromXML(QXmlStreamReader *xml_) {
    //TODO
}

QWidget* C3DPlot::getSettingsWidget() {
    return settingsWidget;
}

void C3DPlot::drawPlot(QGraphicsScene *scene_) {
    //TODO
}

CPlot* C3DPlot::CreatePlot() {
    return new C3DPlot();
}
