#include "cproject.h"

CProject::CProject():CObject(0,ProjectType,0,"Project") {
    //type = ProjectType;
    //name = "Project";

    filename = "";
    currId = 0;
    children.clear();
    changed = false;
}

CProject::~CProject() {
    for(QVector<CObject*>::iterator it = children.begin(); it != children.end(); ++it) {
        delete (*it);
    }
    children.clear();
}

CProject::CProject(QString filename_) {
    CProject();
    filename = filename_;
    loadProjectFromFile();
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

int CProject::loadProjectFromFile() {
    //TODO
    return 0;
}

void CProject::saveProjectToFile() {
    QDomDocument* document = new QDomDocument("qAPV Document");
    exportToXML(document);

    QFile file(filename);
    if(file.open(QIODevice::WriteOnly)) {
        QTextStream textstream(&file);
        document->save(textstream,0);
        file.close();
        setChanged(false);
    } else {
        // TODO
    }

    delete document;
}

QString CProject::getFilename() {
    return filename;
}

void CProject::setFilename(QString filename_) {
    filename = filename_;
}

bool CProject::isChanged() {
    return changed;
}

void CProject::setChanged(bool changed_) {
    changed = changed_;
}
