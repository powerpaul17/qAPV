#ifndef CPROJECT_H
#define CPROJECT_H

#include <QtWidgets>

#include "cobject.h"

class CProject:public CObject {

    //Q_OBJECT

    bool changed;

    uint currId;

public:

    CProject();
    virtual ~CProject();
    CProject(QString filename_);

    void constructFromXML(QXmlStreamReader* xml_);

    int loadProjectFromFile();
    void saveProjectToFile();

    QString getFilename();
    void setFilename(QString filename_);
    bool isChanged();
    void setChanged(bool changed_ = true);

//signals:

    //void projectChanged();

};

#endif // CPROJECT_H
