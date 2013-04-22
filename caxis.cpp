#include "caxis.h"

CAxis::CAxis():CObject(0,"Axis",-1,"Axis") {

}

CAxis::~CAxis() {

}

void CAxis::exportToXML(QXmlStreamWriter *xml_) {
    xml_->writeStartElement("Axis");
        xml_->writeAttribute("name",this->getName());
    //TODO
    xml_->writeEndElement();
}

void CAxis::constructFromXML(QXmlStreamReader *xml_) {
    this->setName(xml_->attributes().value("name").toString());
    //TODO
    xml_->skipCurrentElement();
}
