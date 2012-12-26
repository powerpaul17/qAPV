#include "cdatasource.h"

CDataSource::CDataSource(bool isstatic_) {
    this->isstatic = isstatic_;
}

bool CDataSource::getIsStatic() {
    return this->isstatic;
}

void CDataSource::setIsStatic(bool isstatic_) {
    this->isstatic = isstatic_;
}
