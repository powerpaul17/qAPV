#ifndef CAXIS_H
#define CAXIS_H

#include "cobject.h"

class CAxis:public CObject {

public:

    CAxis();
    virtual ~CAxis();

    void constructFromXML(QXmlStreamReader *xml_);

    bool isLogarithmic();
    void setLogarithmic(bool logarithmic_);

};

#endif // CAXIS_H
