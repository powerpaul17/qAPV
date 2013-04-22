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
    virtual ~CFileDataSource();

    bool hasChildren();
    int getNChildren();
    CObject* getChildById(long id_);
    CObject* getChildByPosition(long pos_);
    int getPositionOfChild(CObject* child_);
    void addChild(CObject *child_);
    void removeChild(CObject *child_);
    void removeChild(long id_);

    void exportToXML(QXmlStreamWriter* xml_);
    void constructFromXML(QXmlStreamReader *xml_);

    QWidget* getSettingsWidget();

    CData* getData();

    static CDataSource* CreateDataSource();

public slots:

    virtual void slot_childDestroyed(CObject *child_);
};

#endif // CFILEDATASOURCE_H
