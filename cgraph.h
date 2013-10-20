#ifndef CGRAPH_H
#define CGRAPH_H

#include "cobject.h"

class CGraph:public CObject {

public:

    CGraph();
    CGraph(CObject* parent_);
    virtual ~CGraph();

    virtual void constructFromXML(QXmlStreamReader* xml_);

};

#endif // CGRAPH_H
