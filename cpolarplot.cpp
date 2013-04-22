#include <QtUiTools>

#include "cpolarplot.h"

CPolarPlot::CPolarPlot():CPlot("Polar") {
    this->name = "Polarplot";
    scene = new QGraphicsScene();
}

CPolarPlot::~CPolarPlot() {
    delete scene;
}

QWidget* CPolarPlot::constructSettingsWidget(QWidget* parent_) {
    QUiLoader loader;
    QFile file("cpolarplot_settings.ui");
    file.open(QFile::ReadOnly);
    QWidget* settingsWidget = loader.load(&file,parent_);
    file.close();
    return settingsWidget;
}

void CPolarPlot::exportToXML(QXmlStreamWriter *xml_) {
    //TODO
}

void CPolarPlot::constructFromXML(QXmlStreamReader *xml_) {
    //TODO
}

QWidget* CPolarPlot::getSettingsWidget(QWidget *parent_) {
    return constructSettingsWidget(parent_);
}

QGraphicsScene* CPolarPlot::getGraphicsScene() {
    return scene;
}

CPlot* CPolarPlot::CreatePlot() {
    return new CPolarPlot();
}
