#ifndef CPROJECT_H
#define CPROJECT_H

#include <QtWidgets>

#include "cobject.h"

class CProject:public CObject {

    //Q_OBJECT

    QString filename;
    QList<CObject*> children;
    bool changed;

    uint currId;

public:

    CProject();
    virtual ~CProject();
    CProject(QString filename_);

    bool hasChildren();
    int getNChildren();
    CObject* getChildById(long id_);
    CObject* getChildByPosition(long pos_);
    int getPositionOfChild(CObject* child_);
    void addChild(CObject *child_);
    void removeChild(CObject* child_);
    void removeChild(long id_);

    void exportToXML(QXmlStreamWriter* xml_);
    void constructFromXML(QXmlStreamReader* xml_);

    int loadProjectFromFile();
    void saveProjectToFile();

    QString getFilename();
    void setFilename(QString filename_);
    bool isChanged();
    void setChanged(bool changed_ = true);

//signals:

    //void projectChanged();

public slots:

    virtual void slot_childDestroyed(CObject *child_);

};

#endif // CPROJECT_H
