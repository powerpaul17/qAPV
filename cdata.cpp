#include "cdata.h"

CData::CData() {
    data.clear();
}

CData::~CData() {
    data.clear();
}

CData::CData(CData &cdata_):CObject() {
    //TODO!!
}

double CData::getValue(long id_) {
    if((id_>=0)&&(id<data.size())) {
        return data[id_];
    } else return 0.0;
}

void CData::appendValue(double value_) {
    data.append(value_);
}
