#include "cdata.h"

CData::CData() {
    data.clear();
}

CData::~CData() {
    data.clear();
}

CData::CData(CData &cdata_):CObject() {
    for(QList<double>::iterator it=data.begin();it!=data.end();it++) {
        cdata_.appendValue((*it));
    }
}

double CData::getValue(long id_) {
    if((id_>=0) && (id<data.size())) {
        return data[id_];
    } else return 0.0;
}

void CData::appendValue(double value_) {
    data.append(value_);
}

void CData::deleteValue(long id_) {
    data.removeAt(id_);
}

void CData::insertValue(long id_, double value_) {
    data.insert(id_,value_);
}

void CData::clearData() {
    data.clear();
}
