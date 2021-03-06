#ifndef CDATASOURCE_H
#define CDATASOURCE_H

#include <QtGui>
#include <QtWidgets/QtWidgets>

#include "cobject.h"
#include "cdata.h"

/* typedef enum {
    FileDataSource
} DataSourceType; */

class CDataSource:public CObject {

public:
    //CDataSource(DataSourceType datasourcetype_,bool isstatic_);
    CDataSource(QString datasourcetype_,bool isstatic_);

    bool getIsStatic();
    void setIsStatic(bool isstatic_);

    virtual QWidget* getSettingsWidget(QWidget* parent_) = 0;

    virtual CData* getData() = 0;

    // virtual CDataSource* CreateDataSource() = 0;
};

typedef CDataSource* (*CreateDataSourceFunc)(void);

#endif // CDATASOURCE_H
