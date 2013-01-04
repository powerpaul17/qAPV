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
    CObject* getChild(long id_);

    void exportToXML(QDomNode *node_);

    bool isLogarithmic();
    void setLogarithmic(bool logarithmic_);

};

#endif // CAXIS_H
