#include "caxis.h"

CAxis::CAxis():CObject(0,"Axis",-1,"Axis") {

    addProperty("logarithmic","Logarithmic?","Is the scale of the axis logarithmic?",false);
}

CAxis::~CAxis() {

}

void CAxis::constructFromXML(QXmlStreamReader *xml_) {
    this->setName(xml_->attributes().value("name").toString());
    //TODO
    xml_->skipCurrentElement();
}
