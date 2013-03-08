#ifndef CDATASOURCEFACTORY_H
#define CDATASOURCEFACTORY_H

#include <QMap>

#include "cdatasource.h"

class CDataSourceFactory {
    QMap<QString,CreateDataSourceFunc> dataSourceMap;
public:
    CDataSourceFactory();
    virtual ~CDataSourceFactory();

    void registerDataSource(const QString& name_, CreateDataSourceFunc createfunc_);

    CDataSource* createDataSource(const QString& name_);

    QMapIterator<QString,CreateDataSourceFunc> getDataSources();
};

#endif // CDATASOURCEFACTORY_H
