#include "cdatasource.h"

CDataSource::CDataSource(DataSourceType datasourcetype_,bool isstatic_) {
    this->type = DataSource;
    this->datasourcetype = datasourcetype_;
    this->isstatic = isstatic_;
}

bool CDataSource::getIsStatic() {
    return this->isstatic;
}

void CDataSource::setIsStatic(bool isstatic_) {
    this->isstatic = isstatic_;
}
