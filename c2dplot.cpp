#include <QtUiTools>
#include <QtWidgets>

#include "c2dplot.h"

C2DPlot::C2DPlot():CPlot("2D") {
    this->name = "2D Plot";
    x.setName("x");
    y.setName("y");
    //constructSettingsWidget();
    scene = new QGraphicsScene();
}

C2DPlot::~C2DPlot() {
    delete scene;
}

QWidget* C2DPlot::constructSettingsWidget(QWidget* parent_) {
    QUiLoader loader;
    QFile file("c2dplot_settings.ui");
    file.open(QFile::ReadOnly);
    QWidget* settingsWidget = loader.load(&file,parent_);
    file.close();
    return settingsWidget;
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

void C2DPlot::addChild(CObject *child_) {

}

void C2DPlot::removeChild(CObject *child_) {

}

void C2DPlot::removeChild(long id_) {

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

QWidget* C2DPlot::getSettingsWidget(QWidget *parent_) {
    return constructSettingsWidget(parent_);
}

QGraphicsScene* C2DPlot::getGraphicsScene() {
    return scene;
}

CPlot* C2DPlot::CreatePlot() {
    return new C2DPlot();
}

void C2DPlot::slot_childDestroyed(CObject *child_) {

}
