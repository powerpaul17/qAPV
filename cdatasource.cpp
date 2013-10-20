#include "cdatasource.h"

CDataSource::CDataSource(QString datasourcetype_,bool isstatic_):CObject(0,"Datasource") {
    addProperty("datasourcetype","Datasource Type","Datasource Type",datasourcetype_,false,false);
    addProperty("isstatic","Static?","Static data source?",isstatic_,true,true);
}

bool CDataSource::getIsStatic() {
    return getBoolPropertyValue("isstatic");
}

void CDataSource::setIsStatic(bool isstatic_) {
    setPropertyValue("isstatic",isstatic_);
}
