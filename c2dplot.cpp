#include <QtUiTools>
#include <QtWidgets>

#include "c2dplot.h"

C2DPlot::C2DPlot():CPlot(Plot2D) {
    this->name = "2D Plot";
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
void C2DPlot::exportToXML(QXmlStreamWriter* xml_) {
    xml_->writeStartElement("Plot");
    xml_->writeAttribute("type",QVariant(this->type).toString());
    xml_->writeAttribute("plottype",QVariant(this->getPlotType()).toString());

    //TODO
    x.exportToXML(xml_);
    y.exportToXML(xml_);

    xml_->writeEndElement();
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
