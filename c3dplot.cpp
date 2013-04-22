#include <QtUiTools>

#include "c3dplot.h"

C3DPlot::C3DPlot():CPlot("3D") {
    this->name = "3D Plot";
    scene = new QGraphicsScene();
}

C3DPlot::~C3DPlot() {
    delete scene;
}

QWidget* C3DPlot::constructSettingsWidget(QWidget* parent_) {
    QUiLoader loader;
    QFile file("c3dplot_settings.ui");
    file.open(QFile::ReadOnly);
    QWidget* settingsWidget = loader.load(&file,parent_);
    file.close();
    return settingsWidget;
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

void C3DPlot::addChild(CObject *child_) {

}

void C3DPlot::removeChild(CObject *child_) {

}

void C3DPlot::removeChild(long id_) {

}

void C3DPlot::exportToXML(QXmlStreamWriter *xml_) {
    //TODO
}

void C3DPlot::constructFromXML(QXmlStreamReader *xml_) {
    //TODO
}

QWidget* C3DPlot::getSettingsWidget(QWidget *parent_) {
    return constructSettingsWidget(parent_);
}

QGraphicsScene* C3DPlot::getGraphicsScene() {
    return scene;
}

CPlot* C3DPlot::CreatePlot() {
    return new C3DPlot();
}

void C3DPlot::slot_childDestroyed(CObject *child_) {

}
