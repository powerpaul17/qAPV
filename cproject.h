#ifndef CPROJECT_H
#define CPROJECT_H

#include <QtWidgets>

#include "cobject.h"

class CProject:public CObject {

    QString filename;
    QList<CObject*> children;
    bool changed;

    uint currId;

public:

    CProject();
    ~CProject();
    CProject(QString filename_);

    bool hasChildren();
    int getNChildren();
    CObject* getChild(long id_);

    void exportToXML(QDomNode* node_);

    int loadProjectFromFile();
    void saveProjectToFile();

    QString getFilename();
    void setFilename(QString filename_);
    bool isChanged();
    void setChanged(bool changed_ = true);

    void addChild(CObject* child_);
};

#endif // CPROJECT_H
