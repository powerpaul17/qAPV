#include "cproject.h"

CProject::CProject():CObject(0,Project,0,"Project") {
    //type = ProjectType;
    //name = "Project";

    filename = "";
    currId = 1;
    children.clear();
    changed = false;
}

CProject::~CProject() {
    //for(QVector<CObject*>::iterator it = children.begin(); it != children.end(); it++) {
    //    delete it;
    //}
    while(children.size()>0) {
        delete children[0];
        children.removeFirst();
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
    for(QList<CObject*>::iterator it = children.begin(); it != children.end(); it++) {
        if((*it)->getId() == id_) return *it;
    }
    return 0;
}

void CProject::exportToXML(QDomNode* node_) {
    QDomElement* node = new QDomElement();
    node->setTagName("Project");
    node->setAttribute("currId",currId);
    node_->appendChild(*node);
    for(QList<CObject*>::iterator it = children.begin(); it != children.end(); it++) {
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

void CProject::addChild(CObject* child_) {
    child_->setId(currId);
    child_->setParent(this);
    currId++;
    children.append(child_);
    setChanged();
}
