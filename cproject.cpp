#include "cproject.h"

CProject::CProject():CObject(0,ProjectType,0,"Project") {
    //type = ProjectType;
    //name = "Project";

    currId = 0;
    children.clear();
}

CProject::~CProject() {
    for(QVector<CObject*>::iterator it = children.begin(); it != children.end(); ++it) {
        delete (*it);
    }
    children.clear();
}

bool CProject::hasChildren() {
    return (children.size()>0);
}

int CProject::getNChildren() {
    return children.size();
}

CObject* CProject::getChild(long id_) {
    for(QVector<CObject*>::iterator it = children.begin(); it != children.end(); ++it) {
        if((*it)->getId() == id_) return *it;
    }
    return 0;
}

void CProject::exportToXML(QDomNode* node_) {
    QDomNode* node = new QDomNode();
    node_->appendChild(*node);
    for(QVector<CObject*>::iterator it = children.begin(); it != children.end(); ++it) {
        (*it)->exportToXML(node);
    }
}
