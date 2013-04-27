#include <QtUiTools>

#include "c3dplot.h"

C3DPlot::C3DPlot():CPlot("3D") {
    m_name = "3D Plot";
    m_scene = new QGraphicsScene();
}

C3DPlot::~C3DPlot() {
    delete m_scene;
}

QWidget* C3DPlot::constructSettingsWidget(QWidget* parent_) {
    QUiLoader loader;
    QFile file("c3dplot_settings.ui");
    file.open(QFile::ReadOnly);
    QWidget* settingsWidget = loader.load(&file,parent_);
    file.close();
    return settingsWidget;
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
    return m_scene;
}

CPlot* C3DPlot::CreatePlot() {
    return new C3DPlot();
}
