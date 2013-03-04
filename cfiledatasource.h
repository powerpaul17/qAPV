#ifndef CFILEDATASOURCE_H
#define CFILEDATASOURCE_H

#include "cdatasource.h"
#include "cdata.h"

class CFileDataSource:public CDataSource {
    QString filename;

    CData* data;

    QWidget* settingsWidget;

    void constructSettingsWidget();

public:
    CFileDataSource();
    CFileDataSource(QString filename_);
    ~CFileDataSource();

    bool hasChildren();
    int getNChildren();
    CObject* getChildById(long id_);
    CObject* getChildByPosition(long pos_);

    void exportToXML(QXmlStreamWriter* xml_);
    void constructFromXML(QXmlStreamReader *xml_);

    QWidget* getSettingsWidget();

    CData* getData();

    static CDataSource* CreateDataSource();
};

#endif // CFILEDATASOURCE_H
