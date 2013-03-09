#include <QtUiTools>
#include <QtWidgets>

#include "c2dplot.h"

C2DPlot::C2DPlot():CPlot("2D") {
    this->name = "2D Plot";
    x.setName("x");
    y.setName("y");
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

CObject* C2DPlot::getChildById(long id_) {
    return 0;
}

CObject* C2DPlot::getChildByPosition(long pos_) {
    return 0;
}

int C2DPlot::getPositionOfChild(CObject* child_) {
    return -1;
}

void C2DPlot::exportToXML(QXmlStreamWriter* xml_) {
    xml_->writeStartElement("Plot");
    xml_->writeAttribute("name",this->getName());
    xml_->writeAttribute("type",QVariant(this->type).toString());
    xml_->writeAttribute("plotType",QVariant(this->getPlotType()).toString());

    //TODO
    x.exportToXML(xml_);
    y.exportToXML(xml_);

    xml_->writeEndElement();
}

void C2DPlot::constructFromXML(QXmlStreamReader *xml_) {
    //TODO
    this->setName(xml_->attributes().value("name").toString());
    while(xml_->readNextStartElement()) {
        if(xml_->name()=="Axis") {
            if(xml_->attributes().value("name").toString() == "x") {
                x.constructFromXML(xml_);
            } else if (xml_->attributes().value("name").toString() == "y") {
                y.constructFromXML(xml_);
            }
        }
    }
    xml_->skipCurrentElement();
}

QWidget* C2DPlot::getSettingsWidget() {
    return settingsWidget;
}

void C2DPlot::drawPlot(QGraphicsScene *scene_) {
    //TODO
}

CPlot* C2DPlot::CreatePlot() {
    return new C2DPlot();
}
