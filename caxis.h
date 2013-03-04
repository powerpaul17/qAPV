#ifndef CAXIS_H
#define CAXIS_H

#include "cobject.h"

class CAxis:public CObject {

    bool logarithmic;

public:

    CAxis();
    ~CAxis();

    bool hasChildren();
    int getNChildren();
    CObject* getChildById(long id_);
    CObject* getChildByPosition(long pos_);

    void exportToXML(QXmlStreamWriter* xml_);

    bool isLogarithmic();
    void setLogarithmic(bool logarithmic_);

};

#endif // CAXIS_H
