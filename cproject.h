#ifndef CPROJECT_H
#define CPROJECT_H

#include <QVector>

#include "cobject.h"

class CProject:public CObject {
    QVector<CObject*> children;

    unsigned long currId;

public:
    CProject();
    ~CProject();

    virtual bool hasChildren();
    virtual int getNChildren();
    virtual CObject* getChild(long id_);

    void exportToXML(QDomNode* node_);
};

#endif // CPROJECT_H
