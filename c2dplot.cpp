#include <QtUiTools>
#include <QtWidgets>

#include "c2dplot.h"

C2DPlot::C2DPlot():CPlot("2D") {
    m_name = "2D Plot";
    //constructSettingsWidget();
    m_scene = new QGraphicsScene();
}

C2DPlot::~C2DPlot() {
    delete m_scene;
}

QWidget* C2DPlot::constructSettingsWidget(QWidget* parent_) {
    QUiLoader loader;
    QFile file("c2dplot_settings.ui");
    file.open(QFile::ReadOnly);
    QWidget* settingsWidget = loader.load(&file,parent_);
    file.close();
    return settingsWidget;
}

void C2DPlot::exportToXML(QXmlStreamWriter* xml_) {
    xml_->writeStartElement("Plot");
    xml_->writeAttribute("name",getName());
    xml_->writeAttribute("type",QVariant(m_type).toString());
    xml_->writeAttribute("plotType",QVariant(getPlotType()).toString());

    //TODO

    xml_->writeEndElement();
}

void C2DPlot::constructFromXML(QXmlStreamReader *xml_) {
    //TODO
    setName(xml_->attributes().value("name").toString());
    while(xml_->readNextStartElement()) {
        //if(xml_->name()=="Axis") {

        //}
    }
    xml_->skipCurrentElement();
}

QWidget* C2DPlot::getSettingsWidget(QWidget *parent_) {
    return constructSettingsWidget(parent_);
}

QGraphicsScene* C2DPlot::getGraphicsScene() {
    return m_scene;
}

CPlot* C2DPlot::CreatePlot() {
    return new C2DPlot();
}
