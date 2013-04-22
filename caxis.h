#ifndef CAXIS_H
#define CAXIS_H

#include "cobject.h"

class CAxis:public CObject {

    bool logarithmic;

public:

    CAxis();
    virtual ~CAxis();

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

    bool isLogarithmic();
    void setLogarithmic(bool logarithmic_);

public slots:

    virtual void slot_childDestroyed(CObject *child_);

};

#endif // CAXIS_H
