#include "cdatasource.h"

CDataSource::CDataSource(QString datasourcetype_,bool isstatic_) {
    m_type = "Datasource";
    m_name = "Plot";
    m_datasourcetype = datasourcetype_;
    m_isstatic = isstatic_;
}

bool CDataSource::getIsStatic() {
    return m_isstatic;
}

void CDataSource::setIsStatic(bool isstatic_) {
    m_isstatic = isstatic_;
}
