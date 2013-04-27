#include "cdata.h"

CData::CData() {
    m_data.clear();
}

CData::~CData() {
    m_data.clear();
}

CData::CData(CData &cdata_):CObject() {
    for(QList<double>::iterator it=m_data.begin();it!=m_data.end();it++) {
        cdata_.appendValue((*it));
    }
}

double CData::getValue(long id_) {
    if((id_>=0) && (m_id<m_data.size())) {
        return m_data[id_];
    } else return 0.0;
}

void CData::appendValue(double value_) {
    m_data.append(value_);
}

void CData::deleteValue(long id_) {
    m_data.removeAt(id_);
}

void CData::insertValue(long id_, double value_) {
    m_data.insert(id_,value_);
}

void CData::clearData() {
    m_data.clear();
}
