#ifndef CPROJECT_H
#define CPROJECT_H

#include <QVector>

#include "cobject.h"

class CProject:public CObject {

    QString filename;
    QVector<CObject*> children;
    bool changed;

    unsigned long currId;

public:

    CProject();
    ~CProject();
    CProject(QString filename_);

    virtual bool hasChildren();
    virtual int getNChildren();
    virtual CObject* getChild(long id_);

    void exportToXML(QDomNode* node_);

    int loadProjectFromFile();
    void saveProjectToFile();

    QString getFilename();
    void setFilename(QString filename_);
    bool isChanged();
    void setChanged(bool changed_ = true);
};

#endif // CPROJECT_H
