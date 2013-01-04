#include "cdatasourcefactory.h"

#include "cfiledatasource.h"

CDataSourceFactory::CDataSourceFactory() {
    dataSourceMap.clear();

    registerDataSource("File",&CFileDataSource::CreateDataSource);
}

CDataSourceFactory::~CDataSourceFactory() {
    dataSourceMap.clear();
}

void CDataSourceFactory::registerDataSource(const QString &name_, CreateDataSourceFunc createfunc_) {
    dataSourceMap[name_] = createfunc_;
}

CDataSource* CDataSourceFactory::createDataSource(const QString &name_) {
    QMap<QString,CreateDataSourceFunc>::iterator it = dataSourceMap.find(name_);
    if(it != dataSourceMap.end()) {
        return (it.value())();
    } else {
        return 0;
    }
}

QMapIterator<QString,CreateDataSourceFunc> CDataSourceFactory::getDataSources() {
    return QMapIterator<QString,CreateDataSourceFunc>(dataSourceMap);
}
