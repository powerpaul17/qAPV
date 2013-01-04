#ifndef CPLOT_H
#define CPLOT_H

#include "cobject.h"
#include "cdata.h"

class CPlot:public CObject {

    QList<CData*> dataSeries;

public:

    CPlot();
    ~CPlot();

    bool hasChildren();
    int getNChildren();
    CObject* getChild(long id_);

    void exportToXML(QDomNode* node_);

};

#endif // CPLOT_H
