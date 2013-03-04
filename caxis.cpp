#include "caxis.h"

CAxis::CAxis():CObject(0,Axis,-1,"Axis") {

}

CAxis::~CAxis() {

}

bool CAxis::hasChildren() {
    return false;
}

int CAxis::getNChildren() {
    return 0;
}

CObject* CAxis::getChildById(long id_) {
    return 0;
}

CObject* CAxis::getChildByPosition(long pos_) {
    return 0;
}

void CAxis::exportToXML(QXmlStreamWriter *xml_) {
    xml_->writeStartElement("Axis");
    //TODO
    xml_->writeEndElement();
}
