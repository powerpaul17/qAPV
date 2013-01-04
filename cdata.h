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
    void appendValue(double value_);
    void deleteValue(long id_);
    void insertValue(long id_,double value_);
    void clearData();
};

#endif // CDATA_H
