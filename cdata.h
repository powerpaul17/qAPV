#ifndef CDATA_H
#define CDATA_H

#include "cobject.h"

class CData:public CObject {
    QVector<double> data;
public:
    CData();
    ~CData();
    CData(CData& cdata_);

    double getValue(long id_);
};

#endif // CDATA_H
