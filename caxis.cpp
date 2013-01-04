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

CObject* CAxis::getChild(long id_) {
    return 0;
}

void CAxis::exportToXML(QDomNode *node_) {
    //TODO
}
