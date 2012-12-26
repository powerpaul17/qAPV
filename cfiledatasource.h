#ifndef CFILEDATASOURCE_H
#define CFILEDATASOURCE_H

#include "cdatasource.h"

class CFileDataSource:public CDataSource {
    QString filename;

public:
    CFileDataSource(QString filename_);
    ~CFileDataSource();

    bool hasChildren();
    int getNChildren();
    CObject* getChild(long id_);

    void exportToXML(QDomNode* node_);
};

#endif // CFILEDATASOURCE_H
